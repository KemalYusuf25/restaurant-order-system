#include "Restaurant.h"
#include <iostream>
using namespace std;
void displayMainMenu(){
    cout<<"\n======================================"<<endl;
    cout<<"    RESTAURANT ORDER SYSTEM"<<endl;
    cout<<"======================================"<<endl;
    cout<<"1. Display Menu"<<endl;
    cout<<"2. Add Menu Item"<<endl;
    cout<<"3. Remove Menu Item"<<endl;
    cout<<"4. Create New Order"<<endl;
    cout<<"5. Process Next Order"<<endl;
    cout<<"6. Cancel Last Order"<<endl;
    cout<<"7. Show Pending Orders"<<endl;
    cout<<"8. Show Completed Orders"<<endl;
    cout<<"9. Show Cancelled Orders"<<endl;
    cout<<"10. Daily Report"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"======================================"<<endl;
    cout<<"Choose option: ";
}

int main(){
Restaurant restaurant;
int choice;
while (true)
{displayMainMenu();
cin>>choice;
switch (choice)
{
case 1:
    restaurant.displayMenu();
    break;
case 2:
    restaurant.addMenuItem();
    break;
case 3:
    restaurant.removeMenuItem();
    break;
case 4:
    restaurant.createOrder();
    break;
case 5:
     restaurant.processNextOrder();
    break;
case 6:
    restaurant.cancelLastOrder();
    break;
case 7:
     restaurant.showPendingOrders();
    break;
case 8:
     restaurant.showCompletedOrders();
    break;
case 9:
    restaurant.showCancelledOrders();
    break;
case 10:
     restaurant.dailyReport();
    break;
case 0:
cout<<"Goodbye!"<<endl;
    return 0;

default:
cout<<"Invalid choice!"<< endl;

    break;
}}

    return 0;
}