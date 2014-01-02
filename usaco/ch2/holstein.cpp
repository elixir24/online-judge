/*
ID: piyushi1
LANG: C++
TASK: holstein
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
	freopen("holstein.in","r", stdin);
	freopen("holstein.out","w", stdout);
#endif
}

int vitnum;
int requirement[25];
int feednum;
int feed[15][25];
int visited[1<<16];

struct NODE{
	int vit[25];
	int scoops;
	int mask;
};
typedef struct NODE node;

bool check(node v){
	bool ret = true;
	rep(i,vitnum)
		if(v.vit[i] >0 )
			ret = false;
	return ret;
}

node bfs( node init){

	queue<node> q;
	q.push(init);
	while(!q.empty()){
		node v = q.front(); q.pop();
		rep(i,feednum){
			if((v.mask&(1<<i)) == 0){//this check for is avoiding using the same feed again
				if( visited[v.mask|(1<<i)]==0){//we have not seen this combination before
					v.mask =v.mask|(1<<i) ; visited[v.mask]=1;
					v.scoops++;
					assert(v.scoops < 16);
					rep(k,vitnum){
						v.vit[k]-= feed[i][k];
					}
				 if( check(v))
					 return v;
				 q.push(v);
				 //Remove this feed now
				 v.scoops--;
				 v.mask = v.mask&(~(1<<i));
				 rep(k,vitnum){
						v.vit[k]+= feed[i][k];
					}
				}
			}
		}
	}
}

int main(){
	fileInit();
	fill(visited,0);
	vitnum = SS();
	node init ; init.mask = 0; init.scoops = 0;
	rep(i,vitnum) init.vit[i] = SS();
	feednum = SS();
	rep(i,feednum)
		rep(j,vitnum)
			feed[i][j] = SS();

	node ans = bfs(init);
	cout<<ans.scoops;
	int m =0;
	while(ans.scoops > 0 ){
	 	if((ans.mask&(1<<m))!=0)
			{cout<<" "<<m+1; ans.scoops--;}
		m++;
	}
	cout<<endl;
}
