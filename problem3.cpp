#include<iostream>
#include<cmath>
using namespace std;
class COMPLEX
{
    private:
    float real,img;
    public:
    void get_info();
    void dispaly();
    COMPLEX operator+(COMPLEX);
    COMPLEX operator-(COMPLEX);
    COMPLEX operator*(COMPLEX);
    COMPLEX operator/(COMPLEX);
    /*in operator loading we can send only one argunment
     if we want send more argunment we shound make it static or friend function member  */
    
};
int main()
{
    COMPLEX c1,c2,c3;
    char operation;
    c1.get_info();
    c2.get_info();
    cout<<"enter the operation :";
    cin>>operation;
    switch(operation)
    {
      case '+':
      c3=c1+c2;
      break;
      case '-':
      c3=c1-c2;
      break;
      case '/':
      c3=c1/c2;
      break;
      case '*':
      c3=c1*c2;
      break;
      default:
      cout<<"wrong operation!!!";

    }
    c3.dispaly();
    return 0;

}

void COMPLEX::get_info()
{
    cout<<"enter the real part of number : ";
    cin>>real;
    cout<<"enter the imaginary part of number :";
    cin>>img;
}
 void COMPLEX::dispaly()
 {
    cout<<""<<real<<" + "<<img<<"i"<<endl;
 }

 COMPLEX COMPLEX::operator+(COMPLEX c1)
 {
    COMPLEX temp;
    temp.real = real + c1.real;
    temp.img = img + c1.img;
    return temp;
 }

 COMPLEX COMPLEX::operator-(COMPLEX c1)
 {
    COMPLEX temp;
    temp.real = real - c1.real;
    temp.img = img - c1.img;
    return temp;
 }

 COMPLEX COMPLEX::operator*(COMPLEX c1)
 {
    COMPLEX temp;
    temp.real=(real*c1.real)-(img*c1.img);
    temp.img=(real*c1.img)+(c1.real*img);
     return temp;
 }

 COMPLEX COMPLEX::operator/(COMPLEX c1)
 {
   COMPLEX temp;
   temp.real = ((real * c1.real) + (img * c1.img)) / (pow(c1.real, 2) + pow(c1.img, 2));
   temp.img = ((img * c1.real) - (real * c1.img)) / (pow(c1.real, 2) + pow(c1.img, 2));
   return temp;

 }
