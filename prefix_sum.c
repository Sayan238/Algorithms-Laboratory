#include<stdio.h>
#include<time.h>

void prefixSum(int arr[], int n, int prefixArr[]){
    int i;
    int x = 0;
    for(i = 0; i < n; i++){
        x += arr[i];
        prefixArr[i] = x;
    }
}

int main(){
    clock_t start,end;
    double cpu_time_used;
    start = clock();

    int n = 5;
    int arr[] = {3, 4, 5, 1, 2};
    int ans[5];
    prefixSum(arr, 5, ans);
    int i;
    for(i = 0; i < n; i++){
        printf("%d\t", ans[i]);
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n%lf",cpu_time_used);
}