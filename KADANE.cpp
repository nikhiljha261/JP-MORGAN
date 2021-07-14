int kadane(vector<int>& a,int i,int j,int sign)
{
    int ans=INT_MIN;
    int cur=0;
    for(int k=i;k<=j;k++)
    {
        cur=sign*a[k]+(max(cur,0));
        ans=max(ans,cur);
    }
    return ans;
}





int maxSubarraySumCircular(vector<int>& A) {
    int n=A.size();
    int S=0;
    for(auto x : A)
    {
        S=S+x;
    }
    if(n==1) return A[0];
    int ans1 = kadane(A, 0, n-1, 1);
    int ans2 = S + kadane(A, 1, n-1, -1);
    int ans3 = S + kadane(A, 0, n-2, -1);
    return max({ans1,ans2,ans3});
}
