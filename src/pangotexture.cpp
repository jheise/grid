#include "pangotexture.h"

PangoTexture::PangoTexture(const std::string& font_str){
    font = font_str;
    glGenTextures(1, &texture_id);
}

PangoTexture::~PangoTexture(){

}

void PangoTexture::generate(const std::string& text){
    cairo_t* layout_context;
    cairo_t* render_context;
    cairo_surface_t* temp_surface;
    cairo_surface_t* surface;
    unsigned char* surface_data = NULL;
    PangoFontDescription *desc;
    PangoLayout* layout;

    //create layout context
    cairo_surface_t* ltemp_surface;
    ltemp_surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 0, 0);

    layout_context  = cairo_create(ltemp_surface);
    cairo_surface_destroy(ltemp_surface);
    //cairo surface set, make pango layout
    layout = pango_cairo_create_layout(layout_context);
    pango_layout_set_text(layout, text.c_str(), -1);

    //load fond
    desc = pango_font_description_from_string(font.c_str());
    pango_layout_set_font_description(layout, desc);
    pango_font_description_free(desc);

    //get_text_size(layout, text_width, text_height);

    pango_layout_get_size(layout, &width, &height);
    //printf("width is %d\n", width);
    //printf("height is %d\n", height);

    width /= PANGO_SCALE;
    height /= PANGO_SCALE;

    //printf("width is %d\n", width);
    //printf("pango height is %d\n", height);

    surface_data = (unsigned char*)calloc(4 * width * height, sizeof(unsigned char));
    surface = cairo_image_surface_create_for_data(surface_data,
                        CAIRO_FORMAT_ARGB32,
                        width,
                        height,
                        4 * width);
    //channels == 4
    render_context = cairo_create(surface);
    cairo_set_source_rgba(render_context, 1, 1, 1, 1);
    pango_cairo_show_layout( render_context, layout);

    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGBA,
                 width,
                 height,
                 0,
                 GL_BGRA,
                 GL_UNSIGNED_BYTE,
                 surface_data);

}

void PangoTexture::bind(GLuint uniform){
    glActiveTexture(GL_TEXTURE0);
    //printf("pango texture id is %d\n", texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glUniform1i(uniform, texture_id);

}

void PangoTexture::unbind(){
    glBindTexture(GL_TEXTURE_2D, 0);
}

int PangoTexture::get_width(){
    return width;
}

int PangoTexture::get_height(){
    return height;
}
