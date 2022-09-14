#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mxN=2*100005;
int n,tree[4*mxN+5],N[mxN+5];
void build(int at,int l,int r){
	if(l==r){
		tree[at]=N[l];
		return;
	}
	int m=(l+r)/2;
	build(2*at,l,m);
	build(2*at+1,m+1,r);
	tree[at]=tree[2*at]+tree[2*at+1];
}
void update(int at,int l,int r,int pos,int val){
	if(l==r){
		tree[at]=val;
		return;
	}
	int m=(l+r)/2;
	if(pos<=m)update(2*at,l,m,pos,val);
	else update(2*at,m+1,r,pos,val);
	tree[at]=tree[2*at]+tree[2*at+1];
}
int query(int at,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr)return tree[at];
	if(r<ql||l>qr)return 0;
	int m=(l+r)/2;
	return query(2*at,l,m,ql,qr)+query(2*at+1,m+1,r,ql,qr);
}
string O;
int main(){
	int t,tc=0;
	while(1){
		scanf("%d",&n);
		if(!n)break;
		if(tc)printf("\n");
		printf("Case %d:\n",++tc);
		for(int i=1;i<=n;i++){
			scanf("%d",&N[i]);
		}
		build(1,1,n);
		while(cin>>O&&O!="END"){
			int l,r;
			scanf("%d %d",&l,&r);
			if(O=="M"){
				cout<<query(1,1,n,l,r)<<"\n";
			}
			else{
				update(1,1,n,l,r);
			}
		}
	}
	return 0;
}
