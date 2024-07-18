#include<iostream>
#include<cstring>
const int max_len=100;
using namespace std;

class STRING
{
    char str[max_len];//string
    int len;
    public:
    STRING(const char *s)
    {
        strcpy(str,s);
    }
    STRING(const STRING & S)
    {
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
    char newstr[max_len];
        strcpy(newstr, str);
        strcat(newstr, s.str);
        return STRING(newstr);
        
        }

STRING STRING::operator=(const STRING s)
{
   strcpy(str,s.str);
}

bool STRING::operator==(const STRING & s) const
{
     return (strcmp(str, s.str) == 0) && (strlen(str) == strlen(s.str));
}
