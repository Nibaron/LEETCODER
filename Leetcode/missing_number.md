# [287. Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/description/?envType=daily-question&envId=2024-03-24)

Given an array of integers `nums` containing`n + 1` integers where each integer is in the range `[1, n]` inclusive.

There is only **one repeated number**  in `nums`, return thisrepeatednumber.

You must solve the problem **without**  modifying the array `nums`and uses only constant extra space.

**Example 1:** 

```
Input: nums = [1,3,4,2,2]
Output: 2
```

**Example 2:** 

```
Input: nums = [3,1,3,4,2]
Output: 3
```

**Example 3:** 

```
Input: nums = [3,3,3,3,3]
Output: 3
```

**Constraints:** 

- `1 <= n <= 10^5`
- `nums.length == n + 1`
- `1 <= nums[i] <= n`
- All the integers in `nums` appear only **once**  except for **precisely one integer**  which appears **two or more**  times.

<b>Follow up:</b>
- How can we prove that at least one duplicate number must exist in `nums`?
- Can you solve the problem in linear runtime complexity?

### Approach 1: Using Sorting


#### Complexity
 - Time complexity:  **O(n log n)**
- Space complexity:  **O(n)**

#### Code
```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                return nums[i];
        }
        return -1;
    }
};
```

### Approach 2: Using Set
#### Code
```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_set<int> seen;

        for (auto &num : nums) 
        {
            if ( seen.count(num) == 1) return num;
            seen.insert(num);
        }
        
        return -1;
    }
};
```
# Approach 3: Slow and Fast Pointer

-   ##### The key intuition behind this method is that if there's a cycle in the linked list, the fast and slow pointers will eventually meet.
    
-   ##### We treat the array as a linked list, where the index represents the node and the value at that index represents the next node.
    
-   ##### Using the fast-slow pointers technique, we traverse the linked list.
    
-   ##### The slow pointer moves one step at a time while the fast pointer moves two steps at a time.
    
-   ##### If there's a cycle in the linked list (indicating a duplicate number), the fast and slow pointers will eventually meet.
    
-   ##### After identifying the meeting point, we reset the slow pointer to the start and move both pointers at the same pace until they meet again. The meeting point will be the duplicate number.
    

## Complexity

-   Time complexity: O(N)

-   Space complexity: O(1)

https://www.youtube.com/watch?v=49HrEGt6D2s&t=1098s

![image](https://github.com/Nibaron/LEETCODER/assets/36547410/fbb70b34-a532-429e-b17b-7d7bbe4c3c7d)

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow= nums[0];
        int fast= nums[0];

        //we find the intersection point
        // at first, both same, 
        //so we first move one point then start comparing
        //thats why we are using do while, not only while.
        do{
            slow = nums[slow];
            fast= nums[nums[fast]];
        } while(slow != fast);

        //slow indicates the intersection point
        // we move the fast[0] to slow to point out the intersection point 
        fast= nums[0];
        while(fast != slow)
        {
            fast= nums[fast];
            slow= nums[slow];
        }

        return fast; //or return slow;
    }
};
```
`
# Approach 4: Cycle detection algorithm

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n= nums.size();
        for(int i=0; i<n; i++)
        {
            int temp = abs(nums[i]); // copy the number
            if(nums[temp] < 0 ) return temp; // check the temp'th number, negative marked or not
            else nums[temp] = nums[temp] * (-1);
        }
        return -1;
    }
};

/*
index = 0 1 2 3 4
number= 1 3 4 2 2

1st iteration, temp= 1, nums[1]=3 > 0, so we will make it -3
number= 1 -3 4 2 2

2nd iteration, temp= -3, abs(-3)= 3, nums[3]=2 > 0, so we will make it -2
number= 1 -3 4 -2 2

3rd iteration, temp= 4, nums[4]=2 > 0, so we will make it -2
number= 1 -3 4 -2 -2

4th iteration, temp= -2,|-2|=2, nums[2]=4 > 0, so we will make it -4
number= 1 -3 -4 -2 -2

5th iteration, temp= -2,|-2|=2, nums[2]=-4 < 0, so we will return 2;
*/
```

# [442. Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/description/?envType=daily-question&envId=2024-03-25)

Given an integer array `nums` of length `n` where all the integers of `nums` are in the range `[1, n]` and each integer appears **once**  or **twice** , return an array of all the integers that appears **twice** .

You must write an algorithm that runs in`O(n)`time and uses only constant extra space.

**Example 1:** 

```
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
```

**Example 2:** 

```
Input: nums = [1,1,2]
Output: [1]
```

**Example 3:** 

```
Input: nums = [1]
Output: []
```

**Constraints:** 

- `n == nums.length`
- `1 <= n <= 10^5`
- `1 <= nums[i] <= n`
- Each element in `nums` appears **once**  or **twice** .

### Approach 1 : With Map
# Code
```
```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int num: nums) mp[num]++;

        vector<int> ans;
        for(auto [num,count]: mp)
        {
            if(count == 2) ans.push_back(num);
        }

        return ans;
    }
};
```

### Follow Up
# Code
```
```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(int i=0; i<nums.size(); i++)
        {
            int num = abs( nums[i]);
            int idx = num-1; //nums size 8, so index 0-7, but 8 exist in nums, so -1 is needed
            if( nums[idx] < 0) ans.push_back(num);
            else nums[idx] *= -1;
        }

        return ans;
    }
};

// index marking approach
//MIK
```

# [41. First Missing Positive](https://leetcode.com/problems/first-missing-positive/description/?envType=daily-question&envId=2024-03-26)

Given an unsorted integer array `nums`. Return the smallest positive integer that is not present in `nums`.

You must implement an algorithm that runs in `O(n)` time and uses `O(1)` auxiliary space.

**Example 1:** 

```
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
```

**Example 2:** 

```
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
```

**Example 3:** 

```
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
```

**Constraints:** 

- `1 <= nums.length <= 10^5`
- `-2^31 <= nums[i] <= 2^31 - 1`

Video: https://www.youtube.com/watch?v=aBhla9jSAeg

### Approach 1 : Extra Space
# Code
```
```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n= nums.size();
        vector<bool> hash(n+2, false);

        for(int num: nums)
        {
            if(num > 0 and num <= n) hash[num] = true;
        }

        for(int i=1; i<= n+1; i++)
        {
            if( hash[i] == false) return i;
        }

        // not found
        return -1;
    }
};
```

### Follow Up
# Code
```cpp
class  Solution {

public:

    int  firstMissingPositive(vector<int>&  nums) {

        int n= nums.size();

        // we make the children sit on their own chair
        for(int i=0; i<n; i++)
        {
            int child = nums[i]; // 4
            // for negative and greater number it can not be children
            if( child >= 1 && child <= n )
            {
                int chair = child -1; // 3 ( child 4 should sit on chair 3 or nums at 3)

                if(nums[chair] != child ) // if children siting wrong position
                {
                    swap( nums[chair], nums[i]);
                    i--;
                }
            }
        }
        // we check missing chair
        int i;

        for(i=0; i<n; i++)
        {
            if( i+1 != nums[i] ) return i+1;
        }

        //if all children siting the right position, we answer the i+1
        return i+1;
        }
};

// alisha di's mother and children algorith

//https://www.youtube.com/watch?v=aBhla9jSAeg

  
/*

* right position
* 1 2 3 4 (children)
* 0 1 2 3 (chair)

*
*wrong position

*

*/