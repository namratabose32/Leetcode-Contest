class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& r) {
        long long c=0;
        if(r.size()==1)
            return 0;
        map<double,int> s;
        for(int i=0;i<r.size();i++){
            double x=(double)r[i][0]/(double)r[i][1];
            if(s.find(x)!=s.end()){
                c+=s[x];
                s[x]++;
            }else
                s.insert(pair<double,int>(x,1));
        }
        return c;
    }
};
