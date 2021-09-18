class Solution {
public:
    vector<int> findOriginalArray(vector<int>& ch) {
        unordered_map<int,int> m;
        int n=ch.size();
        vector<int> ans;
        if(n%2!=0)
            return ans;
        for(auto x:ch){
            m[x]++;
        }
        for(int i=0;i<n;i++){
            if(ch[i]==0){
                if(m[0]%2!=0)
                    return ans;
            }
            if(m.find(ch[i]*2)!=m.end())
                continue;
            else if(m.find(ch[i]/2)!=m.end())
                continue;
            else
                return ans;
        }int i=0;
        vector<int> res;
        sort(ch.begin(),ch.end());
        while(m.size()!=0){
            if(m.find(ch[i])==m.end()){
                m.erase(ch[i]);
                i++;
                continue;
            }
            if(m.find(ch[i]*2)==m.end())
                return res;
            if(m.find(ch[i]*2)!=m.end()){
                ans.push_back(ch[i]);
                m[ch[i]*2]--;
                if(m[ch[i]*2]<=0)
                    m.erase(ch[i]*2);
            }m[ch[i]]--;
            if(m[ch[i]]<=0)
                m.erase(ch[i]);
            i++;
        }
        return ans;
    }
};
