#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10000 + 10;

int shift(char l1[], char l2[]) {
    int len1 = strlen(l1);
    int len2 = strlen(l2);

    for(int i = 0; i < len1; ++i) {
        bool valid = true;
        for(int t = 0; t < len2 && t + i < len1; ++t) {
            if(l2[t] == '2' && l1[i + t] == '2') {
                valid = false;
                break;
            }
        }

        if(valid) {
            return max(len1, i + len2);
        }
    }

    return len1 + len2;
}

void solve(char l1[], char l2[]) {
    int result = min(shift(l1, l2), shift(l2, l1));
    printf("%d\n", result);
}

int main() {
    char l1[N], l2[N];
    while(scanf("%s%s", l1, l2) == 2) {
        solve(l1, l2);
    }

    return 0;
}