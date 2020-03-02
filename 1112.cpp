#include<bits/stdc++.h>//rimi
using namespace std;
#define max 100005
#define ll int
ll ar[max];
vector<ll >tree(max*4);

void update(ll node,ll b,ll e)
{

     if(b==e )
    {
        tree[node] = ar[b];
        return;
    }
    else{
    ll left = node*2;
    ll right = (node*2)+1;
    ll mid = (b+e)>>1;
     update(left ,b,mid);
     update(right,mid+1,e);
     tree[node] =tree[left]+tree[right];
    return ;
}
}

void update1(ll node,ll b,ll e,ll x,ll y)
{
    if(b>e||x<b||x>e)
    {
        return ;
    }
    else if(b==e && e==x )
    {
          tree[node]=y;
          return;
        // cout <<"update o "<<tree[node]<<endl;
       //tree[node];
    }
else{
    ll left = node*2;
    ll right = (node*2)+1;
    ll mid = (b+e)>>1;
    update1(left ,b,mid, x,y);
    update1(right,mid+1,e,x,y);
    tree[node] = tree[left]+tree[right];
    return ;//tree[node];
}
}

 ll  query(ll node,ll b,ll e,ll x,ll y)
{
    if(b>e||e<x||y<b)
    {
        return 0;
    }
    else if(b>=x && e<=y)
    {
        return tree[node];
        //cout<<"tree "<<tree[node]<<endl;
    }
    else{
    ll left = node*2;
    ll right = (node*2)+1;
    ll mid = (b+e)>>1;
     ll a = query(left,b,mid,x,y);
     ll c = query(right,mid+1,e,x,y);
     //cout<<"a c "<<a<<" "<<c<<endl;
     return (a+c);}
}

int main(){
   // printf("hello");
    ll x,y,z,a,c,t,i,j,n,m,k,h,e,w,p,q,l,o,d;
	string s1,s,s2,str;
    scanf("%d",&t);
	for(i=1;i<=t;i++)
    {
        cout<<"Case "<<i<<":"<<endl;
        scanf("%d%d",&n,&m);
        for(k=0;k<n;k++)
        {
        scanf("%d",&ar[k]);

        }
        update(1,0,n-1);
        for(j=1;j<=m;j++)
        {
        scanf("%d",&x);
            if(x==1)
            {
                scanf("%d",&y);
                printf("%d\n",ar[y]);
                ar[y]=0;
                update1(1,0,n-1,y,0);

            }
            else if(x==2)
            {
                scanf("%d%d",&y,&z);
                ar[y]+=z;
                update1(1,0,n-1,y,ar[y]);
            }
            else
            {
                scanf("%d%d",&y,&z);
                printf("%d\n",query(1,0,n-1,y,z));
            }
        }
    }
    return 0;
}
