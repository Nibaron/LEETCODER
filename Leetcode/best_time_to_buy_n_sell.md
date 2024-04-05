# [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i^th` day.

You want to maximize your profit by choosing a **single day**  to buy one stock and choosing a **different day in the future**  to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return `0`.

**Example 1:** 

```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```

**Example 2:** 

```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
```

**Constraints:** 

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^4`

# 1. Brute Force (TLE)
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp =0, n=prices.size();

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                mp= max(mp, prices[j]-prices[i]);
            }
        }
        return mp;
    }
};
```
# 2. One Pass
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int maxProfit = 0;

        for(int i=1; i<n; i++)
        {
            int sell = prices[i];
            maxProfit=max(maxProfit, sell-buy);

            buy = min(buy, sell); 
        }
        return maxProfit;
    }
};
```

### Visualization
```sql
Day    Buy    Sell    Max Profit
1      7      -       0
2      1      -       0
3      1      5       4
4      1      3       4
5      1      6       5
6      1      4       5
 ```
 
 # [122. Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/)

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `i^th` day.

On each day, you may decide to buy and/or sell the stock. You can only hold **at most one**  share of the stock at any time. However, you can buy it then immediately sell it on the **same day** .

Find and return the **maximum**  profit you can achieve.

**Example 1:** 

```
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
```

**Example 2:** 

```
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
```

**Example 3:** 

```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
```

**Constraints:** 

- `1 <= prices.length <= 3 * 10^4`
- `0 <= prices[i] <= 10^4`

# 1. Greedy Approach
**To calculate profit we need to consider each `Local Minima` and Next `Local Maxima`.**

![image](https://assets.leetcode.com/users/images/1331ada2-8d61-4da7-a44d-5544fcdfbcb7_1662411077.8817523.jpeg)

  
# profit = (7-2) + (6-3) + (4-1) =11

**See the last profit criteria,**

here we have avoided value 2, because our maxima is 4.

so, **( 4-1) = 3**
but,
**2-1 = 1 & 4-2 = 2
and 1+2 = 3**
That also gives the same result.
so, we can simply calculate the profit, without avoid middle values.

```cpp
if(prices[i]>prices[i-1])
	profit += (prices[i]-prices[i-1]);
```


The code is simple and clean:
```cpp

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0;
		for( int i=1; i< prices.size(); i++)
		{
			if(prices[i]>prices[i-1])
			profit += (prices[i]-prices[i-1]);
		}
		
		return profit;
    }
};
```

# 2. DP Approach

# Intuition
The problem requires finding the maximum profit that can be achieved by buying and selling stocks, given a list of stock prices. We can use a recursive approach with memoization to keep track of already computed results and avoid redundant calculations.
![image](https://github.com/Nibaron/LEETCODER/assets/36547410/d54d0a5e-5a32-4acc-8f01-0e813c11e6c0)
# Approach
1. Implement a recursive function `solve` that simulates buying and selling stocks at each index, considering whether the action taken is to buy or sell.
2. Use memoization to store already computed results to avoid recalculating them.
3. Start the recursion from index 0 with the buying flag set to true (1) because we will first buy then sell.
4. Return the maximum profit obtained.

# Complexity
- Time complexity: \( O(n) \), where \( n \) is the number of stock prices.
- Space complexity: \( O(n) \) for the memoization array.

# Code

```cpp
class Solution {
public:
int solve(int ind, vector<int> &prices, bool buy, vector<vector<int>> &memo)
{    
    if( ind >= prices.size() ) return 0;
    
    if( memo[ind][buy] != -1 ) return memo[ind][buy];
    
    if(buy) //if we are buying then next time we will sell else next time we will buy
    {      //-prices[i], because bought stock of prices[i], expend money, !buy because next time sell
        
       return memo[ind][buy]=max(-prices[ind]+solve(ind+1,prices,!buy,memo),solve(ind+1,prices,buy,memo));  
    }
    else   //it's time to sell 
    {      //+prices[i], because we now gain (i.e) sell our stock at rate of prices[i]
        
       return memo[ind][buy]=max(prices[ind]+solve(ind+1,prices,!buy,memo),solve(ind+1,prices,buy,memo));  
    }
     
}
    int maxProfit(vector<int>& prices) {
        
        int n= prices.size();
        if( n<2 ) return 0;

        vector<vector<int>> memo(n+1,vector<int>(2,-1));
        //passing here buy=1 because we will first buy then sell 
        return solve(0,prices,1,memo); 
    }
};
```

# Best to underStand
```cpp
class Solution {
    int dp[30003][2];
private:
    int solve(int ind , bool canBuy , vector<int>& prices){
        if( ind >= prices.size() ) return 0;

        if( dp[ind][canBuy] != -1 ) return dp[ind][canBuy];
        
        int ans = 0;
        if(canBuy)
        {
            int buy = -prices[ind] + solve(ind+1 , !canBuy , prices);
            int notBuy = 0 + solve(ind+1 , canBuy , prices);
            
            ans = max(ans , max(buy , notBuy));
        }
        else
        {
            int sell = prices[ind] + solve(ind+1 , !canBuy , prices);
            int notSell = 0+ solve(ind+1 , canBuy , prices);
            
            ans = max(ans , max(sell , notSell));
        }
        
        return dp[ind][canBuy] = ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(0,1,prices);
    }
};
```
# [123. Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/)

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i^th` day.

Find the maximum profit you can achieve. You may complete **at most two transactions** .

**Note:**  You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

**Example 1:** 

```
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
```

**Example 2:** 

```
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
```

**Example 3:** 

```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```

**Constraints:** 

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^5`
This code implements the `solve` function recursively with memoization to find the maximum profit that can be obtained by buying and selling stocks at various indices.

```cpp
class Solution {
public:
    int find(vector<int> &prices,int ind,bool buy,int c,vector<vector<vector<int>>> &memo)
    {   
        //if buy =1 means we have to buy now
        //else we have to sell now
        if( ind >= prices.size() || c >= 2) return 0; //counter
        
        if( memo[ind][buy][c] != -1 ) return memo[ind][buy][c];
        
        if(buy) //now we can either buy prices[i] or we can skip it and try next to buy
        {
            return memo[ind][buy][c]=max(-prices[ind]+find(prices,ind+1,!buy,c,memo),find(prices,ind+1,buy,c,memo));
        }
        else  //now we can either sell prices[i] or we can skip it and try next to sell
        {
            return memo[ind][buy][c]=max(prices[ind]+find(prices,ind+1,!buy,c+1,memo),find(prices,ind+1,buy,c,memo));
        }
        
    }
    int maxProfit(vector<int>& prices) {
        //here we can do maximum two transaction
        //Use 3-D vector because here three states i,k,buy/sell
        vector<vector<vector<int>>> memo(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
          
       return find(prices,0,1,0,memo); 
    }
};
```

# [188. Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/)

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `i^th` day, and an integer `k`.

Find the maximum profit you can achieve. You may complete at most `k` transactions: i.e. you may buy at most `k` times and sell at most `k` times.

**Note:**  You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

**Example 1:** 

```
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
```

**Example 2:** 

```
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
```

**Constraints:** 

- `1 <= k <= 100`
- `1 <= prices.length <= 1000`
- `0 <= prices[i] <= 1000`

```cpp
class Solution {
    int memo[1001][2][101];
private:
    int solve( int ind, int buy, int count,int k, vector<int>& prices, int memo[][2][101])
    {
        if( ind >= prices.size() || count >= k) return 0;
        if( memo[ind][buy][count] != -1) return memo[ind][buy][count];

        if( buy)
        {
            memo[ind][buy][count] = max( -prices[ind]+solve(ind+1, 0, count, k, prices, memo) ,
                                    0+solve(ind+1, 1, count, k, prices, memo));
        }
        else
        {
            memo[ind][buy][count] = max( prices[ind]+solve(ind+1, 1, count+1, k, prices, memo) ,
                                    0+solve(ind+1, 0, count, k, prices, memo));
        }
        return memo[ind][buy][count];
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        memset(memo, -1, sizeof(memo));

        return solve(0, 1, 0, k , prices, memo );
    }
};
```
# [309. Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/)

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i^th` day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

- After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

**Note:**  You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

**Example 1:** 

```
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
```

**Example 2:** 

```
Input: prices = [1]
Output: 0
```

**Constraints:** 

- `1 <= prices.length <= 5000`
- `0 <= prices[i] <= 1000`

```cpp
class Solution {
private:
    int solve( int ind, int buy, vector<int>& prices, int memo[][2])
    {
        if( ind >= prices.size()) return 0;

        if( memo[ind][buy] != -1) return memo[ind][buy];

        if( buy )
        {
            memo[ind][buy] = max( -prices[ind] + solve(ind+1, 0, prices,memo),
                                    0+ solve(ind+1, 1, prices,memo));
        }
        else
        {
            memo[ind][buy] = max( prices[ind] + solve(ind+2, 1, prices,memo),
                                    0+ solve(ind+1, 0, prices,memo));
        }
        return memo[ind][buy];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int memo[n][2];
        memset(memo, -1, sizeof(memo));

        return solve( 0, 1, prices, memo);
    }
};
```
# [714. Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/)

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i^th` day, and an integer `fee` representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

**Note:** 

- You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
- The transaction fee is only charged once for each stock purchase and sale.

**Example 1:** 

```
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
```

**Example 2:** 

```
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
```

**Constraints:** 

- `1 <= prices.length <= 5 * 10^4`
- `1 <= prices[i] < 5 * 10^4`
- `0 <= fee < 5 * 10^4`

```cpp
class Solution {
private:
    int solve(int ind, bool buy, vector<int>&prices, vector<vector<int>>& memo, int fee)
    {
        if( ind >= prices.size()) return 0;
        if(memo[ind][buy] != -1) return memo[ind][buy];

        if(buy)
        {
            //max( buy and explore, explore )
            return memo[ind][buy] = max( -prices[ind]+solve(ind+1, !buy, prices,memo,fee), solve(ind+1, buy, prices,memo,fee));
        }
        else //max( buy and explore, explore )
         return memo[ind][buy] = max( prices[ind]-fee+solve(ind+1, !buy, prices,memo,fee), solve(ind+1, buy, prices,memo,fee));
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        if(n<2) return 0;

        vector<vector<int>> memo(n+1,vector<int>(2,-1));
        return solve(0,1,prices,memo,fee);
    }
};
```

```cpp
class Solution {
    int dp[50005][2], FEE;
private:
    int solve(int i, int canBuy, vector<int>& prices)
    {
        //base case
        if( i >= prices.size() ) return 0;

        //memoization
        if( dp[i][canBuy] != -1) return dp[i][canBuy];

        int ans=0;
        if( canBuy)
        {
            int buy     = -prices[i] + solve(i+1, 0, prices);
            int skipBuy = 0 + solve(i+1, 1, prices);

            ans = max( ans, max(buy, skipBuy));
        }
        else
        {
            int sell    = prices[i] - FEE + solve(i+1, 1, prices);
            int skipSell = 0 + solve(i+1, 0, prices);

            ans = max( ans, max(sell, skipSell));
        }
        return dp[i][canBuy] = ans;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
       int n = prices.size();
       memset(dp,-1,sizeof(dp));
       FEE = fee;
        return solve(0,1,prices);
    }
};
```