#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int l,n;
		scanf("%d %d",&l,&n);
		l*=100;
		queue<int>L,R;
		for(int i=0;i<n;i++){
			int x;
			char S[15];
			scanf("%d %s",&x,S);
			if(S[0]=='l')L.push(x);
			if(S[0]=='r')R.push(x);
		}
		int pos=0,mov=0,cur=0;
		while(!L.empty()||!R.empty()){
			if(!pos){
				while(!L.empty()&&cur+L.front()<=l){
					cur+=L.front();
					L.pop();
				}
				cur=0;
				pos=!pos;
				mov++;
			}
			else{
				while(!R.empty()&&cur+R.front()<=l){
					cur+=R.front();
					R.pop();
				}
				cur=0;
				pos=!pos;
				mov++;
			}
		}
		printf("%d\n",mov);
	}
	return 0;
}
