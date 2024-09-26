#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(const vector<int>& nums) {
    
    int slow = nums[0];
    int fast = nums[0];

   
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow; 
}

int main() {
    
    vector<int> arr = {5, 3, 1, 4, 2, 5}; 
    int duplicate = findDuplicate(arr);
    
    cout << "The duplicate number is: " << duplicate << endl; 

    return 0;
}
