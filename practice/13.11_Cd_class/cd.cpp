#include"cd.h"
#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

Cd::Cd(char * s1, char * s2, int n, double x) 
:selections(n), playtime(x)
{
    performers = new char[std::strlen(s1) + 1];
    label = new char[std::strlen(s2) + 1];
    std::strcpy(performers, s1);
    std::strcpy(label, s2);
}

Cd::Cd(const Cd & d) {
    performers = new char[std::strlen(d.performers) + 1];
    label = new char[std::strlen(d.label) + 1];
    std::strcpy(performers, d.performers);
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd() {
    performers = nullptr;
    label = nullptr;
    selections = 0;
    playtime = 0;
}

Cd::~Cd() {
    delete[]performers;
    delete[]label;
};

void Cd::Report() const {
    cout << "performers: " << performers << endl;
    cout << "label: " << label << endl;
    cout << "selections: " << selections << endl;
    cout << "playtime: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d) {
    if (this == &d) {
        return * this;
    }
    delete[] performers;
    delete[]label;
    performers = new char[std::strlen(d.performers)];
    label = new char[std::strlen(d.label)];
    std::strcpy(performers, d.performers);
    std::strcpy(label, d.label);
    return *this;
}
