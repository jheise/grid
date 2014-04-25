#include "model.h"

Model::Model(const std::string& modelPath, const std::string& modelName){
    std::string fullPath = find_file(modelPath, modelName);

    std::ifstream fin(fullPath.c_str());
    if(!fin.fail()){
        fin.close();
    }else{
        throw std::runtime_error("could not open file" + fullPath);
    }
    //file can be opened, import it
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile( fullPath,
              aiProcessPreset_TargetRealtime_Fast |
              //aiProcess_CalcTangentSpace      |
              aiProcess_Triangulate           |
              aiProcess_GenSmoothNormals      |
              //aiProcess_FlipUVs
              aiProcess_JoinIdenticalVertices //|
          //aiProcess_SortByPType);
    );
    if(!scene){
        throw std::runtime_error(importer.GetErrorString());
    }

    for( int i=0; i < scene->mNumMeshes; i++){
        aiMesh* aimesh = scene->mMeshes[i];
        Mesh* newMesh = new Mesh(aimesh);
        meshes.push_back(newMesh);
    }

    for(int i=0; i < scene->mNumMaterials; i++){
        const aiMaterial* pMaterial = scene->mMaterials[i];
        if(pMaterial->GetTextureCount(aiTextureType_DIFFUSE) > 0){
            aiString newpath;

            if(pMaterial->GetTexture(aiTextureType_DIFFUSE, 0, &newpath, NULL, NULL, NULL, NULL) == AI_SUCCESS){
                std::string texture_path = find_file(modelPath,newpath.data);
                Texture* texture = new Texture(texture_path);
                textures.push_back(texture);
            }
        }
    }
}

void Model::display(glm::mat4& view){
    for(int i=0; i < meshes.size(); i++){
        meshes[i]->display(view, textures);
    }
}
