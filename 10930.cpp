#include<bits/stdc++.h>
using namespace std;
int C[31],DP[31][1001];
bool A[1001];
int coin_change(int t,int n,int w){
	if(w<0)return 11111;
	if(t==n)return w==0?0:11111;
	int r1=1+coin_change(t+1,n,w-C[t]);
	int r2=coin_change(t+1,n,w);
	return DP[t][w]=min(r1,r2);
}
int main(){
	int n,tc=0;
	while(scanf("%d",&n)>0){
		memset(DP,0,sizeof(DP));
		memset(A,-1,sizeof(A));
		bool f=1;
		for(int i=0;i<n;i++){
			DP[i][0]=1;
			scanf("%d",&C[i]);
			if(i&&(C[i]<=C[i-1]))f=0;
		}
		printf("Case #%d:",++tc);
		for(int i=0;i<n;i++){
			printf(" %d",C[i]);
		}
		printf("\n");
		for(int i=1;i<n&&f;i++){
			if(coin_change(0,i,C[i])!=11111)f=0;
		}
		if(f)printf("This is an A-sequence.\n");
		else printf("This is not an A-sequence.\n");
	}
	return 0;
}
