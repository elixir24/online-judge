/*
ID: piyushi1
LANG: C++
TASK: fracdec
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
#define fill(a,i) (memset(a,i, sizeof(a)))
inline int SS(){int x; scanf("%d",&x); return x;}
#define EPS 10e-7
#define INF 100000000

void fileInit(){
#ifdef DEBUG
  freopen("input.txt","r", stdin);
#endif
#ifndef DEBUG
  freopen("fracdec.in","r", stdin);
	freopen("fracdec.out","w", stdout);
#endif
}

/* Global variable */

/* Global varible ends*/

//#define CLOCK

ostringstream s;
void print(){
	string str = s.str();
	rep(i,str.length()){
		if(i && (i %76 == 0)) cout<<endl;
		cout<<str[i];
	}
	cout<<endl;
}

int main(){
#ifdef CLOCK
	int start = clock();
#endif
	fileInit();
	/* Main code begins*/

	int N ; scanf("%d",&N);
	int D ; scanf("%d",&D);
	if( N % D == 0){
		printf("%.1lf\n", (double)N/D);
		return 0;
	}

	int q =0;
	while ( N > D) {
		q++; N-=D;
	}

	int rem = N%D;
	int hash[100005] ; fill(hash,-1);
	
	while(1){
		if(rem ==0) break;
		if( hash[rem]!= -1){
			break;
		}
		int q = (10*rem) / D;
		hash[rem] = q;
		rem = (10*rem) - (q*D);
	}

	//ostringstream s;
	s<<q;
	s<<".";

	if(rem ==0){
		int r = N%D;
		while(r){
			q = (10*r)/D;
			s<<q;
			r = (10*r) - (q*D);
		}
		print();
		return 0;
	}
	int r = N%D;
	while(r!= rem){
		q = (10*r)/D;
		s<<q;
		r = (10*r) - (q*D);
	}

	q =	(10*r)/D;
	s<<"(";
	s<<q;
	r = (10*r) - (q*D);
	while(r!= rem){
		q = (10*r)/D;
		s<<q;
		r = (10*r) - (q*D);
	}
	s<<")";
	print();

	/* Main code ends*/
#ifdef CLOCK
	int end = clock();
	cout<<endl<<((float)(end - start))/CLOCKS_PER_SEC;
#endif

	return 0;
}
