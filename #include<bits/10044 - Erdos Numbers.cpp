#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,tc=0;
	scanf("%d",&t);
	char S[10001];
	while(t--){
		int n,p,k=0;
		scanf("%d %d ",&n,&p);
		map<string,int>ID;
		vector<int>L[n];
		for(int i=0;i<n;i++){
			gets(S+1);
			string c="";
			int a=0;
			for(int j=1;S[j-2]!=':';j++){
				if((S[j]==':'||S[j]==',')&&S[j-1]=='.'){
					if(!ID[c])ID[c]=++k;
					L[i].push_back(ID[c]);
					c="";
					j++;
				}
				else{
					c+=S[j];
				}
			}
		}
		int sz=ID.size(),s=ID["Erdos, P."];
		vector<int>G[sz+1];
		int D[sz+1];
		for(int i=0;i<n;i++){
			for(int j=0;j<L[i].size();j++){
				for(int k=0;k<L[i].size();k++){
					if(j!=k)G[L[i][j]].push_back(L[i][k]);
				}
			}
		}
		bool V[sz+1];
		for(int i=0;i<=sz;i++){
			V[i]=0;
			D[i]=-1;
		}
		V[s]=1;
		D[s]=0;
		queue<int>Q;
		Q.push(s);
		while(!Q.empty()){
			s=Q.front();
			Q.pop();
			for(int i=0;i<G[s].size();i++){
				int v=G[s][i];
				if(!V[v]){
					D[v]=D[s]+1;
					V[v]=1;
					Q.push(v);
				}
			}
		}
		printf("Scenario %d\n",++tc);
		for(int i=0;i<p;i++){
			string c="";
			gets(S);
			for(int j=0;S[j];j++)c+=S[j];
			printf("%s",S);
			if(D[ID[c]]>0)printf(" %d\n",D[ID[c]]);
			else printf(" infinity\n");
		}
	}
	return 0;
}
