//remove duplicates from sorted array
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//brute force
int removeDuplicatesBrute(vector<int> arr){
    int k = 0, a;
    int last = arr[arr.size() - 1];
    for(int i = 0; i < arr.size(); i++){
        k++;
        if(arr[i] == last) return k;
        if(arr[i] == arr[i+1]){
            while(arr[i] == arr[i+1]){
                for(int j = i+1; j < arr.size() - 1; j++){
                    a = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = a;
                }
            }
        }
    }
    return k;
}

//optimal
int removeDuplicate(vector<int> arr){
    int i = 0, k = 1;
    for(int j = 1; j < arr.size(); j++){
        if(arr[i] != arr[j]){
            k++;
            i++;
            arr[i] = arr[j];
        }
    }
    return k;
}

int main(){
    vector<int> arr = {1, 2, 2, 2, 3, 3, 4, 7, 7};
    // cout << removeDuplicatesBrute(arr);
    cout << removeDuplicate(arr);
    return 0;
}

//[3, 2, 1, 5, 2] -> [1, 2, 2, 3, 5, 2]