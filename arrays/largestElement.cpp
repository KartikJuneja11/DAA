//find the largest element in an array
#include<iostream>
#include<algorithm>
using namespace std;

//idk what i did lol
int largestElement_idk(int arr[], int n, int l, int u){
    int m = (l+u)/2;
    if(l == u) return arr[l];
    return max(largestElement_idk(arr, n, l, m), largestElement_idk(arr, n, m+1, u));
}

//optimal
int largestElement(int arr[], int n){
    int largest = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > largest) largest = arr[i];
    }
    return largest;
}

int main(){
    int arr[] = {3, 2, 1, 5, 2};
    cout << largestElement_idk(arr, 4, 0, 4);
    cout << largestElement(arr, 5);
    return 0;
}