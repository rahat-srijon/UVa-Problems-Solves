#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>G[52];
bool V[52];
void dfs(int s){
	V[s]=1;
	for(int i=0;i<G[s].size();i++){
		if(!V[G[s][i]]){
			dfs(G[s][i]);
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t){
		for(int i=0;i<52;i++){
			V[i]=0;
			G[i].clear();
		}
		char S[3];
		bool f=0;
		while(gets(S)){
			if(!strlen(S))break;
			else if(strlen(S)==2){
				int u=S[0]-'A',v=S[1]-'A';
				G[u].push_back(v);
				G[v].push_back(u);
			}
			else{
				n=S[0]-'A';
				f=1;
			}
		}
		if(!f)continue;
		else t--;
		int ans=0;
		for(int i=0;i<=n;i++){
			if(!V[i]){
				dfs(i);
				ans++;
			}
		}
		printf("%d\n",ans);
		if(t)printf("\n");
	}
	return 0;
}
