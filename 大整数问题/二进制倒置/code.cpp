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
    for(int i=b.cnt-1;i>0;i--){
        if(b.v[i]==0) b.cnt--;
        else break;
    }
    if(b.cnt==0){
        b.cnt++;
    }
    return b;
}
string ten2two(bigint& b){
    if(b.cnt==0&&b.v[0]==0) return"0" ;   string result="";
    while(b.cnt>1||b.v[0]!=0){
        result=(char)(b.v[0]%2+'0') + result;
        b=Div2(b);
    }
    return result;
}
void output(bigint& b){
    for(int i=b.cnt-1;i>=0;i--){
        cout<<b.v[i];
    }
    cout<<'\n';
}
string reverse(string& s){
    if(s.size()==0||s.size()==1) return s;
    else{
        int i=0,j=s.size()-1;
        while(i<j){
            int t=s[i];
            s[i]=s[j];
            s[j]=t;
            i++;j--;
        }
    }
    return s;
}
string mult2(string& b){
    int carry=0;
    for(int z=b.size()-1;z>=0;z--){
        int temp=b[z]-'0';
        temp=temp*2+carry;
        carry=0;
        if(temp>=10) {temp-=10;carry=1;}
        b[z]=(char)(temp+'0');
    }
    if(carry==1) b='1'+b;
    return b;
}
string add1(string& b){
    if(b.size()==0) return "1";int carry=1;
    for(int z=b.size()-1;z>=0;z--){
        int value=b[z]-'0'+carry;carry=0;
        if(value>=10){value-=10;carry=1;}
        b[z]=(char)value+'0';
        if(carry==0) break;
    }
    if(carry==1) b="1"+b;
    return b;
}
string two2ten(string& s){
    if(s=="") return "0";
    string result="";
    for(int i=0;i<s.size();i++){
        result=mult2(result);
        if(s[i]=='1') result=add1(result);
    }
    return result;
}
int main(){
    int T;
    cin>>T;
    for(int z=0;z<T;z++){
    string s;
    cin>>s;
    //先转换成大整数
    bigint s_big=convert(s);
    string s_new=ten2two(s_big);
    s_new=reverse(s_new);
    int n=s_new.size();

    //cout<<s_new<<'\n';
    cout<<"case #"<<z<<":"<<'\n';
    cout<<two2ten(s_new)<<'\n';
}
}
