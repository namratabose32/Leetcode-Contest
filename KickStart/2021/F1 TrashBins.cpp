#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int l=0;l<t;l++){
        int n;
        long long int c=0;
        cin>>n;
        string s;
        cin>>s;
        vector<int> one;
        for(int x=0;x<n;x++){
            if(s[x]=='1')
                one.push_back(x);
        }
        if(one.size()==1){
            for(int i=0;i<n;i++){
                c+=abs(one[0]-i);
            }cout<<"Case #"<<l+1<<": "<<c<<endl;
            continue;
        }else{
            int l=one[0],r=one[1],z=1,i=0;
            //cout<<l<<" "<<r<<endl;
            for(i=0;i<n;i++){
                if(l==i)
                    break;
                else
                    c+=l-i;
                //cout<<c<<" ";
            }
            for(;i<n;i++){
                int y=min(i-l,r-i);
                c+=y;
                //cout<<y<<" ";
                if(r==i && z+1<one.size()){
                    l=r;
                    z++;
                    r=one[z];
                }else if(r==i && z+1>=one.size()){
                    l=r;
                    r=INT_MAX;
                    break;
                }
            }for(;i<n;i++){
                c+=i-l;
                //cout<<c<<" ,";
            }
        }
        cout<<"Case #"<<l+1<<": "<<c<<endl;
    }return 0;
}





//2nd method
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> left(n);
        vector<int> right(n);
        if(s[0]=='1')
            left[0]=0;
        else
            left[0]=-1;
        for(int i=1;i<n;i++){
            if(s[i]=='1')
                left[i]=i;
            else
                left[i]=left[i-1];
        }
        if(s[n-1]=='1')
            right[n-1]=n-1;
        else
            right[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='1')
                right[i]=i;
            else
                right[i]=right[i+1];
        }long long int sum=0;
        for(int i=0;i<n;i++){
            if(left[i]==-1)
                sum+=abs(i-right[i]);
            else if(right[i]==-1)
                sum+=abs(i-left[i]);
            else
                sum+=min(abs(i-left[i]),abs(i-right[i]));   
        }cout<<"Case #"<<z<<": "<<sum<<endl;
    }
}
