#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void bubbleSort(vector<int>& nums)
    {
        int n= nums.size();
        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<n-i-1; j++)
            {
                if(nums[j] > nums[j+1])
                    swap(nums[j], nums[j+1]);
            }
        }
    }
};

int main()
{
    vector<int> nums{3,5,1,7,9,2,4,8,6};
    cout<<"Before Bubble Sort:"<<endl;
    for(int num: nums)
    {
        cout<<num<<" ";
    }
    cout<<endl<<endl;

    Solution obj;
    obj.bubbleSort(nums);

    cout<<"After Bubble Sort:"<<endl;
    for(int num: nums)
    {
        cout<<num<<" ";
    }
    cout<<endl;

}