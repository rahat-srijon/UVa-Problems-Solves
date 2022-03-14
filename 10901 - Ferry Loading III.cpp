#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	bool nl=0;
	while(t--){
		if(nl)printf("\n");
		else nl=1;
		int n,t,m;
		scanf("%d %d %d",&n,&t,&m);
		map<int,int>A;
		map<int,pair<int,char> >M;
		multimap<pair<int,char>,int>MM;
		queue<int>L,R;
		for(int i=0;i<m;i++){
			int c;
			char S[10];
			scanf("%d %s",&c,S);
			M[i]={c,S[0]};
			MM.insert({{c,S[0]},i});
		}
		for(auto [z,x]:M){
			if(x.second=='l')L.push(x.first);
			else R.push(x.first);
		}
		bool tr=0;
		int ct=0;
		while(!L.empty()||!R.empty()){
			int cc=0;
			if(!L.empty()&&!R.empty()){
				ct=max(ct,min(L.front(),R.front()));
			}
			else if(!L.empty()){
				ct=max(ct,L.front());
			}
			else if(!R.empty()){
				ct=max(ct,R.front());
			}
			while(!L.empty()&&L.front()<=ct&&cc<n&&!tr){
				cc++;
				auto rem=MM.lower_bound({L.front(),'l'});
				A[rem->second]=ct+t;
				MM.erase(rem);
				L.pop();
			}
			while(!R.empty()&&R.front()<=ct&&cc<n&&tr){
				cc++;
				auto rem=MM.lower_bound({R.front(),'r'});
				A[rem->second]=ct+t;
				MM.erase(rem);
				R.pop();
			}
			ct+=t;
			tr=!tr;
		}
		for(auto [x,y]:A){
			printf("%d\n",y);
		}
	}
	return 0;
}
