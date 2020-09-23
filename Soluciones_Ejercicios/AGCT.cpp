#include<bits/stdc++.h>

using namespace std;
int n,m;
string x, y;
int edit[10000][10000];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(cin >> n >> x >> m >> y){
		memset(edit, -1, sizeof(edit));
		for(int i = 0 ; i<= n ; i++) edit[i][0] = i;
		for(int j = 0;  j<= m; j++) edit[0][j] = j;

		for(int i=1 ; i<=n ; i++){
			for(int j=1 ; j<=m ; j++){
				if(x[i - 1] == y[j - 1]){
					edit[i][j] = edit[i - 1][j - 1];
				}else{
					edit[i][j] = min(edit[i - 1][j] + 1, edit[i][j - 1] + 1);
					edit[i][j] = min(edit[i - 1][j - 1] + 1,edit[i][j]);
				}
			}
		}
		cout << edit[n][m] << "\n";
	}

	return 0;
}
