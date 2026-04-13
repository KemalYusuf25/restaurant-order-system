#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H

#include "Order.h"
using namespace std;

struct QNode {
    Order order;
    QNode* next;
};

class OrderQueue {
private:
    QNode* front;  
    QNode* rear;   
    int size;
    
public:
    OrderQueue() {
        front = rear = nullptr;
        size = 0;
    }
    
    ~OrderQueue() {
        QNode* p = front;
        while (front != nullptr) {
            front = front->next;
            delete p;
            p = front;
        }
        rear = nullptr;
    }
    
    void enqueue(Order order) {
        QNode* p = new QNode;
        p->order = order;
        p->next = nullptr;
        
        if (rear == nullptr) {
            front = rear = p;
        } else {
            rear->next = p;
            rear = p;
        }
        size++;
        cout << "Order #" << order.orderId << " added to queue!" << endl;
    }
    
    Order dequeue() {
        if (isEmpty()) {  
            cerr << "Queue is empty!" << endl;
            return Order(); 
        }
        
        QNode* p = front;
        Order item = front->order;
        front = front->next;
        
        if (front == nullptr) {
            rear = nullptr; 
        }
        
        delete p;
        size--;
        cout << "Order #" << item.orderId << " removed from queue!" << endl;
        return item; 
    }
    
    Order peek() {
        if (isEmpty()) { 
            cerr << "Queue is empty!" << endl;
            return Order(); 
        }
        return front->order;
    }
    
    bool isEmpty() {
        return front == nullptr;
    }
    
    int getSize() {
        return size;
    }
    
    void displayAll() {
        if (isEmpty()) {
            cout << "No pending orders!" << endl;
            return;
        }
        
        cout << "\n=== PENDING ORDERS ===" << endl;
        QNode* current = front;
        int position = 1;
        
        while (current != nullptr) {
            cout << "Position " << position << ":" << endl;
            current->order.display();
            cout << "---" << endl;
            current = current->next;
            position++;
        }
        cout << "Total in queue: " << size << endl;
    }
};  

#endif