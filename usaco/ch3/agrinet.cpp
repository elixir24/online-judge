/*
ID: piyushi1
LANG: C++
TASK: agrinet
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
#include"graph.h" // https://github.com/codetrash/algorithms/blob/master/algorithms/src/graph/graph.h

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
  freopen("agrinet.in","r", stdin);
	freopen("agrinet.out","w", stdout);
#endif
}

/* Global variable */
int N;
graph g(110);
#define NODE 105
/* Global varible ends*/

//#define CLOCK

int calMinSpanningTree(){
	int d[NODE]; FOR(i,0, NODE) d[i] = INF;
	int intree[NODE]; fill(intree,0);

	int minCost = 0;
	//Add first node
	int size = 1;
	intree[1] = 1;
	vector<pair<int, int> > edges = g.getEdgeListForVertex(1);
	FOR(i,0, edges.size()){
		d[edges[i].first] = edges[i].second;
	}

	while( size < N){
		//find the closest node not in the tree
		int min = INF;
		int vertex ;
		FOR(i,1,N+1){
			if( !intree[i] && (d[i]< min)){
				min = d[i]; vertex = i;
			}
		}
		assert(min!=INF);//assertion failed here means that the graph is not connected
		minCost+=min;
		intree[vertex] = 1;
		size++;
		vector<pair<int, int> > edges = g.getEdgeListForVertex(vertex);
		FOR(i,0, edges.size()){
			int n = edges[i].first;
			if( !intree[n] && (d[n] > edges[i].second)){
				d[n] = edges[i].second;
			}
		}
	}

	return minCost;
}

int main(){
#ifdef CLOCK
	int start = clock();
#endif
	fileInit();
	/* Main code begins*/
	N = SS();
	FOR(i,0, N){
		FOR(j,0,N){
			int x = SS();
			if(x)g.addEdge(i+1,j+1,x);
		}
	}
	
	cout<<calMinSpanningTree()<<endl;
	/* Main code ends*/
#ifdef CLOCK
	int end = clock();
	cout<<endl<<((float)(end - start))/CLOCKS_PER_SEC;
#endif

	return 0;
}
