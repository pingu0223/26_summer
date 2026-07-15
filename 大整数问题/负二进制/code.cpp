#include <iostream>
#include <vector>
using namespace std;
struct BIGINT{
    int cnt;
    int v[101];
    int sign;
};
BIGINT convert(string& s){
    BIGINT a{0,{0},1};
    if(s.size()==0) {a.cnt=1;a.v[0]=0;}
    else{
        a.cnt=s.size();int j=0;
        for(int i=s.size()-1;i>=0;i--){
            a.v[j]=s[i]-'0';j++;
        }
    }
    return a;
}
BIGINT Div2(BIGINT& x){
    int t=0;
    if(x.cnt==0){x.cnt++;x.v[0]=0;}
    for(int i=x.cnt-1;i>=0;i--){
        int value=t*10+x.v[i];
        x.v[i]=value/2;
        t=value%2;
    }
    //再把前导0去除
    for(int i=x.cnt-1;i>=0;i--){
        if(x.v[i]==0) x.cnt--;
        else break;
    }
    //去除0的时候要考虑补药减完了
    if(x.cnt==0) x.cnt++;
    return x;
}
BIGINT add1(BIGINT& x){
    if(x.cnt==0) {x.v[0]=1;x.cnt++;}
    else{
        int carry=1;
        for(int i=0;i<x.cnt;i++){
            x.v[i]++;carry=0;
            if(x.v[i]>=10){x.v[i]-=10;carry=1;}
            else break;
        }
        if(carry==1){x.v[x.cnt]=1;x.cnt++;}
    }
    return x;
}
string ten2negativetwo(BIGINT& x){
    string result="";
    if(x.cnt==0||(x.cnt==1&&x.v[0]==0)) return "0";
    while(x.cnt!=1||x.v[0]!=0){
        int rest=x.v[0]%2;
        x=Div2(x);
        if(x.sign==-1&&rest==1) {
            x=add1(x);
        }
        x.sign=-x.sign;
        result=(char)(rest+'0')+result;
    }
    return result;
}
int main(){
    string n;
    cin>>n;
    //转换与正负值判断^^
    bool is_negative=false;
    if(n[0]=='-') {is_negative=true;n=n.substr(1);}
    BIGINT a=convert(n);if(is_negative) a.sign=-1;
    cout<<ten2negativetwo(a);
}
