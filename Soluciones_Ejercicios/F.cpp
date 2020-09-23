#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int dp[3002][3002];


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string a, b, res;
	cin >> a >> b;
	int n = a.size();
	int m = b.size();
	int i = n;
	int j = m;
	for(int i = 0; i<= n; i++){
		for(int j = 0 ; j<=m ; j++){
			if( i == 0 || j == 0){
				dp[i][j] = 0;
			}else if(a[i - 1] == b[j - 1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}else{
				dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
			}
		}
	}
	res = "";
	
	while(i>=1&&j>=1){
                if(a[i-1]==b[j-1]){
                        res.push_back(a[i-1]);
                        --i;
                        --j;
                }
                else if(dp[i][j-1]>dp[i-1][j]) --j;
                else --i;
        }
	reverse(res.begin(), res.end());	
	cout << res  <<"\n";
	return 0;
}
