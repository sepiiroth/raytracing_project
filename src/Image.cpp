#include "../include/Image.h"
#include <vector>
#include <string>
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../lib/stb/stb_image.h"
#include "../lib/stb/stb_image_write.h"
#include <bits/stdc++.h>

using std::vector;
using std::string;
using namespace std;

/*Image::Image(char* filename)
{
    this->pixels = stbi_load(filename, &this->width, &this->height, &this->bpp, 4);
}

Image::Image(string filename)
{
    this->pixels = stbi_load(filename.c_str(), &this->width, &this->height, &this->bpp, 4);
}*/

Image::Image()
{
    this->pixels = (uint8_t*) malloc(0*0*4);
    this->width = 0;
    this->height = 0;
}

Image::Image(int height, int width)
{
    this->pixels = (uint8_t*) malloc(width*height*4);
    this->width = width;
    this->height = height;
}

int Image::getWidth() const
{
    return this->width;
}

int Image::getHeight() const
{
    return this->height;
}

uint8_t* Image::getPixels() const
{
    return this->pixels;
}

uint8_t& Image::operator() (int x, int y, int color){
    return this->pixels[( x + y * this->width) * 4 + color];
}

void const Image::save(const char* filename) const
{
    stbi_write_png(filename, this->getWidth(), this->getHeight(), 4, this->getPixels(), this->getWidth()*4);
}

Image::~Image()
{
    //dtor
}
