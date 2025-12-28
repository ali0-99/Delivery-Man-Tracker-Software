#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
public:
    Person(string n, int i) {
        name = n;
        id = i;
    }
    virtual void showInfo() {
        cout << "Name: " << name << " | ID: " << id << endl;
    }
};

class DeliveryMan : public Person {
private:
    string vehicle;
    string location;
public:
    DeliveryMan(string n, int i, string v, string loc)
        : Person(n, i) {
        vehicle = v;
        location = loc;
    }

    void updateLocation(string newLoc) {
        location = newLoc;
    }

    void showInfo() override {
        cout << "DeliveryMan: " << name
            << " | Vehicle: " << vehicle
            << " | Location: " << location << endl;
    }
};


class Order {
private:
    int orderId;
    string customer;
    string address;
    DeliveryMan* deliveryMan;
public:
    Order(int oid, string c, string addr, DeliveryMan* dm)
        : orderId(oid), customer(c), address(addr), deliveryMan(dm) {
    }

    void showOrder() {
        cout << "Order ID: " << orderId
            << " | Customer: " << customer
            << " | Address: " << address << endl;
        cout << "Assigned -> ";
        deliveryMan->showInfo();
    }
};

int main() {
    
    DeliveryMan dm1("khan", 101, "Bike", "Nilore");
    DeliveryMan dm2("Sajid Khan", 102, "Car", "Ithehad Town");
    DeliveryMan dm3("Bilal Ahmed", 103, "Scooter", "Leathrar Road");
    DeliveryMan dm4("Usman Tariq", 104, "Van", "Thanda Pani");
    DeliveryMan dm5("Hamza Yousaf", 105, "Truck", "Bahria Town");

    Order o1(1, "Sajal Tariq", "Nilore", &dm1);
    Order o2(2, " Ali Raza ", "Leathrar Road", &dm2);
    Order o3(3, "Fatima Noor", "Thanda Pani", &dm3);
    Order o4(4, "Zain Malik", "Bahria Town", &dm4);
    Order o5(5, "Ayesha Khan", "I-8 Islamabad", &dm5);

    cout << "--- Delivery Orders ---\n";
    o1.showOrder();
    cout << "-----------------------\n";
    o2.showOrder();
    cout << "-----------------------\n";
    o3.showOrder();
    cout << "-----------------------\n";
    o4.showOrder();
    cout << "-----------------------\n";
    o5.showOrder();

    dm1.updateLocation("Abasyn University");
    cout << "\nAfter Location Update:\n";
    o1.showOrder();

    return 0;
}
