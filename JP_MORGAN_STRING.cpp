//har har mahadev
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i,a,b)     for(int i=(a);i<(b);i++)
#define endl            "\n"
// cout<<fixed<<setprecision(9)<<" ";

void ganeshji(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}



int main()
{
    ganeshji();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    clock_t begin = clock();
    ll t=1;
    // cin>>t;
    while(t--)
    {
        // given a binary string count substring with equal 0 and equal 1;
        string s;
        cin>>s;
        int n=s.length();
        //solution
        int cur=1;
        vector<int> v;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            {
                cur++;
            }
            else
            {
                v.push_back(cur);
                cur=1;
            }
        }
        v.push_back(cur);
        int ans=0;
        for(int i=1;i<v.size();i++)
        {
            ans=ans+min(v[i],v[i-1]);
        }
        cout<<ans<<endl;
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
}

