#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1000 + 10;
const int ALPHA = 26;

void solve() {
    int n = 0, len = 0;
    scanf("%d%d", &n, &len);
    char line[n][MAXN];
    for(int i = 0; i < n; ++i) {
        scanf("%s", line[i]);
    }

    int count[ALPHA];
    int distance = 0;
    for(int i = 0; i < len; ++i) {
        memset(count, 0, sizeof(int) * ALPHA);
        for(int k = 0; k < n; ++k) {
            count[line[k][i] - 'A'] += 1;
        }

        int max = 0;
        for(int k = 0; k < ALPHA; ++k) {
            if(count[k] > count[max]) {
                max = k;
            }
        }

        distance += (n - count[max]);
        printf("%c", 'A' + max);
    }

    printf("\n%d\n", distance);
}

int main() {
    int n = 0;
    scanf("%d", &n);
    while(n--) {
        solve();
    }

    return 0;
}