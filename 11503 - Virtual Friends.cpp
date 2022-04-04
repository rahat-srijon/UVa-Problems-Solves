#include<bits/stdc++.h>
using namespace std;
map<string,int>ID;
int S[100001],P[100001],c=1;
int find_set(int x){return P[x]==x?x:P[x]=find_set(P[x]);}
void make_set(int x){P[x]=x;S[x]=1;}
void union_set(int a,int b){
	a=find_set(a);
	b=find_set(b);
	if(a!=b){
		if(S[a]<S[b])swap(a,b);
		P[b]=a;
		S[a]+=S[b];
	}
	printf("%d\n",S[a]);
}
void add_id(string A){ID[A]=c;make_set(c);c++;}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		c=1;
		ID.clear();
		memset(S,0,sizeof(S));
		memset(P,0,sizeof(P));
		while(n--){
			string A,B;
			cin>>A>>B;
			if(!ID[A])add_id(A);
			if(!ID[B])add_id(B);
			union_set(ID[A],ID[B]);
		}
	}
	return 0;
}
