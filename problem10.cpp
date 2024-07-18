#include<iostream>
 

using namespace std;
class MATRIX
{
    int mat[100][100];
    int m ,n;
    public:
    MATRIX(int m1, int n1) : m(m1), n(n1) {}
    friend void get(MATRIX &);
    friend void show(MATRIX &);
    friend MATRIX operator+( MATRIX,MATRIX );
};
int main()
{
    int m,n;  
    cout<<"enter the order of MATRIX m and n"<<endl;
    cin>>m>>n;
    MATRIX m1(m,n) ,m2(m,n);
    cout<<"enter the elements of 1st matrix"<<endl;
    get(m1);
    cout<<"enter the elements of 2st matrix"<<endl;
    get(m2);
    MATRIX m3=m1+m2;
    cout<<"result is:"<<endl;
    show(m3);
    return 0;
}
void get(MATRIX & M)
{
    for(int i=0;i<M.m;i++)
    {
        for(int j=0;j<M.n;j++)
        {
            cin>>M.mat[i][j];
        }
    }

}
void show(MATRIX & M)
{
     for(int i=0;i<M.m;i++)
    {
        for(int j=0;j<M.n;j++)
        {
            cout<<M.mat[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
MATRIX operator+( MATRIX M1,MATRIX M2)
{
    MATRIX temp(M1.m,M1.n);
     for(int i=0;i<M1.m;i++)
    {
        for(int j=0;j<M1.n;j++)
        {
            temp.mat[i][j]=M1.mat[i][j]+M2.mat[i][j];
        }
    }
    return temp;
}