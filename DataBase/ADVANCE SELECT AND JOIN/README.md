
# [1731. The Number of Employees Which Report to Each Employee](https://leetcode.com/problems/the-number-of-employees-which-report-to-each-employee/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Employees`

```
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| employee_id | int      |
| name        | varchar  |
| reports_to  | int      |
| age         | int      |
+-------------+----------+
employee_id is the column with unique values for this table.
This table contains information about the employees and 
the id of the manager they report to. Some employees do not report to anyone
(reports_to is null). 
```

For this problem, we will consider a **manager**  an employee who has at least 1 other employee reporting to them.

Write a solution to report the ids and the names of all **managers** , the number of employees who report **directly**  to them, and the average age of the reports rounded to the nearest integer.

Return the result table ordered by `employee_id`.

Theresult format is in the following example.

**Example 1:** 

```
Input: 
Employees table:
+-------------+---------+------------+-----+
| employee_id | name    | reports_to | age |
+-------------+---------+------------+-----+
| 9           | Hercy   | null       | 43  |
| 6           | Alice   | 9          | 41  |
| 4           | Bob     | 9          | 36  |
| 2           | Winston | null       | 37  |
+-------------+---------+------------+-----+
Output: 
+-------------+-------+---------------+-------------+
| employee_id | name  | reports_count | average_age |
+-------------+-------+---------------+-------------+
| 9           | Hercy | 2             | 39          |
+-------------+-------+---------------+-------------+
Explanation: Hercy has 2 people report directly to him, Alice and Bob. 
Their average age is (41+36)/2 = 38.5, which is 39,
 after rounding it to the nearest integer.
```

**Example 2:** 

```
Input: 
Employees table:
+-------------+---------+------------+-----+ 
| employee_id | name  	| reports_to | age |
|-------------|---------|------------|-----|
| 1      	  | Michael | null    	 | 45  |
| 2           | Alice   | 1          | 38  |
| 3           | Bob     | 1          | 42  |
| 4           | Charlie | 2          | 34  |
| 5           | David   | 2          | 40  |
| 6           | Eve     | 3          | 37  |
| 7           | Frank   | null       | 50  |
| 8           | Grace   | null       | 48  |
+-------------+---------+------------+-----+ 
Output: 
+-------------+---------+---------------+-------------+
| employee_id | name  	| reports_count | average_age |
| ----------- | ------- | ------------- | ----------- |
| 1      	  | Michael | 2       		| 40     	  |
| 2      	  | Alice   | 2             | 37          |
| 3           | Bob     | 1             | 37          |
+-------------+---------+---------------+-------------+
```
> Approach
Here, we will use `self Join` technique.
First we will create a table of `reports_to`, `count` and `average`.
```sql
SELECT reports_to AS manager_id,
	COUNT( reports_to)  AS reports_count,
	ROUND(AVG(age))  AS average_age
FROM Employees
WHERE reports_to IS  NOT  NULL
GROUP  BY reports_to
```
Then we will `self join` the new table with the old one on the basis of `employee_id=manager_id`
Then, we will take our `employee_id`,` name` from <b>old table</b> and `reports_count` and ` avearge_age` from <b>new table</b>.


> My Code
```sql
# Write your MySQL query statement below
SELECT e.employee_id, e.name, r.reports_count, r.average_age
FROM Employees e
JOIN
    (SELECT  reports_to AS manager_id,
        COUNT( reports_to) AS reports_count, 
        ROUND(AVG(age)) AS average_age
    FROM Employees 
    WHERE reports_to IS NOT NULL
    GROUP BY reports_to) r
ON e.employee_id = r.manager_id
ORDER BY e.employee_id;
```

# [1789. Primary Department for Each Employee](https://leetcode.com/problems/primary-department-for-each-employee/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Employee`

```
+---------------+---------+
| Column Name   |  Type   |
+---------------+---------+
| employee_id   | int     |
| department_id | int     |
| primary_flag  | varchar |
+---------------+---------+
(employee_id, department_id) is the primary key (combination of columns with unique values) for this table.
employee_id is the id of the employee.
department_id is the id of the department to which the employee belongs.
primary_flag is an ENUM (category) of type ('Y', 'N'). If the flag is 'Y', the department is the primary department for the employee. If the flag is 'N', the department is not the primary.
```

Employees can belong to multiple departments. When the employee joins other departments, they need to decide which department is their primary department. Note that when an employee belongs to only one department, their primary column is `'N'`.

Write a solution to report all the employees with their primary department. For employees who belong to one department, report their only department.

Return the result table in **any order** .

Theresult format is in the following example.

**Example 1:** 

```
Input: 
Employee table:
+-------------+---------------+--------------+
| employee_id | department_id | primary_flag |
+-------------+---------------+--------------+
| 1           | 1             | N            |
| 2           | 1             | Y            |
| 2           | 2             | N            |
| 3           | 3             | N            |
| 4           | 2             | N            |
| 4           | 3             | Y            |
| 4           | 4             | N            |
+-------------+---------------+--------------+
Output: 
+-------------+---------------+
| employee_id | department_id |
+-------------+---------------+
| 1           | 1             |
| 2           | 1             |
| 3           | 3             |
| 4           | 3             |
+-------------+---------------+
Explanation: 
- The Primary department for employee 1 is 1.
- The Primary department for employee 2 is 1.
- The Primary department for employee 3 is 3.
- The Primary department for employee 4 is 3.
```  

> My Code
```sql
SELECT employee_id, department_id
FROM Employee
WHERE employee_id IN (
    SELECT employee_id
    FROM Employee
    GROUP BY employee_id
    HAVING COUNT(primary_flag) = 1
) OR (primary_flag = 'Y')
```

# [610. Triangle Judgement](https://leetcode.com/problems/triangle-judgement/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Triangle`

```
+-------------+------+
| Column Name | Type |
+-------------+------+
| x           | int  |
| y           | int  |
| z           | int  |
+-------------+------+
In SQL, (x, y, z) is the primary key column for this table.
Each row of this table contains the lengths of three line segments.
```

Report for every three line segments whether they can form a triangle.

Return the result table in **any order** .

Theresult format is in the following example.

**Example 1:** 

```
Input: 
Triangle table:
+----+----+----+
| x  | y  | z  |
+----+----+----+
| 13 | 15 | 30 |
| 10 | 20 | 15 |
+----+----+----+
Output: 
+----+----+----+----------+
| x  | y  | z  | triangle |
+----+----+----+----------+
| 13 | 15 | 30 | No       |
| 10 | 20 | 15 | Yes      |
+----+----+----+----------+
```

> My Code
```sql
# Write your MySQL query statement below
SELECT *,
    IF(X+Y>Z AND Y+Z>X AND Z+X>Y, "Yes", "No") AS triangle
FROM Triangle;
```

# [1204. Last Person to Fit in the Bus](https://leetcode.com/problems/last-person-to-fit-in-the-bus/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Queue`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| person_id   | int     |
| person_name | varchar |
| weight      | int     |
| turn        | int     |
+-------------+---------+
person_id column contains unique values.
This table has the information about all people waiting for a bus.
The person_id and turn columns will contain all numbers from 1 to n, where n is the number of rows in the table.
turn determines the order of which the people will board the bus, where turn=1 denotes the first person to board and turn=n denotes the last person to board.
weight is the weight of the person in kilograms.
```

There is a queue of people waiting to board a bus. However, the bus has a weight limit of `1000`** kilograms** , so there may be some people who cannot board.

Write a solution to find the `person_name` of the **last person**  that can fit on the bus without exceeding the weight limit. The test cases are generated such that the first person does not exceed the weight limit.

Theresult format is in the following example.

**Example 1:** 

```
Input: 
Queue table:
+-----------+-------------+--------+------+
| person_id | person_name | weight | turn |
+-----------+-------------+--------+------+
| 5         | Alice       | 250    | 1    |
| 4         | Bob         | 175    | 5    |
| 3         | Alex        | 350    | 2    |
| 6         | John Cena   | 400    | 3    |
| 1         | Winston     | 500    | 6    |
| 2         | Marie       | 200    | 4    |
+-----------+-------------+--------+------+
Output: 
+-------------+
| person_name |
+-------------+
| John Cena   |
+-------------+
Explanation: The folowing table is ordered by the turn for simplicity.
+------+----+-----------+--------+--------------+
| Turn | ID | Name      | Weight | Total Weight |
+------+----+-----------+--------+--------------+
| 1    | 5  | Alice     | 250    | 250          |
| 2    | 3  | Alex      | 350    | 600          |
| 3    | 6  | John Cena | 400    | 1000         | (last person to board)
| 4    | 2  | Marie     | 200    | 1200         | (cannot board)
| 5    | 4  | Bob       | 175    | ___          |
| 6    | 1  | Winston   | 500    | ___          |
+------+----+-----------+--------+--------------+
```

> Intuition

Here if we can calculate `cumulative sum` of weight which comes  order by turn , our problem will be much easier.
```sql
SELECT turn, person_id, person_name,weight,
	SUM(weight)  over(  ORDER  BY turn ASC)  AS Total_weight
From Queue
```
OUTPUT TABLE: 
| turn | person_id | person_name | weight | Total_weight |  
| ---- | --------- | ----------- | ------ | ------------ |  
| 1 | 5 | Alice | 250 | 250 |  
| 2 | 3 | Alex | 350 | 600 |  
| 3 | 6 | John Cena | 400 | 1000 |  
| 4 | 2 | Marie | 200 | 1200 |  
| 5 | 4 | Bob | 175 | 1375 |  
| 6 | 1 | Winston | 500 | 1875 |

Here, we need to output the `john cena`
So, we order by total_weight in DESCENDING order,
where comes john cena, Alex, Alice,
And we limit it to 1, to get `john cena` 

> My code
```sql
# Write your MySQL query statement below
WITH cum_table AS(
    SELECT turn, person_id, person_name,weight, 
        SUM(weight) over( ORDER BY turn ASC) AS Total_weight
    From Queue
)
-- with this table syntax we can use it in QUERY multiple times

SELECT person_name
FROM cum_table
WHERE total_weight <= 1000
ORDER BY total_weight DESC
LIMIT 1; 
```

OR,
```sql
# here we use table like before, single use
SELECT person_name
FROM(
    SELECT turn, person_id, person_name,weight, 
        SUM(weight) over( ORDER BY turn ASC) AS Total_weight
    From Queue) AS cum_table
WHERE total_weight <= 1000
ORDER BY total_weight DESC
LIMIT 1;
```

# [1907. Count Salary Categories](https://leetcode.com/problems/count-salary-categories/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Accounts`

```
+-------------+------+
| Column Name | Type |
+-------------+------+
| account_id  | int  |
| income      | int  |
+-------------+------+
account_id is the primary key (column with unique values) for this table.
Each row contains information about the monthly income for one bank account.
```

Write a solutionto calculate the number of bank accounts for each salary category. The salary categories are:

- `"Low Salary"`: All the salaries **strictly less**  than `$20000`.
- `"Average Salary"`: All the salaries in the **inclusive**  range `[$20000, $50000]`.
- `"High Salary"`: All the salaries **strictly greater**  than `$50000`.

The result table **must**  contain all three categories. If there are no accounts in a category,return`0`.

Return the result table in **any order** .

Theresult format is in the following example.

**Example 1:** 

```
Input: 
Accounts table:
+------------+--------+
| account_id | income |
+------------+--------+
| 3          | 108939 |
| 2          | 12747  |
| 8          | 87709  |
| 6          | 91796  |
+------------+--------+
Output: 
+----------------+----------------+
| category       | accounts_count |
+----------------+----------------+
| Low Salary     | 1              |
| Average Salary | 0              |
| High Salary    | 3              |
+----------------+----------------+
Explanation: 
Low Salary: Account 2.
Average Salary: No accounts.
High Salary: Accounts 3, 6, and 8.
```

> My Code
```sql
# Write your MySQL query statement below
SELECT  "Low Salary"  AS category,  
	SUM(IF(income<20000,  1,  0))  AS accounts_count
FROM Accounts

UNION

SELECT  "Average Salary"  AS category,  
	SUM(IF(income>=20000  AND income<=50000,  1,  0))  AS accounts_count
FROM Accounts

UNION

SELECT  "High Salary"  AS category,  
	SUM(IF(income>50000,  1,  0))  AS accounts_count
FROM Accounts
```