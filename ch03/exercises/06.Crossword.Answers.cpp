#include <cstdio>
#include <cstring>

using namespace std;

void solve(int row, int col, int no) {
    char puzzle[row][col];
    for(int r = 0; r < row; ++r) {
        scanf("%s", puzzle[r]);
    }

    int across[row][col];
    int down[row][col];
    memset(across, 0, sizeof(int) * row * col);
    memset(down, 0, sizeof(int) * row * col);

    int curr = 0;
    for(int r = 0; r < row; ++r) {
        for(int c = 0; c < col; ++c) {
            if(puzzle[r][c] == '*') {
                continue;
            }

            bool valid = false;
            if(r == 0 || puzzle[r - 1][c] == '*') {
                valid = true;
                down[r][c] = curr + 1;
            }

            if(c == 0 || puzzle[r][c - 1] == '*') {
                valid = true;
                across[r][c] = curr + 1;
            }

            curr += (valid ? 1 : 0);
        }
    }

    if(no > 1) {
        printf("\n");
    }

    printf("puzzle #%d:\n", no);

    printf("Across\n");
    for(int r = 0; r < row; ++r) {
        for(int c = 0; c < col; ++c) {
            if(across[r][c] <= 0) {
                continue;
            }

            printf("%3d.", across[r][c]);
            int t = c;
            while(t < col && puzzle[r][t] != '*') {
                printf("%c", puzzle[r][t++]);
            }
            printf("\n");
        }
    }
    
    printf("Down\n");
    for(int r = 0; r < row; ++r) {
        for(int c = 0; c < col; ++c) {
            if(down[r][c] <= 0) {
                continue;
            }

            printf("%3d.", down[r][c]);
            int t = r;
            while(t < row && puzzle[t][c] != '*') {
                printf("%c", puzzle[t++][c]);
            }
            printf("\n");
        }
    }
}

int main() {
    int row = 0, col = 0, no = 0;
    while(scanf("%d%d", &row, &col) == 2 && row > 0 && col > 0) {
        solve(row, col, ++no);
    }

    return 0;
}