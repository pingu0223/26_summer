class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();int sum=0;int num_zero=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(target<0) target=-target; 
        int summ=sum+target;
        if(summ%2!=0) return 0;
        summ/=2;
        int dp[n][summ+1]; int zero=0;
        for(int i=0;i<n;i++){
            int w=nums[i];if(w==0) zero++;
            for(int j=0;j<summ+1;j++){
                if(i==0){
                    if(j==0){
                        if(w==0) dp[i][j]=2;
                        else dp[i][j]=1;
                    }
                    else{
                        if(j==w) dp[i][j]=1;
                        else dp[i][j]=0;
                    }
                }
                else if(j==0){
                    if(w==0) {
                        dp[i][j]=(int)pow(2.0,zero);
                    }
                    else dp[i][j]=dp[i-1][j];
                }
                else if(j<w){
                    dp[i][j]=dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j]+dp[i-1][j-w];
            }
        }
        return dp[n-1][summ];
    }
};
