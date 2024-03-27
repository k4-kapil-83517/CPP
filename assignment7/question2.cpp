#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    double salary;

public:
    Employee()
    {
        cout << "Inside Employee()" << endl;
    }
    Employee(int id, double salary)
    {
        cout << "Inside Employee(int,double)" << endl;
    }
    void setId(int Id)
    {
        this ->id = Id;
    }
    int getId()
    {
            return id;
    }
    void setSalary(double Sal)
    {
        this ->salary = Sal;
    }
    double getSalary()
    {
        return salary;
    }
    virtual void accept()
    {
        cout << "Enter the empid - ";
        cin >> id;
        cout << "Enter the salary - ";
        cin >> salary;
    }
    virtual void display()
    {
        cout << "Id - " << id << endl;
        cout << "Salary - " << salary << endl;
    }
    virtual ~Employee()
    {
        cout << "~Employee()" << endl;
    }
};

class Manager : virtual public Employee
{
private:
    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter the bonus - ";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "Bonus - " << bonus << endl;
    }

public:
    Manager()
    {
        cout << "Inside Manager()" << endl;
    }
    Manager(int id, double salary, double bonus)
    {
        cout << "Inside Manager(int,double,double)" << endl;
    }
    void setBonus(double Bon)
    {
        this->bonus = Bon;
    }
    double getBonus()
    {
        return bonus;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        Employee::display();
        displayManager();
    }
    ~Manager()
    {
        cout << "~Manager()" << endl;
    }
};

class Salesman : virtual public Employee
{
private:
    double commission;

protected:
    void acceptSalesman()
    {
        cout << "Enter the Commission - ";
        cin >> commission;
    }
    void displaySalesman()
    {
        cout << "Commission - " << commission << endl;
    }

public:
    Salesman()
    {
        cout << "Inside Salesman()" << endl;
    }
    Salesman(int id, double salary, double commission)
    {
        cout << "Inside Salesman(int,double,double)" << endl;
    }
    void setCommission(double Comm)
    {
        this->commission = commission;
    }
    double getCommission()
    {
        return commission;
    }
    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displaySalesman();
    }
    ~Salesman()
    {
        cout << "~Salesman()" << endl;
    }
};
class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
        cout << "Inside Salesmanager()" << endl;
    }
    SalesManager(int id, double salary, double bonus, double commission)
    {
        cout << "Inside SalesManager(int,double,double,double)" << endl;
    }
    ~SalesManager()
    {
        cout << "~Salesmanager()" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
};


int main()
{
Employee *emp[5];
int i=0;
int choice;
int index=0;
int mgr=0;
int slmn=0;
int slmgr=0;

do
{

cout<<"0.Exit"<<endl;
cout<<"1. Accept Employee"<<endl;
cout<<"2. Display the count of all employees with respect to designation"<<endl;
cout<<"3. Display All Managers"<<endl;
cout<<"4. Display All Salesman"<<endl;
cout<<"5. Display All SalesManagers"<<endl;
cout<<"enter your choice";
cin>>choice;
    switch(choice)
    {
        case 0:
            cout<<"Thank you"<<endl;
        break;
      
      case 1:
            if(index<5)
                {
                    char c;
                    cout<<"Enter new choice"<<endl;
                    cout<<"a.Accept Manager   b.Accept Salesman   c.Accept Salesmanager"<<endl;
                    cin>>c;
                    switch(c)
                    {
                        case 'a':
                            {
                                emp[index] = new Manager();
                                emp[index] -> accept();
                                index++;
                            }
                        break;

                        case 'b':
                            { 
                                emp[index] = new Salesman();
                                emp[index] -> accept();   
                                index++;
                            }
                        break;

                        case 'c':
                            {
                                emp[index] = new SalesManager();
                                emp[index] -> accept();
                                index++;
                            } 
                        break;

                        default :
                            cout<<"Enter correct choice"<<endl;
                        break;            
                    }
                }else 
                {
                cout<<"No vacancy"<<endl;
                }
                
        break;
        
        case 2:
            {
                for(int i = 0; i = index;i++)
                {
                    if(typeid(*emp[i]).name() == typeid(Manager).name())
                    {mgr++;}
                    
                    if(typeid(*emp[i]).name() == typeid(Salesman).name())
                    {slmn++;}
                    
                    if(typeid(*emp[i]).name() == typeid(SalesManager).name())
                    {slmgr++;}
                }
                
                cout<<"Number of Manager :"<<mgr<<endl;
                cout<<"Number of Salesman :"<<slmn<<endl;
                cout<<"Number of Salesmanager :"<<slmgr<<endl;
                cout<<"Total number of employees :"<<mgr+slmn+slmgr<<endl;
            }
        break;
        case 3:
            {
                cout<<"Managers' Details :"<<endl;
                int count = 0;
                for(int i =0;i<index;i++)
                    {
                        if(typeid(*emp[i])==typeid(Manager))
                        {
                            emp[i] ->display();
                            count++;
                        }
                    }
                    if(count == 0)
                        {
                            cout<<"No Manager in the firm"<<endl;
                        }
            }
        break; 
        case 4:
            {
                cout<<"Salesman Details :"<<endl;
                int count = 0;
                for(int i =0;i<index;i++)
                    {
                        if(typeid(*emp[i])==typeid(Salesman))
                        {
                            emp[i] ->display();
                            count++;
                        }
                    }
                    if(count == 0)
                        {
                            cout<<"No Salesman in the firm"<<endl;
                        }
            }

        break;
        case 5:
            {
                 cout<<"Salesmanager Details :"<<endl;
                int count = 0;
                for(int i =0;i<index;i++)
                    {
                        if(typeid(*emp[i])==typeid(SalesManager))
                        {
                            emp[i] ->display();
                            count++;
                        }
                    }
                    if(count == 0)
                        {
                            cout<<"No Salesmanager in the firm"<<endl;
                        }
            }
        break;
        default:
                cout<<"invalid choice"<<endl;
        break;
    }
}while(choice !=0);

for(int i=0;i<index;i++)
{
delete emp[i];
}

    return 0;
}

/*int main1()
{
    // Employee *eptr = new Employee();
    // Employee *eptr = new Manager();
    // Employee *eptr = new Salesman();
    Employee *eptr = new SalesManager();
    eptr->accept(); // Late Binding
    eptr->display();

    delete eptr;
    eptr = NULL;
    return 0;
}

int main()
{
    // Employee obj;
    // Manager obj;
    // Salesman obj;
    SalesManager obj;
    obj.accept();
    
    
    obj.display();
    return 0;
}
*/