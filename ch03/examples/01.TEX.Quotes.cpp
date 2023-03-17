#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 4 * 1024 * 1024;

int main() {
    char buffer[MAXN];
    memset(buffer, 0, sizeof(char) * MAXN);
    fread(buffer, sizeof(char), MAXN, stdin);
    size_t len = strlen(buffer);

    bool flag = false;
    for(size_t i = 0; i < len; ++i) {
        if(buffer[i] == '"') {
            if(flag) {
                printf("''");
            } else {
                printf("``");
            }
            flag = !flag;
        } else {
            printf("%c", buffer[i]);
        }
    }

    return 0;
}