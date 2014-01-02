/*
ID: piyushi1
LANG: C++
TASK: prefix
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
  freopen("prefix.in","r", stdin);
	freopen("prefix.out","w", stdout);
#endif
}



class trie{
public:
	vector<trie*> v;
	bool doesEnd;
	string alphabet;
	//Constructor
	trie(string alphabet){
		this->alphabet = alphabet;
		this->doesEnd = false;
		int alphSize = (int) alphabet.size();
		v.resize(alphSize);
		for( int i=0; i<alphSize; i++){
			v[i] = NULL;
		}
	}

	/* Method to add a word to the trie*/
	void addWord(const string s){
		if(s.length() == 0){
			this->doesEnd = true;
			return;
		}		
		int c = s[0];
		if(this->v[c-alphabet[0]] == NULL) { 
			this->v[c-alphabet[0]] = new trie(this->alphabet);
		}
		this->v[c-alphabet[0]]->addWord(s.substr(1));
	}

	/* Method to find if the sting is present in the trie or not*/
	bool isPresent(const string s){
		if( s.length() == 0) //base case
			return this->doesEnd;

		char c = s[0];
		if( this->v[c- alphabet[0]] == NULL)
			return false;
		else{
			return this->v[c-alphabet[0]]->isPresent(s.substr(1));
		}
	}

};


int dp[200000 + 3];
int main(){
	fileInit();
	string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	trie t(alph);
	string s;
	for(;;){
		cin>>s;
		if(!s.compare("."))
			break;
		t.addWord(s);
	}

	string sequence,temp;
	while(getline(cin, temp)){
		sequence+=temp;
	}
	fill(dp,0);

	for(int i=0; i< 10;i++){
		if(t.isPresent(sequence.substr(0,i+1))){
			dp[i] = 1;
		}
	}

	int n = sequence.length();
	for( int i = 0; i<n ;i++){
		if( dp[i] == 1){
			trie* temp = &t;
			for ( int ii= 1; ((ii+i)< n) && (ii<=10) ;ii++){
				trie* tt = temp->v[sequence[i+ii]-'A'];
				if( tt!=NULL){
					if( tt->doesEnd)
						dp[i+ii]=1;
					temp = tt;
				}else
					break;
			}
		}
	}

	int i;
	for(i = sequence.length()-1; i>=0; i--){
		if( dp[i]==1){
			cout<<i+1<<endl;
			return 0;
		}
	}
	if( i==-1)
		cout<<0<<endl;
}
