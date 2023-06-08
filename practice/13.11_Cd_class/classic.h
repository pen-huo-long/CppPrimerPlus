#ifndef CLASSIC_H_
#define CLASSIC_H_

#include"cd.h"

class Classic: public Cd
{
private:
    char * musicList;
public:
    Classic();
    Classic(char *s1, char *s2, char *s3, int n, double x);
    Classic(const Classic & c);
    virtual ~Classic();
    virtual void Report() const;
    Classic & operator=(const Classic & c);
};

#endif