/*
ID: piyushi1
LANG: C++
TASK: kimbits
 */
#include <stdio.h>
#include <iostream>
#include <memory.h>

typedef long long ll;
using namespace std;

int main(){
    freopen("kimbits.in","r", stdin);
    freopen("kimbits.out","w", stdout);
    int x;
    ll dp[32][32];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i < 32; i++) {dp[0][i] = 1; dp[i][0] = 1; }
    for( int i = 1; i< 32; i++){
        for( int j = 1; j < 32; j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }

    ll n,l,i;
    cin>>n>>l>>i;
    string ans;
    while(n>0){
        if(i > dp[n-1][l]){
            ans += '1';
            i-= dp[n-1][l];
            n--; l--;
        }else{
            ans += '0';
            n--;
        }
    }
    cout<<ans<<endl;
    return 0;
}        
