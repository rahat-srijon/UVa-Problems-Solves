#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d ",&t);
	bool sp=0;
	while(t--){
		if(sp)printf("\n");
		else sp=1;
		string S;
		int cnt=0;
		map<string,double>M;
		while(getline(cin,S)){
			if(S.size()<1)break;
			M[S]++;
			cnt++;
		}
		for(auto [x,y]:M){
			printf("%s %.4lf\n",x.c_str(),100.0*y/cnt);
		}
	}
	return 0;
}
