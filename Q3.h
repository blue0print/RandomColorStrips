// Name: Ismayil Adigozalzada
// USC NetID: 3786609877
// CSCI 455 HW2Q3
// Summer 2021

#ifndef Q3_Q3_H
#define Q3_Q3_H

// ********************** array2D Class DECLARATION ******************
class array2D {
protected:
    int xRes, yRes; // horizontal (x) and vertical (y) resolution of the image
    float **xtable; // pointer to pointers

public:
    array2D(int xRes, int yRes) {
        this->xRes=xRes;
        this->yRes=yRes;

        xtable = new float*[yRes]; // a ("column") array to hold 'float *' type pointers

        // each element of the above array points to a 'row' of xRes elements
        for(int i=0;i < yRes;i++) {
            xtable[i] = new float[xRes];
        }
        for(int i=0;i < yRes;i++){
            for(int j=0;j < xRes;j++){
                xtable[i][j]=45; // store 45 for pixel data, "for now"
            }
        }
    } // array2D Constructor

    ~array2D() {
        delete xtable;
    }// array2D Destructor

    void getSize(int& xResolution, int& yResolution);
    void setValue(int x, int y, float val);
    float getValue(int x, int y);
}; // array2D class def

// ********************** PGMImage Class DECLARATION ******************
class PGMImage: public array2D {
private:
    std::string filename;
protected:
public:
    // Constructor
    PGMImage(int xRes, int yRes, const std::string &filename) : array2D(xRes, yRes) {
        // cout << xRes << " " << yRes << " " << xtable[0][0] << endl; // *TEST* code
    }
    // Methods
    void getResolution(int& xResolution,int& yResolution);
    void setPixel(int x,int y,int val);
    float getPixel(int x, int y);
    void writeFile(std::string filename);
}; // PGMImage class def

// ********************** ComplexNumber Class DECLARATION ******************
class ComplexNumber {
private:
    double real;
    double imag;

public:
    ComplexNumber() {
        real = 0;
        imag = 0;
    }
    ComplexNumber(double x, double y) {
        real = x;
        imag = y;
    }
    ComplexNumber(ComplexNumber const &c) {
        real = c.real;
        imag = c.imag;
    }
    ComplexNumber add(ComplexNumber c2); // outputs a sum, as a new complex number
    ComplexNumber squared(ComplexNumber c2); // outputs a squared value, as a new complex number
    double abs(ComplexNumber c2); // outputs the magnitude of the complex number: sqrt(real*real+imag*imag)
    void prt(ComplexNumber c2); // does cout in the form of 'real + imag j'
};


#endif //Q3_Q3_H
