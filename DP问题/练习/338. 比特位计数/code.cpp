class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> DP(n+1,0);
        for(int i=0;i<=n;i++){
            if(i==0) DP[i]=0;
            else DP[i]=DP[i>>1]+(i&1);
        }
        return DP;
    }
};
