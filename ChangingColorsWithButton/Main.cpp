
#define CAMERAWIDTH 320 //640
#define CAMERAHEIGHT 240 //480

#define BUTTONPIN 5

// Project libraries
#include "Matrix.hpp"
#include "Pixel.hpp"
#include "Point.hpp"
#include "Webcam.hpp"
#include "BMPExporter.hpp"
#include "Colors.hpp"
#include "ColorsChanger.hpp"

// Standard libraries
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>
#include <string>
#include <wiringPi.h>

//typedef for functiojn calling with map
//typedef void (*FunctionCall)(Matrix matrix);

//the checker function for changers
void ChangingPictureColor(Matrix matrix, Color color)
{
    //changer object
    ColorsChanger change;

    //checking the color name
    switch (color)
    {
	case 1:
	    change.ChangingPictureToRed(matrix);
	    break;

	case 2:
	    change.ChangingPictureToBlue(matrix);
	    break;

	case 3:
	    change.ChangingPictureToGreen(matrix);
	    break;

	case 4:
	    change.ChangingPictureToPink(matrix);
	    break;
	
	case 5:
	    change.ChangingPictureToElectricBlue(matrix);
	    break;
	
	case 6:
	    change.ChangingPictureToYellow(matrix);
	    break;
    }
}

int Start()
{	
	//wiringPI pinout setup
	wiringPiSetup();
	pinMode(BUTTONPIN, INPUT);


	//webcam object creating
	Webcam webcam("/dev/video0", CAMERAWIDTH, CAMERAHEIGHT);
	Matrix matrix;

	//lighting adjustment
	std::cout << "performing lighting adjustment --- please wait:: " << std::endl;
	for(int i = 0; i < 40; ++i)
	{
		matrix = webcam.Frame();
	}
	std::cout << "lighting adjustment completed :: " << std::endl;


	//Color Number
	int ColorNum = Red;

	//starting the loop 
	while(true)
	{
		//PUD UP(1) FOR PIN
		pullUpDnControl(BUTTONPIN, PUD_UP);
	
		//reading frame from webcam
		matrix = webcam.Frame();

		//calling functions after touching
		if(digitalRead(BUTTONPIN) == 0)
		{

			std::cout << "button touched" << std::endl;
			if(ColorNum == Last)
			{
				ColorNum = Red;		
			}

			//color(num) change
			Color a = static_cast<Color>(ColorNum);
			ChangingPictureColor(matrix, a);
			++ColorNum;
			
			//result
			std::cout << "<<<<<<<<go to files and see the result>>>>>>>>" << std::endl;
			std::cout << std::endl;
			sleep(1);
		}

		//not touched button
		else 
		{
			std::cout << "you can touch the button "  << std::endl;
			usleep(50000);
		}

	}
	return 0;
}

// MAIN Function
int main()
{
	//start of Program
	Start();
}
