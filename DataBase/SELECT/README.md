# [1757. Recyclable and Low Fat Products](https://leetcode.com/problems/recyclable-and-low-fat-products/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Products`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product_id  | int     |
| low_fats    | enum    |
| recyclable  | enum    |
+-------------+---------+
product_id is the primary key (column with unique values) for this table.
low_fats is an ENUM (category) of type ('Y', 'N') where 'Y' means this product is low fat and 'N' means it is not.
recyclable is an ENUM (category) of types ('Y', 'N') where 'Y' means this product is recyclable and 'N' means it is not.```

Write a solution to find the ids of products that are both low fat and recyclable.
```
Return the result table in **any order** .

The result format is in the following example.

**Example 1:**
```
Input: 
Products table:
+-------------+----------+------------+
| product_id  | low_fats | recyclable |
+-------------+----------+------------+
| 0           | Y        | N          |
| 1           | Y        | Y          |
| 2           | N        | Y          |
| 3           | Y        | Y          |
| 4           | N        | N          |
+-------------+----------+------------+
Output: 
+-------------+
| product_id  |
+-------------+
| 1           |
| 3           |
+-------------+
Explanation: Only products 1 and 3 are both low fat and recyclable.
```

> The Code
```sql
SELECT product_id

FROM Products

WHERE low_fats="Y"  AND recyclable="Y";
```

# [584. Find Customer Referee](https://leetcode.com/problems/find-customer-referee/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Customer`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| referee_id  | int     |
+-------------+---------+
In SQL, id is the primary key column for this table.
Each row of this table indicates the id of a customer, their name, and the id of the customer who referred them.
```

Find the names of the customer that are **not referred by**  the customer with `id = 2`.

Return the result table in **any order** .

The result format is in the following example.

**Example 1:** 

```
Input: 
Customer table:
+----+------+------------+
| id | name | referee_id |
+----+------+------------+
| 1  | Will | null       |
| 2  | Jane | null       |
| 3  | Alex | 2          |
| 4  | Bill | null       |
| 5  | Zack | 1          |
| 6  | Mark | 2          |
+----+------+------------+
Output: 
+------+
| name |
+------+
| Will |
| Jane |
| Bill |
| Zack |
+------+
```
> Editorial
#### Approach: Using  `<>`(`!=`) and  `IS NULL`  [Accepted]

**Intuition**

Some people come out the following solution by intuition.

```sql
SELECT name FROM customer WHERE referee_Id <> 2;
```

However, this query will only return one result:Zack although there are 4 customers not referred by Jane (including Jane herself). All the customers who were referred by nobody at all (`NULL`  value in the referee_id column) don’t show up. But why?

**Algorithm**

MySQL uses three-valued logic -- TRUE, FALSE and UNKNOWN. Anything compared to NULL evaluates to the third value: UNKNOWN. That “anything” includes NULL itself! That’s why MySQL provides the  `IS NULL`  and  `IS NOT NULL`  operators to specifically check for NULL.

Thus, one more condition 'referee_id IS NULL' should be added to the WHERE clause as below.

**MySQL**

```sql
SELECT name FROM customer WHERE referee_id <> 2 OR referee_id IS NULL;
```

or

```sql
SELECT name FROM customer WHERE referee_id != 2 OR referee_id IS NULL;
```

**Tips**

The following solution is also wrong for the same reason as mentioned above. The key is to always use  `IS NULL`  or  `IS NOT NULL`  operators to specifically check for NULL value.

```sql
SELECT name FROM customer WHERE referee_id = NULL OR referee_id <> 2;
```
> The Code
```sql
# Write your MySQL query statement below
SELECT name
FROM Customer
WHERE referee_id IS NULL OR referee_id <> 2;
```


# [595. Big Countries](https://leetcode.com/problems/big-countries/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `World`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| name        | varchar |
| continent   | varchar |
| area        | int     |
| population  | int     |
| gdp         | bigint  |
+-------------+---------+
name is the primary key (column with unique values) for this table.
Each row of this table gives information about the name of a country, the continent to which it belongs, its area, the population, and its GDP value.
```

A country is **big**  if:

- it has an area of at leastthree million (i.e., `3000000 km^2`), or
- it has a population of at leasttwenty-five million (i.e., `25000000`).

Write a solution to find the name, population, and area of the **big countries** .

Return the result table in **any order** .

The result format is in the following example.

**Example 1:** 

```
Input: 
World table:
+-------------+-----------+---------+------------+--------------+
| name        | continent | area    | population | gdp          |
+-------------+-----------+---------+------------+--------------+
| Afghanistan | Asia      | 652230  | 25500100   | 20343000000  |
| Albania     | Europe    | 28748   | 2831741    | 12960000000  |
| Algeria     | Africa    | 2381741 | 37100000   | 188681000000 |
| Andorra     | Europe    | 468     | 78115      | 3712000000   |
| Angola      | Africa    | 1246700 | 20609294   | 100990000000 |
+-------------+-----------+---------+------------+--------------+
Output: 
+-------------+------------+---------+
| name        | population | area    |
+-------------+------------+---------+
| Afghanistan | 25500100   | 652230  |
| Algeria     | 37100000   | 2381741 |
+-------------+------------+---------+
```
> The Code
```sql
# Write your MySQL query statement below
SELECT name, population, area
FROM World 
WHERE area >= 3000000 OR population >= 25000000;
```


# [1148. Article Views I](https://leetcode.com/problems/article-views-i/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Views`

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| article_id    | int     |
| author_id     | int     |
| viewer_id     | int     |
| view_date     | date    |
+---------------+---------+
There is no primary key (column with unique values) for this table, the table may have duplicate rows.
Each row of this table indicates that some viewer viewed an article (written by some author) on some date. 
Note that equal author_id and viewer_id indicate the same person.
```

Write a solution to find all the authors that viewed at least one of their own articles.

Return the result table sorted by `id` in ascending order.

The result format is in the following example.

**Example 1:** 

```
Input: 
Views table:
+------------+-----------+-----------+------------+
| article_id | author_id | viewer_id | view_date  |
+------------+-----------+-----------+------------+
| 1          | 3         | 5         | 2019-08-01 |
| 1          | 3         | 6         | 2019-08-02 |
| 2          | 7         | 7         | 2019-08-01 |
| 2          | 7         | 6         | 2019-08-02 |
| 4          | 7         | 1         | 2019-07-22 |
| 3          | 4         | 4         | 2019-07-21 |
| 3          | 4         | 4         | 2019-07-21 |
+------------+-----------+-----------+------------+
Output: 
+------+
| id   |
+------+
| 4    |
| 7    |
+------+
```
> The Code
```sql
# Write your MySQL query statement below
SELECT distinct(author_id) as id
FROM Views
WHERE author_id = viewer_id
ORDER BY id;
```

# [1683. Invalid Tweets](https://leetcode.com/problems/invalid-tweets/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Tweets`

```
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| tweet_id       | int     |
| content        | varchar |
+----------------+---------+
tweet_id is the primary key (column with unique values) for this table.
This table contains all the tweets in a social media app.
```

Write a solution to find the IDs of the invalid tweets. The tweet is invalid if the number of characters used in the content of the tweet is **strictly greater**  than `15`.

Return the result table in **any order** .

The result format is in the following example.

**Example 1:** 

```
Input: 
Tweets table:
+----------+----------------------------------+
| tweet_id | content                          |
+----------+----------------------------------+
| 1        | Vote for Biden                   |
| 2        | Let us make America great again! |
+----------+----------------------------------+
Output: 
+----------+
| tweet_id |
+----------+
| 2        |
+----------+
Explanation: 
Tweet 1 has length = 14. It is a valid tweet.
Tweet 2 has length = 32. It is an invalid tweet.
```
> The Code
```sql
# Write your MySQL query statement below
select tweet_id 
from Tweets 
where length(content) > 15;
```
