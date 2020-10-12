#include<bits/stdc++.h>

using namespace std;
vector<int> longi(40);
string sol(int n, int k){
    if(longi[n] < k) return "-1";
    if(n == 0) return "a";
    if(n == 1) return "b";
    if(n == 2) return "c";
    
    for(int i=1 ; i<=3; i++){
        if (k > longi[n - i]) {
            k -= longi[n - i];
        } else {
            return sol(n - i, k);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    
    longi[0] = 1;
    longi[1] = 1;
    longi[2] = 1;
    for(int i=3 ; i<=n ; i++) longi[i] = longi[i - 1] + longi[i - 2] + longi[i - 3];
    cout << sol(n, k) <<"\n";
    return 0;
}
