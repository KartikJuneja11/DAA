//rotate array to right by k steps
#include<iostream>
#include<vector>
using namespace std;

//not optimal. passes most of the cases 37/38. exceeds time limit
void singleRotate(vector<int>& arr){
    int a, b;
    a = arr[0];
    int j = 1;
    while(j < arr.size()){
        b = arr[j];
        arr[j] = a;
        j++;
        a = b;
    }
    arr[0] = a;
}
void rotate(vector<int>& arr, int k) {
    for(int i = 1; i <= k; i++){
        singleRotate(arr);
    }
}

//optimal
class Solution {
    public:
        void reverse(vector<int>& nums, int l, int r){
            int temp;
            while(l < r){
                swap(nums[l++], nums[r--]);
            }
        }
        void rotate(vector<int>& nums, int k) {
            int n = nums.size();
            if(n==0) return;
    
            k %= n;
            if(k==0) return;
            reverse(nums, 0, n-1);
            reverse(nums, 0, k-1);
            reverse(nums, k, n-1);
        }
    };

int main(){
    return 0;
}

// [1, 2, 3, 4, 5], k = 3
//[3, 4, 5, 1, 2]