/*
ID: piyushi1
LANG: C++
TASK: fact4
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
  freopen("fact4.in","r", stdin);
	freopen("fact4.out","w", stdout);
#endif
}

/* Global variable */
int N;
/* End */

//#define CLOCK
int main(){
#ifdef CLOCK
	int start = clock();
#endif
	fileInit();
	/* Main code begins*/
	SI(N);
	int c5 = 0;
	int c2 = 0;
	int ans = 1;
	FOR(k,2,N+1){
		int i = k;
		while(1){
			if(i && i%2==0){
				c2++;
				i/=2;
			}else
				break;
		}

		while(1){
			if(i && i%5==0){
				c5++;
				i/=5;
			}else
				break;
		}
		if(i){
			ans = (ans * i)%10;
		}
	}

	FOR(i,0, c2-c5)
		ans = (ans*2)%10;

	cout<<ans<<endl;

	/* Main code ends*/
#ifdef CLOCK
	int end = clock();
	cout<<endl<<((float)(end - start))/CLOCKS_PER_SEC;
#endif

	return 0;
}	
