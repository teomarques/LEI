#include <stdio.h>

int Stirling(int n, int k){
    if(k == 0 && n > 0 || k > n){
        return 0;
    }
    else if(k > 0 && k < n){
        int res = k * S(n-1, k) + S(n-1, k-1);
        return res;
    }
    return 0;
}

void stirling2(int m, int S[m+1][m+1]){
    for(int l = 0; l <= m; l++){
        printf("\n");
        for(int c = 0; c <= m; c++){
                S[l][c] = Stirling(l, c);
                printf("%d ", S[l, c]);
        }
    }
    return;
}

int main(){
    int m = 5;
    int s[m+1][m+1];
    stirling2(m, s);
}
