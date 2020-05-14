#include<bits/stdc++.h>
using namespace std;
#define mx 22

int i,j,k,l,m,n,c,x,y;
char ar[mx][mx];
int visit[mx][mx];

void floodfill(int x,int y)
{

    if( x>0 && y>0&&x<=m&&y<=n&& ar[x+1][y]=='.'&&visit[x+1][y]==0)
    {
         c++;
         visit[x+1][y]=1;
         floodfill(x+1,y);
    }
    if( x>0 && y>0&&x<=m&&y<=n&& ar[x-1][y]=='.'&&visit[x-1][y]==0)
    {
         c++;
         visit[x-1][y]=1;
         floodfill(x-1,y);
    }
    if( x>0 && y>0&&x<=m&&y<=n&& ar[x][y+1]=='.'&&visit[x][y+1]==0)
    {
         c++;
         visit[x][y+1]=1;
         floodfill(x,y+1);
    }
    if( x>0 && y>0&&x<=m&&y<=n&& ar[x][y-1]=='.'&&visit[x][y-1]==0)
    {
         c++;
         visit[x][y-1]=1;
         floodfill(x,y-1);
    }


}
int main()
{
    int t,tt;
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        cin>>n>>m;

        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin>>ar[i][j];
                if(ar[i][j]=='@')
                {
                    x = i;
                    y = j;
                }
            }

        }
        c=0;
        //cout<<x<<" y "<<y<<endl;
        floodfill(x,y);
        cout<<"Case "<<tt<<": "<<c+1<<endl;
        memset(ar,0,sizeof(ar));
        memset(visit,0,sizeof(visit));

    }
}
