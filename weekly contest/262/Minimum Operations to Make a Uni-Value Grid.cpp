class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++)
                v.push_back(grid[i][j]);
        }int ans=0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            int n=abs(v[v.size()/2]-v[i]);
            if(n%x)
                return -1;
            ans+=n/x;
        }return ans;
    }
};
