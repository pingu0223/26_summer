#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> Passage;
    unordered_map<string,int> mp;
    vector<bool> is_visited(n,false);
    vector<int> cnt(n,0);
    for(int i=0;i<n;i++){
        string t;cin>>t;
        mp[t]=i;
    }
    int m;cin>>m;int total=0;
    for(int j=0;j<m;j++){
        string b;cin>>b;
        auto it=mp.find(b);
        if(it==mp.end()) Passage.push_back(-1);
        else{
            int index=mp[b];
            if(!is_visited[index]){is_visited[index]=true;total++;}
            Passage.push_back(index);
        }
    }
    int i=0,j=0;int len=0,min_len=m+1;int nums=0;
    while(j<m){

        int index=Passage[j];
        if(index==-1){len++;j++;continue;}
        if(cnt[index]==0){
            nums++;cnt[index]++;
        }
        else{
            cnt[index]++;
        }
        len++;j++;
        while(nums==total){
            min_len=min(len,min_len);
            int i_dex=Passage[i];
            if(i_dex==-1) {len--;i++;continue;}
            cnt[i_dex]--;
            if(cnt[i_dex]==0)nums--;
            len--;i++;
        }
    }
    cout<<total<<'\n';
    cout<<min_len<<'\n';

}
