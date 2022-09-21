#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define r first
#define c second
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		char G[2*n+1][2*m+1];
		memset(G,' ',sizeof G);
		for(int i=0;i<=2*n;i++){
			for(int j=i%2==0;j<=2*m;j+=2){
				G[i][j]=j%2?'_':'|';
			}
		}
		bool vis[2*n+1][2*m+1];
		memset(vis,0,sizeof(vis));
		int sx,sy;
		scanf("%d %d",&sx,&sy);
		sx=2*sx-1;
		sy=2*sy-1;
		vis[sx][sy]=1;
		deque<pair<int,int>>L;
		L.push_back({sx,sy});
		while(L.size()){
			int cv=0;
			int cr=L.back().r;
			int cc=L.back().c;
			if(cr==1||vis[cr-2][cc])cv++;
			if(cc==1||vis[cr][cc-2])cv++;
			if(cr==2*n-1||vis[cr+2][cc])cv++;
			if(cc==2*m-1||vis[cr][cc+2])cv++;
			if(cv==4){
				L.pop_back();
				continue;
			}
			string O;
			cin>>O;
			if(O=="F"){
				int v;
				scanf("%d",&v);
				reverse(L.begin()+v-1,L.end());
			}
			if(O=="U"){
				G[cr+1][cc]=' ';
				vis[cr+2][cc]=1;
				L.push_back({cr+2,cc});
			}
			if(O=="D"){
				G[cr-1][cc]=' ';
				vis[cr-2][cc]=1;
				L.push_back({cr-2,cc});
			}
			if(O=="L"){
				G[cr][cc-1]=' ';
				vis[cr][cc-2]=1;
				L.push_back({cr,cc-2});
			}
			if(O=="R"){
				G[cr][cc+1]=' ';
				vis[cr][cc+2]=1;
				L.push_back({cr,cc+2});
			}
		}
		for(int i=2*n;i>=0;i--){
			for(int j=0;j<=2*m-(i==2*n);j++){
				printf("%c",G[i==2*n?i:j%2?i-1:i][j]);
			}
			if(i%2)i--;
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
