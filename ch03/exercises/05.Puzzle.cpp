#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100 + 10;
const int N = 5;

bool read_board(char board[]) {
    char line[MAXN];
    for(int r = 0; r < N; ++r) {
        fgets(line, MAXN, stdin);
        if(line[0] == 'Z') {
            return false;
        }

        for(int c = 0; c < N; ++c) {
            board[r * N + c] = line[c];
        }
    }
    
    return true;
}

bool solve(int no) {
    char board[N * N];
    if(!read_board(board)) {
        return false;
    }

    int r0 = 0, c0 = 0;
    for(int r = 0; r < N; ++r) {
        for(int c = 0; c < N; ++c) {
            if(board[r * N + c] == ' ') {
                r0 = r;
                c0 = c;
            }
        }
    }

    bool end = false;
    bool valid = true;
    char seq[MAXN];
    while(!end) {
        fgets(seq, MAXN, stdin);
        int len = strlen(seq);
        if(seq[len - 2] == '0') {
            end = true;
        }

        if(!valid) {
            continue;
        }

        for(int i = 0; i < len - 1; ++i) {
            char op = seq[i];
            valid = (op == '0') ||
                (op == 'A' && r0 > 0) ||
                (op == 'B' && r0 < N - 1) ||
                (op == 'L' && c0 > 0) ||
                (op == 'R' && c0 < N - 1);
            if(!valid) {
                break;
            }

            int r1 = r0, c1 = c0;
            switch(op) {
                case 'A':
                    --r1; break;
                case 'B':
                    ++r1; break;
                case 'L':
                    --c1; break;
                case 'R':
                    ++c1; break;
            }

            board[r0 * N + c0] = board[r1 * N + c1];
            board[r1 * N + c1] = ' ';
            r0 = r1;
            c0 = c1;
        }
    }

    if(no > 1) {
        printf("\n");
    }
    printf("Puzzle #%d:\n", no);
    if(valid) {
        for(int r = 0; r < N; ++r) {
            for(int c = 0; c < N; ++c) {
                printf("%c%c", board[r * N + c], (c == N - 1 ? '\n' : ' '));
            }
        }
    } else {
        printf("This puzzle has no final configuration.\n");
    }

    return true;
}

int main() {
    int n = 0;
    bool ok = true;
    while(ok) {
        ok = solve(++n);
    }

    return 0;
}