#pragma once

#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"
#include "stb_image.h"
#include "Dependencies/assimp/include/assimp/Importer.hpp"
#include "Dependencies/assimp/include/assimp/scene.h"
#include "Dependencies/assimp/include/assimp/postprocess.h"

#include "Meshtest.h"
#include "Shadertest.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

class Model
{
public:
	/*  Model Data */



	// constructor, expects a filepath to a 3D model.
	Model(std::string const& path, bool gamma = false);

	// draws the model, and thus all its meshes
	void Draw(std::shared_ptr<Shader> shader);



private:

	void loadModel(std::string const& path);

	// processes a node in a recursive fashion. Processes each individual mesh located at the node and repeats this process on its children nodes (if any).
	void processNode(aiNode* node, const aiScene* scene);

	Mesh processMesh(aiMesh* mesh, const aiScene* scene);


	// checks all material textures of a given type and loads the textures if they're not loaded yet.
	// the required info is returned as a Texture struct.
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	/*  Model Data */
	std::vector<Texture> textures_loaded;	// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
	std::vector<Mesh> meshes;
	std::string directory;
	bool gammaCorrection;


};
