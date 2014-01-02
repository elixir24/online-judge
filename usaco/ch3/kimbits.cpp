/*
ID: piyushi1
LANG: C++
TASK: kimbits
 */
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
#include<memory.h>
#include<queue>
#include<set>
#include<assert.h>
#include<time.h>
#include<math.h>
#include<cstdlib>
//#include"graph.h" // https://github.com/codetrash/algorithms/blob/master/algorithms/src/graph/graph.h

using namespace std;

typedef vector<int>::iterator vit;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef vector<int> vi;
typedef long long ll;

#define rep(i,a) repab(i,0,a)
#define repab(i,a,b) repabc(i,a,b,1)
#define repabc(i,a,b,c) for(int i=a;i<b;i+=c)
#define foreach(i,a) for(typeof((a).begin()) i=(a).begin();i!=(a).end();i++)
#define FOR(i,a,b) for(int i = a; i<b; i++)
#define mod(x) ((x>0)?x:(-x))
#define SI(t) scanf("%d",&t);
#define SL(t) scanf("%lld",&t);
//#define SS ({int x;scanf("%d",&x);x;})
#define mp make_pair
#define pb push_back
#define fill(a,i) (memset(a,i, sizeof(a)))
inline int SS(){int x; scanf("%d",&x); return x;}
#define EPS 10e-7
#define INF 1000000000

void fileInit(){
#ifdef DEBUG
  freopen("input.txt","r", stdin);
#endif
#ifndef DEBUG
  freopen("kimbits.in","r", stdin);
	freopen("kimbits.out","w", stdout);
#endif
}

/* Global variable */
ll N,L,I;
ll dp[32][32];
/* End */

int count1(ll x){
	int ans=0;
	while(x){
		if(x%2==1)	
			ans++;
		x/=2;
	}
	return ans;
}

inline string construct( ll i, int len){
	string ans;
	while(i){
		if(i%2==1)
			ans+='1';
		else
			ans+='0';
		i/=2;
	}
	int n= ans.length();
	FOR(i,0, len-n)
		ans+='0';
	reverse(ans.begin(),ans.end());
	return ans;
}

string solve(ll len, ll ones, ll num, ll k){
	//base case
	if(k==0){
		if(num==1){
			return "0";
		}
		else{ 
			return "1";
		}
	}
	
	ll local = 0;
	ll i;
	for(i=0; i<(1<<(len-k));i++){
		local+= dp[k][ones-count1(i)];
		if(local >= num){
			local -= dp[k][ones-count1(i)];
			break;
		}
	}
	
	return construct(i, len-k)+ solve(k,ones-count1(i), num-local, k/2);
}
//#define CLOCK
int main(){
#ifdef CLOCK
	int start = clock();
#endif
	fileInit();
	/* Main code begins*/
	SL(N); SL(L); SL(I);
	dp[1][0] = 1;
	dp[1][1] = 2;
	FOR(i,2,32) dp[1][i]=2;
	for(int i=2; i <=16; i=i*2){
		for( int j=0; j<32; j++){
			if(j>i){
				dp[i][j] = dp[i][i];
				continue;
			}
			int k = i/2;
			for( int kk = 0;kk < (1<<k); kk++){
				if(j>=count1(kk)){
					dp[i][j]+= dp[k][j-count1(kk)]; 
				}
			} 
		}
	}

	int k;
	for(k=1; k <=16; k=k*2)
		if(k>N)
			break;
	cout<<solve(N,L,I,k/2)<<endl;

	/* Main code ends*/
#ifdef CLOCK
	int end = clock();
	cout<<endl<<((float)(end - start))/CLOCKS_PER_SEC;
#endif
	return 0;
}	
