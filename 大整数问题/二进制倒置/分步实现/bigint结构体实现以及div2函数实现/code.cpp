#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct bigint{
    int cnt;//位数
    int v[101];
};
bigint convert(string& s){
    bigint a{0,{0}};
    a.cnt=s.size();
    int j=0;
    for(int i=s.size()-1;i>=0;i--){
        a.v[j]=s[i]-'0';
        j++;
    }
    return a;
}
bigint Div2(bigint& b){
    if(b.cnt==0) return b;int t=0;//t为上一位余数
    for(int i=b.cnt-1;i>=0;i--){
        int temp=t*10+b.v[i];//这一位要除的：上一位余数*10+当前位
        t=temp%2;//更新当前位余数
        b.v[i]=temp/2;//更新
    }
    for(int i=b.cnt-1;i>=0;i--){
        if(b.v[i]==0) b.cnt--;
        else break;
    }
    return b;
}
void output(bigint& b){
    for(int i=b.cnt-1;i>=0;i--){
        cout<<b.v[i];
    }
    cout<<'\n';
}
int main(){
    string s;
    cin>>s;
    //先转换成大整数
    bigint s_big=convert(s);
    s_big=Div2(s_big);
    output(s_big);
}
