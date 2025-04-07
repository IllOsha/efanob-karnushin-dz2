#include "vectorpolynom.h"
#include <iostream>
#include <cmath>

VectPolynomial::VectPolynomial(int size) {
    polynomials.resize(static_cast<int>(size));
}

void VectPolynomial::set_polynomials() {
    for (auto& poly : polynomials) {
        int n;
        cout << "Enter number of terms: ";
        cin >> n;
        vector<double> coeffs(n);
        vector<int> exps(n);
        for (int i = 0; i < n; i++) {
            cout << "Coefficient: ";
            cin >> coeffs[i];
            cout << "Exponent: ";
            cin >> exps[i];
        }
        poly = Polynormal(coeffs, exps);
    }
}

void VectPolynomial::print_polynomials() const {
    for (const auto& poly : polynomials) {
        poly.print();
    }
}

VectPolynomial VectPolynomial::sum(const VectPolynomial& v1, const VectPolynomial& v2) {
    VectPolynomial result(static_cast<int>(v1.polynomials.size()));
    for (size_t i = 0; i < v1.polynomials.size(); i++) {
        result.polynomials[i] = v1.polynomials[i] + v2.polynomials[i];
    }
    return result;
}

VectPolynomial VectPolynomial::subtract(const VectPolynomial& v1, const VectPolynomial& v2) {
    VectPolynomial result(static_cast<int>(v1.polynomials.size()));
    for (size_t i = 0; i < v1.polynomials.size(); i++) {
        result.polynomials[i] = v1.polynomials[i] - v2.polynomials[i];
    }
    return result;
}
