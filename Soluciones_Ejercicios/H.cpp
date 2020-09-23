#include<iostream>

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9 - 7;
typedef long long ll;
bool tablero[1002][1002];
int n, m;
ll dp[1002][1002];
ll camino[1002][1002];
/*
ll pos(int i, int j){
	if(i < 0 || i >= n) return 0;
	if(j < 0 || j >= m) return 0;
	if(tablero[i][j]) return 0;
	if( i==0 && j == 0) return 1;
	if(dp[i][j] != -1) return dp[i][j];

	ll k = pos(i - 1, j) + pos(i, j - 1);
	k %= MOD;

	return dp[i][j] = k;
}
*/
int main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	char aux;
//	memset(dp, -1, sizeof(dp));
	for(int i=0 ; i<n; i++){
		for(int j=0; j<m ; j++){
			cin >> aux;
			if(aux == '.') tablero[i][j] = false;
			if(aux == '#') tablero[i][j] = true;
		}
	}
//	cout << pos(n - 1,m - 1) % MOD <<"\n";

	for(int i=0 ; i<n; i++){
		for(int j=0 ; j<m; j++){
			if(i == 0 && j == 0){
				camino[0][0] = 1;
			}else if(!tablero[i][j]){
				if(i - 1 >= 0) camino[i][j] += camino[i - 1][j];
				camino[i][j] %= MOD;
				if( j - 1 >= 0) camino[i][j] += camino[i][j - 1];
				camino[i][j] %= MOD;
			}
		}
	}
	cout << camino[n - 1][m - 1] % MOD <<"\n";
	return 0;
}
