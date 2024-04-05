
#ifndef TOUROUBERAN_BMPEXPORTER
#define TOUROUBERAN_BMPEXPORTER

// Project libraries
#include "Matrix.hpp"

// Standard libraries
#include <string>

class BMPExporter
{
private:
    const int BYTES_PER_PIXEL = 3; /// red, green, & blue
    const int FILE_HEADER_SIZE = 14;
    const int INFO_HEADER_SIZE = 40;

    void generateBitmapImage(unsigned char* image, int height, int width, const char* imageFileName);
    unsigned char* createBitmapFileHeader(int height, int stride);
    unsigned char* createBitmapInfoHeader(int height, int width);

public:
    void Export(const Matrix& matrix, const std::string& fileName);

};

#endif // TOUROUBERAN_BMPEXPORTER
