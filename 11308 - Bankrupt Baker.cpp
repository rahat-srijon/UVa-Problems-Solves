#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	bool sp=0;
	scanf("%d",&t);
	while(t--){
		sp?printf("\n"):sp=1;
		string B;
		scanf("%*c");
		getline(cin,B);
		for(int i=0;i<B.size();i++){
			printf("%c",towupper(B[i]));
		}
		printf("\n");
		int n,m,k;
		scanf("%d %d %d",&m,&n,&k);
		map<string,int>I,R;
		for(int i=0;i<m;i++){
			string C;
			int c;
			cin>>C>>c;
			I[C]=c;
		}
		for(int i=0;i<n;i++){
			string N;
			scanf("%*c");
			getline(cin,N);
			int d;
			scanf("%d",&d);
			int cur=0;
			for(int j=0;j<d;j++){
				string C;
				int c;
				cin>>C>>c;
				cur+=I[C]*c;
			}
			if(cur<=k)R[N]=cur;
		}
		vector<pair<int,string> >V;
		for(auto [x,y]:R){
			V.push_back({y,x});
		}
		sort(V.begin(),V.end());
		if(V.empty())printf("Too expensive!\n");
		else{
			for(auto [x,y]:V){
				cout<<y<<"\n";
			}
		}
	}
	return 0;
}
