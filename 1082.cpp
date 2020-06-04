// it's a very easy problem on segment tree..//



#include<bits/stdc++.h//rimi//>
#define mx 100002
 using namespace std;
int ar[mx*4];
int i,j,k,l,m,o,p;

int update(int node,int s,int e,int x,int v)
{
return 0;
}
void input(int node,int s,int e,int arr[])
{
    if(s>e) return;
    if(s==e)
    {
        ar[node] = arr[s];
        //cout<<ar[node]<<endl;
        return ;
    }
    int l = node<<1, r = l+1;
    int mid = (s+e)>>1;
    input(l,s,mid,arr);
    input(r,mid+1,e,arr);
    ar[node] = min(ar[l],ar[r]);

}
int query(int node, int s,int e,int x,int y)
{
    if(s>e||e<x||s>y)
    {
        return INT_MAX;
    }
     if(s>=x&&y>=e)
    {
        return ar[node];
    }

    int l = node<<1, r = l+1;
    int mid = (s+e)>>1;
    int a = query(l,s,mid,x,y);
    //cout<<node<<" "<<a<<" ";
    int c = query(r,mid+1,e,x,y);
    //cout<<c<<endl;
    return (min(a,c));
}
int main()
{
    int n,kk,t,tt;
    scanf("%d",&t);
    for(tt=1;tt<=t;tt++){
    memset(ar,0,sizeof ar);

    scanf("%d %d",&n,&kk);
    int arr[n];
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    input(1,1,n,arr);

    printf("Case %d:\n",tt);
    for(int xx=1,a,b;xx<=kk;xx++){
    scanf("%d %d",&a,&b);
    printf("%d\n",query(1,1,n,a,b));
    }
}
}
