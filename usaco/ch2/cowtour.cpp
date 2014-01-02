/*
ID: piyushi1
LANG: C++
TASK: cowtour
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
#define fill(a,i) memset(a,i, sizeof(a));
inline int SS(){int x; scanf("%d",&x); return x;}
#define EPS 10e-7
#define INF 100000000


void fileInit(){
#ifdef DEBUG
  freopen("input.txt","r", stdin);
#endif
#ifndef DEBUG
	freopen("cowtour.in","r", stdin);
	freopen("cowtour.out","w", stdout);
#endif
}

/* Global variable */
double field[160][160];
int comp[160];
vector<ll> x;
vector<ll> y;
int n;
/* Global varible ends*/

void findComponents(int component){
	bool found = true;
	while(found){
		found = false;
		rep(i,n){
			if(comp[i]==-1){
				found = true; comp[i] = component;
				rep(j,n){
					if( (field[i][j] != INF) && (comp[j]==0))	
						comp[j]=-1;
				}
			}
		}
	}
}

double calDis( int i, int j){ return sqrt( (double)( (x[i]-x[j])*(x[i]-x[j])) + (double)( (y[i]-y[j])*(y[i]-y[j])) ); }
double min( double x, double y)				{if(x-y > EPS) return y; else return x;}
double max( double x, double y)				{if( x - y > EPS) return x; else return y; }
double max( double x, double y, double z)	{double temp = max ( x,y); return max( temp,z);}

//#define CLOCK
int main(){
#ifdef CLOCK
	int start = clock();
#endif
	fileInit();
	/* Main code begins*/
	n = SS();
	rep(i,n){
		ll x1; scanf("%ld",&x1); x.pb(x1);
		ll y1; scanf("%ld",&y1); y.pb(y1);	
	}
	
	getchar();
	rep(i,n){
		rep(j,n){
			char c = getchar();
			if( c=='1'){
				field[i][j] =  calDis(i,j);}
			else{
				field[i][j] = INF;
			}
		}
		getchar();
	}

	//Finding connected components
	rep(i,n) comp[i]=0;
	int cmp =0;
		rep(i,n){
			if(comp[i]==0){
				comp[i]=-1;
				findComponents(++cmp);
			}
		}
	// Calculating all pair shortest paths
	rep(k,n){
		rep(i,n){
			rep(j,n){
				if( field[i][j] > (field[i][k]+ field[k][j])){
					field[i][j] = field[i][k]+ field[k][j];
				}
			}
		}
	}

	double maxNode[160]; fill(maxNode,0);
	rep(i,n)
		rep(j,n){
			if( (i!=j) && (field[i][j]!= INF) && (maxNode[i] < field[i][j]))
				maxNode[i] = field[i][j];
	}

	set<int> components;
	double diamterPerComponent[160]; fill(diamterPerComponent,0);
	rep(i,n){ //Calculate diameter per component
		components.insert(comp[i]);
		diamterPerComponent[comp[i]] = max(diamterPerComponent[comp[i]], maxNode[i]);
	}
	
	double minimize = INF;
	for(set<int>::iterator it = components.begin(); it!= components.end(); it++){
		for(set<int>::iterator itt = components.begin(); itt!= components.end(); itt++){

		int comp1= *it; int comp2 = *itt;
		if( (comp1==comp2) || (comp1> comp2)) continue;
		double diamterWhenJoined = INF;
		rep(i,n){
			rep(j,n){
				if( (comp1 == comp[i]) && (comp2 == comp[j])) {
					double temp = (calDis(i,j) + maxNode[i] + maxNode[j]);
					double diamterWhenJoinedCurrent = max( diamterPerComponent[comp1], diamterPerComponent[comp2], temp);
					diamterWhenJoined = min(diamterWhenJoined, diamterWhenJoinedCurrent);
				}
			}
		}
		minimize = min( minimize, diamterWhenJoined);
		}
	}

	printf("%.6lf\n", minimize);
	/* Main code ends*/
#ifdef CLOCK
	int end = clock();
	cout<<endl<<((float)(end - start))/CLOCKS_PER_SEC;
#endif

	return 0;
}
