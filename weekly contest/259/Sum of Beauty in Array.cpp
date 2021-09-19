class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int s=0,n=nums.size();
        vector<int> lh(n);
        vector<int> rh(n);
        lh[0]=nums[0];
        rh[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
            lh[i]=max(lh[i-1],nums[i]);
        for(int j=n-2;j>=0;j--)
            rh[j]=min(rh[j+1],nums[j]);
        for(int i=1;i<=n-2;i++){          
            if(lh[i-1]<nums[i] && rh[i+1]>nums[i]){
                s+=2;
                continue;
            }
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1])
                s+=1;
            else
                s+=0;
        }return s;
    }
};
