#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;
class staff
{
protected:
    int code;
    string name,name1,val1;
public:
    void teacher_put_codename()
    {
        cout<< "Enter the name:";
        getline(cin,name);
        cout<< "Enter the code:";
        cin>>code;
        cin.ignore();
    }
    void typist_put_codename()
    {
        cout<< "Enter the name:";
        getline(cin,name1);
        cout<< "Enter the code:";
        cin>>code;
        cin.ignore();
    }
    void grade_officer()
    {
        int gfe;
        cout<< "Enter the name of the officer:";
        getline(cin,val1);
        cout<<val1 <<"'s code number is:";
        cin>>gfe;
    }

    string give_name_teacher()
    {
        return name;
    }
    string give_name_typist()
    {
        return name1;
    }
    int give_code()
    {
        return code;
    }
    string give_name_officer()
    {
        return val1;
    }
};
class education
{
protected:
    string higest_qualification_education;
    int highest_professional;
public:
    string return_education()
    {
        cin.ignore();
        getline(cin,higest_qualification_education);
        return higest_qualification_education;
    }
    int return_qualification()
    {
        cin>>highest_professional;
        return highest_professional;
    }
    string return_education1()
    {
        cin.ignore();
        getline(cin,higest_qualification_education);
        return higest_qualification_education;
    }
    int return_qualification1()
    {
        cin>>highest_professional;
        return highest_professional;
    }
};
class teacher:public staff,public education
{
protected:
    string subject,publication,ans;
    int ans1;
public:
    void give_subject_name()
    {
        cout<< "Enter the name of the subject teacher is teaching:";
        getline(cin,subject);
        cout<< "Enter the name of the book's publication:";
        getline(cin,publication);
    }
    string get_subject()
    {
        return subject;
    }
    string get_publication()
    {
        return publication;
    }
    void quality()
    {
        cout<< "What is the educational qualification of Mr."<<give_name_teacher() <<":";
        ans=return_education();

    }
    void check_quality()
    {
        int c=0,d=0,e=0;
        string bbc="B.c.s. Cadre";
        int p=ans.length();
        int g=bbc.length();
        if(p>g)
        {
            cout<<give_name_teacher()<< " is perfect for his post"<<endl;
            d++;
        }
        else
        {
            for(int i=0; i<ans.length(); i++)
            {
                if(ans.at(i)==bbc.at(i))
                {
                    c++;
                }
            }
            e++;
        }
        if(c==p)
        {
            cout<<give_name_teacher()<< " neeeds to be promoted"<<endl;
        }
        if(d==0&&e==0)
        {
            cout<<give_name_teacher()<< " is perfect for his post"<<endl;
        }
    }
    void qualification()
    {
        cout<< "What is the highest professional qualification of Mr."<<give_name_teacher()<< ":";
        ans1=return_qualification();
    }
    void check_qualification()
    {
        int g=6;
        if(ans1<6)
        {
            cout<<give_name_teacher()<< " needs "<<6-ans1<< " years of more experience and training"<<endl;
        }
        else
        {
            cout<<give_name_teacher()<< " is perfectly trained and does not require any training if he doesn't want"<<endl;
        }
    }

};

class officer:public staff,public education
{
protected:
    string val1,val2,ans;
    int gfe,ans1;
public:

    void quality1()
    {
        cout<< "What is the educational qualification of Mr."<<give_name_officer()<< ":";
        ans=return_education1();

    }
    void check_quality1()
    {
        int c=0,d=0,e=0;
        string bbc="B.c.s. Cadre";
        int p=ans.length();
        int g=bbc.length();
        if(p>g)
        {
            cout<<give_name_officer()<< " is perfect for his post"<<endl;
            d++;
        }
        else
        {
            for(int i=0; i<ans.length(); i++)
            {
                if(ans.at(i)==bbc.at(i))
                {
                    c++;
                }
            }
            e++;
        }
        if(c==p)
        {
            cout<<give_name_officer()<< " neeeds to be promoted"<<endl;
        }
        if(d==0&&e==0)
        {
            cout<<give_name_officer()<< " is perfect for his post"<<endl;
        }
    }
    void qualification1()
    {
        cout<< "What is the highest professional qualification of Mr."<<give_name_officer()<< ":";
        ans1=return_qualification();
    }
    void check_qualification1()
    {
        int g=6;
        if(ans1<6)
        {
            cout<<give_name_officer()<< " needs "<<6-ans1<< " years of more experience and training"<<endl;
        }
        else
        {
            cout<<give_name_officer()<< " is perfectly trained and does not require any training if he doesn't want"<<endl;
        }
    }

};
class typist:public staff
{
protected:
    int time,page;
public:
    int get_time()
    {
        cout<< "Enter the amount of time "<<give_name_typist()<< " takes to finish one page:";
        cin>>time;
        return time;
    }
};
class regular:public typist
{
protected:
    int salary;
public:
    void just_salary()
    {
        cout<< "Enter the salary of a regular typist:";
        cin>>salary;
    }
    int get_regular_salary()
    {
        return salary;
    }
};
class casual:public typist
{
protected:
    int days,salary1=50,salary2;
public:
    void show()
    {
        cout<< "How many days:";
        cin>>days;
        salary2=days*salary1;
    }
    int get_casual_salary()
    {
        return salary2;
    }
};
int main()
{
    teacher t;
    typist t1;
    officer ob;
    regular r;
    casual c;
    int choose;
    cout<< "Enter the teacher's name and code"<<endl;
    t.teacher_put_codename();
    t.give_subject_name();
    cout<< "Enter the typist's name and code"<<endl;
    t1.typist_put_codename();
    ob.grade_officer();
    t.quality();
    t.qualification();
    t.check_quality();
    t.check_qualification();
    ob.quality1();
    ob.qualification1();
    ob.check_quality1();
    ob.check_qualification1();
    cout<<t.give_name_teacher()<< " is a teacher and his code is "<<t.give_code()<<endl;
    cout<<t.give_name_teacher()<< " is a teacher of "<<t.get_subject()<< " and teaches from this "<<t.get_publication()<< "'s book "<<endl;
    cout<<t1.give_name_typist()<< " is a typist and his code is "<<t1.give_code()<<endl;
    cout<<t1.give_name_typist()<< " takes "<<t1.get_time()<< " minutes to finish 1 page typing"<<endl;
    cout<< "Just choose what kind pf typist is "<<t1.give_name_typist()<<endl;
    cout<< "Press 1 if "<<t1.give_name_typist()<< " is a regular typist or else type anything:";
    cin>>choose;
    if(choose==1)
    {
        r.just_salary();
        cout<<t1.give_name_typist()<< " 's salary is:"<<r.get_regular_salary()<<endl;
    }
    else
    {
        c.show();
        cout<<t1.give_name_typist()<< " 's salary is:"<<c.get_casual_salary()<<endl;
    }
    return 0;
}

