class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& m) {
        int r=m.size();
        int c=m[0].size();
        if(r==0) return m;
        queue<pair<int,int>> q;
        vector<vector<int>> d(r,vector<int>(c,INT_MAX));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(m[i][j]==0)
                {
                    q.push({i,j});
                    d[i][j]=0;
                }
            }
        }
        int X[]={+1,-1,0,0};
        int Y[]={0,0,+1,-1};
        while(!q.empty())
        {
            pair<int,int> z=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=X[i]+z.first;
                int y=Y[i]+z.second;
                if(x>=0 and y>=0 and x<r and y<c)
                {
                    if(d[x][y]>d[z.first][z.second]+1)
                    {
                        d[x][y]=d[z.first][z.second]+1;
                        q.push({x,y});
                    }
                }
            }
        }
        return d;
        
    }
};
