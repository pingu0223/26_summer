#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int main(){
    int T;cin>>T;
    for(int p=0;p<T;p++){
        int n,M;cin>>n>>M;
        vector<int>Weight(n,0);
        vector<int>Price(n,0);
        for(int i=0;i<n;i++){
            int W,P;cin>>W>>P;
            Weight[i]=W;Price[i]=P;
        }
        long long DP[n][M+1];
        for(int i=0;i<n;i++){
            int W=Weight[i];int P=Price[i];
            for(int j=0;j<M+1;j++){
                if(j<W) {
                    if(i==0) DP[i][j]=0;else DP[i][j]=DP[i-1][j];continue;}
                if(i==0) {DP[i][j]=P;continue;}
                DP[i][j]=max(DP[i-1][j],DP[i-1][j-W]+P);
            }
        }
        cout<<DP[n-1][M]<<'\n';
    }
}
