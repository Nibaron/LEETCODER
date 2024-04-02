****Sliding Window Technique**** is a method used to efficiently solve problems that involve defining a ****window**** or    ****range**** in the input data (arrays or strings) and then moving that window across the data to perform some operation within the    window. This technique is commonly used in algorithms like finding    subarrays with a specific sum, finding the longest substring with    unique characters, or solving problems that require a fixed-size    window to process elements efficiently.

### Types of Sliding Windows:
#  **1. Fixed Sized Window**
![image](https://github.com/Nibaron/LEETCODER/assets/36547410/d35e6af4-dda7-4b0b-890e-ab9373da0adb)

### Template

![image](https://github.com/Nibaron/LEETCODER/assets/36547410/d7c546a6-1414-402a-9df5-19424a300487)
```cpp
       int n=s.size();
        int left=0, right=0;
        int sum=0,maxSum=0;

        while(right<n)
        {
            sum += nums[right];

            if(right-left + 1 == k)
            {
                maxSum= max(maxSum, sum);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return maxSum;
    }
```
Fixed Sliding Window:  
4)[https://leetcode.com/problems/maximum-average-subarray-i/](https://leetcode.com/problems/maximum-average-subarray-i/)(Leetcode 643)  
5)[https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/)(Leetcode 1343)  
6)[https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/](https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/)(Leetcode 1461)  
7)[https://leetcode.com/problems/find-all-anagrams-in-a-string/](https://leetcode.com/problems/find-all-anagrams-in-a-string/)(Leetcode 438)  
8)[https://leetcode.com/problems/permutation-in-string/](https://leetcode.com/problems/permutation-in-string/)(Leetcode 567)  
9)[https://leetcode.com/problems/sliding-window-maximum/](https://leetcode.com/problems/sliding-window-maximum/)(Leetcode 239)  
10)[https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/](https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/)(Leetcode 1876)

# 2. Variable Size Sliding Window

### There have two types of variable size sliding windows
# 2.1 At most / less than or equal
 # [2958. Length of Longest Subarray With at Most K Frequency](https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2024-03-28)

You are given an integer array `nums` and an integer `k`.

The **frequency**  of an element `x` is the number of times it occurs in an array.

An array is called **good**  if the frequency of each element in this array is **less than or equal**  to `k`.

Return the length of the **longest**  **good**  subarray of `nums`.

A **subarray**  is a contiguous non-empty sequence of elements within an array.

**Example 1:** 

```
Input: nums = [1,2,3,1,2,3,1,2], k = 2
Output: 6
Explanation: The longest possible good subarray is [1,2,3,1,2,3] since the values 1, 2, and 3 occur at most twice in this subarray. Note that the subarrays [2,3,1,2,3,1] and [3,1,2,3,1,2] are also good.
It can be shown that there are no good subarrays with length more than 6.
```

**Example 2:** 

```
Input: nums = [1,2,1,2,1,2,1,2], k = 1
Output: 2
Explanation: The longest possible good subarray is [1,2] since the values 1 and 2 occur at most once in this subarray. Note that the subarray [2,1] is also good.
It can be shown that there are no good subarrays with length more than 2.
```

**Example 3:** 

```
Input: nums = [5,5,5,5,5,5,5], k = 4
Output: 4
Explanation: The longest possible good subarray is [5,5,5,5] since the value 5 occurs 4 times in this subarray.
It can be shown that there are no good subarrays with length more than 4.
```

**Constraints:** 

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
- `1 <= k <= nums.length`
# Code
```cpp
```cpp
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n= nums.size();
        int l=0, r=0;

        unordered_map<int,int> freq;
        int count=0;
        while(r<n)
        {
            freq[nums[r]]++;

            while( freq[nums[r]] > k )
            {
                freq[nums[l]]--;
                l++;
            }
            count=max(count, r-l+1);
            r++;
        }
        return count;
    }
};
//https://www.youtube.com/watch?v=txSMzRMREKA
```
**First we will find the longest sub-array,
Then, We can find all the at most sub-arrays that ends with r using r-l+1;
1 2 3
sub-array that ends with 3 is 1 2 3, 2 3, 3 , total= 3 sub-array, 3-1+1=3**

# 2.2 At least 
# [2962. Count Subarrays Where Max Element Appears at Least K Times](https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2024-03-29)

You are given an integer array `nums` and a **positive**  integer `k`.

Return the number of subarrays where the **maximum**  element of `nums` appears **at least**  `k` times in that subarray.

A **subarray**  is a contiguous sequence of elements within an array.

**Example 1:** 

```
Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
```

**Example 2:** 

```
Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.
```

**Constraints:** 

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^6`
- `1 <= k <= 10^5`

# Code
```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi =0;
        for(int num: nums) maxi= max(maxi, num);

        long long maxiCount=0, ans=0;
        int n= nums.size();
        int l=0,r=0;
        while(r<n)
        {
            if(nums[r] == maxi) maxiCount++;

            while(maxiCount >= k )
            {
                ans += n-r;
                if(nums[l] == maxi) maxiCount--;
                l++;
            }
            r++;
        }
        return ans;
    }
};
//https://www.youtube.com/watch?v=06VaWkj8e-0&t=836s
```
**Here, we have used n-r to claculate all the sub-arrays that have at least k counts.
if sub-array of 1-2-3 of 1-2-3-4-5 has minumum count, then,  1-2-3-4 and 1-2-3-4-5 will also have the count to consider.**



Variable Sized Sliding Window:  
15)[https://leetcode.com/problems/count-number-of-nice-subarrays/](https://leetcode.com/problems/count-number-of-nice-subarrays/)(Leetcode 1248)  
16)[https://leetcode.com/problems/fruit-into-baskets/](https://leetcode.com/problems/fruit-into-baskets/)(Leetcode 904)  
17)[https://leetcode.com/problems/max-consecutive-ones-iii/](https://leetcode.com/problems/max-consecutive-ones-iii/)(Leetcode 1004)  
18)[https://leetcode.com/problems/subarray-product-less-than-k/](https://leetcode.com/problems/subarray-product-less-than-k/)(Leetcode 713)  
19)[https://leetcode.com/problems/minimum-size-subarray-sum/](https://leetcode.com/problems/minimum-size-subarray-sum/)(Leetcode 209)  
20)[https://leetcode.com/problems/longest-substring-without-repeating-characters/](https://leetcode.com/problems/longest-substring-without-repeating-characters/)(Leetcode 3)