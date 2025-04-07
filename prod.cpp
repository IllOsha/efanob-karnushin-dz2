#include <iostream>
#include "libprod.h"
#include <cstring>
#include <iomanip>
using namespace std;

Product::Product(){
    this->shtr = -1;
    strcpy(this->name, "");
    this->price = 0.0;
    this->kolvo = 0;
    this->shir = 0;
    this->dolg = 0;
}


Product::Product(double shtr, char name[50], double price, int kolvo, int shir, int dolg){
    this->shtr = shtr;
    strcpy(this->name, name);
    this->price = price;
    this->kolvo = kolvo;
    this->shir = shir;
    this->dolg = dolg;
}


Product::Product(const Product &p){
    this->shtr = p.shtr;
    strcpy(this->name, p.name);
    this->price = p.price;
    this->kolvo = p.kolvo;
    this->shir = p.shir;
    this->dolg = p.dolg;
}


Product::~Product(){}


void Product::set_all(double shtr, char name[50], double price, int kolvo, int shir, int dolg){
    this->shtr = shtr;
    strcpy(this->name, name);
    this->price = price;
    this->kolvo = kolvo;
    this->shir = shir;
    this->dolg = dolg;
}


void Product::get_all(double &shtr, char name[50], double &price, int &kolvo, int &shir, int &dolg){
    shtr = this->shtr;
    strcpy(name, this->name);
    price =this->price;
    kolvo = this->kolvo;
    shir = this->shir;
    dolg = this->dolg;
}


void Product::print_all(){
    cout<<setw(20)<<this->shtr<<
            setw(10)<<this->name<<
            setw(10)<<this->price<<
            setw(10)<<this->kolvo<<
            setw(10)<<this->shir<<
            setw(10)<<this->dolg<<endl;
}


