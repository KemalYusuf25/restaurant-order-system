#ifndef MENUITEM_H
#define MENUITEM_H
#include <iostream>
#include <string> 
using namespace std;

class MenuItem
{ 
public:
int id;
string ItemName;
double price;
string category;
MenuItem(int i,string IN,double p,string c):id(i),ItemName(IN),price(p),category(c){}
MenuItem():id(0),price(0.0){}
void DisplayItem(){

    cout<<"["<<id<<"]"<<ItemName<<" - "<<price<<" TL"<<"("<<category<<")"<<endl;
}
};

#endif