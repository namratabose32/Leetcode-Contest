class Solution {
public:
    
    bool same(vector<char> a,int start,int end, string s){
        int n=s.length();
        if(end-start!=n)
            return 0;
        int j=0;
        while(start+j<end && (a[start+j]==s[j] || a[start+j]==' '))
            j++;
        if(j==n)
            return 1;
        j=0;
        while(end-1-j>=start && (a[end-1-j]==s[j] || a[end-1-j]==' '))
            j++;
        return (j==n);
    }
    
    bool match(vector<vector<char>> arr,string s){
        int m=arr.size(),n=arr[0].size();
        for(int i=0;i<m;i++){
            int j=0;
            while(j<n){
                while(j<n && arr[i][j]=='#')
                    j++;
                int start=j;
                while(j<n && arr[i][j]!='#')
                    j++;
                if(same(arr[i],start,j,s))
                    return 1;
            }
        }return 0;
    }
    
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        vector<vector<char>> B(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                B[i][j]=board[j][i];
        }
        return match(board,word)|| match(B,word);
    }
};
