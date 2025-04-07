#include "vectorpolynom.h"
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size;
    cout << "Введите размер вектора полинома: ";
    cin >> size;

    VectPolynomial V1(size), V2(size);
    cout << "Множество для V1: ";
    V1.set_polynomials();
    cout << "Множество для V2: ";
    V2.set_polynomials();

    VectPolynomial Vout = VectPolynomial::sum(V1, V2);
    cout << "Сумма полиномов: ";
    Vout.print_polynomials();

    return 0;
}

