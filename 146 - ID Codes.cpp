#include<bits/stdc++.h>
using namespace std;
int main(){
	char S[52];
	while(1){
		scanf("%s",S);
		if(S[0]=='#')break;
		if(next_permutation(S,S+strlen(S)))printf("%s\n",S);
		else printf("No Successor\n");
	}
	return 0;
}
