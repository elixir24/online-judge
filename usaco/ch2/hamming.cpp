/*
ID: piyushi1
LANG: C++
TASK: hamming
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
	freopen("hamming.in","r", stdin);
	freopen("hamming.out","w", stdout);
#endif
}


int findHD(int x, int y, const int B){

	int z = x^y;
	int ans =0;
	rep(i,B){
		if(z&1)
			ans++;
		z=z>>1;
	}
	return ans;
}


int main(){
	fileInit();

	//cout<<findHD(15,3,3);
	int N = SS(); 
	int B = SS();
	int D = SS();

	int hashmap[1<<8];
	fill(hashmap,0);
	hashmap[0]=1;
	int cnt = 0;
	for(int i=1; i<(1<<B);i++){
		bool found = true;
		for(int j=0; j<(1<<B);j++){
			if((hashmap[j]==1)){
				int dis = findHD(i,j, B);
				if( dis < D){
					found = false;
					break;
				}
			}
		}
		if(found) {
			hashmap[i]=1;
			cnt++;
			if(cnt == N-1)
				break;
		}
	}

	/*for(int i =0; i < (1<<B); i++)
		if( hashmap[i]==1)
			cout<<i<<" ";*/
	vector<int> v;
	int ctr = 0;

	for(int i=0;i<(1<<B);i++){
		if(hashmap[i]==1)
			v.pb(i);
	}
	vector<int>b;
	rep(i,(int)v.size()){
		b.pb(v[i]);ctr++;
		if((ctr%10 == 0) || (ctr==N)){
			cout<<b[0];
			for(int k=1; k<(int)b.size();k++){
			cout<<" "<<b[k];
			}
			cout<<endl;
			b.clear();
		}
	}
}
