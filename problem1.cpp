#include<iostream>
using namespace std;

class B; 

class A {
private:
    int a;
public:
    A(int x) : a(x) {} 

    friend void swap(A&, B&);
    friend void display(A&, B&);
};

class B {
private:
    int b;
public:
    B(int x) : b(x) {} 

    friend void swap(A&, B&);
    friend void display(A&, B&);
};

void swap(A &x, B &y) {
    int temp = x.a;
    x.a = y.b;
    y.b = temp;
}

void display(A &x, B &y) {
    cout << " x = " << x.a << " y = " << y.b << endl;
}

int main() {
    int x, y;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: "; 
    cin >> y;

    A a(x);
    B b(y);
    swap(a, b); 
    cout<<"after swapping"<<endl;
    display(a, b);

    return 0;
}
