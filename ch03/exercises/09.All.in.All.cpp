#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1000000 + 10;

void solve(char s1[], char s2[]) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int t1 = 0, t2 = 0;
    while(t1 < len1) {
        while(t2 < len2 && s1[t1] != s2[t2]) {
            ++t2;
        }

        if(t2 >= len2) {
            break;
        }

        ++t1;
        ++t2;
    }

    printf("%s\n", t1 == len1 ? "Yes" : "No");
}

int main() {
    char str1[MAXN], str2[MAXN];
    while(scanf("%s%s", str1, str2) == 2) {
        solve(str1, str2);
    }

    return 0;
}