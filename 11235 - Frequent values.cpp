#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf INT_MIN
struct seg{
	int l_cnt;
	int l_val;
	int r_cnt;
	int r_val;
	int mx;
}tree[4*100005];
int N[100005],n,q;
seg combine(seg A,seg B){
	if(A.l_val==inf)return B;
	if(B.l_val==inf)return A;
	seg ret;
	ret.l_cnt=A.l_cnt;
	ret.l_val=A.l_val;
	ret.r_cnt=B.r_cnt;
	ret.r_val=B.r_val;
	if(A.l_val==B.l_val)ret.l_cnt+=B.l_cnt;
	if(A.r_val==B.r_val)ret.r_cnt+=A.r_cnt;
	ret.mx=max(A.mx,B.mx);
	if(A.r_val==B.l_val)ret.mx=max(ret.mx,A.r_cnt+B.l_cnt);
	ret.mx=max(ret.mx,ret.r_cnt);
	ret.mx=max(ret.mx,ret.l_cnt);
	return ret;
}
void build(int at,int l,int r){
	if(l==r){
		tree[at]={1,N[l],1,N[l],1};
		return;
	}
	int m=(l+r)/2;
	build(2*at,l,m);
	build(2*at+1,m+1,r);
	tree[at]=combine(tree[2*at],tree[2*at+1]);
}
seg query(int at,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr)return tree[at];
	if(r<ql||l>qr)return {inf,inf,inf,inf,inf};
	int m=(l+r)/2;
	return combine(query(2*at,l,m,ql,qr),query(2*at+1,m+1,r,ql,qr));
}
int main(){
	while(1){
		scanf("%d",&n);
		if(!n)break;
		scanf("%d",&q);
		for(int i=1;i<=n;i++){
			scanf("%d",&N[i]);
		}
		build(1,1,n);
		while(q--){
			int l,r;
			scanf("%d %d",&l,&r);
			printf("%d\n",query(1,1,n,l,r).mx);
		}
	}
	return 0;
}
