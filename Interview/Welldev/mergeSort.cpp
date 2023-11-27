/*
* TC--O(NlogN)
* SC--O(N)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void merge(vector<int>& nums, int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;

        // Create temporary arrays
        vector<int> L(n1), R(n2);

        // Copy data to temporary arrays L[] and R[]
        for (int i = 0; i < n1; i++)
            L[i] = nums[l + i];
        for (int j = 0; j < n2; j++)
            R[j] = nums[m + 1 + j];

        // Merge the temporary arrays back into arr[l..r]
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) 
        {
            if (L[i] <= R[j]) 
            {
                nums[k] = L[i];
                i++;
            } 
            else 
            {
                nums[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of L[], if there are any
        while (i < n1) 
        {
            nums[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[], if there are any
        while (j < n2) 
        {
            nums[k] = R[j];
            j++;
            k++;
        }

    }
    void mergeSort(vector<int>& nums, int l, int r)
    {
        if(l<r)
        {
            int m= (l+r)/2;
            mergeSort(nums, l, m);
            mergeSort(nums, m+1, r);

            merge(nums, l, m, r);
        }
    }
};

int main()
{
    vector<int> nums{3,5,1,7,9,2,4,8,6};
    cout<<"Before Merge Sort:"<<endl;
    for(int num: nums)
    {
        cout<<num<<" ";
    }
    cout<<endl<<endl;

    int l=0, r=nums.size()-1;
    Solution obj;
    obj.mergeSort(nums,l,r);

    cout<<"After Merge Sort:"<<endl;
    for(int num: nums)
    {
        cout<<num<<" ";
    }
    cout<<endl;

}