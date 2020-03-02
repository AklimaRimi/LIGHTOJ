#include<bits/stdc++.h>
using namespace std;

int main()
{
   unsigned long long int i,j,m,k,x,n,y,t,z,d,a,ba,bb,bc,bd;
   char s[123],c[123];
   map<string,int>mp;
   map<string,int> ::iterator ip;
   cin>>t;
      for(i=1;i<=t;i++)
      {
          cin>>x;
          bitset<1000>b(x);
          if(b.count()%2==0)
          {
              cout<<"Case "<<i<<": even"<<endl;
          }
          else
          {
              cout<<"Case "<<i<<": odd"<<endl;
          }
      }
}
