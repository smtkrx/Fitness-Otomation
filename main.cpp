#include "Fitness.h"
#include <iostream>
using namespace std;

int main(){
    
    
    Fitness fit;
    while (1) { 
        int choice;
        fit.showInfos();
        
        for(int i = 1; i < 15; i++){
            cout<<"*";
        }
        
        cout<<"Please Enter Your Value = ";
        cin>>choice;
        
        switch (choice) {
            case 1:
                fit.product_record();
                break;
                
            case 2:
                fit.product_sell();
                break;
                
            case 3:
                fit.product_add();
                break;
                
            case 4:
                fit.product_search();
                break;
                
            case 5:
                fit.product_list();
                break;
                
            case 6:
                fit.product_unregister();
                break;
                
            case 7:
                fit.warehouse_count();
                break;
                
            case 8:
                fit.sporcu_kayit();
                break;
                
            case 9:
            	fit.Reset();
            	break;
            	
            case 10:
            	fit.Exit();
            	break;
                
            default:
                break;
        }
        
    }
}
