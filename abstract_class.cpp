#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class Employee {
protected:
    int empID;
    string name;
    float baseSalary;
   
public:
    Employee() {
        empID = 0;
        name = "Unknown";
        baseSalary = 0;
    }

    Employee(int id, string n, float salary) {
        empID = id;
        name = n;
        baseSalary = salary;
    }
   
    // Pure Virtual function - making this an Abstract class 
    virtual float calculateSalary() const = 0;
    
    // Pure Virtual function for displaying info
    virtual void displayInfo() const = 0;
    
    // --- FIX: Added Getters for protected members ---
    int getEmpID() const { return empID; }
    string getName() const { return name; }
    float getBaseSalary() const { return baseSalary; }

    // Regular Member function (returns Employee& for method chaining)
    Employee& setBaseSalary(float salary) {
        this->baseSalary = salary;
        return *this;
    }
    
    // Demonstrating 'this' pointer for method chaining
    Employee& setEmpID(int id) {
        this->empID = id;
        return *this;
    }   
    
    virtual ~Employee() {}
};

// Derived Class - PermanentEmployee
class PermanentEmployee : public Employee {
private:
    float bonus;
    float allowance;
  
public:
    PermanentEmployee() : Employee() {
        bonus = 0;
        allowance = 0;
    }
   
    PermanentEmployee(int id, string n, float salary, float b, float a) : Employee(id, n, salary) {
        bonus = b;
        allowance = a;
    }

    // Implementation of pure virtual function
    float calculateSalary() const override {
        return baseSalary + bonus + allowance;
    }
    
    void displayInfo() const override {
        cout << "--- Permanent Employee ---" << endl;
        cout << "ID: " << empID << endl;
        cout << "Name: " << name << endl;
        cout << "Base Salary: " << baseSalary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Allowance: " << allowance << endl;
        cout << "Total Salary: " << calculateSalary() << endl;
    }
};

// Derived Class - ContractEmployee
class ContractEmployee : public Employee {
private:
    int contractDuration; // in months
    float hourlyRate;
    int hoursWorked;

public:
    ContractEmployee() : Employee() {
        contractDuration = 0;
        hourlyRate = 0;
        hoursWorked = 0;
    }

    ContractEmployee(int id, string n, float salary, int duration, float rate, int hours) : Employee(id, n, salary) {
        contractDuration = duration;
        hourlyRate = rate;
        hoursWorked = hours;
    }

    // Implementation of pure virtual function
    float calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
    
    void displayInfo() const override {
        cout << "--- Contract Employee ---" << endl;
        cout << "ID: " << empID << endl;
        cout << "Name: " << name << endl;
        cout << "Base salary (Monthly): " << baseSalary << endl;
        cout << "Contract Duration: " << contractDuration << " months" << endl;
        cout << "Hourly Rate: " << hourlyRate << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Total Salary: " << calculateSalary() << endl;
    }
};

// Demonstrating Pointers to objects and Polymorphism
void demonstratePointerOperations() {
    cout << "\n===== Pointers to Objects =====" << endl;

    // Creating Objects
    PermanentEmployee emp1(101, "John Doe", 50000, 10000, 5000);
    ContractEmployee emp2(102, "Jane Smith", 0, 6, 50.0, 120);
    
    // Base class pointers pointing to derived class objects (Runtime Polymorphism)
    Employee* ptr1 = &emp1;
    Employee* ptr2 = &emp2;
    
    cout << "\nUsing Base Class Pointer for Permanent Employee:" << endl;
    ptr1->displayInfo();
    
    cout << "\nUsing Base Class Pointer for Contract Employee:" << endl;
    ptr2->displayInfo();

    // Demonstrating 'this' pointer chaining
    cout << "\n===== Demonstrating 'this' Pointer Chaining =====" << endl;
    PermanentEmployee emp3;
    emp3.setEmpID(103).setBaseSalary(60000); // Chaining method calls returning *this
    
    // --- FIX: Using getters instead of direct access ---
    cout << "Emp3 ID: " << emp3.getEmpID() << ", Base Salary: " << emp3.getBaseSalary() << endl;
}

int main() {
    demonstratePointerOperations();
    return 0;
}
