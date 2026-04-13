
#ifndef ORDERSTACK_H
#define ORDERSTACK_H

#include "Order.h"
using namespace std;

struct SNode{
    Order order;
    SNode* next;
};

class OrderStack{
private:
    SNode* top;
    int size;
public:
    OrderStack() {
        top=nullptr;
        size=0;
    }
    
    ~OrderStack(){
       SNode *current=top;
       while (current!=nullptr)
       {
        top=top->next;
        delete current;
        current=top;
       }
       size=0;
       
    }
    
    void push(Order order){
        SNode *p=new SNode;
        p->order=order;
        p->next=top;
        top=p;
        size++;
        cout << "Order #" << order.orderId << " pushed to stack!" << endl;
    }
    Order pop(){
        if (isEmpty())
        {
           cerr << "Stack is empty!" << endl;
            return Order();
        }
        SNode *p=top;
        Order item;
        item=top->order;
        top=top->next;
        delete p;
        size--;
        cout << "Order #" << item.orderId << " popped from stack!" << endl;
        return item;
    }
    Order peek(){
        if (isEmpty())
        {
           cerr << "Stack is empty!" << endl;
            return Order();
        }
        else
        return top->order;
    }
    bool isEmpty(){
        return top == nullptr;
    }
    int getSize(){
        return size;
    }
    void displayAll(){
        if (isEmpty()) {
            cout << "No cancelled orders!" << endl;
            return;
        }
        cout << "\n=== CANCELLED ORDERS (Stack) ===" << endl;
        SNode *p=top;
        while (p!=nullptr)
        {
            p->order.display();
            cout << "---" << endl;
            p=p->next;
        }
        cout << "Total cancelled: " << size << endl;
    }
};

#endif
