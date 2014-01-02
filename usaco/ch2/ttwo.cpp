/*
ID: piyushi1
LANG: C++
TASK: ttwo
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
#define foreach(i,a) for(typeof((a).begin()) i=(a).begin();i!=(a).end();i++)
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
  freopen("ttwo.in","r", stdin);
	freopen("ttwo.out","w", stdout);
#endif
}

/* Global variable */

struct node{
	pair<int,int> block;
	int dir;
};

// 0 - N, 1-E, 2-S, 3-W
int freex[4] = {-1,0,1,0};
int freey[4] = {0,1,0,-1};
int dirBlock[4] = {1,2,3,0};
char forest[12][12];
int t;
node farmer, cow;
int visited[11][11][4][11][11][4];

bool equal( node a , node b){
	return ((a.block.first==b.block.first) && (a.block.second==b.block.second));
}

node move(const node a){
	node fin = a; //we will return this node
	int dir= a.dir;
	int x = a.block.first + freex[dir];
	int y = a.block.second + freey[dir];
	
	if( (x>10)||(x<1)||(y<1)||(y>10)||(forest[x][y]=='*')){//this means we have to rotate
		dir = dirBlock[dir];
		fin.dir = dir;
	}else{
		fin.block.first = x;
		fin.block.second = y;
	}

	return fin;
}

void solve( node fcurr, node ccurr){

	visited[fcurr.block.first][fcurr.block.second][fcurr.dir][ccurr.block.first][ccurr.block.second][ccurr.dir] = 1;
	
	if( equal(fcurr,ccurr)){
		return;
	}

	fcurr = move(fcurr);
	ccurr = move(ccurr);
	if( visited[fcurr.block.first][fcurr.block.second][fcurr.dir][ccurr.block.first][ccurr.block.second][ccurr.dir] == 1){
		t =0;
		return;
	}
	
	++t;
	solve(fcurr,ccurr);
	return;	
}

int main(){

	fileInit();
	fill(visited,0);
	farmer.dir = cow.dir = 0;
	repab(i,1,11){
		repab(j,1,11){
			char x ; cin>>x;
			forest[i][j]= x;
			if( x == 'C')	cow.block = mp(i,j);
			if( x == 'F')	farmer.block = mp(i,j);
		}
	}
	 solve(farmer, cow);
	 cout<<t<<endl;
	return 0;
}

