class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(); int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        sum=sum/2;sum++;
        int dp[n][sum];
        for(int i=0;i<n;i++){
            int value=nums[i];int w=nums[i];
            for(int j=0;j<sum;j++){
                if(j<w){
                    if(i==0) dp[i][j]=0;
                    else dp[i][j]=dp[i-1][j];
                }
                else if(i==0){
                    dp[i][j]=w;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-w]+w);
                }
            }
            if(dp[i][sum-1]==sum-1) return true;
        }
        return false;
    }
};
