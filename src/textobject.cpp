#include "textobject.h"

TextObject::TextObject(){
    printf("Starting font load\t");
    if(FT_Init_FreeType(&ft)){
        throw std::runtime_error(std::string("Failed to initialize FreeType"));
    }

    if(FT_New_Face(ft, "/usr/share/fonts/truetype/freefont/FreeSans.ttf", 0, &face)){
        throw std::runtime_error(std::string("failed to intialize font"));
    }

    FT_Set_Pixel_Sizes(face, 0, 48);

    g = face->glyph;

    textshader = new Shader(std::string("../shaders/text.vertex"), std::string("../shaders/text.fragment"));
    textshader->assemble();

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vertex);
    glBindBuffer(GL_ARRAY_BUFFER, vertex);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4*sizeof(GLfloat), NULL);

    glGenTextures(1, &texture);
    GLuint utext = textshader->handleUniform(std::string("tex"));
    glUniform1i(utext, texture);

    glBindVertexArray(0);

    printf("Done\n");

}

void TextObject::render_text(const char* characters, float x1, float y1, float scalex, float scaley){

    glBindTexture(GL_TEXTURE_2D, texture);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    const char* p;

    for(p=characters; *p; p++){
        if(FT_Load_Char(face, *p, FT_LOAD_RENDER)){
            throw std::runtime_error("error loading character");
        }
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,
            g->bitmap.width,
            g->bitmap.rows,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            g->bitmap.buffer
        );

        float xlength = g->bitmap.width * scalex;
        float ylength = g->bitmap.rows * scaley;
        float x2 = x1 + g->bitmap_left * scalex;
        float y2 = y1 + g->bitmap_top * scaley;

        float xLeft = x2;
        float xRight = x2 + xlength;

        float yHigh = y2;
        float yLow  = y2 - ylength;

        GLfloat newbox[] = {
            xLeft, yHigh, 0,0,
            xLeft, yLow,  0,1,
            xRight, yHigh, 1,0,
            xRight, yLow, 1,1
        };

        textshader->activate();

        glBindVertexArray(vao);
        glBufferData(GL_ARRAY_BUFFER, sizeof(newbox), newbox, GL_DYNAMIC_DRAW);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        x1 += ( g->advance.x >> 6) * scalex;
        y1 += ( g->advance.y >> 6) * scaley;
    }
}
