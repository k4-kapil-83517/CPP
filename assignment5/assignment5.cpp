#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int day, month, year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    friend ostream& operator<<(ostream& os, const Date& date) {
        os << date.day << "/" << date.month << "/" << date.year;
        return os;
    }
};

class Person {
private:
    string name, address;
    Date birthdate;

public:
    Person(string n, string addr, Date bdate) : name(n), address(addr), birthdate(bdate) {}

    friend ostream& operator<<(ostream& os, const Person& person) {
        os << "Name: " << person.name << ", Address: " << person.address << ", Birthdate: " << person.birthdate;
        return os;
    }
};

class Employee {
private:
    int id;
    double salary;
    string department;
    Date joining_date;

public:
    Employee(int emp_id, double sal, string dept, Date join_date) : id(emp_id), salary(sal), department(dept), joining_date(join_date) {}

    friend ostream& operator<<(ostream& os, const Employee& employee) {
        os << "Employee ID: " << employee.id << ", Salary: " << employee.salary << ", Department: " << employee.department << ", Joining Date: " << employee.joining_date;
        return os;
    }
};

int main() {
    
    Date birth_date(9, 9, 2002);
    Date joining_date(10, 8, 2024);

   
    Person person("kapil", "raver, jalgoan", birth_date);
    cout << "Person:" << endl;
    cout << person << endl;

  
    Employee employee(101, 100000, "IT", joining_date);
    cout << "\nEmployee:" << endl;
    cout << employee << endl;

    return 0;
}
