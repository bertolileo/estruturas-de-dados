#include "utils.h"

/* */
int missing_number(int *A, int n, int m) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (A[mid] == mid) {
            // Missing number must be to the right
            left = mid + 1;
        } else {
            // Missing number must be to the left or could be mid itself
            right = mid - 1;
        }
    }

    // The smallest missing number
    return left;
}
/* */
int main () {
  int i;
  //int n = 4, m = 4;
  //int A[] = {0,1,2,3};
  int n = 4, m = 12;
  int A[] = {4,5,10,11};
  //int n = 7, m = 16;
  //int A[] = {0,1,2,6,9,11,15};
  //int n = 8, m = 16;
  //int A[] = {1,2,3,4,6,9,11,15};
  //int n = 7, m = 7;
  //int A[] = {0,1,2,3,4,5,6};
  //int n = 8, m = 11;
  //int A[] = {0,1,2,3,4,5,6,7,10};
  print (A, n, "Input");
  printf("Missing number: %d\n", missing_number (A, n, m));
  return 0;
}
