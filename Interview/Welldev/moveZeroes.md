# Brute Force


- Time complexity: $$O(n^2)$$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $$O(1)$$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
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
};
```
# Extra Space


- Time complexity: $$O(n)$$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $$O(n)$$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
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
};
```
# 2 Pointers : The best


- Time complexity: $$O(n)$$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $$O(n)$$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int j=0;
        for (int i=0; i<nums.size(); i++)
        {
            if(nums[i] != 0) swap(nums[i],nums[j++]);
        }
        
    }
};
```
# Snowball


- Time complexity: $$O(n)$$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $$O(1)$$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
    public:
     void moveZeroes(vector<int>& nums) {
        int snowball=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                snowball++;
            }

            else if(snowball>0){
                nums[i-snowball]=nums[i];
                nums[i]=0;
            }
        }
    }
};
```