#include <functional>
#include <iostream>

template<typename T>
T use_f(T v, std::function<T(T)> f) {
    static int count = 0;
    count++;
    std::cout << "use_f count = " << count << ", &count = " << &count << std::endl;
    return f(v);
}

class Fp {
    double z_;
public:
    Fp(double z = 1.0) : z_(z) {}
    double operator() (double p) {return z_ * p;}
};

class Fq {
    double z_;
public:
    Fq(double z = 1.0) : z_(z) {}
    double operator() (double q) {return z_ + q;}
};