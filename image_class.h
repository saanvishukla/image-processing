
#ifndef IMAGE_CLASS_H
#define IMAGE_CLASS_H


using namespace std;

#include <string>
#include <iostream>

const int MAX_WIDTH = 128;
const int MAX_HEIGHT = 128;

class Image {
private:
    int width;
    int height;
    int pixels[MAX_WIDTH][MAX_HEIGHT]; 

public:
    
    Image(int w, int h);

    ~Image();

    void setPixel(int row, int col, int value); 

    
    void flip(bool horizontal);

    
    void rotate(int angle);

    
    void resize(int scale);

    
    void crop(int x, int y, int newWidth, int newHeight);

    void invert();
    
    void display() const;

    int getWidth() const;
    int getHeight() const;
};

#endif 
