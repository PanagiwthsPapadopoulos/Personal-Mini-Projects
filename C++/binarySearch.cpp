#include <iostream>
#include <cstdlib>

using namespace std;


int linear(int nums[], int n, int target){
    for(int i=0; i<n; i++){
        if(nums[i] == target) return i;
    }
    return -1;
}

int iterative(int nums[], int n, int target){
    int low = 0; 
    int high = n-1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(nums[mid] == target) return mid;
        else if(nums[mid] > target){
            high = mid-1;
        }
        else low = mid + 1;
    }

    return -1;
}

int recursive(int nums[], int low, int high, int target){
    int mid = (low + high) / 2;

    if(low > high) return -1;

    if(target == nums[mid]) return mid;
    else if(target > nums[mid]) return recursive(nums, mid+1, high, target);
    else return recursive(nums, low, mid-1, target);

}


int main(){

    string input;
    int nums[] = { 2, 5, 6, 8, 9, 10 };
    int target = 8;
    int n = sizeof(nums) / sizeof(nums[0]), i=0, index;
    bool check = false;
    
    do{
        
        cout << "Enter the type of algorithm to use: linear, iterative or recursive. -->";
        cin >> input;

        
        while(input[i] != EOF){
            input[i] = tolower(input[i]);
            i++;
        }

        
        if(input == "linear") {
            index = linear(nums, n, target);
            check = true;
        }
        else if(input == "iterative") {
            index = iterative(nums, n, target);
            check = true;
        }
        else if(input == "recursive") {
            index = recursive(nums, 0, n-1, target);
            check = true;
        }
        else cout << "\nINCORRECT INPUT.\n";
    
    
    }while(check == false);
    
    
    if(index != -1) cout << "\nThe number is in index position " << index <<".\n\n";
    else cout << "\nThe number is not in the given array.\n\n";
    




    return 0;
}