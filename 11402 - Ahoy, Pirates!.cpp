#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=1024000+10;
struct seg{int o=0,z=0,l=0;}tree[mxN*4+10];
int N[mxN+5];
seg combine(seg A,seg B){
	seg R;
	R.o=A.o+B.o;
	R.z=A.z+B.z;
	return R;
}
void build(int at,int l,int r){
	if(l==r){
		tree[at].o=N[l];
		tree[at].z=!N[l];
		tree[at].l=0;
		return;
	}
	int m=(l+r)/2;
	build(2*at,l,m);
	build(2*at+1,m+1,r);
	tree[at]=combine(tree[2*at],tree[2*at+1]);
}
void clear_lazy(int at,int l,int r){
	if(tree[at].l){
		if(tree[at].l==1){
			tree[at].o+=tree[at].z;
			tree[at].z=0;
		}
		if(tree[at].l==2){
			tree[at].z+=tree[at].o;
			tree[at].o=0;
		}
		if(tree[at].l==3){
			swap(tree[at].o,tree[at].z);
		}
		if(l!=r){
			if(tree[at].l!=3){
				tree[2*at].l=tree[at].l;
				tree[2*at+1].l=tree[at].l;
			}
			else{
				if(tree[2*at].l==3)tree[2*at].l=0;
				else if(tree[2*at].l==0)tree[2*at].l=3;
				else if(tree[2*at].l==1)tree[2*at].l=2;
				else if(tree[2*at].l==2)tree[2*at].l=1;
				if(tree[2*at+1].l==3)tree[2*at+1].l=0;
				else if(tree[2*at+1].l==0)tree[2*at+1].l=3;
				else if(tree[2*at+1].l==1)tree[2*at+1].l=2;
				else if(tree[2*at+1].l==2)tree[2*at+1].l=1;
			}
		}
		tree[at].l=0;
	}
}
void update_range(int at,int l,int r,int ql,int qr,int op){
	clear_lazy(at,l,r);
	if(r<ql||l>qr)return;
	if(l>=ql&&r<=qr){
		tree[at].l=op;
		clear_lazy(at,l,r);
		return;
	}
	int m=(l+r)/2;
	update_range(2*at,l,m,ql,qr,op);
	update_range(2*at+1,m+1,r,ql,qr,op);
	tree[at]=combine(tree[2*at],tree[2*at+1]);
}
seg query_range(int at,int l,int r,int ql,int qr){
	clear_lazy(at,l,r);
	seg X;
	if(r<ql||l>qr)return X;
	if(l>=ql&&r<=qr)return tree[at];
	int m=(l+r)/2;
	return combine(query_range(2*at,l,m,ql,qr),query_range(2*at+1,m+1,r,ql,qr));
}
string S;
int main(){
	int t,tc=0;
	scanf("%d",&t);
	while(t--){
		printf("Case %d:\n",++tc);
		int s,c,n=0;
		scanf("%d",&s);
		while(s--){
			scanf("%d",&c);
			cin>>S;
			while(c--){
				for(int x:S){
					N[++n]=x-'0';
				}
			}
		}
		build(1,1,n);
		int q,qc=0;
		scanf("%d",&q);
		while(q--){
			cin>>S;
			int l,r;
			scanf("%d %d",&l,&r);
			l++;
			r++;
			if(S=="F")update_range(1,1,n,l,r,1);
			if(S=="E")update_range(1,1,n,l,r,2);
			if(S=="I")update_range(1,1,n,l,r,3);
			if(S=="S"){
				int qa=query_range(1,1,n,l,r).o;
				printf("Q%d: %d\n",++qc,qa);
			}
		}
	}
	return 0;
}
