class Solution {
public:
    string reversePrefix(string word, char ch) {
        int c=0;
        for(int i=0;i<word.length();i++){
            if(word[i]==ch){
                c=i;
                break;
            }
        }int i=0,j=c;
        while(i<j){
            swap(word[i++],word[j--]);
        }return word;
    }
};
