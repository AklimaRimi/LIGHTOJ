#include<bits/stdc++.h>//rimi
using namespace std;
#define max 100005
#define ll long long
int ar[max];
vector<int >tree(max*4);

int main()
{


	 long  long int x,y,z,a,c,t,i,j,n,m,k,h,e,w,p,q,l,o,d;
	string s1,s,s2,str;
 //tree.resize(4*n);
 cin>>t;
  for(i=1;i<=t;i++)
 {

      deque<int>d;
      cin>>n>>m;
      cout<<"Case "<<i<<":\n";
      for(j=1;j<=m;j++)
       {
           cin>>s;
           if(s=="pushLeft")
           {
               cin>>p;
               if(d.size()==n)
               {
                   cout<<"The queue is full"<<endl;
               }
               else if(d.size()<n)
               {

                   cout<<"Pushed in left: "<<p<<endl;
                   d.push_front(p);
               }
           }
           else if(s=="pushRight")
           {
               cin>>p;
              if(d.size()==n)
               {
                   cout<<"The queue is full"<<endl;
               }
                else if(d.size()<n)
               {

                   cout<<"Pushed in right: "<<p<<endl;
                   d.push_back(p);

               }
           }
           else if(s=="popLeft")
           {
               if(d.empty())
               {
                   cout<<"The queue is empty"<<endl;
               }
               else
               {
                   cout<<"Popped from left: "<<d.front()<<endl;
                   d.pop_front();
               }
           }
           else if(s=="popRight")
           {
               if(d.size()<1)
               {
                   cout<<"The queue is empty"<<endl;
               }
               else
               {
                   cout<<"Popped from right: "<<d.back()<<endl;
                   d.pop_back();
               }
           }
       }

 }



    return 0;
}
