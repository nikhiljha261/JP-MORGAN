class Solution {
public:
    bool canFinish(int no, vector<vector<int>>& v) {
        int n=v.size();
        vector<int> graph[no];
        vector<int> ind(no,0);
        for(int i=0;i<n;i++)
        {
            int a=v[i][0];
            int b=v[i][1];
            graph[b].push_back(a);
            ind[a]++;
        }
        queue<int> q;
        for(int i=0;i<no;i++)
        {
            if(ind[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                int x=q.front();
                q.pop();
                for(auto child : graph[x])
                {
                    ind[child]--;
                    if(ind[child]==0)
                    {
                        q.push(child);
                    }
                }
            }
        }
        for(int i=0;i<no;i++)
        {
            if(ind[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
};
