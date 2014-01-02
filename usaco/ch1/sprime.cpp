/*
ID: piyushi1
LANG: C++
TASK: sprime
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
#define SS ({int x;scanf("%d",&x);x;})
#define mp make_pair
#define pb push_back


void fileInit(){
#ifdef DEBUG
	freopen("/Users/piyushm/Documents/workspace/usaco/usaco/src/input.txt","r", stdin);
#endif
#ifndef DEBUG
	freopen("sprime.in","r", stdin);
	freopen("sprime.out","w", stdout);
#endif
}

int p[100000];

void makeSieve(){
	memset(p,1,sizeof(p));

	p[1] = p[0]= 0;
	for( int i=2; i*i < 100000;i++){
		if(p[i]!=0){
			for( int j=i+i; j<100000; j+=i)
				p[j] = 0;
		}
	}
}

bool isPrime( int x){
	if( x ==0 || x ==1)
		return false;
	for( int i=2; i*i<=x;i++){
		if(p[i]!=0)//i is prime
			if(x%i ==0)
				return false;
	}
	return true;
}


int main(){

	fileInit();
	makeSieve();
	int n = SS;

	queue< pair<int, int> > q;
	for( int i=2; i<=7; i++)
		if( isPrime(i))
			q.push(mp(i,1));

	while(!q.empty()){
		pair<int,int> ele = q.front();
		q.pop();
		if(isPrime(ele.first)){
			if(ele.second == n){
				printf("%d\n", ele.first);
			}else{
				for( int i=1; (i<=9); i+=2){
				q.push(mp(ele.first*10 + i, ele.second+1));
				}
			}
		}
	}
}

