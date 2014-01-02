/*
ID: piyushi1
LANG: C++
TASK: contact
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
#include<cstdlib>
//#include"graph.h" // https://github.com/codetrash/algorithms/blob/master/algorithms/src/graph/graph.h

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
#define FOR(i,a,b) for(int i = a; i<b; i++)
#define mod(x) ((x>0)?x:(-x))
//#define SS ({int x;scanf("%d",&x);x;})
#define mp make_pair
#define pb push_back
#define fill(a,i) (memset(a,i, sizeof(a)))
inline int SS(){int x; scanf("%d",&x); return x;}
#define EPS 10e-7
#define INF 1000000000

void fileInit(){
#ifdef DEBUG
  freopen("input.txt","r", stdin);
#endif
#ifndef DEBUG
  freopen("contact.in","r", stdin);
	freopen("contact.out","w", stdout);
#endif
}

/* Global variable */
int a, b, n;
string s;
/* End */

inline string construct(pair<int, int> p ){
	int num = p.second;
	string s;
	while(num){
		if(num%2==1)s+='1';
		else s+='0';
		num=num/2;
	}
	if(p.first > s.length()){
		int x = s.length();
		FOR(i,0, p.first-x)
			s+='0';
	}
	reverse(s.begin(), s.end());
	return s;
}

inline void print( int freq, vector<pair<int, int> > v){
	printf("%d\n", freq);
	//cout<<construct(v[0]);
	FOR(i,0,(int)v.size()){
		if( i%6 == 0 )
			cout<<construct(v[i]);
		else
			cout<<" "<<construct(v[i]);
		if((i+1)%6 == 0 && (i!=(v.size()-1)))
			printf("\n");
	}
	printf("\n");
}

//#define CLOCK
int main(){
#ifdef CLOCK
	int start = clock();
#endif
	fileInit();
	/* Main code begins*/
	a = SS();
	b = SS();
	n = SS();
	string temp;
	getline(cin, temp);
	while(1){
		string str = "";
		getline(cin,str);
		if(str.length()==0)
			break;
		else
			s+=str;
	}

	int freq[13][1<<12]; fill(freq,0);
	FOR(i,0,s.length()){
		int num = 0;
		for( int j= 0; j< b; j++){
			if((i+j) < s.length()){
				num= num*2 + (s[j+i]-'0');
				if( (j+1) >= a){
					freq[j+1][num]++;
				}
			}
		}
	}
	map<int, vector < pair<int,int> > >f;
	FOR(i,1,13){
		FOR(j,0, 1<<12){
			f[freq[i][j]].pb(mp(i,j));	
		}
	}

	for( map<int, vector<pair<int,int> > >::reverse_iterator it = f.rbegin(); it != f.rend(); it++){
		if(n==0)break;
		if( it->first >0)
			print(it->first, it->second);
		n--;
	}

	/* Main code ends*/
#ifdef CLOCK
	int end = clock();
	cout<<endl<<((float)(end - start))/CLOCKS_PER_SEC;
#endif

	return 0;
}	
