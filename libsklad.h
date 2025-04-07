#pragma once
#include "libprod.h"
enum Sklad {centr, zapad, vostok};

class Warehouse{
    public:
        char ident[4];
        Sklad whr;
        int dolgt;
        int shirt;
        int size;
        int sizenw;
        Product *list;        

    public:
        Warehouse();
        Warehouse(char ident[4], Sklad whr, int dolgt, int shirt, int size);
        Warehouse(const Warehouse &v);
        ~Warehouse();
        int distance(const Product &p);
        void menu(int &opc);
        void set_size(int n);
        int get_size();
        void insert_product();        
        void print_products();
        int search_by_name();
        void delete_product();
        Product get_product(int pos);
        void distbn();
};

Warehouse create_sklad();