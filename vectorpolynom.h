#pragma once
#include <vector>
#include "polynom.h"
using namespace std;

class VectPolynomial {
private:
    vector<Polynormal> polynomials;

public:
    VectPolynomial(int size);
    void set_polynomials();
    void print_polynomials() const;
    static VectPolynomial sum(const VectPolynomial& v1, const VectPolynomial& v2);
    static VectPolynomial subtract(const VectPolynomial& v1, const VectPolynomial& v2);
};

