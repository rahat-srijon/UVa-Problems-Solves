#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	bool c=0;
	scanf("%d",&t);
	char S[100002];
	while(t--){
		if(c)printf("\n");
		else c=1;
		gets(S+1);
		while(strlen(S+1)<1)gets(S+1);
		S[0]='*';
		int cr=0;
		vector<pair<int,string> >P;
		for(int i=1;S[i-1];i++){
			if(S[i]>='0'&&S[i]<='9'){
				cr*=10;
				cr+=S[i]-'0';
			}
			else if(cr){
				P.push_back({cr,""});
				cr=0;
			}
		}
		for(int i=0;i<P.size();i++){
			cin>>P[i].second;
		}
		sort(P.begin(),P.end());
		for(int i=0;i<P.size();i++){
			cout<<P[i].second<<endl;
		}
	}
	return 0;
}
