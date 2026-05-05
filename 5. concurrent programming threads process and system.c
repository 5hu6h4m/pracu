#include <stdio.h>
#include <pthread.h>

int var = 0;

void* print_messsage(void* arg) {
    var = 5;
    printf("Hello from Thread ID: %ld\n variable value = %d\n", pthread_self(), var);
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, print_messsage, NULL);
    pthread_join(thread, NULL);
    printf("Main Thread finished.variable value :%d\n", var);
    return 0;
}

/* Output
student@BTECH-MACHINELEARNINGLAB:~/Documents/Windows$ gcc prac5.c
student@BTECH-MACHINELEARNINGLAB:~/Documents/Windows$ ./a.out
Hello from Thread ID: 127552618231488
variable value = 5
Main Thread finished.variable value :5
*/
