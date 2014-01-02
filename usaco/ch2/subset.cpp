/*
ID: piyushi1
LANG: C++
TASK: subset
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

using namespace std;

typedef vector<int>::iterator vit;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef vector<int> vi;
typedef long long ll;

#define rep(i,a) repab(i,0,a)
#define repab(i,a,b) repabc(i,a,b,1)
#define repabc(i,a,b,c) for(int i=a;i<b;i+=c)
#define foreach(i,a) for((typeof(a).begin()) i=(a).begin();i!=(a).end();i++)
#define mod(x) ((x>0)?x:(-x))
//#define SS ({int x;scanf("%d",&x);x;})
#define mp make_pair
#define pb push_back
#define fill(a,i) memset(a,i, sizeof(a));

inline int SS(){int x; scanf("%d",&x); return x;}

void fileInit(){
#ifdef DEBUG
  freopen("input.txt","r", stdin);
#endif
#ifndef DEBUG
  freopen("subset.in","r", stdin);
	freopen("subset.out","w", stdout);
#endif
}


int main(){
	fileInit();
	
	int n = SS();
	int sum = n*(n+1)/2;

	if( sum%2 == 1){
		cout<<0<<endl;
		return 0;
	}
	
	ll dp[50][2000];
	fill(dp,0);
	dp[0][0] = 1;
	
	for( int i=1; i<=n;i++){
		for( int k=0; k<=sum; k++){
			dp[i][k] = dp[i-1][k];
		}
		for( int k=0; k+i <=sum; k++){
			dp[i][k+i]+= dp[i-1][k];
		}
	}
	cout<<dp[n][sum/2]/2<<endl;
}
