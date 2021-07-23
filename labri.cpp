//har har mahadev
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define loop(i,a,b)     for(int i=(a);i<(b);i++)
#define endl            "\n"
 
void ganeshji(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}
ll n,m;
pair<int,int> cell[1001][1001];
ll grid[1001][1001];
ll vis[1001][1001];
char parent[1001][1001];
int mo[1001][1001];
bool valid(ll x,ll y)
{
    if(x<0 || x>=n || y<0 || y>=m || vis[x][y]==1 || grid[x][y]==0)
    {
        return false;
    }
    return true;
}
int dx[4]={+1,-1,+0,+0};
int dy[4]={+0,+0,+1,-1};
char moves[4]={'D','U','R','L'};
// void dfs(ll x,ll y)
// {
//     vis[x][y]=1;
//     loop(i,0,4)
//     {
//         if(valid(x+dx[i],y+dy[i]))
//         {
//             dfs(x+dx[i],y+dy[i]);
//         }
//     }
// }
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
        ll ans=0;
        cin>>n>>m;
        int x,y;
        int fx=-1,fy=-1;
        loop(i,0,n)
        {
            loop(j,0,m)
            {
                char c;
                cin>>c;
                if(c=='.')
                {
                    grid[i][j]=1;
                }
                else if(c=='#')
                {
                    grid[i][j]=0;
                }
                else if(c=='A')
                {
                    grid[i][j]=5;
                    x=i;
                    y=j;
                }
                else if(c=='B')
                {
                    grid[i][j]=10;
                }
            }
        }
        memset(vis,-1,sizeof(vis));
        queue<pair<int,int>> q;
        vis[x][y]=1;
        q.push({x,y});
        while(!q.empty())
        {
            int a=q.front().first;
            int b=q.front().second;
            vis[x][y]=1;
            if(grid[a][b]==10)
            {
                ans=1;
                fx=a;
                fy=b;
            }
            q.pop();
            loop(i,0,4)
            {
                if(valid(a+dx[i],b+dy[i])==true)
                {
                    vis[a+dx[i]][b+dy[i]]=1;
                    q.push({a+dx[i],b+dy[i]});
                    cell[a+dx[i]][b+dy[i]]={a,b};
                    parent[a+dx[i]][b+dy[i]]=moves[i];
                }
            }
        }
        if(ans==0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            vector<char> cur;
            while(x!=fx || y!=fy)
            {
                cur.push_back(parent[fx][fy]);
                pair<int,int> temp=cell[fx][fy];
                fx=temp.first;
                fy=temp.second;
            }
            reverse(cur.begin(),cur.end());
            cout<<cur.size();
            cout<<endl;
            loop(i,0,cur.size()) cout<<cur[i];
            cout<<endl;
        }
        
 
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
        
   
}
