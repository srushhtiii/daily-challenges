#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int trapRainWater(const vector<int>& height) {
    int n = height.size();
    if (n <= 2) return 0; 

    vector<int> leftMax(n), rightMax(n);
    
    
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    int totalWater = 0;
    for (int i = 0; i < n; i++) {
        totalWater += min(leftMax[i], rightMax[i]) - height[i];
    }

    return totalWater;
}

int main() {
    int n;
    cout << "Enter the number of bars: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter the heights of the bars: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

  
    int trappedWater = trapRainWater(height);
    cout << "Total water trapped: " << trappedWater << endl;

    return 0;
}
