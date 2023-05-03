#include<iostream>
#include"mvector.h"
#include<cmath>

namespace MVECTOR
{
    //set value of pi
    const double PI = M_PI;
    //private methods
    void Mvector::set_x() {
        x = std::sin(ang) * mag;
    }
    void Mvector::set_y() {
        y = std::cos(ang) * mag;
    }
    void Mvector::set_mag() {
        mag = std::sqrt(x*x + y*y);
    }
    void Mvector::set_ang() {
        if (x == 0 && y == 0) {
            ang = 0;
        }
        else {
            ang = std::atan2(y, x);
        }
    }

    //public methods
    Mvector::Mvector() {
        x = y = mag = ang = 0;
        mode = RECT;
    }
    Mvector::Mvector(double a, double b, Mode form) {
        mode = form;
        if (mode == RECT) {
            x = a, y = b;
            set_mag();
            set_ang();
        }
        else if (mode == POL) {
            mag = a, ang = 180 / PI * b;
            set_x();
            set_y();
        }
    }
    Mvector::~Mvector() {}
    void Mvector::reset(double a, double b, Mode form) {
        mode = form;
        if (mode == RECT) {
            x = a, y = b;
            set_mag();
            set_ang();
        }
        else if (mode == POL) {
            mag = a, ang = 180 / PI * b;
            set_x();
            set_y();
        }
    }
    //operator overloading methods
    Mvector Mvector::operator+(const Mvector & v) const {
        return Mvector(x + v.x, y + v.y);
    }
    Mvector Mvector::operator-(const Mvector & v) const {
        return Mvector(x - v.x, y - v.y);
    }
    Mvector Mvector::operator-() const {
        return Mvector(-x, -y);
    }
    Mvector Mvector::operator*(const double t) const {
        return Mvector(t * x, t * y);
    }

    //friends methods
    Mvector operator*(double n, const Mvector & v) {
        return v * n;
    }
    std::ostream & operator<<(std::ostream & os, const Mvector & v) {
        os << "(" << v.x << "," << v.y << ") or " << "(" << v.mag << "," << v.ang*180/PI << ")\n";
        return os;
    }
}