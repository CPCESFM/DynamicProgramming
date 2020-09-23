#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> missiles;
vector<ll> dp;
int main(){
//	ios_base::sync_with_stdio(0);
	int aux, aux2;
	int casos = 0;
	while(cin >> aux && aux != -1){
		 missiles.clear();
		 missiles.push_back(aux);
		 while(cin >> aux2 && aux2 != -1){
			missiles.push_back(aux2);
		 }
		 ll n = (ll)missiles.size();
		 dp = vector<ll>(n);
		 for(int k=0 ; k < n ; k++){
			dp[k] = 1;
			for(int i = 0 ; i < k ; i++){
				if(missiles[i] >= missiles[k]){
					dp[k] = max(dp[i] + 1, dp[k]);
				}
			}
		 }
		 ll mejor = INT_MIN;
		 for(int index_ = 0 ; index_ < n ; index_++) mejor = max((int)mejor, (int)dp[index_]);
		 if(casos) printf("\n");
		 printf("Test #%d:\n", ++casos);
		 printf("  maximum possible interceptions: %lld\n", mejor);
	}
	return 0;
}
