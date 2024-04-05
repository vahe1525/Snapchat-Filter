#ifndef COLORSCHANGER_HPP
#define COLORSCHANGER_HPP

//includes for class functions
#include "Matrix.hpp"
#include "Pixel.hpp"
#include "Point.hpp"
#include "BMPExporter.hpp"

class ColorsChanger
{
public:

    //changing to Yellow
    void ChangingPictureToYellow(Matrix matrix)
    {
	for(int i = 0; i < CAMERAWIDTH; ++i)
	{
	    for(int j = 0; j < CAMERAHEIGHT; ++j)
	    {
		matrix.Data[i][j].B = 0;
	    }
	}
	BMPExporter exporter;
	exporter.Export(matrix, "Output/tmp.bmp"); 		
    }

    //changing to Electric Blue
    void ChangingPictureToElectricBlue(Matrix matrix)
    {
	for(int i = 0; i < CAMERAWIDTH; ++i)
	{
	    for(int j = 0; j < CAMERAHEIGHT; ++j)
	    {
		matrix.Data[i][j].R = 0;
	    }
	}
	BMPExporter exporter;
	exporter.Export(matrix, "Output/tmp.bmp"); 		
    }

    //changing to Red
    void ChangingPictureToRed(Matrix matrix)
    {
	for (int ii = 0; ii < CAMERAHEIGHT; ++ii)
	{
	    for (int jj = 0; jj < CAMERAWIDTH; ++jj)
	    {
		matrix.Data[jj][ii].G = 0;
		matrix.Data[jj][ii].B = 0;
	    }
	}
	BMPExporter exporter;
	exporter.Export(matrix, "Output/tmp.bmp");

    }

    //changing to Blue
    void ChangingPictureToBlue(Matrix matrix)
    {
	for (int ii = 0; ii < CAMERAHEIGHT; ++ii)
	{
	    for (int jj = 0; jj < CAMERAWIDTH; ++jj)
	    {
		matrix.Data[jj][ii].R = 0;

		matrix.Data[jj][ii].G = 0;
	    }
	}
	BMPExporter exporter;
	exporter.Export(matrix, "Output/tmp.bmp");


    }

    //changing to Green
    void ChangingPictureToGreen(Matrix matrix)
    {
	for (int ii = 0; ii < CAMERAHEIGHT; ++ii)
	{
	    for (int jj = 0; jj < CAMERAWIDTH; ++jj)
	    {
		matrix.Data[jj][ii].R = 0;
		matrix.Data[jj][ii].B = 0;
	    }
	}
	BMPExporter exporter;
	exporter.Export(matrix, "Output/tmp.bmp");

    }

    //changing to Pink
    void ChangingPictureToPink(Matrix matrix)
    {
	for(int i = 0; i < CAMERAWIDTH; ++i)
	{
	    for(int j = 0; j < CAMERAHEIGHT; ++j)
	    {
		matrix.Data[i][j].G = 0;
	    }
	}
	BMPExporter exporter;

	exporter.Export(matrix, "Output/tmp.bmp"); 		
    }
};

#endif //COLORSCHANGER_HPP
