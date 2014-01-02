/*
ID: piyushi1
LANG: C++
TASK: frac1
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
	freopen("frac1.in","r", stdin);
	freopen("frac1.out","w", stdout);
#endif
}

int primes[]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79};
struct fraction{
	int num; int den;
	void reduce(){//this can be done through GCD as well
		rep(i,22){
			while((num%primes[i] == 0) && (den%primes[i]== 0)){
				num/=primes[i]; den/=primes[i];
			}
		}
	}

	void print(){cout<<num<<"/"<<den<<endl;}
};

int mat[170][170];
typedef struct fraction frac;
vector<frac> list;

bool comp( frac a , frac b){
	return (a.num*b.den < b.num*a.den);
}

int main(){
	fileInit();
	memset(mat,0, sizeof(mat));
	int n = SS();
	frac f ; f.num = f.den =1;
	list.pb(f);
	f.num = 0; f.den = 1;
	list.push_back(f);

	for( int i = 1; i<=n; i++){
		for(int j= i-1; j>0;j--){
			frac x;
			x.den = i; x.num = j;
			x.reduce();
			if(mat[x.num][x.den] == 0)
			{list.pb(x); mat[x.num][x.den]=1;}
		}
	}
	sort(list.begin(), list.end(),comp);
	for( int i=0; i< (int)list.size();i++){
		list[i].print();
	}

}
