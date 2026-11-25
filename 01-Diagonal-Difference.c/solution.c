
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    long long primary = 0, secondary = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            scanf("%d", &num);

            if (i == j) {
                primary += num;
            }

            if (i + j == n - 1) {
                secondary += num;
            }
        }
    }

    printf("%lld\n", llabs(primary - secondary));

    return 0;
}
