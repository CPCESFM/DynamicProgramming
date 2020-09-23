#include <bits/stdc++.h>

using namespace std;

#define INF 1<<30;
int fuerza[10][1005];
int visitado[10][1005];
int X;

int DP(int altitud, int distancia){
	if(altitud > 9 || distancia > X){
		return INF;
	}
	if(altitud < 0 ){
		return INF;
	}
	if(distancia == X){
		if(altitud == 0){
			return 0;
		}else{
			return INF;
		}
	}
	if(visitado[altitud][distancia]!=-1){
		return visitado[altitud][distancia];
	}

	int subir = DP(altitud+1,distancia+1)+ (60 - fuerza[altitud][distancia]);
	int permanecer = DP(altitud,distancia+1)+ (30 - fuerza[altitud][distancia]);
	int bajar = DP(altitud-1,distancia+1) +(20 - fuerza[altitud][distancia]);

	int mini = min(subir,min(permanecer,bajar));
	return visitado[altitud][distancia]=mini;
}

void leer(){
	cin >> X;
	X/=100;
	memset(visitado, -1, sizeof(visitado));
	for(int i=9 ; i>=0 ; i--){
		for(int j=0 ; j<X ; j++){
			cin >> fuerza[i][j];
		}
	}
	cout << DP(0,0)<<"\n";
}
int TC;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> TC;
	while(TC--){
		leer();
		cout << "\n";
	}

	return 0;
}
