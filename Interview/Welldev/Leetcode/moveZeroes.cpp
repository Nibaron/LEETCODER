#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    /*
     * it will take two for loops, TC -- O(n^2)
     * 1 2 3 4 5 0 0 0 0 0 
     */
    void zeroMover1(vector<int>& nums)
    {
        int n=nums.size();
        
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0 && i != n-1)
            {
                for(int j=i+1; j<n; j++)
                {
                    if(nums[j] != 0)
                        {
                            swap(nums[i], nums[j]);
                            break;
                        }
                }
            }
        }
    }
    
    //with extra space
    // TC: O(n) SC: O(n)
    void zeroMover2(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> ans(n,0);
        
        int i=0;
        for(int num : nums)
        {
            if(num != 0)
            {
                ans[i++]=num;
            }
        }
        nums= ans;
        
    }
    
    //it will move the zero, but relative position is changed
    //output : 1 5 2 4 3 0 0 0 0 0 
    // TC: O(n) SC: O(1)
    void zeroMover3(vector<int>& nums)
    {
        int n= nums.size();
        int l=0, r=n-1;
        
        while(l<=r)
        {
            if( nums[l] == 0 )
            {
                swap(nums[l], nums[r--]);
            }
            
            if(nums[l] != 0) l++;
        }
    }
    
    
    
};

int main()
{
    vector<int> nums={1,0,2,0,0,3,0,4,5,0};
    
    class Solution ob1;
    ob1.zeroMover2(nums);
    
    for(int num: nums)
    {
        cout<<num<<" ";
    }

    return 0;
}
