//O(n^2)

int maximumDifference(vector<int>& nums) {
        int n=nums.size(),mx=-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i])
                    mx=max(mx,nums[j]-nums[i]);
            }
        }return mx;
}

//O(n)
int maximumDifference(vector<int>& nums) {
    int mn = nums[0], res = -1;
    for (int i = 1; i < nums.size(); ++i) {
        res = max(res, nums[i] - mn);
        mn = min(mn, nums[i]);
    }
    return res == 0 ? -1 : res;
}
