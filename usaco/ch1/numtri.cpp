/*
ID: piyushi1
LANG: C++
TASK: numtri
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
	freopen("numtri.in","r", stdin);
	freopen("numtri.out","w", stdout);
#endif
}

int arr[1005][1005], R , answer[1005][1005];

int solve( int row, int column){
	assert( column < R);

	if( answer[row][column] > -1)
		return answer[row][column];

	if( row == R-1)//base case
		return arr[row][column];

	answer[row][column] =  arr[row][column]+ max(solve(row+1,column),solve(row+1,column+1)) ;
	return answer[row][column] ;
}


int main(){

	fileInit();
	R = SS;
	rep(i,R){
		rep(j,i+1){
			arr[i][j] = SS;
			answer[i][j] = -1;
		}
	}
	cout<<solve(0,0)<<endl;
}

