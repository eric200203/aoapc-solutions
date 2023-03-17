#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

const int MAXN = 1000 + 10;

void solve() {
    char line[MAXN];
    scanf("%s", line);
    int len = strlen(line);
    int t = 0;
    double result = 0.0;
    while(t < len) {
        char element = line[t++];
        int num = 0;
        if(t < len && isdigit(line[t])) {
            while(t < len && isdigit(line[t])) {
                num = num * 10 + (line[t++] - '0');
            }
        } else {
            num = 1;
        }

        switch (element) {
            case 'C': 
                result += (12.01 * num);
                break;
            case 'H':
                result += (1.008 * num);
                break;
            case 'O':
                result += (16.00 * num);
                break;
            case 'N':
                result += (14.01 * num);
                break;
        }
    }

    printf("%.3f\n", result);
}

int main() {
    int n = 0;
    scanf("%d", &n);
    while(n--) {
        solve();
    }

    return 0;
}