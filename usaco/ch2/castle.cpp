/*
ID: piyushi1
LANG: C++
TASK: castle
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

inline int SS(){int x; scanf("%d",&x); return x;}

void fileInit(){
#ifdef DEBUG
  freopen("input.txt","r", stdin);
#endif
#ifndef DEBUG
	freopen("castle.in","r", stdin);
	freopen("castle.out","w", stdout);
#endif
}

int mazeInp [51][51];
vector<int> graph[3000];
int width, len;
map<int, int> n;
int component[3000];
int maxComp;
map<int,int> compCount;
int fx, fy;
char dir;

void consume(int x, int val){  
	vector<int> v;
	rep(i,4){
		if(!(val&(1<<i))){// if the bit is not set
			int neighbour = x + n[i];
			assert( neighbour > 0 );
			assert( neighbour < (len*width + 1));
			v.pb(neighbour);
		}
	}
	graph[x] = v;
}

void printGraph(){
	for(int i=1; i< len*width + 1 ; i++){
		cout<<i<<"->";
		for( int j=0; j<(int)graph[i].size();j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
}

void dfs(int node, int comp){
	 int visited = 1;
	 while(visited){
		visited = 0;
		for( int i=1; i< len*width+1; i++){
			if(component[i]== -1){
				component[i] = comp;
				for( int n = 0; n< (int)graph[i].size(); n++){
					if(component[graph[i][n]] == 0){
						component[graph[i][n]] = -1;
						visited++;
					}
				}
			}
		}
	 }
}

void findComponents(){
	int ctr=0;
	repab(i,1, len*width+1){
		if(component[i]==0){
			component[i] = -1;
			dfs(i, ++ctr);
		}
	}
}

void checkForMerge(int x, int y){
	int currentNode = (x-1)*width + y;
	int northNode = currentNode - width;
	int eastNode = currentNode + 1;

  //Only possible directions are north and east
	if(x!=1){//check north first sine it is higher in priority
		if( component[northNode]!= component[currentNode]){
			int freq = compCount[component[currentNode]] +  compCount[component[northNode]];
			if( freq > maxComp){
				maxComp = freq;
				fx = x;
				fy= y;
				dir = 'N';
			}
		}
	}

	if(y!= width){//check east
		if( component[eastNode]!= component[currentNode]){
			int freq = compCount[component[currentNode]] +  compCount[component[eastNode]];
			if( freq > maxComp){
				maxComp = freq;
				fx = x;
				fy= y;
				dir = 'E';
			}
		}
	}
}

int main(){

	fileInit();
	width= SS();len = SS();
	n[0] = -1;	n[1] = -width; n[2] = 1; n[3] = width;
	memset(component,0,sizeof(component));
	
	int ctr = 0;
	repab(i,1,len+1){	
		repab(j,1,width+1){
			int x = SS();
			consume(++ctr, x);
		}
	}

	findComponents();
	map<int, vector<int> > temp;
	for( int i=1; i< len*width+1;i++){// construct component map
		compCount[component[i]]++;	
		temp[component[i]].push_back(i);
	}
	
	int m = -1;
	for(map<int,int>::iterator it = compCount.begin(); it!= compCount.end(); it++)
		if( m < (it->second))
			m= it->second;

	for( int i = 1; i<=width; i++){ //Wemove from south to north and from west to east
		for( int j = len ; j >0; j--){
			checkForMerge(j,i);
		}
	}

	cout<<(int)compCount.size() <<endl<<m<<endl<<maxComp<<endl;
	cout<<fx<<" "<<fy<<" "<<dir<<endl;

}

