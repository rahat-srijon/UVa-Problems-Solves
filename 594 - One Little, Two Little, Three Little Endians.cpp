#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n)>0){
		bool S[32];
		int r=0;
		for(int i=31;i>=0;i--)S[i]=n&(1<<i);
		for(int i=0;i<8;i++)swap(S[i],S[i+24]);
		for(int i=8;i<16;i++)swap(S[i],S[i+8]);
		for(int i=31;i>=0;i--){r<<=1;r|=S[i];}
		printf("%d converts to %d\n",n,r);
	}
	return 0;
}
