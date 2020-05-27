/* it's a very easy problem that belonging Dijkastra algorithm nothing else */
#include<bits/stdc++.h>
#define pii pair<int,int>
#define mx 1010

using namespace std;

int ar[mx][mx];
vector<pii>vc[mx];
int i,j,k,l,n,m;
int visit[mx],cost[mx];

void bfs(int s)
{
    for(i=0;i<=n+10;i++)
    {
        visit[i]=0;
        cost[i]=INT_MAX;
    }

    priority_queue<pii>q;
    q.push({s,0});
    cost[s]=0;
    while(!q.empty())
    {
        int u = q.top().first;
        int w = q.top().second;
        //if(u==n)return ;
        q.pop();
        for(i=0;i<vc[u].size();i++)
        {
           int v = vc[u][i].first;
            int wi =vc[u][i].second;


            if(visit[v]==0)
            {
               if(w+wi<cost[v])
               {
                   cost[v]=w+wi;
                   q.push({v,cost[v]});
               }
            }
        }
    }

}
int main()
{
    int tt,t;
    cin>>t;
    for(tt=1;tt<=t;tt++){
    cin>>n>>m;
    int a,b,c;
    list<pii>mp[n+2];
    for(i=0;i<=n;i++)
    {
        vc[i].clear();
        for(j=0;j<=n;j++)
        {
            ar[i][j]=INT_MAX;
        }
    }
    for(i=1;i<=m;i++)
    {
        a=b=c=0;
        int aa,bb;
        //cout<<endl;
       cin>>a>>b>>c;
       vc[a].push_back({b,c});
       vc[b].push_back({a,c});
    }

   bfs(1);
   if(cost[n]!= INT_MAX)
   {
       cout<<"Case "<<tt<<": "<<cost[n]<<endl;
   }
   else
   {
       cout<<"Case "<<tt<<": Impossible"<<endl;
   }
    }
}
