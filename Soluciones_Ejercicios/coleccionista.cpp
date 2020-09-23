#include <bits/stdc++.h>

using namespace std;

int dinero, n;

struct cartas{
	int precio;
	int puntaje;
};

cartas yugi[502];


void leer(){
	cin >> dinero >> n;
	for(int i=1 ; i <= n ; i++){
		cin >> yugi[i].precio >> yugi[i].puntaje;
	}
}

short memo[502][10002];

int DP( int actual, int money){
	if(money < 0){
		return INT_MIN;
	}
	if(actual > n){
		return 0;
	}
	if(memo[actual][money]!=0){
		return memo[actual][money];
	}
	int retorno= max(yugi[actual].puntaje+DP(actual+1,money-yugi[actual].precio),DP(actual+1,money));
	memo[actual][money]=retorno;
	return retorno;
}

int main(){
	leer();
	cout << DP(1, dinero)<<"\n";
	return 0;
}
