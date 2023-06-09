#ifndef CD_H
#define CD_H

//represents a CD disk
class Cd
{
private:
    char * performers;
    char * label;
    int selections;     //number of selections
    double playtime;    //playing time in minutes
public:
    Cd(char * s1, char * s2, int  n, double x);
    Cd(const Cd & d);
    Cd();
    virtual ~Cd();
    virtual void Report() const;    // reports all CD data
    Cd & operator=(const Cd & d);
};
#endif