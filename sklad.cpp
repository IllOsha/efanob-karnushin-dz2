#include <iostream>
#include <cstring>
#include "libsklad.h"
#include <iomanip>
#include <cmath>

using namespace std;

Warehouse::Warehouse(){
    this -> dolgt = 0;
    this -> shirt = 0;
    this -> size = 0;
    this -> sizenw = 0;
    this -> list = nullptr;
    strcpy(this->ident, "");
    this -> whr = centr;
}

Warehouse::Warehouse(char ident[4], Sklad whr, int dolgt, int shirt, int size){
    this -> dolgt = dolgt;
    this -> shirt = shirt;
    this -> size = size;
    this -> sizenw = 0;
    strcpy(this->ident, ident);
    this -> whr = whr;
    this -> list = new Product[size];
}


Warehouse::Warehouse(const Warehouse &v){
    this -> dolgt = v.dolgt;
    this -> shirt = v.shirt;
    this -> size = v.size;
    this -> sizenw = v.sizenw;
    strcpy(this->ident, v.ident);
    this -> whr = v.whr;
    this -> list = new Product[v.size];

    for(int i=0; i<v.sizenw; i++){
        this->list[i] = v.list[i];
    }
}


Warehouse::~Warehouse(){
    delete[] this->list;
}


int Warehouse::distance(const Product &p){
    return abs(this->shirt - p.shir) + abs(this->dolgt - p.dolg);
}


void Warehouse::menu(int &opc){
    cout<<left;
    cout<<"--------------------"<<endl;
    cout<<"MENU OF CLIENTS"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"[1]. Insert product"<<endl;
    cout<<"[2]. Print list of products at Warehouse"<<endl;
    cout<<"[3]. Search client by name"<<endl;
    cout<<"[4]. Delete client"<<endl;
    cout<<"[5]. Distance warehouse - product"<<endl;
    cout<<"[6]. Exit"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Enter option: "; cin>>opc;
}


Product Warehouse::get_product(int pos){
    return this->list[pos];
}



void Warehouse::insert_product(){
    cout<<"Insert new product..."<<endl;
    
    cout<<"barcode:"; cin>> this ->list[this->sizenw].shtr;
    cout<<"Name: "; cin>> this->list[this->sizenw].name;
    cout<<"PRice: "; cin>> this->list[this->sizenw].price;
    cout<<"count: "; cin>> this->list[this->sizenw].kolvo;
    
    do{
        cout<<"latitude: "; cin>> this->list[this->sizenw].shir;
    }while(this->list[this->sizenw].shir<41 || this->list[this->sizenw].shir>82);
    
    do{
        cout<<"longitude: "; cin>> this->list[this->sizenw].dolg;
    }while(this->list[this->sizenw].dolg<19 || this->list[this->sizenw].dolg>169);
    
    this->sizenw++;
}


void Warehouse::print_products(){
    cout<<left;
    cout<<setw(20)<<"barecode"<<
            setw(10)<<"name"<<
            setw(10)<<"price"<<
            setw(10)<<"count"<<
            setw(10)<<"latitude"<<
            setw(10)<<"longitude"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;

    for(int i=0; i<this->sizenw; i++){
        this->list[i].print_all();
    }
}


int Warehouse::get_size(){
    return this->sizenw;
}


void Warehouse::set_size(int n){
    this->sizenw = n;
}


int Warehouse::search_by_name(){
    int pos;
    char name[50];
    cout<<"Search Name: "; cin>>name;

    for(int i=0; i<this->get_size(); i++){
        if(strcmp(this->list[i].name, name) == 0){
            pos = i;
            return pos;
        }
    }
    
    return -1;
}


void Warehouse::delete_product(){
    int pos;
    pos = this->search_by_name();

    if(pos!= -1){
        for(int i=pos; i<this->get_size()-1; i++)
            this->list[i] = this->list[i+1];        
        this->sizenw--;
        this->set_size(this->sizenw);
        cout<<"Client deleted!"<<endl;
    }else{
        cout<<"Client not found!"<<endl;
    }
}

void Warehouse::distbn(){
    int pos;
    pos = this->search_by_name();
    if(pos!= -1){
        cout << "distance: " << this->distance(list[pos]) << endl;
    }else{
        cout<<"not found!"<<endl;
    }
}

Warehouse create_sklad(){
    cout<<"create new warehouse..."<<endl;
    char ident1[4];
    Sklad whr1;
    int qqqqqqqq;
    int dolgt1;
    int shirt1;
    int size1;


    cout<<"identifikator:"; cin>> ident1;
    cout<<"POsition (centr - 1/zapad - 2/vostok - 3): "; cin >> qqqqqqqq;
    switch(qqqqqqqq){
        case 1:
            whr1 = centr;
            break;
        case 2:
            whr1 = zapad;
            break;
        case 3:
            whr1 = vostok;
            break;
        default:
            cout<<"Invalid position!"<<endl;
    }
    cout<<"size of warehouse "; cin>> size1;
    
    do{
        cout<<"latitude: "; cin>> shirt1;
    }while(shirt1<41 || shirt1>82);
    
    do{
        cout<<"longitude: "; cin>> dolgt1;
    }while(dolgt1<19 || dolgt1>169);
    return Warehouse(ident1, whr1, dolgt1, shirt1, size1);
}
