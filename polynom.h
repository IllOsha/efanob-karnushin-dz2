#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Polynormal {
private:
    vector<double> coeficient;
    vector<int> exponenta;

public:
    Polynormal();
    Polynormal(const vector<double>& coeffs, const vector<int>& exps);
    Polynormal(const Polynormal& poly);
    ~Polynormal();

    void print() const;
    double evaluate(double x) const;
    int degree() const;

    Polynormal operator+(const Polynormal& other) const;
    Polynormal operator-(const Polynormal& other) const;
};

