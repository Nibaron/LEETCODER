#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void selectionSort(vector<int>& nums)
    {
        int n= nums.size();
        for(int i=0; i<n-1; i++)
        {
            int min_IDX= i;
            for(int j=i+1; j<n; j++)
            {
                if( nums[min_IDX] > nums[j] ) min_IDX= j;
            }
            swap(nums[i], nums[min_IDX]);
        }
    }
};

int main()
{
    vector<int> nums{3,5,1,7,9,2,4,8,6};
    cout<<"Before Selection Sort:"<<endl;
    for(int num: nums)
    {
        cout<<num<<" ";
    }
    cout<<endl<<endl;

    Solution obj;
    obj.selectionSort(nums);

    cout<<"After Selection Sort:"<<endl;
    for(int num: nums)
    {
        cout<<num<<" ";
    }
    cout<<endl;

}