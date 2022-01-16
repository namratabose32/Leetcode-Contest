class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        long long int ans=1;
        int moves=0,x=0,n=target;
        // if(maxDoubles==0)
        //     return target-1;
        while(target>1){
            if(x<maxDoubles && target%2==0){
                target/=2;
                x++;
                moves++;
            }
            else if(x==maxDoubles){
                moves+=target-1;
                break;
            }
            else{
                target--;
                moves++;
            }
        }
        return moves;
        
    }
};
