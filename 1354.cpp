#include<bits/stdc++.h>
using namespace std;
int BinaryToDecimal(int n)
{
    int d = 0, i = 0, r;
    while (n!=0)
    {
        r = n%10;
        n /= 10;
        d += r*pow(2,i);
        ++i;
    }
    return d;
}
int main()
{
    int i,j,m,k,n,y,t,z,d,a,b,c,ba,bb,bc,bd;
    cin>>t;
    char x;

//    bitset<8>b;
    int ar[t];
    for(i=1;i<=t;i++)
    {
        cin>>a>>x>>b>>x>>c>>x>>d;
        cin>>ba>>x>>bb>>x>>bc>>x>>bd;
        if(a==BinaryToDecimal(ba)&&b==BinaryToDecimal(bb)&&c==BinaryToDecimal(bc)&&d==BinaryToDecimal(bd))
        {
            cout<<"Case "<<i<<": Yes"<<endl;
        }
        else
        {
            cout<<"Case "<<i<<": No"<<endl;
        }


    }
}
