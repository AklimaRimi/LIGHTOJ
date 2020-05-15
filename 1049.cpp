#include<bits/stdc++.h>
using namespace std;
#define mx 110

int indeg[mx];
 vector<int>v,v2;
int i,j,m,n,o,p,a,b,c;
int ar[mx][mx];
int cost[mx];
map<int,int>mp;
vector<pair<int,int>>vc[mx];
int visit[mx];
int sum =0;
bool aipash[mx],oipash[mx];

int minu=0,plu=0,last=0;
vector<int > ans;

void dfs(int s)
{
    visit[s]=1;
    last=s;
    for(i=0;i<vc[s].size();i++)
    {
        int v = vc[s][i].first;
        if(visit[v]==0)
        {

            if(vc[s][i].second>0)
            {
                plu+=vc[s][i].second;
            }
            else
            {
                minu += abs(vc[s][i].second);
            } visit[v]=1;
            dfs(v);
        }
    }
}


int main()
{
    int tt,t;
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        cin>>n;
        memset(indeg,0,sizeof(indeg));
        memset(ar,0,sizeof(ar));
        for(i=0;i<=n;i++)
        {
            vc[i].clear();
        }
        for(i=0;i<n+2;i++)
        {
            cost[i]=INT_MAX;
        }
        long long int bigsum=0;
        for(i=0;i<n;i++)
        {
            cin>>a>>b>>c;
            mp.insert({a,b});
           vc[a].push_back({b,c});
           vc[b].push_back({a,-c});
           ar[a][b]=c;
           ar[b][a]=-c;
           bigsum += c;
        }
        minu=0,plu=0,last=0;
        memset(visit,0,sizeof(visit));

        dfs(1);
        if(ar[last][1]>0)
        {
            plu+= ar[last][1];
        }
        else
        {
            minu+= abs(ar[last][1]);
        }
        cout<<"Case "<<tt<<": ";
        if(max(plu,minu)==bigsum)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<min(plu,minu)<<endl;
        }
        ans.clear();


    }

}
oneeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeekk kostooooooooooooooo korsiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii

