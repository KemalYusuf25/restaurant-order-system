#ifndef MENU_H
#define MENU_H

#include "MenuItem.h"

struct Node {
    MenuItem item;
    Node* next;
};

class Menu {
private:
    Node* head;
    int itemCount;
    
public:
    Menu() {
        head = nullptr;
        itemCount = 0;
    }
    
    ~Menu() {
        Node* p = head;
        while (head != nullptr) {
            head = head->next;
            delete p;
            p = head;
        }
    }
    
    void addItem(MenuItem item) {
        Node* p = new Node;
        p->item = item;
        p->next = nullptr;
        
        if (head == nullptr) {
            head = p;
        } else {
            Node* last = head;
            while (last->next != nullptr) {
                last = last->next;
            }
            last->next = p;  
        }
        itemCount++;
    }
    
    void removeItem(int id) {
        Node* current = head;
        Node* prev = nullptr;
        
        while (current != nullptr) {
            if (current->item.id == id) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                itemCount--;
                cout << "Item removed successfully!" << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Item not found!" << endl;
    }
    
    MenuItem* findItem(int id) {
        Node* p = head;
        
        while (p != nullptr) {
            if (p->item.id == id) { 
                return &(p->item);
            }
            p = p->next;
        }
        
        return nullptr;
    }
    
    void displayAll() {
        if (head == nullptr) {
            cout << "Menu is empty!" << endl;
            return;
        }
        
        cout << "\n=== MENU ===" << endl;
        Node* p = head;
        while (p != nullptr) {
            p->item.DisplayItem();
            p = p->next;
        }
        cout << "Total items: " << itemCount << endl;
    }
    
    void displayByCategory(string category) {
        cout << "\n=== " << category << " ===" << endl;
        Node* p = head;
        int count = 0;
        
        while (p != nullptr) {
            if (p->item.category == category) {
                p->item.DisplayItem();
                count++;
            }
            p = p->next;
        }
        
        if (count == 0) {
            cout << "No items in this category!" << endl;
        }
    }
    
    int getItemCount() {
        return itemCount;
    }
};

#endif