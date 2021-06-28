// Name: Ismayil Adigozalzada
// USC NetID: 3786609877
// CSCI 455 HW2Q3
// Summer 2021

#include <iostream>
#include <fstream>
#include <cmath>
#include "Q3.h"

using namespace std;

// ********************** array2D Class START ******************
void array2D::getSize(int& xResolution, int& yResolution) {
    xResolution = xRes;
    yResolution = yRes;
} // getSize()
void array2D::setValue(int x, int y, float val) {
    xtable[y][x] = val;
} // setValue()
float array2D::getValue(int x, int y) {
    return xtable[y][x];
} // getValue()
// ********************** array2D Class end ******************

// ********************** PGMImage Class START ******************
void PGMImage::getResolution(int& xResolution,int& yResolution) {
    getSize(xResolution, yResolution);
}
void PGMImage::setPixel(int x,int y,int val) {
    setValue(x,y,val);
}
float PGMImage::getPixel(int x, int y) {
    return getValue(x,y);
}
void PGMImage::writeFile(string filename) {
    ofstream pgmFile(filename); // output image file we're creating

    // header
    pgmFile << "P2" << endl;
    pgmFile << xRes << " " << yRes << endl; // how many columns, how many rows
    pgmFile << 255 << endl; // largest pixel value we'll be outputting (below)

    // pixel data
    for(int i=0;i<yRes;i++){
        for(int j=0;j<xRes;j++){
            pgmFile << getPixel(j,i) << " ";
            //cout << getPixel(j,i) << " "; // *TEST* code
        }// next column
        pgmFile << endl;
        //cout << endl; // *TEST* code
    }// next row

    // all done!
    pgmFile.close();
}
// ********************** PGMImage Class end ******************

// ********************** ComplexNumber Class START ******************
ComplexNumber ComplexNumber::add(ComplexNumber c2) {
    double tmpReal = real + c2.real;
    double tmpImag = imag + c2.imag;
    ComplexNumber *c3 = new ComplexNumber(tmpReal,tmpImag);
    return *c3;
}
ComplexNumber ComplexNumber::squared(ComplexNumber c2) {
    double tmpReal = pow(c2.real,2)-pow(c2.imag,2);
    double tmpImag = 2*c2.real*c2.imag;
    ComplexNumber *c3 = new ComplexNumber(tmpReal,tmpImag);
    return *c3;
}
double ComplexNumber::abs(ComplexNumber c2) {
    return sqrt(c2.real*c2.real+c2.imag*c2.imag);
}
void ComplexNumber::prt(ComplexNumber c2) {
    cout << c2.real << " + " << c2.imag << "j" << endl;
}
// ********************** ComplexNumber Class end ******************


int main() {
    //cout << "TEST" << endl; // *TEST* code
    int xRes=640, yRes=480;
    double cxmin = -2.0, cymin = -1.0, cxmax = 1.0, cymax = 1.0;
    double cReal=0, cImag=0;
    int val=0;

    PGMImage *img = new PGMImage(xRes,yRes,"fractal");

    for(int i=0; i<xRes; i++){
        for(int j=0; j<yRes; j++){
            cReal = cxmin + double(i)/(double(xRes)-1.0)*(cxmax-cxmin);
            cImag = cymin + double(j)/(double(yRes)-1.0)*(cymax-cymin);
            //cout << "cReal: " << cReal << " cImag: " << cImag << endl; // *TEST*
            ComplexNumber c(cReal,cImag), z(0,0);
            //c.prt(c); // *TEST*
            int maxIter = 250, iter = 0;

            while (iter < maxIter && z.abs(z) < 2) {
                z = c.add(z.squared(z));
                // z.prt(z); // *TEST*
                if (z.abs(z) >= 2) {
                    val = iter;
                }
                else {
                    val = 0;
                }
                iter++;
            }
            cout << val << endl; // *TEST*
            img->setPixel(i,j,val);
        }
    }
    img->writeFile("fractal");

    delete img;
    return 0;
}// main()

