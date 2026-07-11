class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size(); int sum=0;
        for(int i=0;i<n;i++){
            sum+=stones[i];
        }
        int subsum=sum/2;
        int dp[n][subsum+1];
        for(int i=0;i<n;i++){
            int w=stones[i];
            for(int j=0;j<=subsum;j++){
                if(j<w){
                    if(i==0) dp[i][j]=0;
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
                else if(i==0){
                    dp[i][j]=w;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-w]+w);
                }
            }
        }
        int more=sum-dp[n-1][subsum];
        return more-dp[n-1][subsum];
    }
};
