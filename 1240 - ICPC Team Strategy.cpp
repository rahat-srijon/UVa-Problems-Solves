#include<bits/stdc++.h>
using namespace std;
int n,N[3][12],DP[3][281][1<<12];
int bitmask_dp(int prev,int time,int pps){
	if(DP[prev][time][pps]!=-1)return DP[prev][time][pps];
	int ret=0;
	for(int i=0;i<n;i++){
		if(!(pps&(1<<i))){
			for(int j=0;j<3;j++){
				if(j!=prev&&(time+N[j][i])<=280){
					ret=max(ret,bitmask_dp(j,time+N[j][i],pps|(1<<i))+1);
				}
			}
		}
	}
	return DP[prev][time][pps]=ret;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<3;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&N[i][j]);
			}
		}
		memset(DP,-1,sizeof(DP));
		int ans=bitmask_dp(0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
