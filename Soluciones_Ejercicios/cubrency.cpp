#include <bits/stdc++.h>

using namespace std;

long long int cubos[24];
long long int memo[10002][24];

void llenado(){
	for(int i=1 ; i<= 21 ; i++){
		cubos[i]=i*i*i;
	}
	memset(memo, -1 , sizeof(memo));	
}

long long int DP(int dinero, int moneda){
	if(dinero < 0){
		return 0;
	}
	if(moneda > 21){
		return 0;
	}
	if(dinero==0 ){
		return 1;
	}
	if(memo[dinero][moneda]!=-1){
		return memo[dinero][moneda];
	}

	return memo[dinero][moneda]=DP(dinero-cubos[moneda],moneda)+DP(dinero,moneda+1);
}

void leer(){
	int N;

	while(scanf("%d", &N) == 1) {
		printf("%lld\n", DP(N,1));
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	llenado();
	leer();
	return 0;
}
