/*
ID: piyushi1
LANG: C++
TASK: inflate
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
  freopen("inflate.in","r", stdin);
	freopen("inflate.out","w", stdout);
#endif
}

/* Global variable */
#define MAX 10000
/* Global varible ends*/

//#define CLOCK


int main(){
#ifdef CLOCK
	int start = clock();
#endif
	fileInit();
	/* Main code begins*/
	
	vector<pair<int,int> > problems;
	int contestLen = SS();
	int problemNum = SS();
	FOR(i,0,problemNum){
		int x = SS();
		int y = SS();
		problems.pb(mp(x,y));
	}

	int dp[MAX+1];  fill(dp,0);

	FOR(i,0, problemNum){
		int points = problems[i].first;
		int time = problems[i].second;
		FOR(j,1,MAX+1){
			dp[j] = max(dp[j],dp[j-1]);
			if(((j-time) >=0)&&(((j-time)==0) || dp[j-time])){
				dp[j] = max( dp[j], dp[j-time]+ points);
			}
		}
	}
	cout<<dp[contestLen]<<endl;

	/* Main code ends*/
#ifdef CLOCK
	int end = clock();
	cout<<endl<<((float)(end - start))/CLOCKS_PER_SEC;
#endif

	return 0;
}
