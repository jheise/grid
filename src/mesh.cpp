#include "mesh.h"
Mesh::Mesh(){
};

Mesh::Mesh(aiMesh* mesh){
    material = mesh->mMaterialIndex;

    std::vector<unsigned int> indices;
    std::vector<float> vertices;
    std::vector<float> uvs;
    std::vector<float> normals;

    int numOfFaces = mesh->mNumFaces;
    int numOfIndices = numOfFaces * 3;
    indices.resize(numOfIndices);
    count = numOfIndices;

    for (unsigned int i =0; i < mesh->mNumFaces; ++i){
        const aiFace &face = mesh->mFaces[i];
        //assert(face.mNumIndices == 3);
        indices[i * 3 + 0] = face.mIndices[0];
        indices[i * 3 + 1] = face.mIndices[1];
        indices[i * 3 + 2] = face.mIndices[2];
    }

    int numOfVertices = mesh->mNumVertices;
    vertices.resize(numOfVertices * 3);
    normals.resize(numOfVertices * 3);
    uvs.resize(numOfVertices * 2);
    for( unsigned int i = 0; i < mesh->mNumVertices; ++i){

        if(mesh->HasPositions()){
            vertices[i * 3 + 0] = mesh->mVertices[i].x;
            vertices[i * 3 + 1] = mesh->mVertices[i].y;
            vertices[i * 3 + 2] = mesh->mVertices[i].z;
        }

        if( mesh->HasNormals()){
            normals[i * 3 + 0] = mesh->mNormals[i].x;
            normals[i * 3 + 1] = mesh->mNormals[i].x;
            normals[i * 3 + 2] = mesh->mNormals[i].x;
        }

        if(mesh->HasTextureCoords(0)){
            uvs[i * 2 + 0] = mesh->mTextureCoords[0][i].x;
            uvs[i * 2 + 1] = mesh->mTextureCoords[0][i].y;
        }
    }

    //create vao
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    //create element buffer
    glGenBuffers(1, &index);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    //create vertex buffer
    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(aiVector3D), &vertices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glGenBuffers(1, &uv);
    glBindBuffer(GL_ARRAY_BUFFER, uv);
    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(aiVector2D), &uvs[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), (void*)0);

    glGenBuffers(1, &normal);
    glBindBuffer(GL_ARRAY_BUFFER, normal);
    glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(aiVector3D), &normals[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    //clean state
    glBindVertexArray(0);
}

Mesh::~Mesh(){
    printf("OBJECT GOES AWAY NOW\n");
}

void Mesh::display(glm::mat4& view, const std::vector<Texture*>& textures){
    //bind vao
    glBindVertexArray(vao);

    //bind texture
    textures[material]->bind(1);

    //draw triangles
    glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, NULL);
    textures[material]->unbind();
}
