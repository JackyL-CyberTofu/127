#include "image2.hpp"
#include <iostream>
#include <fstream>
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
 	cols=0;
 	rows=0;
 	if( pixels != NULL ) 
    {
       delete[] pixels; 
    }
 }

 int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor ){
 	if (pixels != NULL){
 		delete[] pixels;
 	}
 	pixels= new uint8_t[width*height];
 	if (pixels == NULL){
 		return 1;
 	}
 	int i;
 	for (i=0;i<width*height;i++)
 	{
 		pixels[i] = fillcolor;
 	}
 	cols = width ;
 	rows = height ;
 	return 0;
 }  

 int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color ){
 	if (x >= cols || y >= rows ){
 		return 1;
 	}
 	pixels[y*cols+x] = color;
 	return 0;
 }
  

 int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ){
 	if (x >= cols || y >= rows ){
 		return 1;
 	}
 	if (pixels == NULL){
 		return 1;
 	}
 	*colorp = pixels[y*cols+x];
 	return 0;
 }

 int Image::save( const char* filename ){
 	if (filename == NULL){
 		cout << "filename wrong for saving." << endl;
 		return 1;
 	}
 	fstream fp;
	fp.open(filename, fstream::out); /* Read-write. */
 	//FILE *fp = fopen(filename,"w");
 	if (!fp.is_open()){
 		cout << "Error Opening File for saving." << endl;
 		return 1;
 	}
 	if ((rows == 0 && cols > 0) || (rows > 0 && cols == 0)){
		cout << "Error pixels for saving." << endl;
		return 1;
	}
 	if (cols == 0 && rows == 0){		
 		fp.close();
 		cout << "Saving empty File." << endl;
 		return 0;
 	}
 	//cout << "0" <<endl;
 	int i,j;
 	for (i=0;i<rows;i++){
 		j=0;
 		for(j=0;j<cols;j++){
 			fp<<(int)pixels[i*cols+j]<<" ";
 		}
 		fp << endl;
 	}
    fp.close();
 	return 0; 	 	
}
 int Image::load( const char* filename ){
 	if (filename == NULL){
 		cout << "Error filename for loading"<<endl;
		return 1;
	}
	cout << "1" << endl;

	fstream fp;
	fp.open(filename,ios::in);
	if(!fp.is_open()){
		cout << "Error opening file for loading"<<endl;
		return 1;
	}
	fp.seekg (0, fp.end);
    int length = fp.tellg();
    fp.seekg (0, fp.beg);
    cout << "2" << endl;
    if (length == 0) {
 		cols = 0;
 		rows = 0;
 		pixels = NULL;
 		fp.close();
 		cout << "Loading Empty File@." << endl;
    	return 0;
 	}
	cout << "3" << endl;
	int pix;
	int i,total_num=0,cline=0,ccol;
	char line[1500];
	while (!fp.eof()){
		fp >> pix;
		total_num++;
	}
	total_num = total_num -1;
	fp.clear();
	fp.seekg (0, fp.beg);	
	
	cout << "4" << endl;
	while (!fp.eof()){
		fp.getline(line,1500,'\n');
		cline ++;
	}
	cline = cline - 1;	
	fp.clear();
	fp.seekg (0, fp.beg);
	
	if (cline == 0){
		ccol = 0;
		cols = ccol;
		rows = 0;
		if(pixels != NULL){
			delete[] pixels;
			pixels = NULL;
		}		
		cout << "loading empty image successful@."<<endl;
		fp.close();
		return 0;
	}
	else{
		ccol = total_num/cline;
		cols = ccol;
		rows = cline;	
	}
	cout << "loading rows: "<< rows << endl; 
	cout << " cols: " << cols <<endl;		
	if(pixels != NULL){
		delete[] pixels;
	}
	cout << "6" << endl;
	pixels = new uint8_t[cols*rows];
	for (i=0; i<total_num; i++){
		fp >> pix;
		pixels[i] = pix;
	}
	cout << "7" << endl;
	fp.close();
	cout << "Finish loading image."<<endl;
	return 0;
	
 }