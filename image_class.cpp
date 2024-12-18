
#include "image_class.h"
#include <iostream>
using namespace std;


void Image::setPixel(int row, int col, int value) {
    if (row >= 0 && row < height && col >= 0 && col < width) {
        pixels[row][col] = value;
    } else {
        cerr << "Error: Pixel coordinates out of bounds." << endl;
    }
}

Image::Image(int w, int h) : width(w), height(h) {
    if (w > MAX_WIDTH || h > MAX_HEIGHT) {
        cerr << "Error: Image dimensions exceed maximum allowed size." << endl;
        exit(1);
    }


    for (int row = 0; row < height; row++) {
        for (int col = 0; col < col; col++) {
            pixels[row][col] = 0;
        }
    }
}

Image::~Image() {
    
}


void Image::flip(bool horizontal) {
    if (horizontal) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width / 2; ++j) {
                int temp = pixels[i][j];
                pixels[i][j] = pixels[i][width - 1 - j];
                pixels[i][width - 1 - j] = temp;
            }
        }
    } else {
        for (int i = 0; i < height / 2; ++i) {
            for (int j = 0; j < width; ++j) {
                int temp = pixels[i][j];
                pixels[i][j] = pixels[height - 1 - i][j];
                pixels[height - 1 - i][j] = temp;
            }
        }
    }
}

void Image::rotate(int angle) {
    if (angle != 90 && angle != 180 && angle != 270) {
        cerr << "Error: Only 90, 180, 270 degrees are supported." << endl;
        return;
    }

    int rotated[MAX_HEIGHT][MAX_WIDTH];

    if (angle == 90) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                rotated[j][height - 1 - i] = pixels[i][j];
            }
        }
        int temp = width;
        width = height;
        height = temp;

    } else if (angle == 180) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                rotated[height - 1 - i][width - 1 - j] = pixels[i][j];
            }
        }
    } else if (angle == 270) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                rotated[width - 1 - j][i] = pixels[i][j];
            }
        }
        int temp = width;
        width = height;
        height = temp;
    }

    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            pixels[i][j] = rotated[i][j];
        }
    }
}


void Image::crop(int x, int y, int newWidth, int newHeight) {
    if (x + newWidth > width || y + newHeight > height) {
        cerr << "Error: Crop dimensions are out of bounds." << endl;
        return;
    }

    width = newWidth;
    height = newHeight;

    for (int i = 0; i < newHeight; i++) {
        for (int j = 0; j < newWidth; j++) {
            pixels[i][j] = pixels[y + i][x + j];
        }
    }

    for (int i = newHeight; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            pixels[i][j] = 0; 
        }
    }
}



void Image::invert() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixels[i][j] = (pixels[i][j] == 0) ? 1 : 0;
        }
    }
}


 void Image::resize(int scale) {
     if (scale <= 0) {
         cerr << "Error: Scale factor must be a positive integer." << endl;
         return;}

     int newWidth = width * scale;
     int newHeight = height * scale;

     int** new_size = new int*[newHeight];
     for (int i = 0; i < newHeight; i++) {
         new_size[i] = new int[newWidth]; 
     }

    
     for (int i = 0; i < newHeight; i++) {
         for (int j = 0; j < newWidth; j++) {

             int originalX = j / scale;
             int originalY = i / scale;

          
             if (originalX < width && originalY < height) {
                 new_size[i][j] = pixels[originalY][originalX];
             } else {
                 new_size[i][j] = 0;
             }
         }
     }

 
     width = newWidth;
     height = newHeight;

     for (int i = 0; i < height; i++) {
         for (int j = 0; j < width; j++) {
             pixels[i][j] = new_size[i][j];
         }
     }
     for (int i = 0; i < newHeight; i++) {
         delete[] new_size[i]; 
     }
     delete[] new_size;
 }


int Image::getWidth() const {
    return width;
}

int Image::getHeight() const {
    return height;
}

void Image::display() const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << (pixels[i][j] == 1 ? '*' : ' ') << ' ';
        }
        cout << endl;
    }
}
