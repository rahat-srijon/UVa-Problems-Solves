#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		double win,lose,rnd=1.0;
		scanf("%d %lf %d",&n,&win,&k);
		lose=1.0-win;
		for(int i=1;i<k;i++)win*=lose;
		for(int i=0;i<n;i++)rnd*=lose;
		double ans=0.0;
		while(win>1e-6){
			ans+=win;
			win*=rnd;
		}
		printf("%.4lf\n",ans);
	}
	return 0;
}
