#include<iostream>
#include"mstring.h"
using MSTRING::Mstring;

int main() {
    Mstring s = "hello world";
    Mstring tmp = "\nnihao shijie";
    std::cout << s;
    s = tmp;
    std::cout << tmp;
    std::cin >> tmp;
    std::cout << tmp << tmp.size();
    return 0;
}