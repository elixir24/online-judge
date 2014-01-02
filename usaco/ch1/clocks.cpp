/*
ID: piyushi1
LANG: C++
TASK: clocks
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


struct NODE{ //this represent a single state node consisting of all clocks in BFS tree
	int state;
	vi moves;

	NODE(int state, vi oldMoves, int nextMove){
		this->state = state;
		this->moves = oldMoves;
		if(nextMove != -1){
			this->moves.pb(nextMove);
		}
	}
};typedef struct NODE node;

void printBits(int num){
	for(int i=17;i>=0;i--){
		if((num & (1<<i))!=0)
			cout<<"1 ";
		else
			cout<<"0 ";
	}
}

int visited[1<<18];	//we only need 18 bits for representing 9 clocks
string operationsVector[] =
{"ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"};


//Counts the number of existing operations passed already been performed
int count( int operation, vi moves){

	int answer = 0;
	rep(i, (int)moves.size())
	if(moves[i]==operation)
		answer++;
	return answer;
}

int findState( int state, int operation){
    operation --;
	string operationString = operationsVector[operation];
	rep(i, (int)operationString.size()){
		int maskValue = (operationString[i]-'A')<<1; // bits start at double of clock number
		int prevValue = (state>>maskValue)&3;
		int nextState = (prevValue + 1 )%4;
		state = state &   ~(3 << maskValue ) ;
        state = state | (nextState << maskValue) ;
	}

	return state;

}

vi go ( int state){
	queue<node> q;
	vi x;
	node initNode(state, x, -1);
	q.push(initNode);
	visited[initNode.state] = 1;
	while(!q.empty()){
		node n = q.front();
		q.pop(); //remove the front element
		if( n.state == 0)
			return n.moves;
		for( int i =1; i<=9; i++){//try applying all the 9 possible operation on the node current node
			if( count(i, n.moves) >=3)
				continue;
			//Now we know that this moves has not been performed more than 3 times.We can apply this move now.
			int newState = findState(n.state, i);
			if( visited[newState] == 0){
				node s(newState, n.moves, i);
				q.push(s);
				visited[s.state] = 1;
			}
		}
	}
	return x; //Return empty vector
}

int main(){
	freopen("clocks.in","r", stdin);
	freopen("clocks.out","w", stdout);
	memset(visited, 0, sizeof(visited));
	int initialState =0;
	rep(i,9){
		int state = SS;
		if( state == 3) state =1; else if( state ==6) state = 2; else if (state==9) state =3; else state =0;
		//Now find the correct bits to insert this state
		initialState = initialState | ( (state) << (i<<1));
	}

	vi answer  = go(initialState);
	if(answer.size()!=0){
		cout<<answer[0];
		for( int i=1; i< (int)answer.size();i++){
			cout<<" "<<answer[i];
		}
	}

	cout<<endl;

}








