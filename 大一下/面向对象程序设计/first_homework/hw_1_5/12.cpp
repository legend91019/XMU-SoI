#include <iostream>
using namespace std;


void reverse(int a[], int left, int right) {
    while (left < right) {
        int temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        left++;
        right--;
    }
}

void swap_segments(int a[], int m, int n) {

    reverse(a, 0, m - 1);
    

    reverse(a, m, m + n - 1);
    

    reverse(a, 0, m + n - 1);
}