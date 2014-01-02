/*
ID: piyushi1
LANG: C++
TASK: stamps
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
  freopen("stamps.in","r", stdin);
	freopen("stamps.out","w", stdout);
#endif
}

/* Global variable */
#define MAX 2000001
int K,N;
int dp[MAX];
int stamp[55];
/* End */

#define CLOCK
int main(){
#ifdef CLOCK
	int start = clock();
#endif
	fileInit();
	/* Main code begins*/
	K = SS();
	N = SS();
	FOR(i,0,N)
		stamp[i] = SS();

	//Here is a O(k*N*MAX) solution which goes out of memory and time both - http://ideone.com/xbzmx7

	// O(MAX*N)
	dp[0] = 0;
	FOR(i,1,MAX){
		dp[i] = INF;
		FOR(j,0,N){
			if((i-stamp[j])>=0){
				dp[i] = min(dp[i], dp[i-stamp[j]]+1);
			}
		}
	}

	int i;
	for(i=1; i< MAX; i++)
		if(dp[i]>K)
			break;
	cout<<i-1<<endl;

	/* Main code ends*/
#ifdef CLOCK
	int end = clock();
	cout<<endl<<((float)(end - start))/CLOCKS_PER_SEC;
#endif

	return 0;
}	
