#include<iostream>
using namespace std;
class Date
{
    private:
    int day;
    int month;
    int year;

    public:
    Date():day(1),month(1),year(2024)
    {

    }
    void acceptDate()
    {
       // cout<<"Enter the date"<< endl;
       cout<<"Day-";
       cin>>day;
       cout<<"month";
       cin>>month;
       cout<<"year";
       cin>>year;
    }
    void displayDate()
    {
        cout<<day<<"/"<<month<<"/"<<year<<"/"<<endl;
    }
};
class Person
{
    private:
    string name;
    string address;
    Date birthdate;

    public:
    Person()
    {
        name=" ";
        address=" ";

    }
virtual void acceptData()
    {
       cout<<"name-";
       cin>>name;
       cout<<"address-";
       cin>>address;
       cout<<"birthdate-"<<endl;
       birthdate.acceptDate();
    }
    virtual void displayData()
    {   cout<<"name";
        cin>>name;
        cout<<"address";
        cin>>address;
        birthdate.displayDate();
    }   

};
class Employee: public Person
{
  private:
  int id;
  double salary;
  string deptname;
  Date doj;

  public:
  Employee()
  {
      id=0;
      salary=0.0;
      deptname="";
      

  }
  void acceptdata()
  { 
    Person::acceptData();
    cout<<"id";
    cin>>id;
    cout<<"salary";
    cin>>salary;
    cout<<"deptname";
    cin>>deptname;
    doj.acceptDate();
  }
  void displaydata()
  {
    Person::displayData();
    cout<<"id:"<<id<<"salary:"<<salary<<"dept:"<<deptname<<endl;
    doj.displayDate();

  }


};
int main()
{

    Person *ptr=new Employee();
    ptr->acceptData();
    ptr->displayData();

}