#include "vectorpolynom.h"
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size;
    cout << "������� ������ ������� ��������: ";
    cin >> size;

    VectPolynomial V1(size), V2(size);
    cout << "��������� ��� V1: ";
    V1.set_polynomials();
    cout << "��������� ��� V2: ";
    V2.set_polynomials();

    VectPolynomial Vout = VectPolynomial::sum(V1, V2);
    cout << "����� ���������: ";
    Vout.print_polynomials();

    return 0;
}

