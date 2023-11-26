#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void insertionSort(vector<int>& nums)
    {
        int n= nums.size();
        for(int i=1; i<n-1; i++)
        {
            int key= nums[i];
            int j= i-1;
            while(j >= 0 && nums[j] > key)
            {
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1]= key;
        }
    }
};

int main()
{
    vector<int> nums{3,5,1,7,9,2,4,8,6};
    cout<<"Before Insertion Sort:"<<endl;
    for(int num: nums)
    {
        cout<<num<<" ";
    }
    cout<<endl<<endl;

    Solution obj;
    obj.insertionSort(nums);

    cout<<"After Insertion Sort:"<<endl;
    for(int num: nums)
    {
        cout<<num<<" ";
    }
    cout<<endl;

}