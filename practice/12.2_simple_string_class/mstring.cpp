#include<iostream>
#include<cstring>
#include"mstring.h"

using std::cin;
using std::cout;

namespace MSTRING
{
    const int MAX_IN = 10;
    //initializing static number
    int Mstring::str_cnt = 0;

    //constructor methods
    Mstring::Mstring() {
        len = 0;
        str = new char[1];
        str = nullptr;
        str_cnt++;
    }
    Mstring::Mstring(const char * string) {
        len = std::strlen(string);
        str = new char[len + 1];
        std::strcpy(str, string);
        str_cnt++;
    }
    Mstring::Mstring(const Mstring & string) {
        this->len = string.len;
        str = new char[len + 1];
        std::strcpy(str, string.str);
        str_cnt++;
    }
    Mstring::~Mstring() { }
    //operator overloading methods
    Mstring & Mstring::operator=(const Mstring & string) {
        delete[]str;
        len = string.len;
        str = new char[len + 1];
        std::strcpy(str, string.str);
        return *this;
    }
    Mstring & Mstring::operator=(const char* string) {
        delete[]str;
        len = std::strlen(string);
        str = new char[len + 1];
        std::strcpy(str, string);
        return *this;
    }
    char & Mstring::operator[](int n) {
        return str[n];
    }
    const char & Mstring::operator[](int n) const {
        return str[n];
    }
    //friend methods
    std::ostream & operator<<(std::ostream & os, const Mstring & string) {
        os << string.str;
        return os;
    }
    std::istream & operator>>(std::istream & is, Mstring & string) {
        char str_in[MAX_IN];
        is.get(str_in, MAX_IN);
        if (is) {
            string = str_in;
        }
        while (is && is.get() != '\n') {
            continue;
        }
        return is;
    }
}