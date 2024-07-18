#include<iostream>

using namespace std;
class MATRIX
{
    int mat[100][100];
    int m ,n;
    public:
    MATRIX(int m1, int n1) : m(m1), n(n1) {}
    void get();
    void show();
    MATRIX operator+(const MATRIX );
};
int main()
{
    int m,n;
    cout<<"enter the order of MATRIX m and n"<<endl;
    cin>>m>>n;
    MATRIX m1(m,n) ,m2(m,n);
    cout<<"enter the elements of 1st matrix"<<endl;
    m1.get();
    cout<<"enter the elements of 2st matrix"<<endl;
    m2.get();
    MATRIX m3=m1+m2;
    cout<<"result is:"<<endl;
    m3.show();
    return 0;
}
void MATRIX::get()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }

}
void MATRIX::show()
{
     for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
MATRIX MATRIX::operator+(const MATRIX m)
{
    MATRIX temp(m.m,m.n);
     for(int i=0;i<m.m;i++)
    {
        for(int j=0;j<m.n;j++)
        {
            temp.mat[i][j]=mat[i][j]+m.mat[i][j];
        }
    }
    return temp;
}