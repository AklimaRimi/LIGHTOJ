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

ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   // printf("hello");
    ll x,y,z,a,c,t,i,j,n,m,k,h,e,w,p,q,l,o,d;
	string s1,s2,str;
	char s;
    scanf("%d",&t);
	for(i=1;i<=t;i++)
    {
       vector<ll>vec;
        printf("Case %d:\n",i);
        scanf("%d%d",&n,&m);
        for(k=0;k<n;k++)
        {
            scanf("%d",&q);
            vec.push_back(q);
        }
        for(j=1;j<=m;j++)
        {
            scanf(" %c", &s);

            if(s=='c')
            {
                scanf("%d",&e);
                e--;
                if(e<vec.size()){

                printf("%d\n",vec[e]);
                vec.erase (vec.begin()+e);
                }
                else
                {
                    printf("none\n");
                }
            }
            else
            {
                scanf("%d",&e);
                vec.push_back(e);
            }
        }

    }
    return 0;
}
