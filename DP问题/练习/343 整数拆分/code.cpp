class Solution {
public:
    int integerBreak(int n) {
        vector<int>DP(n+1,0);
        DP[1]=1;DP[2]=1;
        for(int i=3;i<=n;i++){
            int max_muti=0;
            for(int j=1;j<i;j++){
                int value=max(j,DP[j]);
                max_muti=max(value*(i-j),max_muti);
            }
            DP[i]=max_muti;
        }
        for(int i=1;i<=n;i++){
            cout<<DP[i]<<" ";
        }
        return DP[n];
    }
