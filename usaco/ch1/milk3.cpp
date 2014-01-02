/*
ID: piyushi1
LANG: C++
TASK: milk3
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
#define SS ({int x;scanf("%d",&x);x;})
#define mp make_pair
#define pb push_back


void fileInit(){
#ifdef DEBUG
	freopen("/Users/piyushm/Documents/workspace/usaco/usaco/src/input.txt","r", stdin);
#endif
#ifndef DEBUG
	freopen("milk3.in","r", stdin);
	freopen("milk3.out","w", stdout);
#endif
}

int visit[1<<17]; //we need the first 15 bits only
set<int> amount;
int A,B,C;


int formstate(int a, int b, int c){
	int init  = 31; int answer =0;
	answer = answer | (c & init);
	answer = answer | ( (b&init) << 5);
	answer = answer | ( (a&init) << 10);
	return answer;
}


void dfs( int state){

	if(visit[state]==1)
		return;
	visit[state]=1;

	//find milk in the three buckets
	const int a = (state>>10)&31;
	const int b = (state>>5)&31;
	const int c = (state)&31;

	if( a == 0) amount.insert(c); // Adding amount of c when a is zero

	if( a>0 ){  //a->b
		int  nb = ((a+b) > B)?B:a+b;
		dfs(formstate(a-(nb-b),nb,c));
		//a->c
		int nc = ((a+c) >C)? C: a+c;
		int x = formstate(a-(nc-c),b,nc);
		dfs(x);
	}

	if(b > 0){
		//b->c
		int nc = ((b+c) > C)?C:b+c;
		dfs(formstate(a,b-(nc-c),nc));
		//b->a
		int na = ((b+a) >A)?A:b+a;
		dfs(formstate(na,b-(na-a),c));
	}

	if( c > 0){
		//c->a
		int na = ((a+c) > A)?A:a+c;
		dfs(formstate(na,b,c-(na-a)));
		//c->b
		int nb = ((b+c) > B)?B:b+c;
		dfs(formstate(a,nb,c-(nb-b)));
	}
}



int main(){

	fileInit();

	memset(visit, 0, sizeof(visit));//initialize visited to 0
	A = SS; B = SS; C = SS;

	int a = 0; int b = 0; int c = C;
	int x = formstate(a,b,c);
	dfs(x);

	cout<<*amount.begin();
	set<int>::iterator it = amount.begin();   it++;
	for( ; it!=amount.end(); it++){
		cout<<" "<<*it;
	}

	cout<<endl;

	return 0;
}

