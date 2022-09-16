#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	//gambler's ruin
	while(1){
		int v1,v2,a,d;
		scanf("%d %d %d %d",&v1,&v2,&a,&d);
		if(!v1&&!v2&&!a&&!d)break;
		double c1=(v1+d-1)/d,c2=(v2+d-1)/d,ans=0.0;
		if(a==3)ans=c1/(c1+c2);
		else{
			double p=(1.0-a/6.0)/(a/6.0);
			double p1=1.0,pt=1.0;
			for(int i=0;i<c1;i++)p1*=p;
			for(int i=0;i<c1+c2;i++)pt*=p;
			ans=(1.0-p1)/(1.0-pt);
		}
		printf("%.1lf\n",100.0*ans);
	}
	return 0;
}
