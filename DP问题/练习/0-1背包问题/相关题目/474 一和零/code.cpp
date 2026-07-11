class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len=strs.size();
        int dp[len][m+1][n+1];
        for(int k=0;k<len;k++){
            int n_1=0,n_0=0;
            for(int pp=0;pp<strs[k].size();pp++){
                if(strs[k][pp]=='0') n_0++;
                else n_1++;
            }
            for(int i=0;i<=m;i++){
                for(int j=0;j<=n;j++){
                    if(k==0){
                        if(i<n_0) dp[k][i][j]=0;
                        else if(j<n_1) dp[k][i][j]=0;
                        else dp[k][i][j]=1;
                    }
                    else if(i<n_0||j<n_1) dp[k][i][j]=dp[k-1][i][j];
                    else dp[k][i][j]=max(dp[k-1][i][j],dp[k-1][i-n_0][j-n_1]+1);
                }
            }
        }
        return dp[len-1][m][n];
    }
};
