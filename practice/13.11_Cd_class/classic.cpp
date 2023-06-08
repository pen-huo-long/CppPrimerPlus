#include<iostream>
#include<cstring>
#include"classic.h"
using std::cout;
using std::endl;

Classic::Classic() 
:Cd()
{
    musicList = new char[1];
    musicList = nullptr;
}

Classic::Classic(char *s1, char * s2, char * s3, int n, double x)
:Cd(s2, s3, n, x)
{
    musicList = new char[std::strlen(s1) + 1];
    std::strcpy(musicList, s1);
}

Classic::Classic(const Classic & c)
: Cd(c)
{
    musicList = new char[std::strlen(c.musicList) + 1];
    std::strcpy(musicList, c.musicList);
}

Classic::~Classic() {
    delete[]musicList;
}

void Classic::Report() const {
    cout << "MusicList: " << musicList << endl;
    Cd::Report();
}

Classic &  Classic::operator=(const Classic & c) {
    if (this == &c) {
        return *this;
    }
    Cd::operator=(c);
    delete[] musicList;
    musicList = new char[std::strlen(c.musicList) + 1];
    std::strcpy(musicList, c.musicList);
}
