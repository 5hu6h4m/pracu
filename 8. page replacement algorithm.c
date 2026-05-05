#include <stdio.h>

int main() {
    int frames, pages;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int ref[pages];
    printf("Enter reference string: ");
    for (int i = 0; i < pages; i++) {
        scanf("%d", &ref[i]);
    }

    int frame[frames];
    int front = 0;
    int faults = 0, hits = 0;

    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    for (int i = 0; i < pages; i++) {
        int found = 0;

        for (int j = 0; j < frames; j++) {
            if (frame[j] == ref[i]) {
                found = 1;
                hits++;
                break;
            }
        }

        if (!found) {
            frame[front] = ref[i];
            front = (front + 1) % frames;
            faults++;
        }

        printf("Frame: ");
        for (int j = 0; j < frames; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }

        if (found)
            printf("-> Hit\n");
        else
            printf("-> Fault\n");
    }

    printf("\nTotal Page Hits = %d\n", hits);
    printf("Total Page Faults = %d\n", faults);

    float hit_ratio = (float)hits / pages;
    float fault_ratio = (float)faults / pages;

    printf("Hit Ratio = %.2f\n", hit_ratio);
    printf("Fault Ratio = %.2f\n", fault_ratio);

    return 0;
}

/*
student@BTECH-MACHINELEARNINGLAB:~/Windows$ gcc Prac8.c
student@BTECH-MACHINELEARNINGLAB:~/Windows$ ./a.out
Enter number of frames: 3
Enter number of pages: 4 1 1 2 3
Enter reference string: Frame: 1 - - -> Fault
Frame: 1 - - -> Hit
Frame: 1 2 - -> Fault
Frame: 1 2 3 -> Fault

Total Page Hits = 1
Total Page Faults = 3
Hit Ratio = 0.25
Fault Ratio = 0.75
student@BTECH-MACHINELEARNINGLAB:~/Windows$
*/
