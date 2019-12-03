#include "Model.h"
#include <fstream>
#include <math.h>
#include <sstream>

Model::Model(){
	triangles = vector<Triangle3D>();
}

int Model::NumTriangles(){ return triangles.size(); }

Triangle3D Model::operator[](int i){
	return triangles[i];
}

void Model::Transform(Matrix4 m){
	for (int i = 0; i < triangles.size(); i++){
		triangles[i].Transform(m);
	}
}

void Model::ReadFromOBJFile(string filepath, Color pFillColor){
	ifstream ifile(filepath);
	string line;
	vector<string> words;
	vector<Vector4> vertices;
	vector<Triangle3D> vectriangles;

	if (ifile.is_open())
	{
		while (getline(ifile, line)){

			istringstream s(line);

			std::string sub;
			while (s >> sub){
				words.push_back(sub);
			}
			if (words.size() > 0){
				if (words[0] == "v"){
					// Vertex
					vertices.push_back(Vector4(atof(words[1].c_str()), atof(words[2].c_str()), atof(words[3].c_str()),1.0));
				}
				else if (words[0] == "f"){
					// Face
					triangles.push_back(Triangle3D(vertices[atoi(words[1].c_str()) - 1], vertices[atoi(words[2].c_str()) - 1], vertices[atoi(words[3].c_str()) - 1], pFillColor, pFillColor, pFillColor,true));
				}
				words.clear();
			}
		}
	}
	ifile.close();
}
