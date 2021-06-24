#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
using namespace std;
class person
{
protected:
    string name,name1;
    int code,code1;
    int c=0;
    void get_name_code()
    {
        cout<< "What is the name of the person:";
        getline(cin,name);
        cout<< "What is the code of Mr."<<name<< ":";
        cin>>code;
    }
    void put_name_code()
    {
        cout<< "The name of the person is:"<<name<<endl;;
        cout<< "The code of the "<<name<<" is:"<<code<<endl;
    }
};
class account:virtual public person
{
protected:
    int pay,pay1;
public:
    void get_pay()
    {
        cout<< "Plaese pay the amount:";
        cin>>pay;
    }
    void put_pay()
    {
        cout<<name<< " has paid "<<pay<< " doller to the master"<<endl;
    }
};
class admin:public virtual person
{
protected:
    int experience,experience1;
public:
    void get_experience()
    {
        cout<< "What has been your experience these past few days"<<endl;
        cout<< "Press 1 or any number:";
        cin>>experience;
    }
    void put_experience()
    {
        if(experience==1)
        {
            cout<<name<< " had a good experience these days"<<endl;
        }
        else
        {
            cout<<name<< " had a bad experience these days"<<endl;
        }
    }
};
class master:public account,public admin
{
protected:
    string paku;
    int ccpoka,pay_you_motherfucker,shit;
public:
    void create()
    {
        cout<< "Create all the information"<<endl;
        get_name_code();
        get_pay();
        get_experience();
    }
    void display()
    {
        put_name_code();
        put_pay();
        put_experience();
    }
};
int main()
{
    master m;
    m.create();
    m.display();
    return 0;
}
