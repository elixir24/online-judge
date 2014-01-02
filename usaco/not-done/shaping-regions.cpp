/*
ID: piyushi1
LANG: C++
TASK: rect1
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
  freopen("rect1.in","r", stdin);
	freopen("rect1.out","w", stdout);
#endif
}

/* Global variable */
struct point{
	int x; 
	int y;
	
	point(){
	}
	point( int x1, int y1){
		x = x1; y = y1;
	}

}; typedef struct point point;

struct rec{
	point lb;
	point rt;
	int color;

	rec(int x1 , int y1, int x2, int y2, int c){
		lb.x = x1; lb.y = y1;
		rt.x = x2; rt.y = y2;
		color = c;
	}
};	typedef struct rec rec;

int X,Y,N;
/* End */

bool intersect(const rec a, const rec b){
	if( (b.rt.x < a.lb.x) || (b.lb.x > a.rt.x) || (b.lb.y > a.rt.y) || (b.rt.x < a.lb.y))
		return false;
	return true;
}

bool isInside( point p, rec c){
	if((p.x >= c.lb.x) && (p.x<= c.rt.x) && (p.y >= c.lb.y) && (p.y <= c.rt.y))
		return true;
	return false;
}
void solve(rec rnew, vector<rec>&rectangles , int index){
	rec split = rectangles[index];
	rectangles.erase(rectangles.begin()+index);
	rnew.lb.x = max(split.lb.x, rnew.lb.x);
	rnew.lb.y = max(split.lb.y, rnew.lb.y);
	rnew.rt.x = min(split.rt.x, rnew.rt.x);
	rnew.rt.y = min(split.rt.y, rnew.rt.y);
	rectangles.pb(rnew);

}

//#define CLOCK
int main(){
#ifdef CLOCK
	int start = clock();
#endif
	fileInit();
	/* Main code begins*/
	X = SS();
	Y = SS();
	N = SS();
	rec sheet(0,0,N-1,N-1,1);
	vector<rec> rectangles;
	rectangles.pb(sheet);
	FOR(i,0,N){
		rec r(SS(),SS(),SS()-1,SS()-1,SS());
		FOR(j,0,(int)rectangles.size()){
			if(intersect(r, rectangles[j])){
				solve(r, rectangles, j);
			}
		}
	}

	/* Main code ends*/
#ifdef CLOCK
	int end = clock();
	cout<<endl<<((float)(end - start))/CLOCKS_PER_SEC;
#endif

	return 0;
}
