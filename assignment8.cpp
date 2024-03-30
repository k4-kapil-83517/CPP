#include<iostream>
using namespace std;

enum EAccountType{
SAVING = 1,
CURRENT,
DMAT
};

 class InSufficientFundsException{
    private:
        int accno ;
        double currentBalance;
        double withdrawAmount;
    public:
        InSufficientFundsException(){}

        InSufficientFundsException(int accno, double currentBalance, double withdrawAmount){  
            this->accno=accno;
            this->currentBalance= currentBalance;
            this->withdrawAmount=withdrawAmount;
           
        }

        void display(){

            cout<<"Insufficient Balance"<<endl;
            cout<<"Account Number-"<<accno<<endl;
            cout<<"Withdraw Attempt Amount- "<<withdrawAmount<<endl;
            cout<<"Available Balance- "<<currentBalance<<endl;
        }

};

class Account{
    private:
        const int accno;
        EAccountType accType;
        double balance;
        static int genAccNo;
        
    public:   
        Account():accno(++genAccNo)
        {}

        Account(double balance,EAccountType accType):accno(++genAccNo)
        {
            // this->accno = accno;
            this->balance = balance;
            this->accType = accType;
        }    
        void accept(){
            try{
            int choice;
            cout<<"Enter Account Type: "<<endl;
            cout<<"Press 1 to Create a SAVING Account"<<endl;
            cout<<"Press 2 to Create a CURRENT Account"<<endl;
            cout<<"Press 3 to Create a DEMAT Account"<<endl;
            cin>>choice;
            if(choice!=1 && choice!=2 && choice!=3)
                throw 1;
            else{    
            accType = (EAccountType)choice; 
            balance = 0;
            cout<<"The Acount has been created!!"<<endl;}
            }
            catch(int error){
                cout<<"Invalid Choice Entered!!"<<endl;
                cout<<"Transaction Failed!!"<<endl;

            }

            
        }


        void display(){

            cout<<"Account No: "<<accno<<endl;
            switch (accType)
            {
            case SAVING:  cout<<"Account Type: Saving"<<endl;
                break;

            case CURRENT:  cout<<"Account Type: CURRENT"<<endl;
                break;

            case DMAT:     cout<<"Account Type: DMAT"<<endl;
                break;        
            
            default:
                break;
            }
           
            
            cout<<"The Available  Balance is: "<<balance<<endl;
        }

        int getAccno(){
            return accno;
        }

        void setBalance(int balance){
            this->balance = balance;
        }

        double getBalance(){
            return balance;
        }

        double withdraw(int withdraw){
            
            if(withdraw>balance)
                
                throw InSufficientFundsException(accno, balance, withdraw);
            else
                this->balance= balance - withdraw;
                cout<<"The Amount has been withdrawn"<<endl;  
                
            return balance;
        }

        double deposite(int deposite){
            if(deposite<0)
                throw 1;
            else    
                this->balance= balance + deposite;
                cout<<"The Amount has been deposited"<<endl;  
            return balance;
        }


};

int Account::genAccNo = 0;

int main(){
    Account *arr[5];
    int index = 0;
    int choice; 

    do{
        cout<<"0. Exit"<<endl;
        cout<<"1. Create An Account"<<endl;
        cout<<"2. Withdraw Amount"<<endl;
        cout<<"3. Deposit Amount"<<endl;
        cout<<"4. Display Accounts"<<endl;
        cin>>choice;

        switch(choice){
            case 0:  cout<<"Thank you for using our App!"<<endl;
                break;

            case 1:     if(index<5){
                        arr[index] = new Account();
                        arr[index]->accept();
                        index++;
                        }
                        else 
                        {
                            cout << "Maximum account limit reached. Cannot create more accounts." << endl;
                        }

                        
                break;

            case 2: try{    
                            int accNo;
                            cout<<"Enter Accout No-";
                            cin>>accNo;    
                            for(int i = 0; i<index; i++)
                            {
                                if(accNo == arr[i]->getAccno())
                                {
                                    double withdraw;
                                    cout<<"Enter Amount to Withdraw:";
                                    cin>>withdraw;
                                    arr[i]->withdraw(withdraw);
                                }
                            }
                        }
                    catch(InSufficientFundsException e)
                    {    
                       cout<<"Transaction Failed!"<<endl;
                       e.display();
                    }
                break;

            case 3:     try{    int accNo;
                            cout<<"Enter Accout No-";
                            cin>>accNo;    
                            for(int i = 0; i<index; i++){
                                if(accNo == arr[i]->getAccno())
                                {
                                    double deposite;
                                    cout<<"Enter Amount to Deposite:";
                                    cin>>deposite;
                                    arr[i]->deposite(deposite);
                                }
                                }
                            }catch(int error){
                                cout<<"The Deposite Amount is Invalid"<<endl;
                                cout<<"Transaction Failed!!"<<endl;
                            }
                            
                break;

            case 4:         for(int i = 0; i< index; i++)
                                arr[i]->display();
                break;                

        }
        
    } while(choice!=0);

    for(int i=0; i<index; i++)
    {
        delete arr[i];
        arr[i] = NULL;
    }


    return 0;
}