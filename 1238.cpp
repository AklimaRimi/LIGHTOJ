#include<bits/stdc++.h>
#define pii pair<int,int>
#define uu first
#define vv second
using namespace std;


vector<int>vc[110];
int i,j,k,l,m,n,o;

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};

int visit[25][25];
char ar[25][25];
int cost[25][25];
int sourcecost[25];
int last = 0;
int c=0;
void bfs(int sx,int sy) {

for(i=1;i<=n;i++)
{
    for(j=1;j<=m;j++)
    {
        visit[i][j]=0;
        cost[i][j]=INT_MAX;
    }
}
	visit[sx][sy]=1;
	cost[sx][sy]=0;
	queue<pii>q;
	q.push(pii(sx,sy));
	while(!q.empty())
	{
		pii top=q.front(); q.pop();

		for(int k=0;k<4;k++)
		{
			int tx=top.uu+fx[k];
			int ty=top.vv+fy[k];
			if(tx>0 && tx<=n && ty>0 && ty<=m && ar[tx][ty]!='#'&&ar[tx][ty]!='m' && visit[tx][ty]==0)
            {
				visit[tx][ty]=1;
				cost[tx][ty]=min(cost[tx][ty],cost[top.uu][top.vv]+1);
				q.push(pii(tx,ty));
			}
		}
	}
}
int main()
{
    int t,tt;
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {

    memset(ar,0,sizeof ar);
    memset(cost,0,sizeof cost);
    memset( visit,0,sizeof visit);
    cin>>n>>m;
    int ax,ay,bx,by,cx,cy,hx,hy;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>ar[i][j];
            if(ar[i][j]=='a')
            {
                ax=i;
                ay=j;
            }
            if(ar[i][j]=='b')
            {
                bx=i;
                by=j;
            }
            if(ar[i][j]=='c')
            {
                cx=i;
                cy=j;
            }
            if(ar[i][j]=='h')
            {
                hx=i;
                hy=j;
            }
        }

    }
    int mx = 0;
    //bfs(ax,ay);
   // cout<<count[hx][hy]<<endl;
    bfs(hx,hy);
    cout<<"Case "<<tt<<": ";
    cout<<max(cost[ax][ay],max(cost[bx][by],cost[cx][cy]))<<endl;

    //

    }
}


