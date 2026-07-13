class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> cnt;
        int n=fruits.size();
        int i=0,j=0;int max_count=0;int count=0;
        while(j!=n){
            //先处理
            int curr=fruits[j];
            auto it=cnt.find(curr);
            if(it==cnt.end()){
                cnt[curr]=1;
            }
            else cnt[curr]++;
            //再遍历
            while(cnt.size()>2){
                max_count=max(max_count,count);
                count--;
                cnt[fruits[i]]--;
                if(cnt[fruits[i]]==0) cnt.erase(fruits[i]);
                i++;
            }
            count++;j++;
        }
        max_count=max(count,max_count);
        return max_count;
        
    }
};
