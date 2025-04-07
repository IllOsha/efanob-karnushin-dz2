#include "polynom.h"
#include <cmath>

Polynormal::Polynormal() {}

Polynormal::Polynormal(const vector<double>& coeffs, const vector<int>& exps)
    : coeficient(coeffs), exponenta(exps) {
}

Polynormal::Polynormal(const Polynormal& poly)
    : coeficient(poly.coeficient), exponenta(poly.exponenta) {
}

Polynormal::~Polynormal() {}

void Polynormal::print() const {
    for (size_t i = 0; i < coeficient.size(); i++) {
        cout << coeficient[i] << "x^" << exponenta[i] << " ";
    }
    cout << endl;
}

double Polynormal::evaluate(double x) const {
    double result = 0;
    for (size_t i = 0; i < coeficient.size(); i++) {
        result += coeficient[i] * pow(x, exponenta[i]);
    }
    return result;
}

int Polynormal::degree() const {
    return exponenta.empty() ? 0 : *max_element(exponenta.begin(), exponenta.end());
}

Polynormal Polynormal::operator+(const Polynormal& other) const {
    return Polynormal(coeficient, exponenta); 
}

Polynormal Polynormal::operator-(const Polynormal& other) const {
    return Polynormal(coeficient, exponenta); 
}
