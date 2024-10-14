#include <stdio.h>

int main() {
    int disk[1000] = {0}, n, size, dir, curr, headMovement = 0;
    printf("ENTER THE DISK SIZE AND NO. OF REQUESTS: ");
    scanf("%d %d", &size, &n);

    printf("ENTER THE REQUESTS: ");
    for (int i = 0; i < n; ++i) {
        int temp;
        scanf("%d", &temp);
        disk[temp]++;
    }

    printf("ENTER THE DIRECTION OF MOVEMENT UP(0) OR DOWN(1): ");
    scanf("%d", &dir);

    printf("ENTER THE CURRENT HEAD POINTER: ");
    scanf("%d", &curr);
    disk[curr]++;  

    if (dir == 1) {  
        int i;
        for (i = curr; i >= 0; --i) {
            if (disk[i] >= 1) {
                printf("%d --> ", i);
                headMovement += (curr - i);
                curr = i;
            }
        }
        for (i = curr + 1; i < size; ++i) {
            if (disk[i] >= 1) {
                printf("%d --> ", i);
                headMovement += (i - curr);
                curr = i;
            }
        }
    } 
    else {  
        int i;
        for (i = curr; i < size; ++i) {
            if (disk[i] >= 1) {
                printf("%d --> ", i);
                headMovement += (i - curr);
                curr = i;
            }
        }
        for (i = curr - 1; i >= 0; --i) {
            if (disk[i] >= 1) {
                printf("%d --> ", i);
                headMovement += (curr - i);
                curr = i;
            }
        }
    }
    printf("\nTOTAL HEAD MOVEMENT: %d\n", headMovement);

    return 0;
}
