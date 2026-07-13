#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    vector<vector<int>>DP;
    vector<int> x;
    x.push_back(0);x.push_back(1);x.push_back(1);
    DP.push_back(x);
    while(cin>>n,n!=-1){
        if(n<=DP.size()){cout<<DP[n-1][0]+DP[n-1][1]+DP[n-1][2]<<'\n';continue;}
        else{
            int i=DP.size();
            while(i<n){
                vector<int>x;
                x.push_back(DP[i-1][1]);
                x.push_back(DP[i-1][1]+DP[i-1][2]);
                x.push_back(DP[i-1][2]+DP[i-1][0]);
                i++;
                DP.push_back(x);
            }
            cout<<DP[n-1][0]+DP[n-1][1]+DP[n-1][2]<<'\n';
        }
    }
}
