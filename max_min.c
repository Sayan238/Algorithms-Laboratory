#include<stdio.h>
#include<limits.h>

int secondLargest(int arr[], int n){
    int i;
    int large, secLarge;
    large = secLarge = -1;
    
    for(i = 0; i < n; i++){
        if(arr[i] > large){
            secLarge = large;
            large = arr[i];
        }
        else if(arr[i] > secLarge && arr[i] != large){
            secLarge = arr[i];
        }
    }
    
    return secLarge;
}

int secondSmallest(int arr[], int n){
    int i;
    int small, secSmall;
    small = secSmall = INT_MAX;
    
    for(i = 0; i < n; i++){
        if(arr[i] < small){
            secSmall = small;
            small = arr[i];
        }
        else if(arr[i] < secSmall && arr[i] != small){
            secSmall = arr[i];
        }
    }
    
    return secSmall;
}

int main(){
    int arr[5] = {2, 4, 5, 1, 2};
    int largest = secondLargest(arr, 5);
    int smallest = secondSmallest(arr, 5);
    printf("Second Largest: %d\n", largest);
    printf("Second Smallest: %d\n", smallest);
}