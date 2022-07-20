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

class Image
{
    public:
        //Image(char* filename);
        //Image(string filename);
        Image();
        Image(int height, int width);
        int getWidth() const;
        int getHeight() const;
        uint8_t* getPixels() const;
        virtual ~Image();
        uint8_t& operator() (int x, int y, int color);
        void const save(const char* filename) const;

    protected:

    private:
        int width, height, bpp;
        uint8_t* pixels;
};

#endif // IMAGE_H
