/*
ID: piyushi1
LANG: C++
TASK: maze1
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

class graph{

private:

  //Actual data structure storing the graph
  vector<vector<pair<int, int> > > g;
	//size of the graph
	int vertexSize; 
	vector<int> vertices;

public:

	graph(int vertexSize){
		this->vertexSize = vertexSize;
		this->g.resize(vertexSize+1);
		this->vertices.resize(vertexSize+1);
	}

	int getSize(){
		return this->vertexSize;
	}

	vector<int> getVertexList(){
		vector<int> ret;
		for(int i =0; i< (int)this->vertices.size(); i++){
			if(this->vertices[i] == 1)
				ret.push_back(i);
		}
		return ret;
	}

	vector<pair<int,int> > getEdgeListForVertex( const int vertex){
		return g[vertex];
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

		this->vertices[source]=1; this->vertices[destination]=1;
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

	/* Returns true if the edge is present and is deleted success
	fully, returns false otherwise*/
	bool removeEdge(const int source, const int destination){

		assert( (source <= this->vertexSize) && (destination <= this->vertexSize) );
		vector<pair<int, int> > v = g[source];
		int i;
		for( i = 0; i< (int)v.size(); i++){
			if(v[i].first == destination)
				break;
		}
		//vector<pair<int,int> > co
		if(i!= (int)v.size()){//this means element has been found
			v.erase(v.begin()+i);
			g[source] = v; //reset the vector from which the value has been deleted
			return true;
		}else
			return false;
	}
};

void fileInit(){
#ifdef DEBUG
  freopen("input.txt","r", stdin);
#endif
#ifndef DEBUG
	freopen("maze1.in","r", stdin);
	freopen("maze1.out","w", stdout);
#endif
}

/* Global variable */
char grid[1000][1000];
graph g(5000);
int outside = 4500;
int ans = -1;
/* Global varible ends*/

void bfs(int source){

	int visited[5000]; fill(visited,0);
	visited[source]=1;
	queue<pair<int,int> > q ;
	q.push(mp(source,0));
	while(!q.empty()){
		pair<int,int> node = q.front(); q.pop();
		if( ans < node.second)
			ans = node.second;

		vector<pair<int,int> > edgeList= g.getEdgeListForVertex(node.first);
		rep(i, edgeList.size()){
			pair<int,int> n = edgeList[i];
			if(!visited[n.first]){
				visited[n.first]=1;
				q.push(mp(n.first, node.second+1));
			}
		}
	}
}

int main(){
	
  fileInit();
	int W = SS();
	int H = SS();
	getchar();
	rep(i, (2*H+1)){
		string str;
		getline(cin, str); 
		rep(j, (2*W+1)){
			grid[i+1][j+1] = str[j];
		}
	}

	//vector<pair<int,int> > exits;

	for( int i=1; i<=H; i++){
		for( int j =1; j<=W; j++){
			int node = (i-1)*W + j;
			if( grid[2*i-1][2*j] == ' '){
				if( (2*i-1) == 1){
					g.addEdge(node,outside,1);
					g.addEdge(outside,node,1);
				}
				else
					g.addEdge(node, ((i-2)*W+j),1);
			}
			if(grid[2*i][2*j+1] == ' '){
			 if( (2*j+1) == (2*W+1)){
					g.addEdge(node,outside,1);
					g.addEdge(outside,node,1);
				}
				else
					g.addEdge(node, ((i-1)*W + j + 1),1);
			}
			if(grid[2*i+1][2*j] == ' '){
			 if( (2*i+1) == (2*H+1) ){
					g.addEdge(node,outside,1);
					g.addEdge(outside,node,1);
				}
				else
					g.addEdge(node, ((i)*W +j),1);
			}
			if(grid[2*i][2*j-1] == ' '){
			 if( (2*j-1) == 1){
					g.addEdge(node,outside,1);
					g.addEdge(outside,node,1);
				}
				else
					g.addEdge(node, ((i-1)*W + j-1),1);
			}
		}
	}

	bfs(outside);
	cout<<ans<<endl;
	return 0;
}
