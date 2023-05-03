//header for simple string class
#ifndef MSTRING_H_
#define MSTRING_H_

#include<iostream>

namespace MSTRING
{
    class Mstring
    {
    private:
        char * str;         //pointer for string
        int len;            //length of string
        static int str_cnt; //count of string, a static variable
    public:
        Mstring();
        Mstring(const char * string);
        Mstring(const Mstring & string);
        ~Mstring();
        int size() {return len;}
    //operator overloading
        Mstring & operator=(const Mstring & string);
        Mstring & operator=(const char * string);
        char & operator[](int n);
        const char & operator[](int n) const;
    //friend methods
        friend std::ostream & operator<<(std::ostream & os, const Mstring & string);
        friend std::istream & operator>>(std::istream & is, Mstring & string);

    };
}
#endif