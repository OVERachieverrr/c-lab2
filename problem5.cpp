#include<iostream>
#include<cstring>
using namespace std;

class STRING
{
    char *str;//string
    int len;
    public:
    STRING(const char *s)
    {
        len=strlen(s);
        str=new char[len+1];
        strcpy(str,s);
    }
    STRING(const STRING & S)
    {
        str= new char[strlen(S.str)+1];
        strcpy(str,S.str);
    }
    STRING operator+(const STRING);
    STRING operator=(const STRING);
    bool operator==(const STRING &) const;
    void display()
    {
        cout<<str<<endl;
    }
    ~STRING()
    {
        delete[] str;
    }
};
int main()
{
    STRING s1("bijaya");
    STRING s2("khanal");
    STRING s3=s2+s1;
    s3.display();
    if(s1==s2)
    {
        cout<<"same string"<<endl;
    }
    else
    {
        cout<<"different string"<<endl;
    }
    s1=s2;
    s1.display();
}

STRING STRING::operator+(const STRING s)
{
     char *temp = new char[strlen(str) + strlen(s.str) + 1];
        strcpy(temp, str);
        strcat(temp, s.str);
        STRING result(temp);
        delete[] temp;
        return result;
}

STRING STRING::operator=(const STRING s)
{
    delete[] str;
    str=new char[strlen(s.str)+1];
    strcpy(str,s.str);
    return *this;
}

bool STRING::operator==(const STRING & s) const
{
     return (strcmp(str, s.str) == 0) && (strlen(str) == strlen(s.str));
}
