#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "../include/Image.h"
#include "../lib/stb/stb_image.h"
#include "../lib/stb/stb_image_write.h"
#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;
using std::vector;
using std::string;

/*Initialisation*/
Image::Image() {
    this->pixels = (uint8_t*) malloc(0*0*4);
    this->width = 0;
    this->height = 0;
    this->imageName = "image.jpg";
}

Image::Image(int height, int width) {
    this->pixels = (uint8_t*) malloc(width*height*4);
    this->width = width;
    this->height = height;
    this->imageName = "image.jpg";
}

Image::Image(int height, int width, const char* filename) {
    this->pixels = (uint8_t*) malloc(width*height*4);
    this->width = width;
    this->height = height;
    this->imageName = filename;
}

Image::~Image() {

}

/*Calculs*/
int Image::getWidth() const {
    return this->width;
}

int Image::getHeight() const {
    return this->height;
}

uint8_t* Image::getPixels() const {
    return this->pixels;
}

uint8_t& Image::operator() (int x, int y, int color){
    return this->pixels[( x + y * this->width) * 4 + color];
}

void const Image::save() const {
    stbi_write_png(this->imageName, this->getWidth(), this->getHeight(), 4, this->getPixels(), this->getWidth()*4);
}

