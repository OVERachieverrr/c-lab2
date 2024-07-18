#include<iostream>
using namespace std;

class Time
{
    int hr, min, sec;

    public:
    friend ostream &operator<<(ostream & , const Time&);
    friend istream &operator>>(istream & ,  Time&);
};
ostream &operator<<(ostream & output , const Time &T)
{
    output<<T.hr<<"hr "<<T.min<<"min "<<T.sec<<"sec"<<endl;
    return output;
}

istream &operator>>(istream & input, Time &T)
{
    input>>T.hr>>T.min>>T.sec;
    return input;
}
int main()
{
    Time t1;
    cout<<"enter the time in hr/min/sec"<<endl;
    cin>>t1;
    cout<<t1;
    return 0;
}
