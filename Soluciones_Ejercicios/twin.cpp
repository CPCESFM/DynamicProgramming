#include<bits/stdc++.h>

using namespace std;

int dp[102][102];
int casos;

int main(){
	ios_base::sync_with_stdio(0);
	int n1,n2;
	while(cin >> n1 >> n2 &&(n1 != 0 && n2!=0)){
		vector<int> tow1(n1);
		vector<int> tow2(n2);
		memset(dp, -1, sizeof(dp));
		for(auto &it : tow1) cin >> it;
		for(auto &it : tow2) cin >> it;
		for(int i=0 ; i<=n1; i++){
			for(int j=0 ; j<=n2; j++){
				if( i == 0 || j == 0) dp[i][j] = 0;
				else if( tow1[i - 1] == tow2[j - 1]){
				       	dp[i][j] = dp[i - 1][j - 1] +1;
				}else{
				       	dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);
				}
			}
		}
		cout << "Twin Towers #" << ++casos <<"\n";
		cout << "Number of Tiles : " << dp[n1][n2] <<"\n\n";
	}

	return 0;
}
