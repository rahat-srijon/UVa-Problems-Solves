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
		char C[40];
		int cnt=0;
		map<string,int>M;
		while(gets(C)!=NULL){
			if(strlen(C)<2)break;
			S="";
			for(int i=0;C[i];i++)S+=C[i];
			M[S]++;
			cnt++;
		}
		for(auto [x,y]:M){
			printf("%s %.4lf\n",x.c_str(),100.0*y/cnt);
		}
	}
	return 0;
}
