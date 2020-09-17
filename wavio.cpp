//LIS and math

#include<bits/stdc++.h>

using namespace std;

 int main()
{
     int t,tt;
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        int n;
        cin>>n;
        vector<int >ar(n);
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        vector<int>br(n),cr(n),lis(n),lds(n);
        int sum =0,pos=0;
        for(int i=0;i<n;i++)
        {
            pos = lower_bound(br.begin(),br.begin()+sum,ar[i])-br.begin();
            br[pos]= ar[i];

            if(pos==sum)
            {
                sum++;
            }

            lis[i]=pos+1;
        }

        reverse(ar.begin(),ar.end());

          sum =0,pos=0;
        for(int i=0;i<n;i++)
        {
            pos = lower_bound(cr.begin(),cr.begin()+sum,ar[i])-cr.begin();
            cr[pos]= ar[i];

            if(pos==sum)
            {
                sum++;
            }

            lds[i]=pos+1;
        }
        reverse(lds.begin(),lds.end());

        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans  = max(ans, 2*min(lis[i],lds[i]));
        }

            cout<<"Case "<<tt<<": "<<ans-1<<endl;
        }
}
