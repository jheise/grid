#include "textbox.h"
using namespace std;
using namespace grid;
using namespace textbox;
TextBox::TextBox(float xpos, float ypos, float ylength, const string& font){
    x1 = xpos;
    y1 = ypos;
    yrange = ylength;
    textshader = new Shader("../shaders/text.vertex","../shaders/text.fragment");
    textshader->assemble();

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    //printf( "textbox vao is %d\n", vao);

    glGenBuffers(1, &vertex);
    //printf( "textbox vertex is %d\n", vertex);
    glBindBuffer(GL_ARRAY_BUFFER, vertex);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4*sizeof(GLfloat), NULL);
    utexture = textshader->handleUniform("tex");

    glBindVertexArray(0);
    texture = new PangoTexture(font);
    buffer = string("");
    needsupdate = true;
}

void TextBox::append(const string& new_string){
    buffer += new_string;
    if( (int) buffer.length() > 2000){
        int buffer_diff = (int) buffer.length() - 2000;
        buffer = buffer.substr(buffer_diff, -1);
    }

    needsupdate = true;
}

void TextBox::update(float tick){
    //printf( "textbox vao is %d\n", vao);
    //printf( "textbox vertex is %d\n", vertex);
    if(needsupdate){
        texture->generate(buffer);

        float xlength = texture->get_width() * 2.0/1366;
        float ylength = texture->get_height() * 2.0/768;
        float ylimit = yrange * 2.0/768;
        float x2 = x1 + 2.0/1366;
        float y2 = y1 + 2.0/768;

        float xLeft = x2;
        float xRight = x2 + xlength;

        float yHigh = y2;
        float yLow = y2 - ylength;

        float texture_y_pos = 0;

        //check texture lenght vs box length
        if(ylength > ylimit){
            //printf("past limit\n");
            texture_y_pos = 1 - ylimit/ylength;
            yLow = y2 - ylimit;

        }

        //printf("texture_y_pos is %f\n", texture_y_pos);
        //printf("text height %d", texture->get_height());
        //printf(" yHigh %f", yHigh);
        //printf(" yLow %f", yLow);
        //printf(" ylength %f",ylength);
        //printf(" ylimit %f\n",ylimit);


        GLfloat newbox[] = {
            xLeft, yHigh, 0,texture_y_pos,
            xLeft, yLow, 0,1,
            xRight, yHigh, 1, texture_y_pos,
            xRight, yLow, 1,1
        };

        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vertex);
        glBufferData(GL_ARRAY_BUFFER, sizeof(newbox), newbox, GL_DYNAMIC_DRAW);

        needsupdate = false;
    }
}

void TextBox::pop_back(){
    buffer.pop_back();
    needsupdate = true;
}

void TextBox::render(){
    textshader->activate();
    glBindVertexArray(vao);
    texture->bind(1);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    texture->unbind();
    glBindVertexArray(0);
}
