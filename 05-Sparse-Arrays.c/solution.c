#include <stdio.h>
#include <string.h>

#define SIZE 20011
#define LEN 21

char keys[SIZE][LEN];
int counts[SIZE];
int used[SIZE];

unsigned long hashFunction(char *s) {
    unsigned long hash = 5381;

    while (*s) {
        hash = hash * 33 + *s;
        s++;
    }

    return hash % SIZE;
}

int findSlot(char *s) {
    int index = hashFunction(s);

    while (used[index] && strcmp(keys[index], s) != 0) {
        index = (index + 1) % SIZE;
    }

    return index;
}

int main() {
    int n;
    scanf("%d", &n);

    char s[LEN];

    for (int i = 0; i < n; i++) {
        scanf("%20s", s);

        int index = findSlot(s);

        if (!used[index]) {
            strcpy(keys[index], s);
            used[index] = 1;
        }

        counts[index]++;
    }

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        scanf("%20s", s);

        int index = findSlot(s);

        printf("%d\n", counts[index]);
    }

    return 0;
}