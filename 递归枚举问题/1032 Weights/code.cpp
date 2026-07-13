#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int n=0;vector<int>L;
void dfs(int index,int value,vector<int>& can){
    if(index==n) {
        if(value<=0) return;
        if(find(can.begin(),can.end(),value)!=can.end()) return; 
        can.push_back(value);
        return;
    }
    dfs(index+1,value+L[index],can);
    dfs(index+1,value-L[index],can);
    dfs(index+1,value,can);
}
int main(){
    vector<int> can_calculate;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        int value;cin>>value;
        L.push_back(value);
        sum+=value;
    }
    dfs(0,0,can_calculate);
    sort(can_calculate.begin(),can_calculate.end());
    int i=0;
    for(int target=1;target<=sum;target++){
        if(target<can_calculate[i]) cout<<0;
        else if(target==can_calculate[i]){
            cout<<1;i++;
        }
        else i++;
    }

}
