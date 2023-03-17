#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int N = 10;

void solve() {
    int num = 0;
    scanf("%d", &num);
    
    int result[N];
    memset(result, 0, sizeof(int) * N);
    for(int i = 1; i <= num; ++i) {
        int div = i;
        while(div > 0) {
            result[div % 10] += 1;
            div /= 10;
        }
    }

    for(int i = 0; i < N; ++i) {
        if(i > 0) {
            printf(" ");
        }
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {
    int n = 0;
    scanf("%d", &n);
    while(n--) {
        solve();
    }

    return 0;
}