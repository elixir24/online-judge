/*
ID: piyushi1
LANG: C++
TASK: money
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
  freopen("money.in","r", stdin);
  freopen("money.out","w", stdout);
#endif
}
int coins[30];
ll dp[30][11000];


int main(){

	fileInit();
	int v = SS();
	int n = SS();
	rep(i,v){
		int v = SS();
		coins[i]= v;
	}
	fill(dp,0);
	dp[0][0]=1;

	for( int coin = 1; coin <=v; coin++){
		for( int sum =0; sum <= 10000; sum++){
		   dp[coin][0]=1;// sum 0 is always possible with any coin count
		   int k = coins[coin-1];
		   dp[coin][sum]+= dp[coin-1][sum];
		   while( (sum+k) <=10000){
			dp[coin][sum+k]+= dp[coin-1][sum];
			k+=coins[coin-1];			
		   }
		}
	}

	cout<<dp[v][n]<<endl;
	return 0;
}

