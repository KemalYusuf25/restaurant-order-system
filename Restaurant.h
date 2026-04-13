#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Menu.h"
#include "OrderQueue.h"
#include "OrderStack.h"
#include <vector>

class Restaurant {
private:
    Menu menu;
    OrderQueue pendingOrders;   
    OrderStack cancelledOrders;
    vector<Order> completedOrders;
    int nextOrderId;
    double totalRevenue;
    
public:
    Restaurant() {
        nextOrderId = 1;
        totalRevenue = 0.0;
        initializeMenu();
    }
    
    void initializeMenu() {
        menu.addItem(MenuItem(1,"Pizza",350.0,"Main Course"));
        menu.addItem(MenuItem(2,"Burger",300.0,"Main Course"));
        menu.addItem(MenuItem(3,"Cola",80.0,"Beverage"));
        menu.addItem(MenuItem(4,"Cake",250.0,"Dessert"));
        menu.addItem(MenuItem(5,"Fries", 90.0,"Side"));
    }
       
    void displayMenu() {
        menu.displayAll();
    }


    void addMenuItem() {
        int id;
        string name,category;
        double price;
        cout<<"\n=== ADD MENU ITEM ==="<<endl;
        cout<<"ID: ";
        cin>>id;
        cin.ignore();
        cout<<"Name: ";
        getline(cin,name);
        cout<<"Price: "; 
        cin>>price;
        cin.ignore();
        cout<<"Category:b";
        getline(cin,category);
        
        menu.addItem(MenuItem(id,name,price,category));
        cout << "Item added successfully!"<<endl;
    }
    
    void removeMenuItem(){
        int id;
        cout<<"Enter item ID to remove:";
        cin>>id;
        menu.removeItem(id);
    }
    
    void createOrder(){
        Order newOrder(nextOrderId++);
        
        cout<<"\n=== CREATE NEW ORDER ==="<<endl;
        menu.displayAll();
        
        while(true){
            cout<<"\nEnter item ID (0 to finish): ";
            int itemId;
            cin >>itemId;
            
            if(itemId==0) break;
            
            MenuItem* item=menu.findItem(itemId);
            if(item==nullptr) {
                cout<<"Item not found!"<<endl;
                continue;
            }
            
            cout<<"Quantity: ";
            int quantity;
            cin >>quantity;
            
            newOrder.addItem(*item, quantity);
            cout <<"Added to order!"<<endl;
        }
        
        if(newOrder.items.size()>0){
            pendingOrders.enqueue(newOrder);
            cout<<"\nOrder created successfully!"<<endl;
            newOrder.display();
        } else{
            cout<< "Order cancelled - no items added."<< endl;
        }
    }
    
    void processNextOrder(){
        if(pendingOrders.isEmpty()){
            cout <<"No pending orders!" <<endl;
            return;
        }
        
        cout <<"\n=== PROCESSING NEXT ORDER ==="<<endl;
        Order order =pendingOrders.dequeue();
        order.status= "Completed";
        
        completedOrders.push_back(order);
        totalRevenue+=order.totalPrice;
        
        cout<<"Order completed!"<<endl;
        order.display();
    }
    
    void cancelLastOrder(){
        if(pendingOrders.isEmpty()){
            cout<< "No pending orders to cancel!" <<endl;
            return;
        }
        
        cout<<"\n=== CANCEL LAST ORDER ==="<<endl;
        
        vector<Order> temp;
        while(!pendingOrders.isEmpty()){
            temp.push_back(pendingOrders.dequeue());
        }
        
        if(temp.size() > 0){
            Order cancelled=temp.back();
            temp.pop_back();
            
           
            for(size_t i = 0; i < temp.size(); i++){
                pendingOrders.enqueue(temp[i]);
            }
        
            cancelledOrders.push(cancelled);
            cout <<"Order cancelled!" <<endl;
            cancelled.display();
        }
    }
    
    void showPendingOrders(){
        pendingOrders.displayAll();
    }
    
    void showCancelledOrders(){
        cancelledOrders.displayAll();
    }
    
    void showCompletedOrders(){
        if(completedOrders.empty()){
            cout << "No completed orders!"<< endl;
            return;
        }
        
        cout <<"\n=== COMPLETED ORDERS ===" << endl;
        for(size_t i = 0; i < completedOrders.size(); i++) {
            completedOrders[i].display();
            cout<< "---" <<endl;
        }
        cout <<"Total completed: " <<completedOrders.size() << endl;
    }
    
    void dailyReport() {
        cout <<"\n========== DAILY REPORT ==========" << endl;
        cout<< "Pending Orders: "<< pendingOrders.getSize()<< endl;
        cout<<"Completed Orders: "<< completedOrders.size()<< endl;
        cout<< "Cancelled Orders: "<< cancelledOrders.getSize()<< endl;
        cout<<"Total Revenue: " <<totalRevenue << " TL" << endl;
        cout<<"==================================\n" << endl;
    }
};

#endif