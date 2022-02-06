#include <bits/stdc++.h>
using namespace std;
int main()
{
    while(1){
        int n,x,y;
        scanf("%d",&n);
        if(!n)break;
        int sq=sqrt(n);
        int re=n-sq*sq;
        if(re<=sq+1){
            x=re;
            y=sq+1;
            if(!re){
                x=1;
                y--;
            }
        }
        else{
            x=sq+1;
            re-=sq+1;
            y=sq+1-re;
            if(!re){
                y=1;
                x--;
            }
        }
        if(!(sq&1)){
            swap(x,y);
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}
