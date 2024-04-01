# [56. Merge Intervals](https://leetcode.com/problems/merge-intervals/description/)

Given an arrayof `intervals`where `intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]`, merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

**Example 1:** 

```
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
```

**Example 2:** 

```
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

**Constraints:** 

- `1 <= intervals.length <= 10^4`
- `intervals[i].length == 2`
- `0 <= start<sub>i</sub> <= end<sub>i</sub> <= 10^4`

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The intuition behind this solution is to first sort the intervals based on their start times. This allows us to merge overlapping intervals efficiently. By iterating through the sorted intervals, we can compare adjacent intervals and either merge them or add the non-overlapping interval to the answer.
# Approach
<!-- Describe your approach to solving the problem. -->
1. Sort the intervals based on their start times.
2. Initialize an empty vector ans to store the merged intervals.
3. Iterate through the sorted intervals:
- If the current interval overlaps with the previous interval, update the current interval's start and end to encompass both intervals.
- If there's no overlap, push the previous interval to the ans vector.
4. Push the last interval (whether merged or not) to the ans vector.
5. Return the ans vector containing the merged intervals.

# visualization
`Intervals`
```
1        3
2 (i=1)  6 -->here,2<=3 true, so, min(2,1)=1, max(3,6)=6 --> 1  6
8 (i=2) 10 --> false, so, push previous value to ans([1,6])
12(i=3) 18 --> false, so, push i-1'th value to ans([1,6],[8,10])

at last push n-1'th value to ans ([1,6],[8,10],[12, 18]);
```
# Complexity
The time complexity is dominated by the sorting step, which takes O(n log n) time. The subsequent iteration through the sorted intervals takes linear time O(n).
- Time complexity:  $$ O( n*logn )$$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
The space complexity is mainly determined by the storage of the merged intervals in the ans vector, which can be at most O(n) in the worst case.
- Space complexity: $$ O( n )$$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        int n = inter.size();
        if (n == 1) return inter;
        sort(inter.begin(), inter.end());

        vector<vector<int>> ans;
        
        for (int i = 1; i < n; i++) {
            //if contidion is true, update the ith interval
            if (inter[i][0] <= inter[i-1][1]) {

                inter[i][0] = min(inter[i][0], inter[i-1][0]);
                inter[i][1] = max(inter[i][1], inter[i-1][1]);
            } 
            //else push the previos interval
            else {
                ans.push_back(inter[i-1]);
            }
        }
        // Push the last merged interval
        ans.push_back(inter[n-1]);
        return ans;
    }
};

```

# [57. Insert Interval](https://leetcode.com/problems/insert-interval/description/?envType=daily-question&envId=2024-03-17)

You are given an array of non-overlapping intervals `intervals` where `intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]` represent the start and the end of the `i^th` interval and `intervals` is sorted in ascending order by `start<sub>i</sub>`. You are also given an interval `newInterval = [start, end]` that represents the start and end of another interval.

Insert `newInterval` into `intervals` such that `intervals` is still sorted in ascending order by `start<sub>i</sub>` and `intervals` still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return `intervals` after the insertion.

**Note**  that you don't need to modify `intervals` in-place. You can make a new array and return it.

**Example 1:** 

```
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
```

**Example 2:** 

```
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
```

**Constraints:** 

- `0 <= intervals.length <= 10^4`
- `intervals[i].length == 2`
- `0 <= start<sub>i</sub> <= end<sub>i</sub> <= 10^5`
- `intervals` is sorted by `start<sub>i</sub>` in **ascending**  order.
- `newInterval.length == 2`
- `0 <= start <= end <= 10^5`


# Code
```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();

        if(n == 0) return {newInterval};
        intervals.push_back(newInterval);
        //n has been updated
        n=intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(int i=1; i<n; i++)
        {
            if( intervals[i][0] <= intervals[i-1][1] ){
                intervals[i][0]= min(intervals[i][0], intervals[i-1][0]);
                intervals[i][1]= max(intervals[i][1], intervals[i-1][1]);
            }
            else{
                ans.push_back(intervals[i-1]);
            }
        }
        ans.push_back(intervals[n-1]);

        return ans;
    }
};
/*
* this code is totally same as merge intervals, 
* we have added new interval to intervals
* and have done the merging intervals
*/
```

# [452. Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=daily-question&envId=2024-03-18)

There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array `points` where `points[i] = [x<sub>start</sub>, x<sub>end</sub>]` denotes a balloon whose **horizontal diameter**  stretches between `x<sub>start</sub>` and `x<sub>end</sub>`. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up **directly vertically**  (in the positive y-direction) from different points along the x-axis. A balloon with `x<sub>start</sub>` and `x<sub>end</sub>` is **burst**  by an arrow shot at `x` if `x<sub>start</sub> <= x <= x<sub>end</sub>`. There is **no limit**  to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array `points`, return the **minimum**  number of arrows that must be shot to burst all balloons.

**Example 1:** 

```
Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
```

**Example 2:** 

```
Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.
```

**Example 3:** 

```
Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
```

**Constraints:** 

- `1 <= points.length <= 10^5`
- `points[i].length == 2`
- `-2^31 <= x<sub>start</sub> < x<sub>end</sub> <= 2^31 - 1`

# Code
```cpp
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n= points.size();

        sort(points.begin(), points.end());
        vector<int> prev= points[0];
        
        int count=1;
        for(int i=1; i<n; i++)
        {
            vector<int> curr= points[i];

            if( curr[0] > prev[1]) //(prev=(1,4), curr=(5,7), 5>4, so no overlapping)
            {
                count++; //no overlapping, we need arrow
                prev= curr;
            }
            else //overlapping ocuurs, update previos //1,6 && 2,8
            {
                int newStart= max( prev[0], curr[0]);  //2
                int newEnd  = min(prev[1], curr[1]);   //6
                prev= {newStart, newEnd};
            }
        }
        return count;
    }
};
```