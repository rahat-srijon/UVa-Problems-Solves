#include<bits/stdc++.h>
using namespace std;
int main(){
	char Name[16][50];
	for(int i=0;i<16;i++){
		scanf("%s",Name[i]);
	}
	double W[16][16];
	for(int i=0;i<16;i++){
		for(int j=0;j<16;j++){
			scanf("%lf",&W[i][j]);
			W[i][j]*=0.01;
		}
	}
	double P[16][5];
	for(int i=0;i<16;i++){
		P[i][0]=1.0;
		for(int j=1;j<5;j++){
			P[i][j]=0.0;
		}
	}
	for(int s=1,i=1;i<5;i++,s*=2){
		for(int j=0;j<16;j++){
			int c=j/s,l;
			if(c%2==0)l=(c+1)*s;
			else l=(c-1)*s;
			for(int k=l;k<l+s;k++){
				P[j][i]+=P[j][i-1]*P[k][i-1]*W[j][k];
			}
		}
	}
	for(int i=0;i<16;i++){
		printf("%-10s p=%.2lf%%\n",Name[i],100.0*P[i][4]);
	}
	return 0;
}
