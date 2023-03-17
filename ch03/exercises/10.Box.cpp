#include <cstdlib>
#include <cstdio>

using namespace std;

const int N = 6;

struct Surface {
    int width;
    int height;
};

bool read(Surface box[]) {
    int w = 0, h = 0;
    for(int i = 0; i < N; ++i) {
        if(scanf("%d%d", &w, &h) != 2) {
            return false;
        }

        box[i].width = w;
        box[i].height = h;
    }

    return true;
}

int cmp(const void *a, const void *b) {
    const Surface* x = (Surface*)a;
    const Surface* y = (Surface*)b;
    if(x->width > y->width) {
        return 1;
    } else if(x->width < y->width) {
        return -1;
    } else {
        if(x->height > y->height) {
            return 1;
        } else if(x->height < y->height) {
            return -1;
        } else {
            return 0;
        }
    }
}

void solve(Surface box[]) {
    for(int i = 0; i < N; ++i) {
        if(box[i].width > box[i].height) {
            int t = box[i].width;
            box[i].width = box[i].height;
            box[i].height = t;
        }
    }

    qsort(box, N, sizeof(Surface), cmp);

    for(int i = 0; i < N / 2; ++i) {
        if(box[i * 2].width != box[i * 2 + 1].width || 
            box[i * 2].height != box[i * 2 + 1].height) {
            printf("IMPOSSIBLE\n");
            return;
        }
    }

    if(box[0].width == box[1].width && 
        box[1].width == box[2].width && 
        box[2].width == box[3].width && 
        box[0].height == box[1].height && 
        box[1].height == box[4].width && 
        box[4].width == box[5].width && 
        box[2].height == box[3].height && 
        box[3].height == box[4].height && 
        box[4].height == box[5].height
    ) {
        printf("POSSIBLE\n");
    } else {
        printf("IMPOSSIBLE\n");
    }
}

int main() {
    Surface box[N];
    while(read(box)) {
        solve(box);
    }

    return 0;
}