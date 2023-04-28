#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {
    int arr[ROWS][COLS] = {{3, 2, 1}, {546, 578, 4}, {789, 878, 967}};
    int min = arr[0][0], max = arr[0][0], sum = 0, count = 0;
    
    // find min and max elements
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(arr[i][j] < min) {
                min = arr[i][j];
            }
            if(arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    
    // calculate sum and count of elements excluding min and max
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(arr[i][j] != min && arr[i][j] != max) {
                sum += arr[i][j];
                count++;
            }
        }
    }
    
    // calculate and print average
    if(count > 0) {
        double average = (double) sum / count;
        printf("The average excluding the minimum (%d) and maximum (%d) elements is: %f\n", min, max, average);
    } else {
        printf("There are no elements to calculate the average.\n");
    }
    
    return 0;
}
