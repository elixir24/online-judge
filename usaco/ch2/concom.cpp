/*
ID: piyushi1
LANG: C++
TASK: concom
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
#define foreach(i,a) for(typeof((a).begin()) i=(a).begin();i!=(a).end();i++)
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
  freopen("concom.in","r", stdin);
	freopen("concom.out","w", stdout);
#endif
}

class graph{

private:

	/* Data structure storing the graph */
	vector<vector<pair<int, int> > > g;
	//size of the graph
	int vertexSize; 
	set<int> vertices;

public:

	graph(int vertexSize){
		this->vertexSize = vertexSize;
		this->g.resize(vertexSize+1);
	}

	int getSize(){
		return this->vertexSize;
	}

	vector<pair<int,int> > getEdgeListForVertex(const int vertex){
		return g[vertex];
	}

	set<int> getVertices(){
		return this->vertices;
	}

	int getWeight( const int head, const int tail){
		vector<pair<int,int> > edgeList = getEdgeListForVertex(head);
		for( int i=0; i< (int)edgeList.size(); i++){
			if(edgeList[i].first == tail)
				return edgeList[i].second;
		}
		return 0;
	}

	void addEdge( const int source, const int destination, const int weight){
		assert( (source <= this->vertexSize) && (destination <= this->vertexSize) );
		g[source].push_back(make_pair(destination,weight));
		this->vertices.insert(source);
		this->vertices.insert(destination);
	}

	void printGraph(){
		for(int i=0;i<vertexSize;i++){
		if(g[i].size()!=0){
			printf("%d ->",i);
			for(int j=0;j<(int)g[i].size();j++)
				printf("%d ",g[i][j].first);
			printf("\n");
			}
		}
	}

	/* Returns true if the edge is present and is deleted successfully, 
		returns false otherwise*/
	bool removeEdge(const int source, const int destination){

		assert( (source <= this->vertexSize) && (destination <= this->vertexSize) );
		vector<pair<int, int> > v = g[source];
		int i;
		for( i = 0; i< (int)v.size(); i++){
			if(v[i].first == destination)
				break;
		}
		if(i!= (int)v.size()){//this means element has been found
			v.erase(v.begin()+i);
			g[source] = v; //reset the vector from which the value has been deleted
			return true;
		}else
			return false;
	}
};

/* Global variable */
int control[101][101];
int mark[110][110];
graph g(100);
int visited[101];
vector<pair<int, int> > answer;

void search (const int node, const int current){
	if( node!= current)
		answer.pb(mp(node,current));
	mark[node][current]=1;
	vector<pair<int, int> > edges = g.getEdgeListForVertex(current);
	visited[current]=1;
	rep(i, (int)edges.size()){
		pair<int,int> edge = edges[i];
		control[node][edge.first]+= edge.second;
		if(!visited[edge.first] && (control[node][edge.first] > 50) )
			search(node, edge.first);
	}
}

bool cmp( pair<int,int> a, pair<int, int> b){
	if( a.first < b.first)	return true;
	else if( a.first == b.first){
		if( a.second < b.second) return true;
		else return false;
	}else	return false;
}

int main(){
#ifdef CLOCK
	int start = clock();
#endif
	fileInit();
	fill(control,0);
	int n = SS();
	int x,y,z;
	rep(i,n){
		x = SS(); y = SS(); z = SS();
		g.addEdge(x,y,z);
	}
	
	set<int> vertices = g.getVertices();
	for( set<int>::iterator it = vertices.begin(); it!= vertices.end(); it++){
		fill(visited,0);
		search(*it,*it);
	}

	sort(answer.begin(), answer.end(), cmp);

	rep(i,(int)answer.size()){
		cout<<answer[i].first<<" "<<answer[i].second<<endl;
	}

#ifdef CLOCK
	int end = clock();
	cout<<endl<<((float)(end - start))/CLOCKS_PER_SEC;
#endif

	return 0;
}

