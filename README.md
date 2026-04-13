# Restaurant Order Management System

A command-line restaurant order management system built with C++ featuring custom implementations of fundamental data structures.

## 🎯 Features

- **Menu Management**: Add, remove, and display menu items using Linked List
- **Order Processing**: FIFO queue system for pending orders
- **Order Cancellation**: LIFO stack for cancelled orders
- **Order Tracking**: Track pending, completed, and cancelled orders
- **Daily Reports**: View statistics and total revenue

## 🛠️ Data Structures Used

- **Linked List**: Menu item storage
- **Queue (FIFO)**: Pending orders management
- **Stack (LIFO)**: Cancelled orders tracking
- **Vector**: Completed orders storage

## 🏗️ Project Structure
restaurant-order-system/
├── MenuItem.h          # Menu item class
├── Order.h             # Order class
├── Menu.h              # Menu management (Linked List)
├── OrderQueue.h        # Order queue (FIFO)
├── OrderStack.h        # Cancelled orders (LIFO)
├── Restaurant.h        # Main restaurant system
├── main.cpp            # User interface
└── README.md           # Project documentation
## 🚀 How to Run

### Prerequisites
- C++ compiler (g++ recommended)
- C++11 or later

### Compilation
```bash
g++ -std=c++11 main.cpp -o restaurant
```

### Execution
```bash
./restaurant          # Linux/Mac
.\restaurant.exe      # Windows
```

## 📖 Usage

1. **Display Menu** - View all available items
2. **Add Menu Item** - Add new items to menu
3. **Remove Menu Item** - Remove items from menu
4. **Create New Order** - Place a new order
5. **Process Next Order** - Complete the next pending order
6. **Cancel Last Order** - Cancel the most recent pending order
7. **Show Pending Orders** - View orders in queue
8. **Show Completed Orders** - View completed orders
9. **Show Cancelled Orders** - View cancelled orders
10. **Daily Report** - View statistics and revenue

## 💡 Learning Outcomes

- Implementation of Linked List, Queue, and Stack from scratch
- Object-Oriented Programming principles
- Dynamic memory management
- File I/O operations (planned)
- Command-line interface design

## 🔮 Future Enhancements

- [ ] File persistence (save/load data)
- [ ] Search functionality
- [ ] Order modification
- [ ] Customer management
- [ ] Multiple restaurant locations

## 👨‍💻 Author

Kemal Yusuf Atabey - Computer Engineering Student

## 📝 License

This project is open source and available for educational purposes.
