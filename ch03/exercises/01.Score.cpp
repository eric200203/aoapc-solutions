#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100 + 10;

void solve() {
    char line[MAXN];
    scanf("%s", line);
    int len = strlen(line);
    int curr = 0, result = 0;
    for(int i = 0; i < len; ++i) {
        if(line[i] == 'O') {
            result += (++curr);
        } else {
            curr = 0;
        }
    }

    printf("%d\n", result);
}

int main() {
    int n = 0;
    scanf("%d", &n);
    while(n--) {
        solve();
    }

    return 0;
}