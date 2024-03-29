#pragma once

#include <vector>
#include <string>

#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>

#include "Mesh.h"
#include "Texture.h"
#include "Texture3D.h"

class Model
{
public:
	Model();
	Model(const Model& obj);
	void LoadModel(const std::string& fileName);
	void RenderModel();
	void RenderModel3D(Texture3D& text);
	void ClearModel();
	void ClearMeshes();
	void ChangeandUploadData(glm::mat4 matrix,bool scalenormal = false);
	void SetNormals();
	//Model& operator=(const Model& obj);

	~Model();

	std::vector<Mesh*> meshList;
	std::vector<Texture*> textureList;
	std::vector<unsigned int> meshToTex;
	bool copy = false;
private:

	void LoadNode(aiNode *node, const aiScene *scene);
	void LoadMesh(aiMesh *mesh, const aiScene *scene);
	void LoadMaterials(const aiScene *scene);

};
