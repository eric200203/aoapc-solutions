#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1000 + 10;

void solve() {
    char line[MAXN];
    scanf("%s", line);
    int len = strlen(line);
    bool flag = true;
    for(int i = 1; i <= len; ++i) {
        if(len % i != 0) {
            continue;
        }

        flag = true;
        int sec = len / i;
        for(int n = 0; n < i; ++n) {
            char target = line[n];
            for(int m = 0; m < sec; ++m) {
                char ch = line[m * i + n];
                if(ch != target) {
                    flag = false;
                    break;
                }
            }

            if(!flag) {
                break;
            }
        }

        if(flag) {
            printf("%d\n", i);
            return;
        }
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    while(n--) {
        solve();
        if(n > 0) {
            printf("\n");
        }
    }
}