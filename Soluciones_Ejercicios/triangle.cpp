#include <bits/stdc++.h>

using namespace std;

struct nodo{
        int nivel;
        int valor;
};

nodo triangulo[5052];
int n;
int memo[5052];
void leer(){
        cin >> n;
        for(int i=1 ; i <= n ; i++){
                for(int j=0 ; j<i ; j++){
                        cin >> triangulo[((i*i+i)/2)-i+1+j].valor;
                        triangulo[((i*i+i)/2)-i+1+j].nivel=i;
                }
        }
        memset(memo, -1, sizeof (memo));
}


long long int DP(int index){
    if(triangulo[index].nivel==n) return triangulo[index].valor;
    
    if(index>((n*n+n)/2)) return 0;
    
    if(memo[index]!=-1) return memo[index];

    long long int suma;
    long long int izquierda = triangulo[index].valor+DP(index+triangulo[index].nivel);
    long long int derecha = triangulo[index].valor+DP(index+triangulo[index].nivel +1);
    return memo[index]=max(izquierda,derecha);
}

int main(){
        ios_base::sync_with_stdio(0);cin.tie(0);
        leer();
        cout << DP(1)<< "\n";
        return 0;

}
