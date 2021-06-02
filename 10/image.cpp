#include "image.hpp"
#include <iostream>
#include <stdint.h> // for uint8_t
#include <stdlib.h>
#include <stdio.h>
using namespace std;
Image::Image()
{
	cols = 0;
	rows = 0;
	pixels = NULL;//
}

 Image::~Image()
 {
 	if( pixels != NULL ) 
    {
       delete[] pixels; 
    }
 }

 /* Changes the size of an image, allocating memory as necessary, and
     setting all pixels to fillcolor. Returns 0 on success, or a non-zero error code.*/ 
 int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor ){
 	delete[] pixels; 
 	uint8_t pixels[width*height];
 	if (pixels == NULL){
 		return 1;
 	}
 	int i;
 	for (i=0;i<width*height;i++)
 	{
 		pixels[i]=fillcolor;
 	}
 	return 0;
 }
  
  /* Sets the color of the pixel at (x,y) to color. Returns 0 on success, else a non-zero 
     error code. If (x,y) is not a valid pixel, the call fails and the image does not change.*/
 int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color ){
 	if (x >= cols || y >= rows ){
 		return 1;
 	}
 	pixels[y*cols+x] = color;
 	return 0;
 }
  
  /* Gets the color of the pixel at (x,y) and stores at the address pointed to 
     by colorp. Returns 0 on success, else a non-zero error code. */
 int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ){
 	if (x >= cols || y >= rows ){
 		return 1;
 	}
 	*colorp = pixels[y*cols+x];
 	return 0;
 }