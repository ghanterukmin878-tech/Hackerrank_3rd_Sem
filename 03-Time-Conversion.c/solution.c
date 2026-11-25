
#include <stdio.h>
#include <string.h>

int main() {
    char time[11];

    scanf("%10s", time);

    int hour = (time[0] - '0') * 10 + (time[1] - '0');

    if (strcmp(time + 8, "AM") == 0) {
        if (hour == 12) {
            hour = 0;
        }
    } 
    else {
        if (hour != 12) {
            hour += 12;
        }
    }

    printf("%02d%s\n", hour, time + 2);

    return 0;
}
