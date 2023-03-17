#include <cstdio>
#include <cstring>

const int MAXN = 4 * 1024 * 1024;

int main() {
    char table[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char buffer[MAXN];
    memset(buffer, 0, sizeof(char) * MAXN);
    fread(buffer, sizeof(char), MAXN, stdin);
    size_t len = strlen(buffer);
    size_t tlen = strlen(table);
    for(size_t i = 0; i < len; ++i) {
        bool flag = false;
        for(size_t j = 1; j < tlen; ++j) {
            if(table[j] == buffer[i]) {
                printf("%c", table[j - 1]);
                flag = true;
                break;
            }
        }

        if(!flag) {
            printf("%c", buffer[i]);
        }
    }

    return 0;
}