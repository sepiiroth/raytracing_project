#ifndef IMAGE_H
#define IMAGE_H
#include <vector>
#include <string>

#define RED 0
#define GREEN 1
#define BLUE 2
#define ALPHA 3

using std::vector;
using std::string;

class Image {
    private:
        int width, height, bpp;
        uint8_t* pixels;
    public:
        const char* imageName;

        Image();
        Image(int height, int width);
        Image(int height, int width, const char* filename);
        virtual ~Image();

        int getWidth() const;
        int getHeight() const;
        uint8_t* getPixels() const;
        uint8_t& operator() (int x, int y, int color); //permet de modifier la couleur du pixel en x, y
        void const save() const; //sauvegarde l'image
};

#endif
