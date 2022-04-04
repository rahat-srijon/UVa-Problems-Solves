#include<bits/stdc++.h>
using namespace std;
int main(){
	map<int,int>M;
	char S[20];
	while(1){
		scanf("%s",S);
		if(S[0]=='#')break;
		int n,t;
		scanf("%d %d",&n,&t);
		M[n]=t;
	}
	int k;
	scanf("%d",&k);
	vector<pair<int,int> >V,P;
	for(auto &x:M){
		for(int i=1;i<=k;i++){
			V.push_back({i*x.second,x.first});
		}
	}
	sort(V.begin(),V.end());
	for(int i=0;i<k;i++){
		printf("%d\n",V[i].second);
	}
	return 0;
}
