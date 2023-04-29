#include<bits/stdc++.h>
using namespace std;

double calculator(double, double, double (*fp)(double, double));
double f1(double, double);
double f2(double, double);
double f3(double, double);

int main() {
    double n1, n2;
    cin >> n1 >> n2;

    double (*f[3])(double, double) = { f1, f2, f3 };
    for (int i = 0; i < 3; i++) {
        cout << calculator(n1, n2, f[i]) << endl;
    }
    return 0;
}

double calculator(double num1, double num2, double (*fp)(double, double)) {
    return fp(num1, num2);
}

double f1(double n1, double n2) {
    return n1 + n2;
}

double f2(double n1, double n2) {
    return n1 * n2;
}

double f3(double n1, double n2) {
    return n1 / n2;
}