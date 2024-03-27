#include<iostream>
using namespace std;

class Date
{
    private:
    int day;
    int month;
    int year;

    public:
    Date()
    {
        day=01;
        month=01;
        year=2000;    
    }

    void acceptDate()
    {
        cout<<"enter day"<<endl;
        cin>>day;
        cout<<"enter month"<<endl;
        cin>>month;
        cout<<"enter year"<<endl;
        cin>>year;
    }

    void displayDate()
    {
         cout<<endl<<day<<"/"<<month<<"/"<<year<<endl;
    }
};

class Person
{
    private:
    string name;
    string address;
    Date birthDate;

    public:

    Person()
    {
        name="";
        address="";
    }

    virtual void acceptData()
    {
        cout<<endl<<"enter person name "<<endl;
        cin>>name;
        cout<<"enter person address"<<endl;
        cin>>address;
        cout<<"enter person birthdate"<<endl;
        birthDate.acceptDate();
    }

    virtual void displayData()
    {
        cout<<endl<<"person name is "<<name<<endl<<"person address is "<<address<<endl;
        cout<<endl<<"person birthdate : "<<endl;
        birthDate.displayDate();
    }
};

class Employee:public Person
{
    private:
    int id;
    int sal;
    string dept;
    Date doj;

    public:

    Employee()
    {
        id=0;
        sal=1000;
        dept="";
    }

    void acceptData()
    {
        Person::acceptData();
        cout<<endl<<"enter employee id"<<endl;
        cin>>id;
        cout<<"enter employee sal"<<endl;
        cin>>sal;
        cout<<"enter department name"<<endl;
        cin>>dept;
        cout<<"date of joining"<<endl;
        doj.acceptDate();
        
    }

    void displayData()
    {
        cout<<"person details "<<endl;
        Person::displayData();
        cout<<endl<<"employee id is "<<id<<endl<<"employee sal is "<<sal<<endl<<"employee department is "<<dept<<endl;
        cout<<"date of joining is "<<endl;
        doj.displayDate();
        
    }

};

int main()
{
    Person*pptr=new Employee();
    pptr->acceptData();
    pptr->displayData();

    delete pptr;
    pptr=NULL;
}
