#include <cstdio>
#include <cmath>

using namespace std;

void solve(double a, int b) {
    double x = log10(a) + b;
    for(int m = 0; m < 10; ++m) {
        double lo = 1 - pow(2, -(m + 1));
        for(int e = 0; e <= 30; ++e) {
            double hi = pow(2, e) - 1;
            if(fabs(log10(lo) + hi * log10(2) - x) < 1e-5) {
                printf("%d %d\n", m, e);
                return;
            }
        }
    }
}

int main() {
    double a;
    int b;
    while((scanf("%17lfe%d", &a, &b) == 2) && a != 0) {
        solve(a, b);
    }

    return 0;
}
