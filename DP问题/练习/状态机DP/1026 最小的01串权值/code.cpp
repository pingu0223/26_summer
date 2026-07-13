#include <iostream>
#include <vector>
#include <string>
using namespace std;
int INF=1e9;
int main(){
    int n=4;
    for(int z=0;z<n;z++){
        int w1,w2;
        string s;
        cin>>w1>>w2>>s;
        int n_s=s.size();
        vector<vector<int>>DP(n_s+1,vector<int>(2,0));
        for(int i=0;i<n_s;i++){
            if(i==0) {
                if(s[i]=='0') DP[i][1]=INF;
                else if(s[i]=='1') DP[i][0]=INF;
            }
            else{
                if(s[i]=='0'){
                    DP[i][0]=min(DP[i-1][1]+w2,DP[i-1][0]);
                    DP[i][1]=INF;
                }
                else if(s[i]=='1') {DP[i][1]=min(DP[i-1][0]+w1,DP[i-1][1]);DP[i][0]=INF;}
                else{
                    DP[i][0]=min(DP[i-1][1]+w2,DP[i-1][0]);
                    DP[i][1]=min(DP[i-1][0]+w1,DP[i-1][1]);
                }
            }
        }
        if(s[n_s-1]=='?') cout<<min(DP[n_s-1][0],DP[n_s-1][1])<<'\n';
        else if(s[n_s-1]=='0') cout<<DP[n_s-1][0]<<'\n';
        else cout<<DP[n_s-1][1]<<'\n';
    }
    
}
