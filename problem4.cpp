#include<iostream>
using namespace std;
class TIME
{
private:
int hours, minutes , seconds;
public:

 TIME (int hr=0 ,int min=0, int sec=0):hours(hr),minutes(min),seconds(sec){}

 TIME operator+(const TIME&);
 TIME operator-(const TIME&);
 bool operator>(const TIME&) const;
 void display()const;

};
int main ()
{
    TIME t3;
    int hours,minutes,seconds;
    char operation;
    cout<<"enter hour ,minutes and seconds respectively : "<<endl;
    cin>>hours>>minutes>>seconds;
    TIME t1(hours,minutes,seconds);

    cout<<"enter hour ,minutes and seconds respectively : "<<endl;
    cin>>hours>>minutes>>seconds;
    TIME t2(hours,minutes,seconds);

    cout<<"enter the operation(+,-,>) :"<<endl;
    cin>>operation;
    switch (operation)
    {
    case '+':
        t3=t1+t2;
        t3.display();
        break;
    case '-':
        t3=t2-t1;
        t3.display();
        break;
    case '>':
        if (t1 > t2) 
        {
            t1.display();
            cout<<" is greater  than "<<endl;
            t2.display();
        }
        else
        {
            t2.display();
            cout<<" is greater  than "<<endl;
            t1.display();
        }
        break;
    
    default:
        break;
    }
    

}
TIME TIME::operator+(const TIME &T2)
{
    int sec1,sec2;
    sec1=(hours*3600)+(minutes*60)+seconds;
    sec2=(T2.hours*3600)+(T2.minutes*60)+T2.seconds;

    int total_sec=sec1+sec2;
    
    int h=(total_sec/3600);
    int m=(total_sec-(h*3600))/60;
    int s=(total_sec- (h*3600) -(m*60));

    return ( TIME ( h , m , s ) );
}
TIME TIME::operator-(const TIME &T2)
{
    int sec1,sec2;
    sec1=(hours*3600)+(minutes*60)+seconds;
    sec2=(T2.hours*3600)+(T2.minutes*60)+T2.seconds;

    int total_sec=sec1-sec2;

    int h=(total_sec/3600);
    int m=(total_sec-(h*3600))/60;
    int s=(total_sec- (h*3600) -(m*60));

    return ( TIME ( h , m , s ) );
}
bool TIME::operator>(const TIME& T2) const
{    
    if(hours!=T2.hours)
    {
        return hours>T2.hours;
    }
    else if(minutes!=T2.minutes)
    {
        return minutes>T2.minutes;
    }
    else{
        return seconds>T2.seconds;
    }
}
void TIME::display()const
{
    cout<<hours<<"hrs "<<minutes<<"min "<<seconds<<"sec"<<endl;
}