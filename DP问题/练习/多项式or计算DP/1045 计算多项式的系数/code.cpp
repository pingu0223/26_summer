#include <iostream>
#include <vector>
using namespace std;
int con=10007;
int main(){
    int T;cin>>T;
    for(int z=0;z<T;z++){
        int a,b,K,n,m;
        cin>>a>>b>>K>>n>>m;
        a=a%con;b=b%con;
        vector<long long>DP(K+1,0);
        for(int i=0;i<K;i++){
            if(i==0) {DP[0]=b;DP[1]=a;continue;}
            for(int j=i+1;j>=0;j--){
                if(j==0) DP[j]=(DP[j]*b)%con;
                else DP[j]=((a*DP[j-1])%con+(b*DP[j])%con)%con;
            }
        }
        cout<<"case #"<<z<<":"<<'\n';
        if(K==0) cout<<1<<'\n';
        else cout<<DP[n]<<'\n';
    }
}
