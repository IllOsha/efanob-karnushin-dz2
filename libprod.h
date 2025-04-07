#pragma once

class Product{
    public:
    double shtr;
        char name[50];
        double price;
        int kolvo;
        int shir;
        int dolg;

    public:
        Product();
        Product(double shtr, char name[50], double price, int kolvo, int shir, int dolg);
        Product(const Product &p);
        ~Product();
        void set_all(double shtr, char name[50], double price, int kolvo, int shir, int dolg);
        void get_all(double &shtr, char name[50], double &price, int &kolvo, int &shir, int &dolg);
        void print_all();
};
