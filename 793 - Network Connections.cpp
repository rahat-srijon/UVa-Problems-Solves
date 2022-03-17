#include<bits/stdc++.h>
using namespace std;
int P[100000];
int fp(int v){return P[v]==v?v:fp(P[v]);}
int main(){
	int t;
	scanf("%d",&t);
	bool sp=0;
	while(t--){
		sp?printf("\n"):sp=1;
		int n,z=0,o=0;
		scanf("%d%*c",&n);
		for(int i=0;i<=n;i++)P[i]=i;
		int u,v;
		char O,S[100];
		while(gets(S)&&sscanf(S,"%c %d %d",&O,&u,&v)==3){
			int pu=fp(u),pv=fp(v);
			O=='c'?P[pv]=pu:pu==pv?z++:o++;
		}
		printf("%d,%d\n",z,o);
	}
	return 0;
}
