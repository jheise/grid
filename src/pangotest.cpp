#include "pangotest.h"

PangoTest::PangoTest(){
    ptextshader = new Shader(std::string("../shaders/text.vertex"), std::string("../shaders/text.fragment"));
    ptextshader->assemble();

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vertex);
    glBindBuffer(GL_ARRAY_BUFFER, vertex);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4*sizeof(GLfloat), NULL);

    ptext = ptextshader->handleUniform(std::string("tex"));

    glBindVertexArray(0);
    ptexture = new PangoTexture(std::string("Sans bold 100"));
}

void PangoTest::render(){
    std::string test = std::string("1\tdog\n");
    test += 'd';
    ptexture->generate(test);

    float xlength = 256 * 2.0/1366;
    float ylength = 256 * 2.0/768;
    float x1 = -0.9f;
    float y1 = 0.8f;
    float xLeft = x1;
    float xRight = x1 + xlength;
    float yHigh = y1;
    float yLow  = y1 - ylength;

    GLfloat newbox[] = {
        xLeft, yHigh,  0,0,
        xLeft, yLow,   0,1,
        xRight, yHigh, 1,0,
        xRight, yLow,  1,1
    };

    ptextshader->activate();
    glBindVertexArray(vao);
    ptexture->bind(1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(newbox), newbox, GL_DYNAMIC_DRAW);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);


}
