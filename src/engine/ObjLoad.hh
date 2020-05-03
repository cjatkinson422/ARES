#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <array>
#include <vector>

#include "engine/Logger.hh"
#include "GNClib/vec3f.hh"

using std::cout;
using std::endl;
using std::string;

#if defined _WIN32 || defined _WIN64
#define fscanf fscanf_s
#endif


inline bool loadObj(string path, std::vector<std::array<float,14>>& vertex_out, std::vector<unsigned int>& indices_out){

	// Verify that the output vectors are clean
	indices_out.clear();
	vertex_out.clear();


	// Open the file 
	FILE* file;
	#if defined __APPLE__ || __linux__
	file = fopen(path.c_str(), "r");
	bool err = (file==NULL);
	#elif defined _WIN32 || _WIN64
	errno_t err = fopen(&file, path.c_str(), "r");
	#endif

	Logger::println("Loading model ");

	// Check that the file was opened properly
	if (err) {
		Logger::println("Could not open file: " + path);
		return false;
	}

	// Declare the variables that will be used to read in the data from the file
	// obj files contain vertex, normal, and uv coordinates for each vertex
	std::vector<std::array<unsigned int, 3>> vertex_data_indices;
	std::vector<vec3f> tmp_pos;
	std::vector<vec3f> tmp_normals;
	std::vector<vec3f> tmp_uvs; // note: uv is only 2 coordinates, but we use a vec3 for simplicity

	// Continue reading the file until the end of the file is detected and then
	// once EOF is found, a break is called
	while (1) {
		// Declare a buffer to read in each line. Obj files contain relatively short lines, 
		// even if double precision numbers were used, 256 characters should be sufficient 
		char lineHeader[256];

		// Read in the next line of the file and store its contents in the lineHeader buffer
		#ifdef __APPLE__
		int res = fscanf(file, "%128s", lineHeader);
        #elif defined __linux__
        int res = fscanf(file, "%[^\n]\n", lineHeader);
		#elif defined _WIN64 || defined _WIN32
		int res = fscanf(file, "%128s", lineHeader, (unsigned int)sizeof(lineHeader));
		#endif

		// If the line is the end of the file, exit the loop.
		if (res == EOF)
			break;
		// If the line begins with a single 'v', then this line contains vertex data
		if (lineHeader[0]=='v' && lineHeader[1]==' ') {
			// read in the three floats as a vertex position
			vec3f position;
			int pass = sscanf(lineHeader, "v %f %f %f \n", &position[0], &position[1], &position[2]);
			// double check that the three floats were all read into the array
			if(pass !=3){
				Logger::println("ERROR::LOADOBJ - File not properly formatted. Vertex data does not match input format.");
				Logger::println(lineHeader);
				return false;
			}
			// Else, add this vertex to the list of vertices
			tmp_pos.push_back(position);
		}
		// if the line begins with 'vn' then this line conains normal vector data
		else if (lineHeader[0]=='v' && lineHeader[1]=='n') {
			// Read in the floats as a normal vector
			vec3f normal;
			int pass = sscanf(lineHeader,"vn %f %f %f \n", &normal[0], &normal[1], &normal[2]);
			// double check that the three floats were all read into the array
			if(pass !=3){
				Logger::println("ERROR::LOADOBJ - File not properly formatted. Normal data does not match input format.");
				Logger::println(lineHeader);
				return false;
			}
			// Else add the vertex to the vector of normals
			tmp_normals.push_back(normal);
		}
		// if the line begins with 'vt', then this line contains texture coordinate data
		else if (lineHeader[0]=='v' && lineHeader[1]=='t') {
			// Read in the textuer coordinate data
			vec3f uv;
			int pass = sscanf(lineHeader, "vt %f %f \n", &uv[0], &uv[1]);
			// Verify that the data was read correctly
			if(pass !=2){
				Logger::println("ERROR::LOADOBJ - File not properly formatted. Texture data does not match input format.");
				Logger::println(lineHeader);
				return false;
			}
			// Add the texture coordinate set to the array of UVs
			tmp_uvs.push_back(uv);
		}
		// If the line beings with 'f' then this line contains the indices of position, normal, and uv that define a polygon (triangle) of the model.
		else if (lineHeader[0]=='f') {

			// Create three arrays of unsigned ints to hold the index data. (might need to move to unsigned longs if models get large)
			unsigned int positionIndex[3], uvIndex[3], normalIndex[3];
			// then read in each set of three indices as a a vertex. Each vertex should have a position, normal, and uv. Three vertices should be read to form a triangle.
			int matches = sscanf(lineHeader, "f %u/%u/%u %u/%u/%u %u/%u/%u \n", &positionIndex[0], &uvIndex[0], &normalIndex[0], &positionIndex[1], &uvIndex[1], &normalIndex[1], &positionIndex[2], &uvIndex[2], &normalIndex[2]);
			// Verify that the data was all ready correctly
			if (matches != 9) {
				Logger::println("ERROR::LOADOBJ - File not properly formatted. Are you sure it is triangulated? Loader does not support quads.");
				Logger::println(lineHeader);
				return false;
			}

			// change the indices from 1 indexed to 0 indexed
			for(int i = 0; i  <  3; ++i){
				positionIndex[i] -= 1;
				normalIndex[i] -= 1;
				uvIndex[i] -= 1;
			}
			

			// For each face (triangle), we need to test each vertex for uniqueness, and if the vertex is unique,
			// we need to both calculate that vertex's NTB (normal tangent bitangent) matrix, and then push its data
			// into the vertex data array, and its index into the index array.

			// This loader only supports triangles, so we need to loop over the three vertices that make it up
			for(int i = 0; i < 3; ++i){
				
				// Now we need to check if this vertex has already been added to the vertex data array
				// We will compare it to existing by using the vertex_data_indices array
				size_t j = 0;
				bool is_unique = true;
				for(auto const& vertex_indices : vertex_data_indices){
					
					// Now check if each of the indices for each component of the vertex are
					// identical to ones already in the vertex_data_indices array
					if(vertex_indices[0]==positionIndex[i]&&
					   vertex_indices[1]==uvIndex[i]&&
					   vertex_indices[2]==normalIndex[i]){
						    // If it is not, set the flag to false
						    is_unique = false;
							// add the index of the vertex_indices values within vertex_data_indices
							indices_out.push_back(j);
							// exit the loop since we found what we were looking for
							break;
					}
					// if we didn't find it this attempt, we need
					// to iterate the index before the next go
					++j;
				}

				// If the is_unique flag remains true, then we need
				// to add its data to the ouput arrays and do some other
				// processing, such as calculating NTB matrices.
				if(is_unique){

					// If this is a unique vertex, ie has not been loaded yet,
					// then we should add the size of the output data as it
					// is before we push data to it (so we dont take the index after this one)
					indices_out.push_back(vertex_out.size());

					// Now we need to calculate this vertex's NTB matrix
					// The algorithm used was sourced here:
					// https://learnopengl.com/Advanced-Lighting/Normal-Mapping

					// Get two edges of the triangle
					vec3f edge1 = tmp_pos[positionIndex[1]] - tmp_pos[positionIndex[0]];
					vec3f edge2 = tmp_pos[positionIndex[2]] - tmp_pos[positionIndex[0]];
					// Get two edges but in uv space
					vec3f deltaUV1 = tmp_uvs[uvIndex[1]] - tmp_uvs[uvIndex[0]];
					vec3f deltaUV2 = tmp_uvs[uvIndex[2]] - tmp_uvs[uvIndex[0]];

					// value to normalize the vectors with
					float f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

					// calculate the tangent vector
					vec3f tangent;
					tangent.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
					tangent.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
					tangent.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);

					// calculate the bitangent vector
					vec3f bitangent;
					bitangent.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
					bitangent.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
					bitangent.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);


					// We now have all the data we need to send this vertex to the GPU. 
					// So lets append its data to the output array.
					vertex_out.push_back({
						tmp_pos[positionIndex[i]][0],tmp_pos[positionIndex[i]][1],tmp_pos[positionIndex[i]][2], 
						tmp_uvs[uvIndex[i]][0],tmp_uvs[uvIndex[i]][1], 
						tmp_normals[normalIndex[i]][0],tmp_normals[normalIndex[i]][1],tmp_normals[normalIndex[i]][2],
						tangent.x, tangent.y, tangent.z,
						bitangent.x, bitangent.y, bitangent.z
					});

					// Push the indices out to the indices array for
					// testing uniqueness on the next loop iteration
					vertex_data_indices.push_back({positionIndex[i],uvIndex[i],normalIndex[i]});
				}
			}
		}
	}


	vertex_data_indices.clear();
	tmp_normals.clear();
	tmp_uvs.clear();
	tmp_pos.clear();

	fclose(file);
	return true;
}