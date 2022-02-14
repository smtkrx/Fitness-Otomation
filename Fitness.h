#ifndef Files_hpp
#define Files_hpp

#include <iostream>
using namespace std;

class Fitness{
private:
    string product_name;
    string product_type;
    string company;
    string soyisim;
    float serial_number;
    int piece;
    int expiration_date;
    int toz; 
    int mg; 
    int price;
    
public:
    
    //Setters
    void setProductName(string name){
        product_name = name;
    }
    
    void setProductType(string type){
        product_type = type;
    }
    
    void setCompany(string comp){
        company = comp;
    }
    void setSoyisim(string soyad){
        soyisim = soyad;
    }
    
    void setSerialNo(float serial){
        serial_number = serial;
    }
    
    void setPiece(int pie){
        piece = pie;
    }
    
    void setExpiration(int expiration){
        expiration_date = expiration;
    }
    
    void setToz(int to){
        toz = to;
    }
    
    void setPrice(int charge){
        price = charge;
    }
    
    //Getters
    string getProductName(){
        return product_name;
    }
    
    string getProdutcType(){
        return product_type;
    }
    
    string getCompany(){
        return company;
    }
    
    string getSoyisim(){
        return soyisim;
    }
    
    float getSerialNo(){
        return serial_number;
    }
    
    int getPiece(){
        return piece;
    }
    int getExpiration(){
        return expiration_date;
    }
    int getToz(){
        return toz;
    }
    
    int getPrice(){
        return price;
    }
    

/*public:
    char *product_name;
    char *product_type;
    char *company;
    float serial_number;
    int piece;
    int expiration_date;
    int toz;
    int mg;
    int price;*/
    
    void showInfos();
    
    void product_record();
    void product_sell();
    void product_add();
    void product_search();
    void product_list();
    void product_unregister();
    void warehouse_count();
    void sporcu_kayit();
    void Reset();
    void Exit();
     
    
};


#endif /* Files_hpp */
