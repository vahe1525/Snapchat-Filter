
#define CAMERAWIDTH 320 //640
#define CAMERAHEIGHT 240 //480

#ifndef MATRIX
#define MATRIX

// Project dependency
#include "Pixel.hpp"
#include "Point.hpp"

class Matrix
{
private:

public:
    // Dimentions
    int Width;
    int Height;
    
    // Center of the stamp
    Point Center;

    // Data
    Pixel Data[CAMERAWIDTH][CAMERAHEIGHT];

    // Constructor
    Matrix();
};

#endif // MATRIX
