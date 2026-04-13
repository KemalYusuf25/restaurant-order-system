#ifndef ORDER_H
#define ORDER_H
#include "MenuItem.h"
#include <vector>
#include <ctime>
using namespace std;

class Order {
public:
    int orderId;
    vector<MenuItem> items;       
    vector<int> quantities;      
    double totalPrice;
    string status;              
    time_t orderTime;            
    
    
    Order(int id):orderId(id),totalPrice(0.0),status("Pending"){
        orderTime = time(0); 
    }
    
    
    Order():orderId(0),totalPrice(0.0),status("Beklemede"){
        orderTime = time(0);
    }
    
    void addItem(MenuItem item, int quantity) {
        items.push_back(item);
        quantities.push_back(quantity);
        totalPrice+=item.price*quantity;}

    void display() {
        cout<<"Order #"<<orderId<<"["<<status<<"]"<<endl;
        for (int i = 0; i< items.size() ; i++)
        {
            cout << "- " << quantities[i] << "x " << items[i].ItemName
            << " (" << (items[i].price * quantities[i]) << " TL)" << endl;

        }
         cout << "Total: " << totalPrice << " TL" << endl;}
    
    double calculateTotal() {
       double total = 0.0;
    
        for (int i = 0; i < quantities.size(); i++)
            {total += items[i].price * quantities[i];}

    return total;}
};

#endif