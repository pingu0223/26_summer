#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,v;
    cin>>n>>v;
    vector<int> weight(n,0);
    vector<int> price(n,0);
    for(int i=0;i<n;i++){
        int wi,pi;cin>>wi>>pi;
        weight[i]=wi;price[i]=pi;
    }
    vector<vector<long long>> dp(n,vector<long long>(v+1,0));
    for(int i=0;i<n;i++){
        int w=weight[i];int p=price[i];
        for(int j=0;j<v+1;j++){
            if(i==0){
                if(j<w) dp[i][j]=0;
                else if(j==w) dp[i][j]=p;
                else dp[i][j]=dp[i][j-w]+p;
            }
            else if(j<w){
                dp[i][j]=dp[i-1][j];
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-w]+p);
        }
    }
    cout<<dp[n-1][v];
}
