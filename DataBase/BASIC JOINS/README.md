# [1378. Replace Employee ID With The Unique Identifier](https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Employees`

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| name          | varchar |
+---------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table contains the id and the name of an employee in a company.
```

Table: `EmployeeUNI`

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| unique_id     | int     |
+---------------+---------+
(id, unique_id) is the primary key (combination of columns with unique values) for this table.
Each row of this table contains the id and the corresponding unique id of an employee in the company.
```

Write a solution to show the **unique ID ** of each user, If a user does not have a unique ID replace just show `null`.

Return the result table in **any**  order.

The result format is in the following example.

**Example 1:** 

```
Input: 
Employees table:
+----+----------+
| id | name     |
+----+----------+
| 1  | Alice    |
| 7  | Bob      |
| 11 | Meir     |
| 90 | Winston  |
| 3  | Jonathan |
+----+----------+
EmployeeUNI table:
+----+-----------+
| id | unique_id |
+----+-----------+
| 3  | 1         |
| 11 | 2         |
| 90 | 3         |
+----+-----------+
Output: 
+-----------+----------+
| unique_id | name     |
+-----------+----------+
| null      | Alice    |
| null      | Bob      |
| 2         | Meir     |
| 3         | Winston  |
| 1         | Jonathan |
+-----------+----------+
Explanation: 
Alice and Bob do not have a unique ID, We will show null instead.
The unique ID of Meir is 2.
The unique ID of Winston is 3.
The unique ID of Jonathan is 1.
```
> My Code
```sql
# Write your MySQL query statement below
SELECT eu.unique_id,e.name
FROM Employees as e LEFT JOIN EmployeeUNI as eu
ON e.id = eu.id;
```
# [1068. Product Sales Analysis I](https://leetcode.com/problems/product-sales-analysis-i/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Sales`

```
+-------------+-------+
| Column Name | Type  |
+-------------+-------+
| sale_id     | int   |
| product_id  | int   |
| year        | int   |
| quantity    | int   |
| price       | int   |
+-------------+-------+
(sale_id, year) is the primary key (combination of columns with unique values) of this table.
product_id is a foreign key (reference column) to `Product` table.
Each row of this table shows a sale on the product product_id in a certain year.
Note that the price is per unit.
```

Table: `Product`

```
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| product_id   | int     |
| product_name | varchar |
+--------------+---------+
product_id is the primary key (column with unique values) of this table.
Each row of this table indicates the product name of each product.
```

Write a solution to report the `product_name`, `year`, and `price` for each `sale_id` in the `Sales` table.

Return the resulting table in **any order** .

The result format is in the following example.

**Example 1:** 

```
Input: 
Sales table:
+---------+------------+------+----------+-------+
| sale_id | product_id | year | quantity | price |
+---------+------------+------+----------+-------+ 
| 1       | 100        | 2008 | 10       | 5000  |
| 2       | 100        | 2009 | 12       | 5000  |
| 7       | 200        | 2011 | 15       | 9000  |
+---------+------------+------+----------+-------+
Product table:
+------------+--------------+
| product_id | product_name |
+------------+--------------+
| 100        | Nokia        |
| 200        | Apple        |
| 300        | Samsung      |
+------------+--------------+
Output: 
+--------------+-------+-------+
| product_name | year  | price |
+--------------+-------+-------+
| Nokia        | 2008  | 5000  |
| Nokia        | 2009  | 5000  |
| Apple        | 2011  | 9000  |
+--------------+-------+-------+
Explanation: 
From sale_id = 1, we can conclude that Nokia was sold for 5000 in the year 2008.
From sale_id = 2, we can conclude that Nokia was sold for 5000 in the year 2009.
From sale_id = 7, we can conclude that Apple was sold for 9000 in the year 2011.
```

> My Code
```sql
SELECT p.product_name, s.year, s.price
FROM Sales as s LEFT JOIN Product as p
ON s.product_id = p.product_id;
```
# [1581. Customer Who Visited but Did Not Make Any Transactions](https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Visits`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| visit_id    | int     |
| customer_id | int     |
+-------------+---------+
visit_id is the column with unique values for this table.
This table contains information about the customers who visited the mall.
```

Table: `Transactions`

```
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| transaction_id | int     |
| visit_id       | int     |
| amount         | int     |
+----------------+---------+
transaction_id is column with unique values for this table.
This table contains information about the transactions made during the visit_id.
```

Write asolution to find the IDs of the users who visited without making any transactions and the number of times they made these types of visits.

Return the result table sorted in **any order** .

Theresult format is in the following example.

**Example 1:** 

```
Input: 
Visits
+----------+-------------+
| visit_id | customer_id |
+----------+-------------+
| 1        | 23          |
| 2        | 9           |
| 4        | 30          |
| 5        | 54          |
| 6        | 96          |
| 7        | 54          |
| 8        | 54          |
+----------+-------------+
Transactions
+----------------+----------+--------+
| transaction_id | visit_id | amount |
+----------------+----------+--------+
| 2              | 5        | 310    |
| 3              | 5        | 300    |
| 9              | 5        | 200    |
| 12             | 1        | 910    |
| 13             | 2        | 970    |
+----------------+----------+--------+
Output: 
+-------------+----------------+
| customer_id | count_no_trans |
+-------------+----------------+
| 54          | 2              |
| 30          | 1              |
| 96          | 1              |
+-------------+----------------+
Explanation: 
Customer with id = 23 visited the mall once and made one transaction during the visit with id = 12.
Customer with id = 9 visited the mall once and made one transaction during the visit with id = 13.
Customer with id = 30 visited the mall once and did not make any transactions.
Customer with id = 54 visited the mall three times. During 2 visits they did not make any transactions, and during one visit they made 3 transactions.
Customer with id = 96 visited the mall once and did not make any transactions.
As we can see, users with IDs 30 and 96 visited the mall one time without making any transactions. Also, user 54 visited the mall twice and did not make any transactions.
```
> Editorial


# Pandas

To identify customers who visited but did not make any transactions, we need to remove the records of customers who made transactions from the list of all customers who visited. By doing so, we convert this problem to a typical "NOT IN" problem. There are two main ways to solve "NOT IN" problems: 1) using the function similar to  `NOT IN/EXISTS`  directly or 2)`LEFT OUTER JOIN/merge`  where the right table is set as  `NULL`. We will introduce both methods in pandas and Mysql.

### Approach 1: Removing Records Using  `~`  and  `isin()`

#### Algorithm

For this approach, we leverage the functions  `~`  and  `isin()`  to exclude unwanted records from the list. Since we want to remove the customers who made transactions from all customers who visited, we first identify those customers from the DataFrame  `visits`  to see who are also in the DataFrame  `transactions`  using  `isin()`. We then remove these visits from all visits using  `~`.

```python
visits_no_trans = visits[~visits.visit_id.isin(transactions.visit_id)]
```

This step creates a new DataFrame that contains the visits that the customers made no transactions.

visit_id  | customer_id
|  --------  |  -------  |
4  | 30
6  | 96
7  | 54
8  | 54

The next step is to count how many of these types of visits were made by each customer. To do this, we have the results grouped by the  `customer_id`  and  `count`  the  `visit_id`. To get the final output, we also need to rename the column that stores the calculated result.

```python
df = visits_no_trans.groupby('customer_id', as_index=False)['visit_id'].count()

return df.rename(columns={'visit_id': 'count_no_trans'})
```

#### Implementation

​

### Approach 2: Removing Records Using  `left merge`  and  `isna()`

#### Algorithm

For this approach, we leverage the  `left merge`  and  `isna()`  to achieve the same goal: removing the visits with transactions from all visits. To do this, we first  `left merge`  the DataFrame  `visits`  that contain all  `visit_id`s to the DataFrame  `transactions`  that contain only the  `visit_id`s that have transactions. We want to make sure the records that need to be removed are placed in the right DataFrame.

```python
visits_no_trans = visits.merge(transactions, on='visit_id', how='left')
```

We now have a DataFrame with all  `visit_id`s and their corresponding transactions. The visits that have no transactions associated return  `null`  values for the column  `transaction_id`.

visit_id  |  customer_id |  transaction_id  |  amount
|  --------  |  -------  |   --------  |  -------  | 
1  |    23 |  12  |  910
2  |  9  |  13  |  970
4  |  30  |  null  |  null
5  |  54  |  2  |  310
5  |  54  |  3  |  300
5  |  54  |  9  |  200
6  |  96  |  null  |  null
7  |  54  |  null  |  null
8  |  54  |  null  |  null

Now we only need to remove those visits that have  `null`  transactions. We can use the function  `isna()`  to achieve this.

```python
visits_no_trans = visits_no_trans[visits_no_trans.transaction_id.isna()]
```

The DataFrame  `visits_no_trans`  now retains only the visits that have no transactions.

visit_id | customer_id | transaction_id | amount |
|  --------  |  -------  |   --------  |  -------  | 
4 |30|null|null
6|96|null|null
7|54|null|null
8|54|null|null

Next, we want to count how many of these types of visits were made by each customer. To do this, we have the results grouped by the  `customer_id`  and  `count`  the  `visit_id`. To get the final output, we also need to rename the column that stores the calculated result.

```python
df = visits_no_trans.groupby('customer_id', as_index=False)['visit_id'].count()

return df.rename(columns={'visit_id': 'count_no_trans'})
```

#### Implementation

​

----------

​

# Database

### Approach 1: Removing Records Using  `NOT IN/EXISTS`

#### Algorithm

For this approach, we remove the visits that have transactions directly using  `NOT IN`. Let's start by identifying these visits. For this problem, they are all the  `visit_id`  from the table  `Transactions`.

```sql
SELECT visit_id FROM Transactions
```

Next, in the main query, we can  `COUNT`  the  `visit_id`  at the  `customer_id`  level from table  `Visits`  excluding the visits we identified in the subquery. The aggregate value is grouped at the  `customer_id`  level as we are looking for the total result for each customer. This column is also renamed as requested by the final output.

#### Implementation

MySQL

```sql
SELECT 
  customer_id, 
  COUNT(visit_id) AS count_no_trans 
FROM 
  Visits 
WHERE 
  visit_id NOT IN (
    SELECT 
      visit_id 
    FROM 
      Transactions
  ) 
GROUP BY 
  customer_id
```

### Approach 2: Removing Records Using  `LEFT JOIN`  and  `IS NULL`

#### Algorithm

For this approach, we want to exclude visits that involved transactions from the complete set of visits by using  `LEFT JOIN`. To do this, we have all visits as the left table (table  `Visits`) to join the visits from table  `Transactions`  on the shared column  `visit_id`. To remove the records from the right table, we set its key as  `NULL`, so the remains in the  `Visits`  table are the records of visits where no transactions occurred.

To get the final output, we want to  `COUNT`  the number of such visits associated with each  `customer_id`, and have the aggregated value grouped at the  `customer_id`  level. Lastly, we update the column as requested in the original problem statement.

#### Implementation

MySQL

```sql
SELECT 
  customer_id, 
  COUNT(*) AS count_no_trans 
FROM 
  Visits AS v 
  LEFT JOIN Transactions AS t ON v.visit_id = t.visit_id 
WHERE 
  t.visit_id IS NULL 
GROUP BY 
  customer_id
```

> My Code
```sql
# Write your MySQL query statement below

SELECT v.customer_id, COUNT(v.visit_id) AS count_no_trans
from Visits v LEFT JOIN Transactions t 
ON v.visit_id = t.visit_id
WHERE t.transaction_id IS NULL
GROUP BY v.customer_id;
```

# [197. Rising Temperature](https://leetcode.com/problems/rising-temperature/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Weather`

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| recordDate    | date    |
| temperature   | int     |
+---------------+---------+
id is the column with unique values for this table.
There are no different rows with the same recordDate.
This table contains information about the temperature on a certain day.
```

Write a solution to find all dates' `Id` with higher temperatures compared to its previous dates (yesterday).

Return the result table in **any order** .

The result format is in the following example.

**Example 1:** 

```
Input: 
Weather table:
+----+------------+-------------+
| id | recordDate | temperature |
+----+------------+-------------+
| 1  | 2015-01-01 | 10          |
| 2  | 2015-01-02 | 25          |
| 3  | 2015-01-03 | 20          |
| 4  | 2015-01-04 | 30          |
+----+------------+-------------+
Output: 
+----+
| id |
+----+
| 2  |
| 4  |
+----+
Explanation: 
In 2015-01-02, the temperature was higher than the previous day (10 -> 25).
In 2015-01-04, the temperature was higher than the previous day (20 -> 30).
```

### Overview

**Problem Statement Reference**

> Write a solution to find all dates' Id with higher temperatures compared to its previous dates (yesterday). Return the result table in any order.

Let's further elaborate on the given example to deepen our understanding of the problem at hand.

If we conduct a time series analysis of the temperature data, we would notice distinct points where there is a rise in temperature compared to the previous day. This phenomenon is precisely what we are interested in identifying.

By analyzing the given data:
id | recordDate | temperature
| -------- | ------- | -------- |
1 | 2015-01-01 | 10
2 | 2015-01-02 | 25
3 | 2015-01-03 | 20
4 | 2015-01-04 | 30

We can graphically represent the temperature readings across the consecutive dates. When we plot these points on a graph, with the  `recordDate`  on the X-axis and the  `temperature`  on the Y-axis, we observe a graphical representation of the temperature variations over the specified period.

![fig](https://leetcode.com/problems/rising-temperature/Figures/197/197-1.png)

From this graphical analysis, we notice two instances where there is a rise in the temperature compared to the day before:

1.  **January 2, 2015 (id: 2)**: On this day, the temperature is recorded to be 25, which is higher than the 10 recorded on January 1st.
    
2.  **January 4, 2015 (id: 4)**: Here, the temperature escalated to 30, surpassing the temperature of 20 noted on January 3rd.
    

Thus, based on our criteria of identifying days with a temperature rise compared to the immediate preceding day, we should return the ids for January 2nd and January 4th, which are 2 and 4 respectively.

----------

# Database

### Approach 1: Using  `JOIN`  and  `DATEDIFF()`

#### Intuition

By doing a self-join on the  `Weather`  table, we create a Cartesian product of the table with itself, creating pairs of days. We then use the  `DATEDIFF`  function to restrict these pairs to only include consecutive days. Lastly, we filter these pairs of consecutive days further to only include pairs where the temperature is higher on the second day. The resulting ids represent the days where the temperature was higher than the previous day.

Let's break this down step by step:

**Step 1: Defining the Main Query Structure**

```sql
SELECT 
    w1.id
FROM 
    Weather w1
JOIN 
    Weather w2
```

Here, we are setting up a query to retrieve the  `id`  from the  `Weather`  table aliased as  `w1`. To find the records where the temperature is greater than the previous day, we are performing a self-join on the  `Weather`  table, creating a second alias  `w2`. This allows us to compare each record in  `w1`  with each record in  `w2`.

**Step 2: Join Condition**

```sql
ON 
    DATEDIFF(w1.recordDate, w2.recordDate) = 1
```

In the join condition, we are using the  `DATEDIFF`  function to find pairs of records where the  `recordDate`  differs by exactly one day. This condition ensures that we are comparing each day's temperature with the temperature of the previous day.

**Step 3: Filter Records with Higher Temperature**

```sql
WHERE 
    w1.temperature > w2.temperature;
```

After finding pairs of days that are consecutive, we apply a filter in the  `WHERE`  clause to only get the records where the temperature on a day (represented by a record in  `w1`) is greater than the temperature on the previous day (represented by a record in  `w2`). This is the main condition to fulfill the requirement of finding the ids where the temperature is higher than the previous day.

#### Implementation

MySQL

```sql
SELECT 
    w1.id
FROM 
    Weather w1
JOIN 
    Weather w2
ON 
    DATEDIFF(w1.recordDate, w2.recordDate) = 1
WHERE 
    w1.temperature > w2.temperature;

```

### Approach 2: Using  `LAG()`  Function

#### Intuition

Let's break this down step by step:

**Step 1: Creating a Common Table Expression (CTE) with Lag Function**

```sql
WITH PreviousWeatherData AS
(
    SELECT 
        id,
        recordDate,
        temperature, 
        LAG(temperature, 1) OVER (ORDER BY recordDate) AS PreviousTemperature,
        LAG(recordDate, 1) OVER (ORDER BY recordDate) AS PreviousRecordDate
    FROM 
        Weather
)
```

In this step, we create a Common Table Expression (CTE) named  `PreviousWeatherData`  using a  `WITH`  clause. Inside this CTE, we are selecting all the rows from the "Weather" table along with two additional columns:

1.  `PreviousTemperature`: The temperature from the previous day, which is obtained using the  `LAG()`  function with an offset of 1, ordered by  `recordDate`.
2.  `PreviousRecordDate`: The record date of the previous day, similarly obtained using the  `LAG()`  function with an offset of 1, ordered by  `recordDate`.

This setup helps us associate each record with the respective details from the previous day in the same row.

**Step 2: Selecting IDs with Conditions on Temperature and Date**

```sql
SELECT 
    id 
FROM 
    PreviousWeatherData
WHERE 
    temperature > PreviousTemperature
AND 
    recordDate = DATE_ADD(PreviousRecordDate, INTERVAL 1 DAY);
```

In this step, we execute a query on the  `PreviousWeatherData`  CTE with two conditions in the WHERE clause to filter the required IDs:

1.  `temperature > PreviousTemperature`: This condition filters for the days where the temperature was higher than the previous day's temperature.
2.  `recordDate = DATE_ADD(PreviousRecordDate, INTERVAL 1 DAY)`: This condition ensures that we are comparing consecutive days. It uses the  `DATE_ADD()`  function to add an interval of 1 day to the  `PreviousRecordDate`  and checks if it equals the current  `recordDate`.

By combining these two conditions with an  `AND`  clause, we ensure that we only select the IDs where both conditions are met, which are the days when the temperature is higher than the day before.

#### Implementation

MySQL

```sql
WITH PreviousWeatherData AS
(
    SELECT 
        id,
        recordDate,
        temperature, 
        LAG(temperature, 1) OVER (ORDER BY recordDate) AS PreviousTemperature,
        LAG(recordDate, 1) OVER (ORDER BY recordDate) AS PreviousRecordDate
    FROM 
        Weather
)
SELECT 
    id 
FROM 
    PreviousWeatherData
WHERE 
    temperature > PreviousTemperature
AND 
    recordDate = DATE_ADD(PreviousRecordDate, INTERVAL 1 DAY);

```

### Approach 3: Using Subquery

#### Intuition

Let's break this down step by step:

**Step 1: Inner Subquery to Get the Previous Day’s Temperature**

```sql
        SELECT 
            w2.temperature
        FROM 
            Weather w2
        WHERE 
            w2.recordDate = DATE_SUB(w1.recordDate, INTERVAL 1 DAY)
```

The inner query is responsible for retrieving the temperature of the day before the date currently under consideration in the outer query.

It utilizes the  `DATE_SUB`  function to find the date one day before the  `recordDate`  in the outer query (`w1.recordDate`) and then fetches the temperature recorded on that previous date from the same Weather table (alias  `w2`).

**Step 2: Outer Query to Find Days with Higher Temperature**

```sql
SELECT 
    w1.id
FROM 
    Weather w1
WHERE 
    w1.temperature > (
        -- ... (inner subquery)
    );
```

The outer query iterates over each row (each day) in the Weather table (alias  `w1`) and checks if the temperature on that day is greater than the temperature on the previous day, the latter being obtained from the inner subquery.

**Step 3: Comparing Temperatures**

```sql
    w1.temperature > (
        -- ... (inner subquery)
    )
```

Here, we have the crucial comparison that serves our goal. For each day in the outer query, it checks whether the temperature is greater than the temperature fetched from the inner subquery (which is the temperature of the previous day).

**Step 4: Selecting the ID**

```sql
SELECT 
    w1.id
```

If the condition in the  `WHERE`  clause is satisfied (today’s temperature is greater than yesterday’s), we select the ID of the current day (from the outer query’s perspective). This ID indicates a day where the temperature was higher than the temperature on the previous day.

#### Implementation

MySQL

```sql
SELECT 
    w1.id
FROM 
    Weather w1
WHERE 
    w1.temperature > (
        SELECT 
            w2.temperature
        FROM 
            Weather w2
        WHERE 
            w2.recordDate = DATE_SUB(w1.recordDate, INTERVAL 1 DAY)
    );

```

### Approach 4: Using Cartesian Product and  `WHERE`  Clause

#### Intuition

Let's break this down step by step:

**Step 1: Cartesian Product**

```sql
FROM 
    Weather w1, Weather w2
```

In this step, we are performing a Cartesian product (or cross join) of the  `Weather`  table with itself. This means we create a new table where each row from  `w1`  (first instance of the Weather table) is paired with every row from  `w2`  (second instance of the Weather table), resulting in a table with n² rows (where n is the number of rows in the Weather table).

**Step 2: Filtering Based on Date Difference**

```sql
WHERE 
    DATEDIFF(w2.recordDate, w1.recordDate) = 1 
```

Next, we use the  `DATEDIFF`  function to find pairs of rows where the difference between the 'recordDate' in w2 and w1 is exactly 1 day. This effectively filters down to pairs of rows representing consecutive days.

**Step 3: Filtering Based on Temperature Difference**

```sql
AND 
    w2.temperature > w1.temperature;
```

In this step, we are filtering the pairs further to retain only those where the temperature on the second day (`w2.temperature`) is greater than the temperature on the first day (`w1.temperature`). This finds the days where the temperature is rising compared to the previous day.

**Step 4: Selecting the Result**

```sql
SELECT 
    w2.id
```

Finally, from all the pairs that satisfy the conditions set in the WHERE clause, we select the ID of the day from the w2 table (i.e., the ID of the day with the higher temperature).

#### Implementation

MySQL

```sql
SELECT 
    w2.id
FROM 
    Weather w1, Weather w2
WHERE 
    DATEDIFF(w2.recordDate, w1.recordDate) = 1 
AND 
    w2.temperature > w1.temperature;
```

> My Code
```sql
# Write your MySQL query statement below
SELECT w1.id 
FROM Weather as w1, Weather as w2
WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1
AND w1.temperature > w2.temperature;
```

# [1661. Average Time of Process per Machine](https://leetcode.com/problems/average-time-of-process-per-machine/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Activity`

```
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| machine_id     | int     |
| process_id     | int     |
| activity_type  | enum    |
| timestamp      | float   |
+----------------+---------+
The table shows the user activities for a factory website.
(machine_id, process_id, activity_type) is the primary key (combination of columns with unique values) of this table.
machine_id is the ID of a machine.
process_id is the ID of a process running on the machine with ID machine_id.
activity_type is an ENUM (category) of type ('start', 'end').
timestamp is a float representing the current time in seconds.
'start' means the machine starts the process at the given timestamp and 'end' means the machine ends the process at the given timestamp.
The 'start' timestamp will always be before the 'end' timestamp for every (machine_id, process_id) pair.```

There is a factory website that has several machines each running the **same number of processes** . Write a solutionto find the **average time**  each machine takes to complete a process.

The time to complete a process is the `'end' timestamp` minus the `'start' timestamp`. The average time is calculated by the total time to complete every process on the machine divided by the number of processes that were run.

The resulting table should have the `machine_id` along with the **average time**  as `processing_time`, which should be **rounded to 3 decimal places** .

Return the result table in **any order** .

The result format is in the following example.

**Example 1:** 

```
Input: 
Activity table:
+------------+------------+---------------+-----------+
| machine_id | process_id | activity_type | timestamp |
+------------+------------+---------------+-----------+
| 0          | 0          | start         | 0.712     |
| 0          | 0          | end           | 1.520     |
| 0          | 1          | start         | 3.140     |
| 0          | 1          | end           | 4.120     |
| 1          | 0          | start         | 0.550     |
| 1          | 0          | end           | 1.550     |
| 1          | 1          | start         | 0.430     |
| 1          | 1          | end           | 1.420     |
| 2          | 0          | start         | 4.100     |
| 2          | 0          | end           | 4.512     |
| 2          | 1          | start         | 2.500     |
| 2          | 1          | end           | 5.000     |
+------------+------------+---------------+-----------+
Output: 
+------------+-----------------+
| machine_id | processing_time |
+------------+-----------------+
| 0          | 0.894           |
| 1          | 0.995           |
| 2          | 1.456           |
+------------+-----------------+
Explanation: 
There are 3 machines running 2 processes each.
Machine 0's average time is ((1.520 - 0.712) + (4.120 - 3.140)) / 2 = 0.894
Machine 1's average time is ((1.550 - 0.550) + (1.420 - 0.430)) / 2 = 0.995
Machine 2's average time is ((4.512 - 4.100) + (5.000 - 2.500)) / 2 = 1.456
```


# database

### Approach 1: Transform Values with CASE WHEN and then Calculate

#### Algorithm

To calculate the time to complete a process, we need to know the difference between the 'start'  `timestamp`  and the 'end'  `timestamp`  for each machine and process. If we set all the 'start'  `timestamp`  to its negative value, we can get the time difference by using  `SUM()`, since  `(-start) + end`  is equal to  `end - start`, which is the time difference.

To do this, we use  `CASE WHEN`  to multiply all the start  `timestamp`  by -1, so the aggregated total of  `timestamp`  becomes the time to complete a process for each machine.

```sql
SUM(CASE WHEN activity_type = 'start' THEN timestamp*-1 ELSE timestamp END)
```

Since we need the average by each  `machine_id`  and there might be multiple processes for each machine, we manually calculate the average by having the processing time divided by the number of processes. Luckily, for this question, all machines have the same number of processes.

```sql
SUM(CASE WHEN activity_type='start' THEN timestamp*-1 ELSE timestamp END)*1.0/(SELECT COUNT(DISTINCT process_id))
```

Lastly, we round the  `processing_time`  to 3 decimal places by using the function  `ROUND()`  and rename the column name.

```sql
ROUND(SUM(CASE WHEN activity_type='start' THEN timestamp*-1 ELSE timestamp END)*1.0/(SELECT COUNT(DISTINCT process_id)),3) AS processing_time
```

#### Implementation

```sql
SELECT 
    machine_id,
    ROUND(SUM(CASE WHEN activity_type='start' THEN timestamp*-1 ELSE timestamp END)*1.0
    / (SELECT COUNT(DISTINCT process_id)),3) AS processing_time
FROM 
    Activity
GROUP BY machine_id
```

​

### Approach 2: Calling the original Table twice and Calculate as two columns

#### Algorithm

For this approach, we are calling the original table twice, once as the table that stores the start  `timestamps`  and once as the table that stores the end  `timestamps`. To create the table alias, we give the original table  `Activity`  two different names, and filter each table by the  `activity_type`. We also make sure the two tables are joined on the  `machine_id`  and  `process_id`, so the output will have the start  `timestamp`  and end  `timestamp`  stored in two different columns for each machine and process.

```sql
SELECT *
FROM Activity a, 
     Activity b
WHERE 
    a.machine_id = b.machine_id
AND 
    a.process_id = b.process_id
AND 
    a.activity_type = 'start'
AND 
    b.activity_type = 'end'
```

The output looks like this:

machine_id  | process_id  | activity_type  | timestamp  | machine_id  | process_id  | activity_type  | timestamp
|  --------  |  -------  | --------  |  -------  | --------  |  -------  | --------  |  -------  |
0 | 0 | start | 0.712 | 0 | 0 | end | 1.52
0 | 1 | start | 3.14 | 0 | 1 | end | 4.12
1 | 0 | start | 0.55 | 1 | 0 | end | 1.55
1 | 1 | start | 0.43 | 1 | 1 | end | 1.42
2 | 0 | start | 4.1 | 2 | 0 | end | 4.512
2 | 1 | start | 2.5 | 2 | 1 | end | 5


With this table, we can update the calculation for  `processing_time`  by having all the timestamps from table b (end  `timestamp`) to subtract all the  `timestamp`  in table a (start  `timestamp`):

```sql
SELECT (b.timestamp - a.timestamp) AS processing_time
```

Since we want the average  `processing_time`  at the  `machine_id`  level, we add AVG() to the  `processing_time`  calculation and round it to 3 decimal places using the function  `ROUND()`.

```sql
SELECT a.machine_id, 
       ROUND(AVG(b.timestamp - a.timestamp), 3) AS processing_time
```

#### Implementation

```sql
SELECT a.machine_id, 
       ROUND(AVG(b.timestamp - a.timestamp), 3) AS processing_time
FROM Activity a, 
     Activity b
WHERE 
    a.machine_id = b.machine_id
AND 
    a.process_id = b.process_id
AND 
    a.activity_type = 'start'
AND 
    b.activity_type = 'end'
GROUP BY machine_id;
```

> My Code
```sql
SELECT machine_id, ROUND(AVG(end - start), 3) AS processing_time
FROM 
(SELECT machine_id, process_id, 
    MAX(CASE WHEN activity_type = 'start' THEN timestamp END) AS start,
    MAX(CASE WHEN activity_type = 'end' THEN timestamp END) AS end
 FROM Activity 
  GROUP BY machine_id, process_id) AS subq
GROUP BY machine_id;
```

# [577. Employee Bonus](https://leetcode.com/problems/employee-bonus/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Employee`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| empId       | int     |
| name        | varchar |
| supervisor  | int     |
| salary      | int     |
+-------------+---------+
empId is the column with unique values for this table.
Each row of this table indicates the name and the ID of an employee in addition to their salary and the id of their manager.
```

Table: `Bonus`

```
+-------------+------+
| Column Name | Type |
+-------------+------+
| empId       | int  |
| bonus       | int  |
+-------------+------+
empId is the column of unique values for this table.
empId is a foreign key (reference column) to empId from the Employee table.
Each row of this table contains the id of an employee and their respective bonus.
```

Write a solution to report the name and bonus amount of each employee with a bonus **less than**  `1000`.

Return the result table in **any order** .

Theresult format is in the following example.

**Example 1:** 

```
Input: 
Employee table:
+-------+--------+------------+--------+
| empId | name   | supervisor | salary |
+-------+--------+------------+--------+
| 3     | Brad   | null       | 4000   |
| 1     | John   | 3          | 1000   |
| 2     | Dan    | 3          | 2000   |
| 4     | Thomas | 3          | 4000   |
+-------+--------+------------+--------+
Bonus table:
+-------+-------+
| empId | bonus |
+-------+-------+
| 2     | 500   |
| 4     | 2000  |
+-------+-------+
Output: 
+------+-------+
| name | bonus |
+------+-------+
| Brad | null  |
| John | null  |
| Dan  | 500   |
+------+-------+
```

# database

### Approach 1: Using  `OUTER JOIN`  and  `WHERE`  clause

#### Algorithm

1.  Initialize Query: Start an SQL query.
    
2.  Since foreign key  **Bonus.empId**  refers to  **Employee.empId**  and some employees do not have bonus records, we can use  `OUTER JOIN`  to link these two tables as the first step.
    

```sql
SELECT
    Employee.name, Bonus.bonus
FROM
    Employee
        LEFT OUTER JOIN
    Bonus ON Employee.empid = Bonus.empid
;
```

> Note: "LEFT OUTER JOIN" could be written as "LEFT JOIN".

The output to run this code with the sample data is as below.

```sql
| name   | bonus |
|--------|-------|
| Dan    | 500   |
| Thomas | 2000  |
| Brad   |       |
| John   |       |
```

The bonus value for  `Brad`  and  `John`  is empty, which is actually  `NULL`  in the database. "Conceptually, NULL means “a missing unknown value” and it is treated somewhat differently from other values." Check the  [Working with NULL Values](https://dev.mysql.com/doc/refman/5.7/en/working-with-null.html)  in MySQL manual for more details. In addition, we have to use  `IS NULL`  or  `IS NOT NULL`  to compare a value with  `NULL`.

3.  At last, we can add a  `WHERE`  clause with the proper conditions to filter these records.

#### Implementation

MySQL

```sql
SELECT
    Employee.name, Bonus.bonus
FROM
    Employee
        LEFT JOIN
    Bonus ON Employee.empid = Bonus.empid
WHERE
    bonus < 1000 OR bonus IS NULL
;
```

> My Code
```sql
# Write your MySQL query statement below
SELECT Employee.name, Bonus.bonus
FROM Employee LEFT JOIN Bonus 
ON Employee.empid = Bonus.empid
WHERE bonus < 1000 OR bonus IS NULL;
```

# [1280. Students and Examinations](https://leetcode.com/problems/students-and-examinations/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Students`

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| student_id    | int     |
| student_name  | varchar |
+---------------+---------+
student_id is the primary key (column with unique values) for this table.
Each row of this table contains the ID and the name of one student in the school.
```

Table: `Subjects`

```
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| subject_name | varchar |
+--------------+---------+
subject_name is the primary key (column with unique values) for this table.
Each row of this table contains the name of one subject in the school.
```

Table: `Examinations`

```
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| student_id   | int     |
| subject_name | varchar |
+--------------+---------+
There is no primary key (column with unique values) for this table. It may contain duplicates.
Each student from the Students table takes every course from the Subjects table.
Each row of this table indicates that a student with ID student_id attended the exam of subject_name.
```

Write a solution to find the number of times each student attended each exam.

Return the result table ordered by `student_id` and `subject_name`.

The result format is in the following example.

**Example 1:** 

```
Input: 
Students table:
+------------+--------------+
| student_id | student_name |
+------------+--------------+
| 1          | Alice        |
| 2          | Bob          |
| 13         | John         |
| 6          | Alex         |
+------------+--------------+
Subjects table:
+--------------+
| subject_name |
+--------------+
| Math         |
| Physics      |
| Programming  |
+--------------+
Examinations table:
+------------+--------------+
| student_id | subject_name |
+------------+--------------+
| 1          | Math         |
| 1          | Physics      |
| 1          | Programming  |
| 2          | Programming  |
| 1          | Physics      |
| 1          | Math         |
| 13         | Math         |
| 13         | Programming  |
| 13         | Physics      |
| 2          | Math         |
| 1          | Math         |
+------------+--------------+
Output: 
+------------+--------------+--------------+----------------+
| student_id | student_name | subject_name | attended_exams |
+------------+--------------+--------------+----------------+
| 1          | Alice        | Math         | 3              |
| 1          | Alice        | Physics      | 2              |
| 1          | Alice        | Programming  | 1              |
| 2          | Bob          | Math         | 1              |
| 2          | Bob          | Physics      | 0              |
| 2          | Bob          | Programming  | 1              |
| 6          | Alex         | Math         | 0              |
| 6          | Alex         | Physics      | 0              |
| 6          | Alex         | Programming  | 0              |
| 13         | John         | Math         | 1              |
| 13         | John         | Physics      | 1              |
| 13         | John         | Programming  | 1              |
+------------+--------------+--------------+----------------+
Explanation: 
The result table should contain all students and all subjects.
Alice attended the Math exam 3 times, the Physics exam 2 times, and the Programming exam 1 time.
Bob attended the Math exam 1 time, the Programming exam 1 time, and did not attend the Physics exam.
Alex did not attend any exams.
John attended the Math exam 1 time, the Physics exam 1 time, and the Programming exam 1 time.
```

> My Code
```sql
SELECT a.student_id, a.student_name, b.subject_name, COUNT(c.subject_name) AS attended_exams
FROM Students a
JOIN Subjects b
LEFT JOIN Examinations c
ON a.student_id = c.student_id
AND b.subject_name = c.subject_name
GROUP BY 1, 3
ORDER BY 1, 3 ;
```

# [570. Managers with at Least 5 Direct Reports](https://leetcode.com/problems/managers-with-at-least-5-direct-reports/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Employee`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| department  | varchar |
| managerId   | int     |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table indicates the name of an employee, their department, and the id of their manager.
If managerId is null, then the employee does not have a manager.
No employee will be the manager of themself.
```

Write a solution to find managers with at least **five direct reports** .

Return the result table in **any order** .

The result format is in the following example.

**Example 1:** 

```
Input: 
Employee table:
+-----+-------+------------+-----------+
| id  | name  | department | managerId |
+-----+-------+------------+-----------+
| 101 | John  | A          | null      |
| 102 | Dan   | A          | 101       |
| 103 | James | A          | 101       |
| 104 | Amy   | A          | 101       |
| 105 | Anne  | A          | 101       |
| 106 | Ron   | B          | 101       |
+-----+-------+------------+-----------+
Output: 
+------+
| name |
+------+
| John |
+------+
```

> My Code
```sql
SELECT name 
FROM Employee
WHERE id IN
( SELECT managerId 
FROM Employee
GROUP BY managerId
HAVING count(managerId)>=5);

-- OR
SELECT name 
FROM Employee
WHERE id IN
( SELECT managerId 
FROM Employee
GROUP BY managerId
HAVING count(id)>=5);

-- OR
SELECT a.name
FROM Employee a
JOIN Employee b
WHERE a.id = b.managerId
GROUP BY b.managerId
HAVING COUNT(*) >= 5;
```
# [1934. Confirmation Rate](https://leetcode.com/problems/confirmation-rate/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Signups`

```
+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| user_id        | int      |
| time_stamp     | datetime |
+----------------+----------+
user_id is the column of unique values for this table.
Each row contains information about the signup time for the user with ID user_id.
```

Table: `Confirmations`

```
+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| user_id        | int      |
| time_stamp     | datetime |
| action         | ENUM     |
+----------------+----------+
(user_id, time_stamp) is the primary key (combination of columns with unique values) for this table.
user_id is a foreign key (reference column) to the Signups table.
action is an ENUM (category) of the type ('confirmed', 'timeout')
Each row of this table indicates that the user with ID user_id requested a confirmation message at time_stamp and that confirmation message was either confirmed ('confirmed') or expired without confirming ('timeout').
```

The **confirmation rate**  of a user is the number of `'confirmed'` messages divided by the total number of requested confirmation messages. The confirmation rate of a user that did not request any confirmation messages is `0`. Round the confirmation rate to **two decimal**  places.

Write a solution to find the **confirmation rate**  of each user.

Return the result table in **any order** .

The result format is in the following example.

**Example 1:** 

```
Input: 
Signups table:
+---------+---------------------+
| user_id | time_stamp          |
+---------+---------------------+
| 3       | 2020-03-21 10:16:13 |
| 7       | 2020-01-04 13:57:59 |
| 2       | 2020-07-29 23:09:44 |
| 6       | 2020-12-09 10:39:37 |
+---------+---------------------+
Confirmations table:
+---------+---------------------+-----------+
| user_id | time_stamp          | action    |
+---------+---------------------+-----------+
| 3       | 2021-01-06 03:30:46 | timeout   |
| 3       | 2021-07-14 14:00:00 | timeout   |
| 7       | 2021-06-12 11:57:29 | confirmed |
| 7       | 2021-06-13 12:58:28 | confirmed |
| 7       | 2021-06-14 13:59:27 | confirmed |
| 2       | 2021-01-22 00:00:00 | confirmed |
| 2       | 2021-02-28 23:59:59 | timeout   |
+---------+---------------------+-----------+
Output: 
+---------+-------------------+
| user_id | confirmation_rate |
+---------+-------------------+
| 6       | 0.00              |
| 3       | 0.00              |
| 7       | 1.00              |
| 2       | 0.50              |
+---------+-------------------+
Explanation: 
User 6 did not request any confirmation messages. The confirmation rate is 0.
User 3 made 2 requests and both timed out. The confirmation rate is 0.
User 7 made 3 requests and all were confirmed. The confirmation rate is 1.
User 2 made 2 requests where one was confirmed and the other timed out. The confirmation rate is 1 / 2 = 0.5.
```

> My Code
```sql
# Write your MySQL query statement below

SELECT s.user_id, IFNULL( ROUND( SUM(action = 'confirmed')/COUNT(*) ,2), 0.00) AS confirmation_rate
FROM Signups as s LEFT JOIN Confirmations as c
ON s.user_id = c.user_id
GROUP BY s.user_id;


-- SUM counts total confirmed
-- COUNT counts total s.user_id which we stricted to 1 using group by
-- ROUND(3,2)= 3.00, it rounds 3 to 3.00 upto 2 digits
-- IFNULL(expression, value_if_null), here we will show 3.00 , if null then 0.00
```
