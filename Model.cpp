#include "Raster.h"
#include "Vector2.h"
#include "Model.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

Model::Model()
: triangles({}){}

int Model::NumTriangles(){
	return triangles.size();
}

Triangle3D Model::operator[ ](int i){
	return triangles.at(i);
}

void Model::Transform(Matrix4 transform){
	triangles.at(0).v0.print();
	triangles.at(0).v1.print();
	triangles.at(0).v2.print();
	for (int i = 0; i < triangles.size(); i++){
		triangles.at(i).Transform(transform);
	}
	triangles.at(0).v0.print();
	triangles.at(0).v1.print();
	triangles.at(0).v2.print();
}

void Model::ReadFromOBJFile(string path, Color c){
	vector<Vector4> vects;
	ifstream myFile(path);
	if (myFile.is_open()){
		string line;
		while (getline(myFile,line)){
			istringstream s(line);
			string myWord;
			vector<string> words;
			while(getline(s,myWord,' ')){
				words.push_back(myWord);
			}
			if (words[0].compare("v") == 0) {
				Vector4 add(stof(words[1]),
						stof(words[2]),
						stof(words[3]), 1);
				vects.push_back(add);
			}
			if (words[0].compare("f") == 0) {
				Triangle3D add(vects.at(stoi(words[1])-1),
						(vects.at(stoi(words[2])-1)),
						(vects.at(stoi(words[3])-1)),
						 c, c, c);
				triangles.push_back(add);
			}
		}
	}
}
