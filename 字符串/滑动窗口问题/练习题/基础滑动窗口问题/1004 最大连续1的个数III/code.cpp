class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero=0;
        int n=nums.size();
        if(n<=k) return n;
        
            int i=0,j=0;int count=0,max_count=0;
            while(j!=n){
                if(nums[j]==1){
                    j++;
                    count++;
                }
                else if(nums[j]==0){
                    if(k==zero){
                        max_count=max(count,max_count);
                        while(k==zero){
                            if(nums[i]==0) {zero--;count--;i++;}
                            else{count--;i++;}
                        }
                    }
                    count++;j++;zero++;
                }
            }
        
        max_count=max(count,max_count);
        return max_count;
    }
};
