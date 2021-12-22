#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,tc=0;
	char S[1001];
	scanf("%d",&t);
	while(t--){
		scanf("%s",S);
		int i,F[26]={0},C[26]={0};
		for(i=0;S[i]!='\0';i++)F[S[i]-'a']++;
		int l=i,c=0;
		for(i=0;i<26;i++)if(F[i])C[c++]='a'+i;
		for(i=0;i<l-c;i++)printf("%c",C[0]);
		for(i=0;i<c;i++)printf("%c",C[i]);
		printf("\n");
	}
    return 0;
}
