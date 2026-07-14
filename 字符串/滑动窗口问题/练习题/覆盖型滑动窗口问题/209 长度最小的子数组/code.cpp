class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        long long sum=0;int min_len=n+1;int index=-1;int len=0;
        int i=0;int j=0;
        while(j<n){
            cout<<"i:"<<i<<"j:"<<j<<'\n';
            sum+=nums[j];len++;
                while(sum>=target){
                    
                     if(len<min_len){
                        index=i;
                        min_len=len;
                     }
                     sum-=nums[i];
                     i++;len--;
                }       
                j++;
        }
        if(sum>=target){
            if(len<min_len){
                        index=i;
                        min_len=len;
                     }
        }
        if(min_len==n+1) min_len=0;
        return min_len;
    }
};
