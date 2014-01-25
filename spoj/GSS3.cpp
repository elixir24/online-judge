#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define N 16 // height of the tree
#define SIZE (2<<(N+1)) //size of the segment tree
#define left(i) (2*i)
#define right(i) (2*i + 1)

struct node{
	int bestsum;
	int subsetsum;
	int prefixsum;
	int suffixsum;
	void merge(node& a, node&b){
		subsetsum = a.subsetsum + b.subsetsum;
		prefixsum = max( a.prefixsum , a.subsetsum + b.prefixsum);
		suffixsum = max( b.suffixsum, b.subsetsum + a.suffixsum);
		bestsum = max( max(a.bestsum , b.bestsum), a.suffixsum + b.prefixsum);
	}
	void split(node& a, node& b){
		//pass
	}
}segtree[SIZE];

node query_range(int root, int leftleaf, int rightleaf, int u, int v){
	if( leftleaf>=u && rightleaf<=v)
		return segtree[root];

	int mid = (leftleaf + rightleaf)/2;
	node res;
	if(u >= mid){
		res = query_range(right(root) , mid, rightleaf, u, v);
	}else if(v <= mid){
		res= query_range(left(root), leftleaf, mid, u, v);
	}else{
		node r = query_range(right(root) , mid, rightleaf, u, v);
		node l = query_range(left(root), leftleaf, mid, u, v);
		res.merge(l,r);	
	}
	return res;
}

node query( int u, int v){
	return query_range(1, 0, 1<<N, u, v);
}

void update_single_element(node& ele, int val){
	ele.subsetsum = ele.prefixsum = ele.suffixsum = ele.bestsum = val;

}

void update_range(int root, int leftleaf, int rightleaf, int u, int v, int val){
	
	if( leftleaf>=u && rightleaf<=v){
		update_single_element(segtree[root],val);
		return;
	}
	int mid = (leftleaf + rightleaf)/2;
	if(u < mid)	update_range(left(root) , leftleaf, mid, u, v, val);
	if(v > mid)	update_range(right(root), mid, rightleaf, u, v, val);
	segtree[root].merge(segtree[left(root)],segtree[right(root)]);
}

void update(int index, int val){
	update_range(1, 0, 1<<N, index, index+1, val);
}

int main(){
	freopen("input.txt", "r", stdin);
	int n; scanf("%d",&n);
	int a,b,c,m,temp;
	rep(i,0,n){
		scanf("%d", &temp);
		segtree[(1<<N)+i].prefixsum = segtree[(1<<N)+i].subsetsum = 
		segtree[(1<<N)+i].suffixsum = segtree[(1<<N)+i].bestsum = temp;
	}
	for( int i = (1<<N) -1; i>0; i--)	segtree[i].merge(segtree[left(i)], segtree[right(i)]);
	
	scanf("%d",&m);
	rep(i,0,m){
		scanf("%d",&a); scanf("%d",&b); scanf("%d",&c);
		if(a) {printf("%d\n",query(b-1, c).bestsum); fflush(stdout);}
		else update(b-1, c);
	}	
}