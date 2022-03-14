#include<bits/stdc++.h>
using namespace std;
bool p(string S){
	int l=S.size();
	for(int i=0;i<l;i++){
		if(S[i]!=' '){
			if(S[i]>='a'&&S[i]<='z'){
				return 0;
			}
		}
	}
	return 1;
}
bool cmp(pair<string,int>A,pair<string,int>B){
	if(A.second==B.second)return A.first<B.first;
	return A.second>B.second;
}
int main()
{
	bool f=1;
	while(f){
		vector<pair<string,int> >M;
		string S="";
		M.push_back({S,-1});
		map<string,int>P;
		int c=0;
		f=0;
		getline(cin,S);
		while(1){
			if(!f){
				if(S[0]=='0')break;
				f=1;
			}
			else getline(cin,S);
			if(S[0]=='1')break;
			if(p(S)){
				M.push_back({S,0});
				c++;
			}
			else{
				if(P[S]>0&&P[S]!=c){
					M[P[S]].second--;
					P[S]=-1;
				}
				else if(!P[S]){
					M.back().second++;
					P[S]=c;
				}
			}
		}
		if(!f)break;
		sort(M.begin(),M.end(),cmp);
		for(int i=0;i<M.size()-1;i++)printf("%s %d\n",M[i].first.c_str(),M[i].second);
	}
	return 0;
}
