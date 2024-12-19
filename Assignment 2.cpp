// Question 1
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << (n*(n+1))/2;
    return 0;
}

// Question 2
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count=0;
    while(n!=0){
        n=n/10;
        count++;
    }
    cout<<count;
    return 0;
}

//Question 3
#include <iostream>
#include <cmath>
using namespace std;

double calculateArea(double radius) {
    return M_PI * radius * radius; 
}

double calculateArea(double length, double width) {
    return length * width;
}

double calculateArea(double base, double height, char triangle) {
    return 0.5 * base * height;
}

int main() {
    double radius;
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    cout << "Area of the circle: " << calculateArea(radius) << endl;

    double length, width;
    cout << "Enter the length and width of the rectangle: ";
    cin >> length >> width;
    cout << "Area of the rectangle: " << calculateArea(length, width) << endl;

    double base, height;
    cout << "Enter the base and height of the triangle: ";
    cin >> base >> height;
    cout << "Area of the triangle: " << calculateArea(base, height, 'T') << endl;

    return 0;
}

//Question 4
#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountHolder;
    double balance;

public:
    Account(const string& holder, double initialBalance)
        : accountHolder(holder), balance(initialBalance) {}

    virtual void calculateInterest() = 0;

    virtual void displayAccountDetails() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual ~Account() {} 
};
class SavingsAccount : public Account {
    double rate; 

public:
    SavingsAccount(const string& holder, double initialBalance, double rate, double time)
        : Account(holder, initialBalance), rate(rate), time(time) {}

    void calculateInterest() override {
        double interest = balance * rate * time;
        balance += interest;
        cout << "Interest added: " << interest << endl;
    }

    void displayAccountDetails() const override {
        cout << "--- Savings Account Details ---" << endl;
        Account::displayAccountDetails();
        cout << "Interest Rate: " << rate << endl;
        cout << "Time Period: " << time << " years" << endl;
    }
};

class CurrentAccount : public Account {
    double maintenanceFee; 

public:
    CurrentAccount(const string& holder, double initialBalance, double fee)
        : Account(holder, initialBalance), maintenanceFee(fee) {}

    void calculateInterest() override {
        balance -= maintenanceFee;
        cout << "Maintenance fee deducted: " << maintenanceFee << endl;
    }

    void displayAccountDetails() const override {
        cout << "--- Current Account Details ---" << endl;
        Account::displayAccountDetails();
        cout << "Monthly Maintenance Fee: " << maintenanceFee << endl;
    }
};

int main() {
    SavingsAccount savings("Abhay", 5000.0, 0.05, 1); 
    CurrentAccount current("Keshav", 3000.0, 50.0);      

    savings.displayAccountDetails();
    current.displayAccountDetails();

    cout << endl;

    cout << "Updating account details..." << endl;
    savings.calculateInterest();
    current.calculateInterest();

    cout << endl;

    savings.displayAccountDetails();
    current.displayAccountDetails();

    return 0;
}

// //Question 5
#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    double salary;

public:
    Employee(const string& empName, int empId, double empSalary)
        : name(empName), id(empId), salary(empSalary) {}

    virtual void calculateEarnings() = 0; 

    virtual void displayDetails() const {
        cout << "Employee ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Base Salary: " << salary << endl;
    }

    virtual ~Employee() {} 
};

class Manager : public Employee {
    double performanceRating;
    double bonus;

public:
    Manager(const string& empName, int empId, double empSalary, double rating)
        : Employee(empName, empId, empSalary), performanceRating(rating), bonus(0) {}

    void calculateEarnings() override {
        bonus = salary * (performanceRating / 10); 
        salary += bonus;
    }

    void displayDetails() const override {
        cout << "--- Manager Details ---" << endl;
        Employee::displayDetails();
        cout << "Performance Rating: " << performanceRating << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Earnings: " << salary << endl;
    }
};

class Developer : public Employee {
    double overtimeHours;
    double overtimeRate;
    double overtimeCompensation;

public:
    Developer(const string& empName, int empId, double empSalary, double hours, double rate)
        : Employee(empName, empId, empSalary), overtimeHours(hours), overtimeRate(rate), overtimeCompensation(0) {}

    void calculateEarnings() override {
        overtimeCompensation = overtimeHours * overtimeRate;
        salary += overtimeCompensation;
    }

    void displayDetails() const override {
        cout << "--- Developer Details ---" << endl;
        Employee::displayDetails();
        cout << "Overtime Hours: " << overtimeHours << endl;
        cout << "Overtime Rate: " << overtimeRate << endl;
        cout << "Overtime Compensation: " << overtimeCompensation << endl;
        cout << "Total Earnings: " << salary << endl;
    }
};

int main() {
    cout << "Enter details for Manager:" << endl;
    string managerName;
    int managerId;
    double managerSalary, performanceRating;
    cout << "Name: ";
    cin >> managerName;
    cout << "ID: ";
    cin >> managerId;
    cout << "Salary: ";
    cin >> managerSalary;
    cout << "Performance Rating (0-10): ";
    cin >> performanceRating;

    Manager manager(managerName, managerId, managerSalary, performanceRating);

    cout << "\nEnter details for Developer:" << endl;
    string developerName;
    int developerId;
    double developerSalary, overtimeHours, overtimeRate;
    cout << "Name: ";
    cin >> developerName;
    cout << "ID: ";
    cin >> developerId;
    cout << "Salary: ";
    cin >> developerSalary;
    cout << "Overtime Hours: ";
    cin >> overtimeHours;
    cout << "Overtime Rate: ";
    cin >> overtimeRate;

    Developer developer(developerName, developerId, developerSalary, overtimeHours, overtimeRate);

    cout << "\nCalculating earnings..." << endl;

    manager.calculateEarnings();
    developer.calculateEarnings();

    cout << "\nDisplaying details:" << endl;
    manager.displayDetails();
    cout << endl;
    developer.displayDetails();

    return 0;
}




