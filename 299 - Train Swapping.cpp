#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int N[n];
		for(int i=0;i<n;i++){
			scanf("%d",&N[i]);
		}
		int s=0;
		bool go=1;
		while(go){
			go=0;
			for(int j=0;j<n-1;j++){
				if(N[j]>N[j+1]){
					swap(N[j],N[j+1]);
					s++;
					go=1;
				}
			}
		}
		printf("Optimal train swapping takes %d swaps.\n",s);
	}
	return 0;
}
