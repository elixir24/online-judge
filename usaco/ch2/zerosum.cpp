/*
ID: piyushi1
LANG: C++
TASK: zerosum
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
  freopen("zerosum.in","r", stdin);
	freopen("zerosum.out","w", stdout);
#endif
}

char operations [3] = {' ','+','-'};
vector<string> sol;
int N;

int calVal(string exp){
	vector<int> num;
	vector<char> op;
	for(int i=0; i< (int)exp.length();i++){
		if( (exp[i]!=' ') && (exp[i]!='+') && (exp[i]!='-')){
			num.pb(exp[i]-'0');
		} else{
			if(exp[i]==' '){
				int n = num[ num.size()-1];
				n = 10*n + exp[i+1]-'0';
				num[ num.size()-1] = n;
				i++;
			}else{
				op.pb(exp[i]);
			}			
		}
	}
	int answer = num[0];
	for(int i=1; i< (int)num.size();i++){
		char o = op[i-1];
		if( o =='+') answer+=num[i];
		else answer-=num[i];
	}
	return answer;
}

void solve( string curr, const int n){
	if( n==0){
		if(calVal(curr) == 0)
			sol.pb(curr);
		return;
	}

	int val = N - n + 1;
	rep(i,3){
		curr+=operations[i];
		curr+=(char)('0'+ val);
		solve(curr, n-1);
		curr = curr.substr(0, curr.length()-2);
	}
	return;
}

int main(){
#ifdef CLOCK
	int start = clock();
#endif

	fileInit();

	N = SS();
	int cnt = N-1;
	string current = "1";
	solve(current, cnt);
	rep(i, (int)sol.size())
		cout<<sol[i]<<endl;

#ifdef CLOCK
	int end = clock();
	cout<<endl<<((float)(end - start))/CLOCKS_PER_SEC;
#endif
	return 0;
}

