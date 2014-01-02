/*
ID: piyushi1
LANG: C++
TASK: comehome
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
#define mod(x) ((x>0)?x:(-x))
//#define SS ({int x;scanf("%d",&x);x;})
#define mp make_pair
#define pb push_back
#define fill(a,i) memset(a,i, sizeof(a));
inline int SS(){int x; scanf("%d",&x); return x;}
#define EPS 10e-7
#define INF 100000000

void fileInit(){
#ifdef DEBUG
  freopen("input.txt","r", stdin);
#endif
#ifndef DEBUG
	freopen("comehome.in","r", stdin);
	freopen("comehome.out","w", stdout);
#endif
}

/* Global variable */
#define NODE 200
graph g(20000);
int d[NODE]; 
/* Global varible ends*/

void dijskta( int source){

	vector<int> nodes = g.getVertexList();
	rep(i,NODE) d[i] = INF;
	int visited[NODE]; fill(visited,0);
	d[source] = 0;
	rep(k, nodes.size()){
		int min = INF;
		int vertex;	
		rep(j, nodes.size()){
			if(!visited[nodes[j]] && (d[nodes[j]] < min)){
				min = d[nodes[j]];
				vertex = nodes[j];
			}
		}
		visited[vertex] = 1;
		vector<pair<int,int> > edges = g.getEdgeListForVertex(vertex);
		rep(i, (int)edges.size()){
			pair<int,int> edge = edges[i];
			if(d[edge.first] > (d[vertex] + edge.second)){
				d[edge.first ] = d[vertex] + edge.second;
			}
		}
	}
}

//#define CLOCK
int main(){
#ifdef CLOCK
	int start = clock();
#endif
	fileInit();
	/* Main code begins*/
	int n = SS();
	vector<int> cowSource;
	//getchar();
	rep(i,n){
		char ch ; scanf("%*[ \n\t]%c", &ch);
		char ch1; scanf("%*[ \n\t]%c", &ch1);
		int w = SS();
		g.addEdge( ch -'A'+1, ch1 - 'A' +1, w);
		g.addEdge( ch1 -'A'+1, ch - 'A' +1, w);
		if( ch!='Z' && ch < 92) cowSource.pb(ch-'A'+1);
		if( ch1!='Z' && ch1 < 92) cowSource.pb(ch1-'A'+1);
	}

	//g.printGraph();
	dijskta('Z' - 'A' + 1);
	int min = INF;
	int answer = 0 ;
	rep(i, (int)cowSource.size()){
		if( min > d[cowSource[i]]){
			min = d[cowSource[i]];
			answer = cowSource[i];
		} 
	}

	cout<<(char)(answer+'A'-1)<<" "<<min<<endl;
	/* Main code ends*/
#ifdef CLOCK
	int end = clock();
	cout<<endl<<((float)(end - start))/CLOCKS_PER_SEC;
#endif

	return 0;
}
