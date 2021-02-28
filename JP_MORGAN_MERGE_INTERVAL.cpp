vector<vector<int>> mergeinterval(vector<vector<int>> inter)
{
    sort(inter.begin(),inter.end());
    int n=inter.size();
    int st=inter[0][0];
    int ed=inter[0][1];
    vector<vector<int>> ans;
    for(int i=1;i<n;i++)
    {
        if(inter[i][0]<=ed)
        {
            ed=max(ed,inter[i][1]);
        }
        else
        {
            ans.push_back({st,ed});
            st=inter[i][0];
            ed=inter[i][1];
        }
    }
    ans.push_back({st,ed});
    return ans;
}
