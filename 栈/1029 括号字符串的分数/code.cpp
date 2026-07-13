#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    stack<int>st;
    string s;
    cin>>s;
    int score=0;
    st.push(0);
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') st.push(0);
        else if(s[i]==')'){
            int x=st.top();
            st.pop();
            if(x==0) st.top()+=1;
            else st.top()+=2*x;
        }
    }
    cout<<st.top();
}
