/* I've sovled this using dfs in 2 ways  ..at first I find the number of indegree and outdegree ,,
which node has value 1 that mean that node is the last or leaf node... 
from those leaf node I call dfs(i)[where i =1].. so there have many leaf nodes in which dfs(i) returns maximum cost that should be the ans..
but as I said there must have so many leaf nodes .. guess what would be happened :) TLE ...code is below  */


#include<bits/stdc++.h>
#define mx 30010
#define pii pair<int,int>
using namespace std;

int i,n,m,k,l,o,p;
int indegree[mx],visit[mx],cost[mx];
vector<pii>vc[mx];

int dfs(int s)
{
    for(i=0;i<=n;i++)
    {
        cost[i]=0;
        visit[i]=0;
    }
    stack<int>st;
    st.push(s);
    visit[s]=1;
    int maxii=0,weight=0;
    while(!st.empty())
    {
        int u = st.top();
        st.pop();
        for(i=0;i<vc[u].size();i++)
        {
            int v = vc[u][i].first;
            int w = vc[u][i].second;
            if(visit[v]==0)
            {
                cost[v] = max(cost[v],cost[u]+w);
              // cout<<u<<" "<<v<<" "<<cost[v]<<endl;
              maxii = max(maxii,cost[v]);
                visit[v]=1;
                st.push(v);

            }

        }
    }

return maxii;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt,t;
    cin>>t;
    for(tt=1;tt<=t;tt++)
        {
        cin>>n;
        pair<int,pii>pi[n];

        for(int i=1,a,b,c;i<n;i++)
        {
            cin>>a>>b>>c;
            pi[i]={c,{a,b}};
            indegree[a]++;
            indegree[b]++;
            vc[a].push_back({b,c});
            vc[b].push_back({a,c});

        }
        int maxiii = 0;
        for(k=0;k<n;k++)
        {
            if(indegree[k]==1){
                  maxiii = max(maxiii,dfs(k));
            }
        }
        cout<<"Case "<<tt<<": "<<maxiii<<endl;
        for(i=0;i<=n;i++)
        {
            vc[i].clear();
            //pi.erase();
        }
        memset(indegree,0,sizeof indegree);
    }
    //cout<<paisi<<endl;
}



/*Another strategy is whatever node are connected with each other i start dfs from 0 .. cause every tastcase starts from 0... 
that dfs returns the farthest node from 0..also count the distance from node to another.. and finally again use dfs for the farthest node 
it also returns again farthest node with accurate distance; it got ACCEPT and code in underneath*/


#include<bits/stdc++.h>
#define mx 30010
#define pii pair<int,int>
using namespace std;

int i,n,m,k,l,o,p;
int indegree[mx],visit[mx];
long long int cost[mx];
vector<pii>vc[mx];

long long int maxii=0,dure=0;
int dfs(int s)
{
    for(i=0;i<=n;i++)
    {
        cost[i]=0;
        visit[i]=0;
    }
    stack<int>st;
    st.push(s);
    visit[s]=1;
    while(!st.empty())
    {
        int u = st.top();
        st.pop();
        for(i=0;i<vc[u].size();i++)
        {
            int v = vc[u][i].first;
            int w = vc[u][i].second;
            if(visit[v]==0)
            {
                cost[v] = max(cost[v],cost[u]+w);
              // cout<<u<<" "<<v<<" "<<cost[v]<<endl;

               if(cost[v]>maxii)
               {
                   maxii=cost[v];
                   dure = v;
               }

                visit[v]=1;
                st.push(v);
            }
        }
    }
    return dure;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt,t;
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        cin>>n;
       // pair<int,pii>pi[n];
        int maxiii = 0,aa = 0,bb = 0;

        for(int i=1,a,b,c;i<n;i++)
        {
            cin>>a>>b>>c;
            //pi[i]={c,{a,b}};
            indegree[a]++;
            indegree[b]++;
            vc[a].push_back({b,c});
            vc[b].push_back({a,c});
        }
        dure=0;
        maxii = 0;
        int large = dfs(0);
        maxii=0;
        int bohudure = dfs(large);

        cout<<"Case "<<tt<<": "<<cost[bohudure]<<endl;
        for(i=0;i<=n;i++)
        {
            vc[i].clear();
            //pi.erase();
        }
        memset(indegree,0,sizeof indegree);
    }
    //cout<<paisi<<endl;
}
