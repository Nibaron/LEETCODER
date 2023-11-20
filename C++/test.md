# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
what happens when we get 1 to 10 numbers of 2's, check minimum numbers of operations to make the array empty...
```
number -- combinations -- minimun operations
1  --> X(no combination)   --> -1
2  --> 22                  --> 1
3  --> 222                 --> 1 
4  --> 22 | 22             --> 2
5  --> 222 | 22            --> 2
6  --> 222 | 222           --> 2
7  --> 222 | 22 | 22       --> 3
8  --> 222 | 222 | 22      --> 3
9  --> 222 | 222 | 222     --> 3
10 --> 222 | 222 | 22 | 22 --> 4
```
so i guess you can see there have a pattern of changes.
1. if number is divisable by 3, number of operations is= num / 3
for 6, it is `6/3 = 2`.
2. but if it is not divisable? then what ? 
 check for 8, `8/3 = 2` , but minimum operations are 3 !!
so, if `8 % 3 != 0`, we need one extraa operation. `2+1 = 3`, we have got our answer.
3. Do not forget 1, here we failed to empty the array, so return -1.

**Now Check the code.**
  

# Complexity
- Time complexity: $$O(n)$$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $$O(n)$$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code 1
```
class Solution {
public:
    int minOperations(vector<int>& nums) {

        unordered_map<int, int> mp;
        for(int num: nums)
        {
            mp[num]++;
        }
        
        int ans=0;
        for(auto num: mp)
        {   
            if( num.second == 1) return -1; 
            
            int val = num.second/3;
            int rem = num.second%3;
            
            if(rem > 0) val++;
            
            ans += val;
        }
        return ans;
    }
};
```
# Code 2
```
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> mp;
        for(auto num: nums) mp[num]++;
        
        
        for(auto num:mp)
        {
            int pair3=0, pair2=0;

            if( num.second == 1 ) // no possible combination
            {
                return -1;
            }

            else if( num.second%3 == 0 ) //totally divisible by 3
            {
                pair3 = num.second/3;
            }

            else if( num.second%3 == 1) // 4, 7, 10 
            {
                /* 222 | 2 --> | 222 2 --> 22 | 22 */
                pair3 = (num.second/3) - 1; // we have break a pair3 = so we have 3+1=4 number
                pair2 = 2; //4 number can make 2 pair2
            }
            else if( num.second%3 == 2 ) // 5,8,11
            {
                /* 222 | 22 */
                pair3= num.second/3;
                pair2= 1; //rem 2 will make one pair2
            }

            ans += pair3;
            ans += pair2;
        }
        return ans;
    }
};
```
