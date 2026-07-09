class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        int DP[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(obstacleGrid[i][j]==1) {DP[i][j]=0;continue;}// 最开始错在这里了，因为我想着应该起始点不是障碍物吧，没想到hhh
                if(i==0&&j==0) {DP[i][j]=1;continue;}
                if(i==0){
                    DP[i][j]=DP[i][j-1];
                }
                else if(j==0) DP[i][j]=DP[i-1][j];
                else DP[i][j]=DP[i-1][j]+DP[i][j-1];
                
            }
        }
        return DP[m-1][n-1];
    }
};
