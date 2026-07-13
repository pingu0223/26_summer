#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main(){
    unordered_map<char,int> mp;
    string c;
    cin>>c;
    int n=c.size();
    if(n==1) cout<<c;
    else{
        int i=0,j=0,max_len=0,curr_len=0;
        int i_index=0;
        while(j!=n){
            auto it=mp.find(c[j]);
            if(it==mp.end()||it->second<i){
                //这种情况说明没有重复;
                curr_len++;
                mp[c[j]]=j;
                j++;
            }
            else{
                if(curr_len>max_len){
                    i_index=i;
                }
                max_len=max(curr_len,max_len);
                
                i=mp[c[j]]+1;
                mp[c[j]]=j;
                curr_len=j-i+1;
                j++;
            }
        }
        if(curr_len>max_len){
                    i_index=i;
                }
        max_len=max(max_len,curr_len);
        
        cout<<c.substr(i_index,max_len);
    }

}
