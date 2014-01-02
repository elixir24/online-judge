/*
ID: piyushi1
LANG: C++
TASK: pprime
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
	freopen("pprime.in","r", stdin);
	freopen("pprime.out","w", stdout);
#endif
}


int p[100000];

void makeSieve(){
	memset(p,1,sizeof(p));
	for( int i=2; i*i < 100000;i++){
		if(p[i]!=0){
			for( int j=i+i; j<100000; j+=i)
				p[j] = 0;
		}
	}
}

bool isPrime( int x){
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

	int a = SS;
	int b = SS;
	set<int> sol;


	for(int d1 = 1; d1 <= 9; d1+= 2){
		for( int d2 = 0; d2 <= 9 ; d2++){
			for( int d3 = 0; d3 <= 9; d3++){
				for( int d4 = 0; d4 <= 9; d4++){

					int x = d1*1000000 + d2*100000 + d3*10000 + d4*1000 + d3*100 + d2*10 + d1;
					if( x>=a && x <=b)
						if(isPrime(x))
							sol.insert(x);

					x = d1*10000000 + d2*1000000 + d3*100000 + d4*10000 + d4*1000 + d3*100 + d2*10 + d1;
					if( x>=a && x <=b)
						if(isPrime(x))
							sol.insert(x);


					x = d1*10000 + d2*1000 + d3*100 + d2*10 + d1;
					if( x>=a && x <=b)
						if(isPrime(x))
							sol.insert(x);

					x = d1*100000 + d2*10000 + d3*1000 + d3*100 + d2*10+ d1;
					if( x>=a && x <=b)
						if(isPrime(x))
							sol.insert(x);

					x = d1*100 + d2*10 + d1;
					if( x>=a && x <=b)
						if(isPrime(x))
							sol.insert(x);

					x = d1*1000 + d2*100 + d2*10 + d1;
					if( x>=a && x <=b)
						if(isPrime(x))
							sol.insert(x);

					x = d1;
					if( x>=a && x <=b)
						if(isPrime(x))
							sol.insert(x);

					x = 10*d1 + d1;
					if( x>=a && x <=b)
						if(isPrime(x))
							sol.insert(x);

				}
			}
		}
	}

	for( set<int>::iterator iter = sol.begin(); iter!= sol.end(); iter++)
		printf("%d\n", *iter);

}

