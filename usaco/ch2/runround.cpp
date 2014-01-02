/*
ID: piyushi1
LANG: C++
TASK: runround
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
  freopen("runround.in","r", stdin);
	freopen("runround.out","w", stdout);
#endif
}

bool isRunAround( int m){

	int freq[10];
	fill(freq,0);
	ostringstream s;
	s<<m;
	string str = s.str();
	int len = str.length();
	int currPos = 0 ;
	int currVal = str[currPos] - '0';
	for( int i=0;i<len; i++){
		currPos = (currPos + currVal)%len;
		currVal = str[currPos] - '0';
		freq[currVal]++;

		if( currVal == 0)
			return false;
		if( freq[currVal] > 1)
			return false;
	}
	return true;
}

int main(){
	fileInit();
	
	int m = SS();

	while(1){
		if(isRunAround(++m))
		{cout<<m<<endl;
			return 0;
		}
		//m++;
	}

}
