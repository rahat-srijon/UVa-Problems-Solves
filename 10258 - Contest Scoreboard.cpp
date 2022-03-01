#include<bits/stdc++.h>
using namespace std;
struct subs{
	int c_id,p_id,time,vdct;
};
struct part{
	int c_id,S_cnt,penalty;
	vector<int>PA;
};
subs getdata(char S[]){
	int i=0,c=0,p=0,t=0,v;
	while(S[i]!=' '){
		c*=10;
		c+=S[i]-'0';
		i++;
	}
	i++;
	while(S[i]!=' '){
		p*=10;
		p+=S[i]-'0';
		i++;
	}
	i++;
	while(S[i]!=' '){
		t*=10;
		t+=S[i]-'0';
		i++;
	}
	i++;
	if(S[i]=='C')v=0;
	else if(S[i]=='I')v=1;
	else v=-1;
	return {c,p,t,v};
}
part initialize(subs S){
	part ret;
	ret.c_id=S.c_id;
	ret.S_cnt=0;
	ret.penalty=0;
	for(int i=0;i<11;i++){
		ret.PA.push_back(0);
	}
	if(S.vdct==1)ret.PA[S.p_id]++;
	else if(S.vdct==0){
		ret.penalty+=S.time;
		ret.S_cnt++;
		ret.PA[S.p_id]=-1;
	}
	return ret;
}
part update(part P,subs S){
	if(P.PA[S.p_id]!=-1){
		if(S.vdct==1){
			P.PA[S.p_id]++;
		}
		else if(S.vdct==0){
			P.S_cnt++;
			P.penalty+=S.time+P.PA[S.p_id]*20;
			P.PA[S.p_id]=-1;
		}
	}
	return P;
}
bool cmp(part A,part B){
	if(A.S_cnt!=B.S_cnt){
		return A.S_cnt>B.S_cnt;
	}
	if(A.penalty!=B.penalty){
		return A.penalty<B.penalty;
	}
	return A.c_id<B.c_id;
}
int main(){
	int t;
	scanf("%d ",&t);
	bool sp=0;
	char S[1000];
	while(t--){
		if(sp)printf("\n");
		else sp=1;
		vector<subs>V;
		while(gets(S)!=NULL){
			if(strlen(S)<2)break;
			V.push_back(getdata(S));
		}
		map<int,int>ID;
		vector<part>P;
		int pcnt=0;
		for(subs &x:V){
			if(!ID[x.c_id]){
				part cur=initialize(x);
				P.push_back(cur);
				ID[x.c_id]=++pcnt;
			}
			else{
				P[ID[x.c_id]-1]=update(P[ID[x.c_id]-1],x);
			}
		}
		sort(P.begin(),P.end(),cmp);
		for(part &y:P){
			printf("%d %d %d\n",y.c_id,y.S_cnt,y.penalty);
		}
	}
	return 0;
}
