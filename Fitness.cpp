//
//  Files.cpp
//  Project
//
//  Created by USER on 26.12.2019.
//

#include "Fitness.h"
#include<stdlib.h>
#include<string>
#include<iostream>
#include<fstream> 
using namespace std;
char *mystrcmp(const char *, const char *);

void Fitness::showInfos(){
    cout<<"\n* * * * * * MENU * * * * * *\n";
    cout<<endl;
    cout<<"1.  Product Registration" <<endl;
    cout<<"2.  Product Sales" <<endl;
    cout<<"3.  Product Adding" <<endl;
    cout<<"4.  Product Searching" <<endl;
    cout<<"5.  Product List" <<endl;
    cout<<"6.  Product Unregister" <<endl;
    cout<<"7.  Warehouse Count(Stock)" <<endl;
    cout<<"8.  Sportsmen Record" <<endl;
    cout<<"9.  Reset" <<endl;
    cout<<"10. Exit from Automation..." <<endl;
    
}
void compareOperation(string s1, string s2) 
{ 
    // returns a value < 0 (s1 is smaller then s2) 
    if((s1.compare(s2)) < 0) 
        cout << s1 << " is smaller than " << s2 << endl; 
  
    // returns 0(s1, is being comapared to itself) 
    if((s1.compare(s1)) == 0) 
        cout << s1 << " is equal to " << s1 << endl; 
    else
        cout << "Strings didn't match "; 
      
} 
void Fitness::product_record(){
    
    Fitness fit;
    
    
    char s1[300];
    string s2, s3;
    int a,b,c,d,e,f;
    
    fit.product_name = (char *)malloc(sizeof(char)*300);
    cout<<"Please enter a product name: ";
    cin>>s1;
    setProductName(s1);
    
    fit.company = (char *)malloc(sizeof(char)*300);
    cout<<"Please enter a company name: ";
    cin>>s2;
    setCompany(s2);
    
    fit.product_type = (char *)malloc(sizeof(char)*300);
    cout<< "Please enter a product type: ";
    cin>>s3;
    setProductType(s3);
    
    cout<<"Please enter a serial number: ";
    cin>>a;
    setSerialNo(a);
    
    cout<<"Please enter piece: ";
    cin>>b;
    setPiece(b);
    
    cout<<"Please enter a expiration date: ";
    cin>>c;
    setExpiration(c);
    
    cout<<"Please enter amount of powder: ";
    cin>>d;
    setToz(d);
    
    cout<<"Please enter mg: ";
    cin>>e;
    
    cout<<"Please enter price of product: ";
    cin>>f;
    setPrice(f);
    
    ofstream fp;
    
    fp.open("Olympia.txt",ios::app);
    
    fp <<"Product Name: "<<s1 << endl;
	fp <<"Company: "<<s2 << endl <<"Product Type: "<<s3 << endl;
	fp <<"Serial No: "<<a << endl;
	fp <<"Piece: "<<b << endl;
	fp <<"Expiration Date: "<<c << endl;
	fp <<"Amount of powder"<<d << endl;
	fp <<"Mg: "<<e << endl;
	fp <<"Price: "<<f <<endl<<endl<<endl;
    
    cout<<"----Registiration is successful !---";
    
    if(!fp){
        
        cerr << "File could not be opened" << endl;
        
        exit(1);
        
    }
    fp.close();
    
}

void Fitness::product_sell(){
    
    fstream fp;
    fp.open("Olympia.txt", ios::in);
    
    string sell_product;
    
    int asked;
    
    cout<<"Please enter a name: ";
    cin>>sell_product;
    
    cout<< "Asked: ";
    cin>> asked;
    
    int i =0;
    
    Fitness fit[300];
    
    while (!fp.eof()) {
        
        fit[i].product_name = (char *)malloc(sizeof(char)*300);
        fit[i].company = (char *)malloc(sizeof(char)*300);
        fit[i].product_type = (char *)malloc(sizeof(char)*300);
        
        fp>>fit[i].product_name >>fit[i].company >>fit[i].product_type >>fit[i].serial_number >>fit[i].piece >>fit[i].expiration_date >>fit[i].toz >>fit[i].mg >>fit[i].price;
        
        i++;
		       
}
    
for(int j = 0; j < i; j++){ 
    
	if((sell_product.compare(fit[j].product_name)) == 0){
        	
    
            
    	fit[j].piece -= asked; 
            
   	 	cout<<"Seals have been complated...";
            
    	cout<<"Total amount payable = " <<fit[j].price * asked; 
            
    	fp.open("Olympia.txt", ios::out); 
            
for(int j = 0; j <= i - 1; j++){
                
    fp<<fit[j].product_name <<fit[j].company <<fit[j].product_type <<fit[j].serial_number <<fit[j].piece <<fit[j].expiration_date <<fit[j].toz <<fit[j].mg <<fit[j].price; 
                
}
            
fp<<"\0";
            
fp.close();
       
}
		        
}
   
}
void Fitness::product_add(){
	Fitness fit[300];
    fstream dosya;
    dosya.open("Olympia.txt", ios::in);

    string gelUrun;
    int alim;
    
    cout << "Enter the name of ordered: ";
    cin >> gelUrun;
    cout << "Enter the number of orders";
    cin >> alim;
    int i=0;
    
while(!dosya.eof()){   
    fit[i].product_name=(char *)malloc(sizeof(char)*300);  
    fit[i].product_name=(char *)malloc(sizeof(char)*300);
    fit[i].product_name=(char *)malloc(sizeof(char)*300); 
    
dosya >> fit[i].product_name >> fit[i].company >> fit[i].product_type >> fit[i].serial_number >> fit[i].piece >> fit[i].expiration_date >> fit[i].toz >> fit[i].mg >> fit[i].price;
i++;

}

for(int j=0;j<i;j++){    
                          
if((gelUrun.compare(fit[j].product_name))==0){   
	
	fit[j].piece=fit[j].piece+alim;
    cout << "Purchase Order Completed .." << endl;
    cout << "Total Amount Payable :" << fit[j].price*alim;
}

}
dosya.close();

dosya.open("Olympia.txt",ios::out);

for(int j=0;j<=i-1;j++){
	dosya << fit[j].product_name << fit[j].company << fit[j].product_type<< fit[j].serial_number<< fit[j].piece<<fit[j].expiration_date<<fit[j].toz<<fit[j].mg<<fit[j].price; 
}
dosya.close();

}

void Fitness::product_search(){
    cout << "Enter the name of the product you are looking for: ";
    string searched;
    cin >> searched;
    int flag=0;
    
    fstream fileSearch;
	fileSearch.open("Olympia.txt",ios::in);
	
    Fitness fit; 
    fit.company=(char *)malloc(sizeof(char)*300);
    fit.product_name=(char *)malloc(sizeof(char)*300);
    fit.product_type=(char *)malloc(sizeof(char)*300);
    
while(!fileSearch.eof()){
	
	fileSearch >> fit.product_name >> fit.company >> fit.product_type >> fit.serial_number >> fit.piece >> fit.expiration_date >> fit.toz >> fit.mg >> fit.price;
        	
		if((fit.product_name.compare(searched))==0){ 
            flag=1;
			cout << "Company Name: " << fit.company <<endl;
			cout << "Product Name: " << fit.product_name <<endl;
			cout << "Product Type: " << fit.product_type<<endl;
			cout << "Serial Number: " << fit.serial_number<<endl;
			cout << "Expiration Date: " << fit.expiration_date<<endl;
			cout << "Piece: " << fit.piece << endl;
			cout << "Toz: " << fit.toz<<endl;	
			cout << "Mg miktari: "<< fit.mg<<endl;
			cout << "Price: " << fit.price<<endl;
			break;		                       
}
}	
if(flag==0){
    cout << "Searched that NOT FOUND..!";
}

fileSearch.close();
}

void Fitness::product_list(){
   	cout<<"PRODUCT STORE: "<<endl;
    ifstream read;
    read.open("Olympia.txt",ios::in);
    
if(read.is_open()){
	Fitness fit;
        fit.company=(char *)malloc(sizeof(char)*300);   
        fit.product_name=(char *)malloc(sizeof(char)*300);
        fit.product_type=(char *)malloc(sizeof(char)*300); 
        
while(!read.eof()){  

read >> fit.product_name;
read >> fit.company;
read >> fit.product_type;
read >> fit.serial_number;
read >> fit.piece;
read >> fit.expiration_date;
read >> fit.toz;
read >> fit.mg;
read >> fit.price;
cout <<"Product Name: "<<fit.product_name << endl<< "Product Type : " <<fit.product_type <<endl << "Company: " <<fit.company;
break;
}
read.close();

}
}

void Fitness::product_unregister(){
	Fitness fit[200]; 
    ifstream read("Olympia.txt",ios::in);
	ofstream write("Olympia.txt",ios::out | ios::app);
	string isim; 
	string line = "";
	int artis=0;
	
if(read.is_open()){

    cout<<"Name of the product you want to delete..?";                       
    cin>>isim;  
 
while(!read.eof()){                                                       
    fit[artis].product_name=(char *)malloc(sizeof(char)*300);  
    fit[artis].company=(char *)malloc(sizeof(char)*300);
    fit[artis].product_type=(char *)malloc(sizeof(char)*300);
	cin>> fit[artis].product_name, fit[artis].company, fit[artis].product_type, fit[artis].serial_number, fit[artis].piece, fit[artis].expiration_date , fit[artis].toz, fit[artis].mg, fit[artis].price;                                   
artis++;  
}
read.close();
write.close();
}
read.open("Olympia.txt",ios::out | ios::in | ios::app);
write.open("Olympia.txt",ios::out | ios::in | ios::app);
	        
if(read.is_open()){
for(int i=0;i<=artis-1;i++){
    if((isim.compare(fit[i].product_name))!=0)  
	cout<<fit[i].product_name, fit[i].company, fit[i].product_type, fit[i].serial_number, fit[i].piece, fit[i].expiration_date, fit[i].toz, fit[i].mg, fit[i].price;                                                                                                                    
}
cout<<"Record has been removed...";
cout<<'\0';                         
read.close();
write.close();  
}
}
void Fitness::warehouse_count(){
	Fitness fit;
	fstream file;
	file.open("Olympia.txt");
	string line = "";
	
if(file.is_open()){
	while(getline(file,line)){
		int i=0;
		fit.product_name=(char *)malloc(sizeof(char)*300);    
        fit.company=(char *)malloc(sizeof(char)*300);
        fit.product_type=(char *)malloc(sizeof(char)*300);
            
        file>>fit.product_name>>fit.company>>fit.product_type>>fit.serial_number>>fit.piece>>fit.expiration_date>>fit.toz>>fit.mg>>fit.price;
while(fit.product_name[i++]!='\0'){ 

if(fit.piece>=40){
			cout<<endl<<"Stock availability is enough"<<endl;
			break;
}
else if(fit.piece>=25){
            cout<<endl<<"Stock can be entered.."<<endl;
			break;
			}
else if(fit.piece>=15){
            cout<<endl<<"Track stock status..."<<endl;
			break;
			}
else if(fit.piece>=6){
            cout<<endl<<"Stock availability is critical..."<<endl;
			break;
			}
else if(fit.piece>=1){
            cout<<endl<<" Stock is running out...!!"<<endl;
			break;
			}
else if(fit.piece==0){
            cout<<endl<<"Out of Stock..."<<endl;
			break;
			}
file << fit.product_name << fit.piece;
}
}	
}
file.close();
}
void Fitness::sporcu_kayit(){
	string isim;          
    string soyisim;
    double kayitno;
    int ay;
    int yil;
    int gun;
    Fitness fit; 
    fit.soyisim=(char *)malloc(sizeof(char)*300);    
    
    cout<<"Sportsmen Record";
    cout<<"Sportsmen Name and Surname(enter a space between them): ";
    cin>>isim>>soyisim;
    cout<<"Please enter the date (day month year, enter a space between them ): ";
    cin>>gun>>ay>>yil;
 	int enFazla =1000;
  	int enAz=1;
    cout<<"Sportsmen registiration number:";
    cin >> kayitno;
    fstream write;
    write.open("Kayit.txt",ios::out | ios::app);
    write << "Name: "<< isim <<endl;
	write << "Surname: "<< soyisim <<endl;
	write << "Day: " <<gun<<endl;
	write << "Month: "<<ay<<endl;
	write <<"Year: "<<yil<<endl;
	write << "Registiration No: "<<kayitno<<endl;
	
	write <<endl<<endl;
    cout <<"Registiration is complate...";
    write.close();
}

void Fitness::Reset(){
	system("CLS"); 
}

void Fitness::Exit(){
	
    exit(0);   //The program exit...
}


