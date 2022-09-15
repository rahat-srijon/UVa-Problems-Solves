#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int tc=0;
	while(1){
		int n,r;
		scanf("%d %d",&n,&r);
		double P[n],Q[n],all=0.0;
		if(!n&&!r)break;
		printf("Case %d:\n",++tc);
		for(int i=0;i<n;i++){
			scanf("%lf",&P[i]);
			Q[i]=0.0;
		}
		string S="";
		for(int i=0;i<n;i++)S+=i<r?'1':'0';
		reverse(S.begin(),S.end());
		do{
			double cur=1.0;
			for(int i=0;i<n;i++)cur*=S[i]=='1'?P[i]:(1.0-P[i]);
			for(int i=0;i<n;i++)Q[i]+=S[i]=='1'?cur:0.0;
			all+=cur;
		}while(next_permutation(S.begin(),S.end()));
		for(int i=0;i<n;i++)printf("%.6lf\n",Q[i]/all);
	}
	return 0;
}
