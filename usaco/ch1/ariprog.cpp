/*
ID: piyushi1
LANG: C++
TASK: ariprog
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
	freopen("ariprog.in","r", stdin);
	freopen("ariprog.out","w", stdout);
#endif
}


int main(){

	fileInit();
	int n= SS;  //sequence length
	int m = SS;  // max value of p,q

	int bisquares[125004];
	memset(bisquares,0, sizeof(bisquares));
	for( int i=0; i<=m; i++){
		for(int j= 0; j<= m; j++){
			bisquares[i*i + j*j] = 1;
		}
	}

	vector< pair<int, int> > seq;
	for( int i = 0; i <= (m*m + m*m); i++){//i is the starting point of the sequence
		if( bisquares[i] ==1){
			for( int diff =1; i + (n-1)*diff <= (m*m + m*m) ; diff+=1){
				bool found = true;
				for( int k= 1; k<n;k++){
					if( bisquares[i + k*diff] == 0 ){
						found = false;
						break;
					}
				}
				if( found){
					seq.push_back(make_pair(diff,i));
				}
			}
		}
	}

	if(seq.size() == 0){
		cout<<"NONE"<<endl;
	}else{
		sort(seq.begin(), seq.end());
		rep(i, (int)seq.size()){
			printf("%d %d\n", seq[i].second, seq[i].first);
		}
	}

	return 0;
}









