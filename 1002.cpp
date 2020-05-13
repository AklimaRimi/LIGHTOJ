#include<bits/stdc++.h>
using namespace std;

int ar[510];



int i,j,k,l,m,n,o,p;
vector<pair<int,int>>vc[510];
int parent(int x)
{
    return(x==ar[x])?x:parent(ar[x]);
}

void krushkal(pair<int,pair<int,int>>mp[])
{
    int c=0;
    for(i=0;i<m;i++)
    {
       int u = (mp[i].second).first;
       int v = (mp[i].second).second;
       if(parent(u)!=parent(v))
       {
           ar[u]=v;
           int w=mp[i].first;
          // cout<<x<<" "<<y<<" "<<w<<endl;
           vc[u].push_back({v,w});
           vc[v].push_back({u,w});

           c++;
       }
       if(c==n-1)
       {
           return;
       }
    }
}
int visit[510];
int bfs(int x,int y)
{
    for(i=0;i<n;i++)
    {
        visit[i]=0;
    }
    int maxi=-1,last=0;
    queue<int>qu;
    visit[x]=1;
    qu.push(x);
    while(!qu.empty())
    {
        int u=qu.front();
        qu.pop();
        for (auto it = vc[u].begin(); it!=vc[u].end(); it++)
        {
                int a = it->first;
                int b = it->second;
            if(!visit[a])
            {
                //cout<<" u  i  "<<u<<" "<<a<<" b "<<b<<endl;
                if(x==u&&y==a)
                {
                   return b;
                }
                maxi = max(maxi,b);
                visit[a]=1;
                if(a==y||u==y)
                {
                    return maxi;
                }
                qu.push(a);
            }
        }
    }
    return -1;
}
int main()
{
    int t,task;
    scanf("%d",&task);
    for(t=0;t<task;t++)
    {


            scanf("%d %d",&n,&m);
            pair<int,pair<int,int>>mp[m];
            for(i=0;i<m;i++)
            {
            scanf("%d %d %d",&k,&o,&p);
                mp[i]={p,{k,o}};
            }

            for(i=0;i<n;i++)
            {
                ar[i]=i;
                vc[i].clear();
            }
            sort(mp,mp+m);
            krushkal(mp);
                scanf("%d",&p);

            cout<<"Case "<<t<<":\n";
            for(int tt=0;tt<n;tt++){
                    if(p==tt)
                    {
                        cout<<0<<endl;
                    }
                    else
                    {
                        int xx = bfs(p,tt);
                        if(xx==-1)
                        {
                            cout<<"Impossible"<<endl;
                        }
                        else
                        {
                            cout<<xx<<endl;
                        }
                    }

            }
    }
}
