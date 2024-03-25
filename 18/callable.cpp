#include "somedefs.h"
#include <iostream>
double dub(double x) {return 2.0 * x;}
double square(double x) {return x * x;}

int main() {
    using std::cout;
    using std::endl;
    double y = 1.21;
    cout << "Function pointer dub: ";
    cout << use_f(y, dub) << endl; // указатель на функцию dub
    cout << "Function pointer square: ";
    cout << use_f(y, square) << endl; // указатель на функцию square
    cout << "Function object Fp: ";
    cout << use_f(y, Fp(5.0)) << endl; // функциональный объект Fp
    cout << "Function object Fp: ";
    cout << use_f(y, Fq(5.0)) << endl; // функциональный объект Fq
    cout << "Lambda expression 1: ";
    cout << use_f(y, [](double u){return u * u;}) << endl; // лямбда выражение 1
    cout << "Lambda expression 2: ";
    cout << use_f(y, [](double u){return u + u / 2.0;}) << endl; // лямбда выражение 2
    return 0; 
}