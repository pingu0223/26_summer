#include <set> //set可以过滤重复的
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;
set<string>sett;
void find_str(string s){
    int n=s.size();
    int pos=0;
    for(int i=0;i<n;i++){
        if(s[i]==','||s[i]=='.'||s[i]=='!'||s[i]=='?'||s[i]==' '){
            if(pos==i){pos++;continue;}
            sett.insert(s.substr(pos,i-pos));
            pos=i+1;
        }
    }
    if(pos<n) sett.insert(s.substr(pos));
}
int main(){
    int T;cin>>T;cin.ignore();
    for(int i=0;i<T;i++){
    sett.clear();
    string s1;
    getline(cin,s1);
    find_str(s1);
    cout<<"case #"<<i<<":"<<'\n';
    for(int j=0;j<sett.size();j++){
        auto it=next(sett.begin(),j);
        cout<<*it;
        if(j!=sett.size()-1) cout<<" ";
        else cout<<'\n';
    }
    }
}
