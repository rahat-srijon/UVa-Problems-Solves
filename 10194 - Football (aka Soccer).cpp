#include<bits/stdc++.h>
using namespace std;
struct team{
	int pnt,gms,win,tie,los,gdf,gsc,ghv;
	string nam="";
};
bool cmp(team A,team B){
	if(A.pnt!=B.pnt)return A.pnt>B.pnt;
	if(A.win!=B.win)return A.win>B.win;
	if(A.gdf!=B.gdf)return A.gdf>B.gdf;
	if(A.gsc!=B.gsc)return A.gsc>B.gsc;
	if(A.gms!=B.gms)return A.gms<B.gms;
	for(int i=0;i<A.nam.size();i++)A.nam[i]=tolower(A.nam[i]);
	for(int i=0;i<B.nam.size();i++)B.nam[i]=tolower(B.nam[i]);
	return A.nam<B.nam;
}
int main(){
	int t;
	scanf("%d ",&t);
	bool sp=0;
	char G[1001];
	while(t--){
		if(sp)printf("\n");
		else sp=1;
		gets(G);
		puts(G);
		int n,j;
		scanf("%d ",&n);
		team T[n];
		map<string,int>ID;
		for(int i=0;i<n;i++)
		{
			gets(G);
			T[i].pnt=0;
			T[i].gms=0;
			T[i].win=0;
			T[i].tie=0;
			T[i].los=0;
			T[i].gdf=0;
			T[i].gsc=0;
			T[i].ghv=0;
			T[i].nam="";
			for(j=0;G[j];j++){
				T[i].nam+=G[j];
			}
			ID[T[i].nam]=i;
		}
		int g;
		scanf("%d ",&g);
		for(int i=0;i<g;i++){
			gets(G);
			string F="",S="";
			int f=0,s=0;
			j=0;
			for(;G[j]!='#';j++){
				F+=G[j];
			}
			j++;
			for(;G[j]!='@';j++){
				f*=10;
				f+=G[j]-'0';
			}
			j++;
			for(;G[j]!='#';j++){
				s*=10;
				s+=G[j]-'0';
			}
			j++;
			for(;G[j]!='\0';j++){
				S+=G[j];
			}
			int ft=ID[F],st=ID[S];
			T[ft].gsc+=f;
			T[st].gsc+=s;
			T[ft].ghv+=s;
			T[st].ghv+=f;
			T[ft].gms++;
			T[st].gms++;
			if(f==s){
				T[ft].tie++;
				T[st].tie++;
				T[ft].pnt++;
				T[st].pnt++;
			}
			else if(f<s){
				T[ft].los++;
				T[st].win++;
				T[st].pnt+=3;
			}
			else{
				T[ft].win++;
				T[st].los++;
				T[ft].pnt+=3;
			}
		}
		for(int i=0;i<n;i++){
			T[i].gdf=T[i].gsc-T[i].ghv;
		}
		sort(T,T+n,cmp);
		for(int i=0;i<n;i++){
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1,T[i].nam.c_str(),T[i].pnt,T[i].gms,T[i].win,T[i].tie,T[i].los,T[i].gdf,T[i].gsc,T[i].ghv);
		}
	}
	return 0;
}
