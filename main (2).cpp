#include <iostream>
#include <cstring>
#include "libprod.h"
#include "libsklad.h"

using namespace std;


int main(){
    int opt;
    Warehouse WB = create_sklad();
    //Warehouse OZON = create_sklad();
    
    //warehouse WB
    do{
        WB.menu(opt);        

        switch(opt){
            case 1:
                WB.insert_product();
                break;
            case 2:
                WB.print_products();
                break;
            case 3:
                int pos;
                pos = WB.search_by_name();
                if(pos != -1){
                    WB.get_product(pos).print_all();
                }else{
                    cout<<"Client not found!"<<endl;
                }
                break;
            case 4:
                WB.delete_product();
                break;
            case 5:
                WB.distbn();
                break;
            case 6:
                cout<<"Exit from program!"<<endl;
                break;
            default:
                cout<<"Invalid option!"<<endl;
        }
    }while(opt!=6);


    //OZOn
    /*
    do{
        OZON.menu(opt);        

        switch(opt){
            case 1:
                OZON.insert_product();
                break;
            case 2:
                OZON.print_products();
                break;
            case 3:
                int pos;
                pos = OZON.search_by_name();
                if(pos != -1){
                    OZON.get_product(pos).print_all();
                }else{
                    cout<<"Client not found!"<<endl;
                }
                break;
            case 4:
                OZON.delete_product();
                break;
            case 5:
                WB.distbn();
                break;
            case 6:
                cout<<"Exit from program!"<<endl;
                break;
            default:
                cout<<"Invalid option!"<<endl;
        }
    }while(opt!=6);
    */
    return 0;
}
