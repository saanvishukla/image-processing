
#include "image_class.h"
#include <iostream>

using namespace std;

void loadImageData(int& width, int& height, int pixelData[MAX_HEIGHT][MAX_WIDTH]) {
    cin >> width >> height;

    if (cin.fail()) {
        cerr << "Error: Failed to read width and height from input." << endl;
        exit(1);
    }

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        cerr << "Error: Input dimensions exceed maximum allowed size." << endl;
        exit(1);
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cin >> pixelData[i][j];
            if (cin.fail()) {
                cerr << "Error: Failed to read pixel data at position (" << i << ", " << j << ")." << endl;
                exit(1);
            }
        }
    }
}

int main() {
    int width = 0, height = 0;
    int pixelData[MAX_HEIGHT][MAX_WIDTH];

    loadImageData(width, height, pixelData);

    cout << "Image loaded successfully.\n";

    Image img(width, height);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            img.setPixel(i, j, pixelData[i][j]);
        }
    }


    cout << "\nOriginal image:\n";
    img.display();

    cout << "\nFlipping horizontally:\n";
    img.flip(true);
    img.display();
    cout << "\nInverting the image:\n";
    img.invert();
    img.display();

    cout << "\nRotating by 90 degrees:\n";
    img.rotate(90);
    img.display();
    cout << "\nResizing by a factor of 2:\n";
    img.resize(2);
    img.display();

    cout << "\nInverting the image:\n";
    img.invert();
    img.display();
    cout << "\nRotating by 90 degrees:\n";
    img.rotate(90);
    img.display();

    cout << "\nCropping to center half:\n";
    img.crop(img.getWidth() / 4, img.getHeight() / 4, img.getWidth() / 2, img.getHeight() / 2);
    img.display();
    cout << "\nFlipping vertically:\n";
    img.flip(false);
    img.display();

    return 0;
}
