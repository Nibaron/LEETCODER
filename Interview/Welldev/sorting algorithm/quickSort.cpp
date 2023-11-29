/*
* TC--O(NlogN)
* SC--O(logN)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[i + 1], nums[high]);
        return i + 1;
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int pi = partition(nums, low, high);

            quickSort(nums, low, pi - 1);
            quickSort(nums, pi + 1, high);
        }
    }
};

int main() {
    vector<int> nums{3, 5, 1, 7, 9, 2, 4, 8, 6};
    cout << "Before Quick Sort:" << endl;
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl << endl;

    int low = 0, high = nums.size() - 1;
    Solution obj;
    obj.quickSort(nums, low, high);

    cout << "After Quick Sort:" << endl;
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
