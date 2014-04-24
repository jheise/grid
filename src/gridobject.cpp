#include "gridobject.h"
GridObject::GridObject(){
};

GridObject::GridObject(Shader* shader_reference, const std::string& modelPath, const std::string& modelName){
    shader = shader_reference;

    printf("Loading model: %s\n", modelPath.c_str());
    std::string fullpath = find_file(modelPath, modelName);
    printf("found path: %s\n", fullpath.c_str());

    std::string fullPath = find_file(modelPath, modelName);

    //check file exists
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
            aiProcess_GenSmoothNormals      //|
            //aiProcess_FlipUVs
        //aiProcess_JoinIdenticalVertices |
        //aiProcess_SortByPType);
    );
    if(!scene){
        throw std::runtime_error(importer.GetErrorString());
    }
    printf("imported %s\n",modelPath.c_str());
    fflush(stdout);

    //aiMesh* aimesh = scene->mMeshes[0];
    for( int i=0; i < scene->mNumMeshes; i++){
        aiMesh *aimesh = scene->mMeshes[i];
        Mesh* newMesh = new Mesh(shader, modelPath, aimesh);
        meshes.push_back(newMesh);
    }

    //setup all textures
    for(int i=0; i < scene->mNumMaterials; i++){
        const aiMaterial* pMaterial = scene->mMaterials[i];
        printf("texture count is %d\n",pMaterial->GetTextureCount(aiTextureType_DIFFUSE));
        if(pMaterial->GetTextureCount(aiTextureType_DIFFUSE) > 0){
            aiString newpath;
            printf("attempting to get texture\n");

            if(pMaterial->GetTexture(aiTextureType_DIFFUSE, 0, &newpath, NULL, NULL, NULL, NULL) == AI_SUCCESS){
                std::string texture_path = find_file(modelPath,newpath.data);
                printf( "texture is at %s\n",texture_path.c_str());
                Texture* texture = new Texture(texture_path);
                textures.push_back(texture);
            }
        }
    }

    //setup identity and position
    identity = glm::mat4();
    umodel = shader->handleUniform("model");
    ucamera = shader->handleUniform("camera");
    utexture = shader->handleUniform("textureUniform");
    degree = 0;

}

GridObject::~GridObject(){
    printf("OBJECT GOES AWAY NOW\n");
}

void GridObject::display(glm::mat4& view){
    //turn on shader to use
    shader->activate();

    //update model
    glUniformMatrix4fv(umodel, 1, GL_FALSE, &identity[0][0]);
    //push current camera position
    glUniformMatrix4fv(ucamera, 1, GL_FALSE, &view[0][0]);

    for(int i=0; i < meshes.size(); i++){
        meshes[i]->display(view, textures);
    }
}

void GridObject::update(float tick){
    //update code goes here
    degree += tick * 180.0f;
    if(degree > 360.0f){
        degree -= 360.0f;
    }
    //identity = glm::rotate(glm::mat4(), degree, glm::vec3(0,1,0));
    identity = glm::rotate(glm::mat4(), 270.0f, glm::vec3(1,0,0));
    identity = glm::rotate(identity, degree, glm::vec3(0,0,1));
}
