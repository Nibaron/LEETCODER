# [1. Two Sum](https://leetcode.com/problems/two-sum/description/)

 

Given an array of integers `nums`and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have **exactly one solution** , and you may not use the same element twice.
You can return the answer in any order.
**Example 1:**
```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```
**Example 2:**

```
Input: nums = [3,2,4], target = 6
Output: [1,2]
```
**Example 3:**

```
Input: nums = [3,3], target = 6
Output: [0,1]
```
**Constraints:**

-  `2 <= nums.length <= 10^4`

-  `-10^9 <= nums[i] <= 10^9`

-  `-10^9 <= target <= 10^9`

-  **Only one valid answer exists.**
**Follow-up:** Can you come up with an algorithm that is less than `O(n^2)`time complexity?

 

> Brute Force

```c++

class  Solution {
public:
	vector<int> twoSum(vector<int>&  nums, int  target) {
		int n = nums.size();
		for (int i = 0; i < n; ++i) 
		{
			for (int j = i + 1; j < n; ++j) 
			{
				if (nums[i] + nums[j] == target) 
				{ return {i, j};}
			}
		}
// If no solution is found 
//(which should not happen according to the problem constraints)
return {};

	}
};
```

  

> Map

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            int curr = nums[i];
            int need = target - curr;

            if( mp.find(need) != mp.end() ) //if need number is found
            {
                return {i, mp[need]};
            }
            else
            mp[curr]=i;
        }

        return {}; // not found
    }
};
```

  

# [167. Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/)


Given a **1-indexed** array of integers `numbers` that is already **sorted in non-decreasing order** , find two numbers such that they add up to a specific `target` number. Let these two numbers be `numbers[index<sub>1</sub>]` and `numbers[index<sub>2</sub>]` where `1 <= index<sub>1</sub> < index<sub>2</sub> <= numbers.length`.

Return the indices of the two numbers, `index<sub>1</sub>` and `index<sub>2</sub>`, **added by one** as an integer array `[index<sub>1</sub>, index<sub>2</sub>]` of length 2.

The tests are generated such that there is **exactly one solution** . You **may not** use the same element twice.

Your solution must use only constant extra space.
**Example 1:**
```
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. 
Therefore, index<sub>1</sub> = 1, index<sub>2</sub> = 2. We return [1, 2].
```

**Example 2:**

```
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. 
Therefore index<sub>1</sub> = 1, index<sub>2</sub> = 3. We return [1, 3].
```
**Example 3:**

```
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. 
Therefore index<sub>1</sub> = 1, index<sub>2</sub> = 2. We return [1, 2].

```

**Constraints:**
-  `2 <= numbers.length <= 3 * 10^4`

-  `-1000 <= numbers[i] <= 1000`

-  `numbers` is sorted in **non-decreasing order** .

-  `-1000 <= target <= 1000`

- The tests are generated such that there is **exactly one solution** .

> My Code
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> nums;
        int l = 0;
        int r= numbers.size()-1;
        while(l<=r)
        {
            if(numbers[l]+numbers[r]== target)
            {
                nums.push_back(l+1);
                nums.push_back(r+1);
                break; 
            }
            else if(numbers[l]+numbers[r] > target)
            {
                r--;
            }
            else 
            {
                l++;
            }
        }
        return nums;
    }
};
```

# [15. 3Sum](https://leetcode.com/problems/3sum/description/)

Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.

**Example 1:** 

```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
```

**Example 2:** 

```
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
```

**Example 3:** 

```
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
```

**Constraints:** 

- `3 <= nums.length <= 3000`
- `-10^5 <= nums[i] <= 10^5`


> Using 2SUM approach
```cpp
class Solution {
private:
    void twoSum(vector<int>& nums, int target, int idx, vector<vector<int>>& result) {
        
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (i == idx) continue;
            
            int curr = nums[i];
            int need = target - curr;

            if (mp.find(need) != mp.end()) 
            {
                result.push_back({ nums[idx], curr, need });
            }
            mp[curr]++;
        }
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;

        // Sort the input array to facilitate the two-pointer approach
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            
            // Avoid duplicate target values
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            vector<vector<int>> temp;
            twoSum(nums, -nums[i], i, temp); // Find pairs that sum up to -nums[i]

            for (auto& triplet : temp) {
                sort(triplet.begin(), triplet.end());
                st.insert(triplet); // Use a set to avoid duplicate triplets
            }
        }

        for (auto& triplet : st) {
            ans.push_back(triplet);
        }

        return ans;
    }
};
```

<B> BUT it will face TLE.
So, we need better approach, binary search is good.
</B> 

> Code
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        set <vector<int>> st;
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<n-2; i++)  // move for a
        {
                int low=i+1, high= n-1, sum= 0 -nums[i]; // two pointer for b & c
                
                while(low < high)
                {
                    if( (nums[low] + nums[high] == sum) && st.count({nums[i], nums[low], nums[high]})==0 )
                    {
                        vector<int> temp;            //push reslut
                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        
                        ans.push_back(temp);
                        st.insert(temp);
                        
                        low++; high--;
                    }
                    
                    else if(nums[low] + nums[high] < sum) low++;
                    
                    else
                        high--;
                }
            }
        return ans;
    }
};
```
>Best Code
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.front()>0 || nums.back()<0) return {};
        
        vector<vector<int>> ans;
        int n=nums.size();
        
        for(int i=0; i<n-2; i++) 
        {
            //avoid duplicate number
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            int left = i+1, right = n-1, target = -nums[i];
            while(left<right) 
            {
                if( nums[left] + nums[right] == target) 
                {
                    ans.push_back( {nums[i], nums[left], nums[right]} );

                    //avoid repeating
                    while( left < right && nums[left+1] == nums[left] ) left++;
                    while( right > left && nums[right] == nums[right-1] ) right--;

                    left++;
                    right--;
                } 
                else if( nums[left] + nums[right] < target) left++;
                else right--;
            }
        }
        
        return ans;
    }
};
```