class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long s=0,n=grid[0].size(),b=0,res=LLONG_MAX;
        for(int i=0;i<n;i++)
            s+=grid[0][i];
        for(int i=0;i<n;i++){
            s-=grid[0][i];
            res=min(res,max(s,b));
            b+=grid[1][i];
        }return res;
    }
};
