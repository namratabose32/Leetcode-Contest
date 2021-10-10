class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> m1,m2,m3;
        vector<int> ans;
        for(int x:nums2)
            m2.insert(x);
        for(int x:nums3)
            m3.insert(x);
        for(int i=0;i<nums1.size();i++){
            int x=nums1[i];
            if(m2.find(x)!=m2.end() && m3.find(x)!=m3.end()){
                ans.push_back(x);
                m2.erase(x);
                m3.erase(x);
            }else if(m2.find(x)!=m2.end()){
                    ans.push_back(x);
                    m2.erase(x);  
            }else if(m3.find(x)!=m3.end()){
                    ans.push_back(x);
                    m3.erase(x);  
            }
        }
        for(int i=0;i<nums2.size();i++){
            //if(m2[nums2[i]]>0){
                if(m3.find(nums2[i])!=m3.end()){
                    ans.push_back(nums2[i]);
                    m3.erase(nums2[i]);
                }
            //}
        }return ans;
    }
};
