#include<bits/stdc++.h>//rimi
using namespace std;
#define max 100005
#define ll long long
int ar[max];
vector<int >tree(max*4);

int main()
{


	 long  long int x,y,z,a,c,t,i,j,n,k,h,e,w,p,q,l,o,d;
	string s1,s,s2,str;
 //tree.resize(4*n);

    cin>>x;
    for(i=1;i<=x;i++)
    {
        stack<string> b,f;
        cout<<"Case "<<i<<":"<<endl;
        b.push("http://www.lightoj.com/");
        while(cin>>s)
        {
            if(s=="QUIT")
            {
                break;
            }
              else if(s=="VISIT")
            {
                cin>>s1;
                b.push(s1);
                cout<<s1<<endl;

                while ( ! f.empty() )
                {   f.pop();}

            }
           else if(s=="BACK")
            {
                if(b.size()<2)
                {
                    cout<<"Ignored"<<endl;
                }
                else
                {
                    f.push(b.top());
                    b.pop();
                    cout<<b.top()<<endl;
                }
            }
            else if(s=="FORWARD")
            {
                if(f.empty())
                {
                    cout<<"Ignored"<<endl;
                }
                else
                { cout<<f.top()<<endl;
                 b.push(f.top());
                    f.pop();


                }

            }

        }
    }



    return 0;
}
