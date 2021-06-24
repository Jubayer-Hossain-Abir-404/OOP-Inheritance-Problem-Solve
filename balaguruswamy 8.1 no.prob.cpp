#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Account
{
protected:
    string customer_name;
    int account_number;
public:
    void store(string n,int a)
    {
        customer_name=n;
        account_number=a;
    }
    int type_of_account()
    {
        int number;
        cout<< "What type of account you wish to have in our bank:"<<endl;
        cout<< "Prees 1 if you want to open a saving's account/Press 2 if you want to open a current account:";
        cin>>number;
        switch(number)
        {
        case 1:
            cout<< "So "<<customer_name<< " wishes to have a saving's account in our bank"<<endl;
            break;
        case 2:
            cout<<"So "<<customer_name<< " wishes to have a current account in our bank"<<endl;
            break;
        default:
            break;
        }
        return number;
    }
    string get_name()
    {
        return customer_name;
    }
};
class cur_acct:public Account
{
protected:
    int minimum=1000,value,balance=0;
    string another_person;
public:
    void cheque_book_facility()
    {
        cout<< "Enter the name of the person who wants to take a cheque on the behalf of Mr."<<customer_name<< ":";
        cin.ignore();
        getline(cin,another_person);
        cout<< "Mr."<<another_person<< " how much money do you want to take:";
        cin>>value;
        if(value<minimum)
        {
            cout<< "You don't have the minimum amount of money in the bank.So you can't recieve any money and you have been imposed penalty of 2000 taka"<<endl;
        }
        else if(value>balance)
        {
            cout<< "You don't have enough amount of money to receive the amount you want"<<endl;
        }
        else if(value<=balance)
        {
            balance=balance-value;
        }

    }
    void I_want_take_money()
    {
        int val2;
        cout<< "How much money do you wish to take Mr."<<customer_name<< ":";
        cin>>val2;
        if(val2<minimum)
        {
            cout<< "You don't have the minimum amount of money in the bank.So you can't recieve any money and you have been imposed penalty of 2000 taka"<<endl;
        }
        else if(val2>balance)
        {
            cout<< "You don't have enough amount of money to receive the amount you want"<<endl;
        }
        else if(val2<=balance)
        {
            balance=balance-val2;
        }
    }
    void deposit(int b)
    {
        balance=balance+b;
    }
    void display()
    {
        int val1;
        if(balance<1000)
        {
            cout<< "Your current balance is "<<balance<< " which is less than the minimum amount"<<endl;
            cout<< "You have been imposed penalty of 2000 taka"<<endl;
            val1=2000-balance;
            cout<< "Your "<<balance<< " taka has been cut off already and still you have to give "<<val1<< " taka "<<endl;
            balance=0;
            cout<< "So your current balance is "<<balance<<endl;

        }
        else
        {
            cout<< "You current account balance is:"<<balance<<endl;
        }
    }
    void minimum_amount()
    {
        cout<< "The minimum balance should be "<<minimum<<endl;
    }
};
class sav_acct:public Account
{
protected:
    double interest;
    double month,balance;
public:
    void deposit_interest(double n)
    {
        interest=n;
    }
    void deposit_balance(int a)
    {
        balance=a;
    }
    void update_balance()
    {
        balance=balance+balance*interest;
    }
    void withdrawal()
    {
        cout<< "For how many month's you have been saving money:";
        cin>>month;
        balance=balance*month;
        cout<< "After withdrawing your money your current balance is :"<<fixed<<setprecision(2)<<balance;
    }
};
int main()
{
    cur_acct a1;
    sav_acct b1;
    string name;
    int code,ans,bg,paku,pg,dj,gel;
    cout<< "Enter the customer's name:";
    getline(cin,name);
    cout<< "Enter the code of the customer:";
    cin>>code;
    a1.store(name,code);
    ans=a1.type_of_account();
    if(ans==1)
    {
        cout<< "Deposit the amount of money:";
        cin>>bg;
        b1.deposit_balance(bg);
        b1.deposit_interest(0.4);
        b1.update_balance();
        cout<< "Do you wish to withdraw your money or not:"<<endl;
        cout<< "Press 1 if you want to withdraw otherwise press any number:";
        cin>>paku;
        if(paku==1)
        {
            cout<< "Yes, I want to withdraw all my money"<<endl;
            b1.withdrawal();
        }
        else
        {
            cout<< "No, I don't want to";
        }
    }
    else
    {
        cout<< "Input the amount of money you want to deposit:";
        cin>>bg;
        a1.deposit(bg);
        a1.display();
        a1.minimum_amount();
        cout<< "Do you wish to deposit any more money:"<<endl;
        cout<< "Press 1 if you want to deposit or otherwise press anything:";
        cin>>pg;
        if(pg==1)
        {
            cout<< "Please insert the amount:";
            cin>>dj;
            a1.deposit(dj);
        }
        a1.display();
        cout<< "Who want's to take the money of Mr. "<<a1.get_name()<<endl;
        cout<< "Is it Mr. "<<a1.get_name()<< " or someone else wants to take out the money:"<<endl;
        cout<< "Press 1 if its Mr."<<a1.get_name()<< " or any number for someone else:";
        cin>>gel;
        if(gel==1)
        {
            a1.I_want_take_money();
            a1.display();
        }
        else
        {
            a1.cheque_book_facility();
            a1.display();
        }
    }
    return 0;
}
