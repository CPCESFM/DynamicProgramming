#include<bits/stdc++.h>

using namespace std;
vector<int> a;
int n,t;
const int MaxN = 2 * 1e5;
const int INF = 1e9 - 7;
int dp[MaxN][2];

int skip(int entrada, int turno){
	if(entrada >= n) return 0;
	int costo = a[entrada] == 1 ? 1 : 0;
	int cost2 = 0;
	if(entrada+1<=n) cost2 = a[entrada + 1] == 1? 1 : 0;
	if(dp[entrada][turno] != -1) return dp[entrada][turno];
	if(turno == 0){
		return dp[entrada][turno] = min(skip(entrada + 1, 1),skip(entrada + 2, 1));
	}else{
		return dp[entrada][turno] = min(skip(entrada + 1,0) + costo,skip(entrada + 2,0) + costo + cost2);
	}

}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=0; i<n; i++){
			for(int j=0; j<2; j++){
				dp[i][j] = -1;
			}
		}
		a = vector<int>(n);
		for(auto &it: a) cin >> it;
		cout << skip(0,1) <<"\n";
	}

	return 0;
}
