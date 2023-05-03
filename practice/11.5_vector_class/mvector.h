// header for Mvector
#ifndef MVECTOR_H_
#define MVECTOR_H_

#include<iostream>

namespace MVECTOR
{
    class Mvector
    {
    public:
        //RECT for rectangular, POL for polar modes
        enum Mode { RECT, POL };
    private:
        double x;      //horizontal value
        double y;      //vertical value
        double mag;    //length of vector
        double ang;    //direction of vector
        Mode mode;  //RECT or POL
        //private methods for setting values
        void set_x();
        void set_y();
        void set_mag();
        void set_ang();
    public:
        Mvector();      //default constructor
        Mvector(double x, double y, Mode mode = RECT);
        ~Mvector();
        void reset(double a, double b, Mode mode = RECT);
        double xval() { return x; }
        double yval() { return y; }
        double magval() { return mag; }
        double angval() { return ang; }
        void polar_mode() { mode = POL; }
        void rect_mode() { mode = RECT; }
        //operator overloading
        Mvector operator+(const Mvector& t) const;
        Mvector operator-(const Mvector& t) const;
        Mvector operator-() const;
        Mvector operator*(const double t) const;
        //friends
        friend Mvector operator*(double n, const Mvector& v);
        friend std::ostream& operator<<(std::ostream& os, const Mvector& v);
    };
}

#endif