#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <array>
#include <vector>

#include "Logger.hh"

using std::cout;
using std::endl;
using std::string;

#if defined _WIN32 || defined _WIN64
#define fscanf fscanf_s
#endif

typedef std::array<float, 3> vec3f;
typedef std::array<float, 2> vec2f;

inline bool loadObj(string name, std::vector<std::array<float,8>>& vertex_out, std::vector<unsigned int>& indices_out){

	indices_out.clear();
	vertex_out.clear();

	string path = name;
	FILE* file;
	#if defined __APPLE__ || __linux__
	file = fopen(path.c_str(), "r");
	bool err = (file==NULL);
	#elif defined _WIN32 || _WIN64
	errno_t err = fopen(&file, path.c_str(), "r");
	#endif

	cout << "Loading model " << path << endl;

	if (err) {
		cout << "Could not open file: " << path << endl;
		return false;
	}

	std::vector<std::array<unsigned int, 3>> vertex_data;
	std::vector<vec3f> tmp_verts;
	std::vector<vec3f> tmp_normals;
	std::vector<vec2f> tmp_uvs;


	while (1) {
		char lineHeader[256];
		#ifdef __APPLE__
		int res = fscanf(file, "%128s", lineHeader);
        #elif defined __linux__
        int res = fscanf(file, "%[^\n]\n", lineHeader);
		#elif defined _WIN64 || defined _WIN32
		int res = fscanf(file, "%128s", lineHeader, (unsigned int)sizeof(lineHeader));
		#endif

		if (res == EOF)
			break;
		if (lineHeader[0]=='v' && lineHeader[1]==' ') {
			vec3f vertex;
			int pass = sscanf(lineHeader, "v %f %f %f \n", &vertex[0], &vertex[1], &vertex[2]);
			if(pass !=3){
				Logger::println("ERROR::LOADOBJ - File not properly formatted. Vertex data does not match input format.");
				Logger::println(lineHeader);
				return false;
			}
			tmp_verts.push_back(vertex);
		}
		else if (lineHeader[0]=='v' && lineHeader[1]=='n') {
			vec3f normal;
			int pass = sscanf(lineHeader,"vn %f %f %f \n", &normal[0], &normal[1], &normal[2]);
			if(pass !=3){
				Logger::println("ERROR::LOADOBJ - File not properly formatted. Normal data does not match input format.");
				Logger::println(lineHeader);
				return false;
			}
			tmp_normals.push_back(normal);
		}
		else if (lineHeader[0]=='v' && lineHeader[1]=='t') {
			vec2f uv;
			int pass = sscanf(lineHeader, "vt %f %f \n", &uv[0], &uv[1]);
			if(pass !=2){
				Logger::println("ERROR::LOADOBJ - File not properly formatted. Texture data does not match input format.");
				Logger::println(lineHeader);
				return false;
			}
			tmp_uvs.push_back(uv);
		}
		else if (lineHeader[0]=='f') {

			string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = sscanf(lineHeader, "f %u/%u/%u %u/%u/%u %u/%u/%u \n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if (matches != 9) {
				Logger::println("ERROR::LOADOBJ - File not properly formatted. Are you sure it is triangulated? Loader does not support quads.");
				Logger::println(lineHeader);
				return false;
			}

			vertex_data.push_back({vertexIndex[0]-1,uvIndex[0]-1,normalIndex[0]-1});
			vertex_data.push_back({vertexIndex[1]-1,uvIndex[1]-1,normalIndex[1]-1});
			vertex_data.push_back({vertexIndex[2]-1,uvIndex[2]-1,normalIndex[2]-1});
		}
	}
	size_t iii = 0;
	for (auto const& vertex_indices : vertex_data) {
		size_t jjj = 0;
		bool is_unique = true;
		for(auto const& existing_vertex : vertex_out){
			if(tmp_verts[vertex_indices[0]][0]==existing_vertex[0] && 
			   tmp_verts[vertex_indices[0]][1]==existing_vertex[1] && 
			   tmp_verts[vertex_indices[0]][2]==existing_vertex[2] && 
			   tmp_normals[vertex_indices[1]][0]==existing_vertex[3] && 
			   tmp_normals[vertex_indices[1]][1]==existing_vertex[4] && 
			   tmp_normals[vertex_indices[1]][2]==existing_vertex[5] && 
			   tmp_uvs[vertex_indices[2]][0]==existing_vertex[6] && 
			   tmp_uvs[vertex_indices[2]][1]==existing_vertex[7])
			{
				indices_out.push_back(jjj);
				is_unique = false;
				break;
			}
			++jjj;
		}
		if(is_unique){
			indices_out.push_back(iii);
			vertex_out.push_back({tmp_verts[vertex_indices[0]][0],tmp_verts[vertex_indices[0]][1],tmp_verts[vertex_indices[0]][2], tmp_normals[vertex_indices[1]][0],tmp_normals[vertex_indices[1]][1],tmp_normals[vertex_indices[1]][2], tmp_uvs[vertex_indices[2]][0],tmp_uvs[vertex_indices[2]][1]});
			++iii;
		}
	}

	vertex_data.clear();
	tmp_normals.clear();
	tmp_uvs.clear();
	tmp_verts.clear();

	fclose(file);
	return true;
}