
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