# [1978. Employees Whose Manager Left the Company](https://leetcode.com/problems/employees-whose-manager-left-the-company/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Users`

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| name          | varchar |
| mail          | varchar |
+---------------+---------+
user_id is the primary key (column with unique values) for this table.
This table contains information of the users signed up in a website. Some e-mails are invalid.
```

Write a solution to find the users who have **valid emails** .

A valid e-mail has a prefix name and a domain where:

- **The prefix name**  is a string that may contain letters (upper or lower case), digits, underscore `'_'`, period `'.'`, and/or dash `'-'`. The prefix name **must**  start with a letter.
- **The domain**  is `'@leetcode.com'`.

Return the result table in **any order** .

The result format is in the following example.

**Example 1:** 

```
Input: 
Users table:
+---------+-----------+-------------------------+
| user_id | name      | mail                    |
+---------+-----------+-------------------------+
| 1       | Winston   | winston@leetcode.com    |
| 2       | Jonathan  | jonathanisgreat         |
| 3       | Annabelle | bella-@leetcode.com     |
| 4       | Sally     | sally.come@leetcode.com |
| 5       | Marwan    | quarz#2020@leetcode.com |
| 6       | David     | david69@gmail.com       |
| 7       | Shapiro   | .shapo@leetcode.com     |
+---------+-----------+-------------------------+
Output: 
+---------+-----------+-------------------------+
| user_id | name      | mail                    |
+---------+-----------+-------------------------+
| 1       | Winston   | winston@leetcode.com    |
| 3       | Annabelle | bella-@leetcode.com     |
| 4       | Sally     | sally.come@leetcode.com |
+---------+-----------+-------------------------+
Explanation: 
The mail of user 2 does not have a domain.
The mail of user 5 has the # sign which is not allowed.
The mail of user 6 does not have the leetcode domain.
The mail of user 7 starts with a period.
```
>My Code
```sql
# Write your MySQL query statement below
SELECT employee_id
FROM Employees
WHERE salary < 30000
AND  manager_id NOT IN 
(
    SELECT employee_id FROM Employees
)
ORDER BY employee_id;
```

# [626. Exchange Seats](https://leetcode.com/problems/exchange-seats/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Users`

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| name          | varchar |
| mail          | varchar |
+---------------+---------+
user_id is the primary key (column with unique values) for this table.
This table contains information of the users signed up in a website. Some e-mails are invalid.
```

Write a solution to find the users who have **valid emails** .

A valid e-mail has a prefix name and a domain where:

- **The prefix name**  is a string that may contain letters (upper or lower case), digits, underscore `'_'`, period `'.'`, and/or dash `'-'`. The prefix name **must**  start with a letter.
- **The domain**  is `'@leetcode.com'`.

Return the result table in **any order** .

The result format is in the following example.

**Example 1:** 

```
Input: 
Users table:
+---------+-----------+-------------------------+
| user_id | name      | mail                    |
+---------+-----------+-------------------------+
| 1       | Winston   | winston@leetcode.com    |
| 2       | Jonathan  | jonathanisgreat         |
| 3       | Annabelle | bella-@leetcode.com     |
| 4       | Sally     | sally.come@leetcode.com |
| 5       | Marwan    | quarz#2020@leetcode.com |
| 6       | David     | david69@gmail.com       |
| 7       | Shapiro   | .shapo@leetcode.com     |
+---------+-----------+-------------------------+
Output: 
+---------+-----------+-------------------------+
| user_id | name      | mail                    |
+---------+-----------+-------------------------+
| 1       | Winston   | winston@leetcode.com    |
| 3       | Annabelle | bella-@leetcode.com     |
| 4       | Sally     | sally.come@leetcode.com |
+---------+-----------+-------------------------+
Explanation: 
The mail of user 2 does not have a domain.
The mail of user 5 has the # sign which is not allowed.
The mail of user 6 does not have the leetcode domain.
The mail of user 7 starts with a period.
```
# Discussion
When we use if-else if-else type , we use `CASE`
Structure:
```CASE
WHEN
	THEN
WHEN 
	THEN
ELSE
END AS
```

> My Code
```sql
# Write your MySQL query statement below
SELECT 
    CASE
        WHEN 
	        -- last id and odd, then id = id
            id = (SELECT MAX(id) FROM Seat ) AND MOD(id, 2) = 1
            THEN id
        WHEN
	        -- id odd (1), then make it even(1+1=2) 
            MOD(id,2) = 1 
            THEN id+1
        ELSE 
	        -- id even(2), make it odd(2-1=1)
            id-1
        END AS id,
    student
FROM Seat
ORDER BY id;
```
# [1341. Movie Rating](https://leetcode.com/problems/movie-rating/description/?envType=study-plan-v2&envId=top-sql-50)

Table: `Users`

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| name          | varchar |
| mail          | varchar |
+---------------+---------+
user_id is the primary key (column with unique values) for this table.
This table contains information of the users signed up in a website. Some e-mails are invalid.
```

Write a solution to find the users who have **valid emails** .

A valid e-mail has a prefix name and a domain where:

- **The prefix name**  is a string that may contain letters (upper or lower case), digits, underscore `'_'`, period `'.'`, and/or dash `'-'`. The prefix name **must**  start with a letter.
- **The domain**  is `'@leetcode.com'`.

Return the result table in **any order** .

The result format is in the following example.

**Example 1:** 

```
Input: 
Users table:
+---------+-----------+-------------------------+
| user_id | name      | mail                    |
+---------+-----------+-------------------------+
| 1       | Winston   | winston@leetcode.com    |
| 2       | Jonathan  | jonathanisgreat         |
| 3       | Annabelle | bella-@leetcode.com     |
| 4       | Sally     | sally.come@leetcode.com |
| 5       | Marwan    | quarz#2020@leetcode.com |
| 6       | David     | david69@gmail.com       |
| 7       | Shapiro   | .shapo@leetcode.com     |
+---------+-----------+-------------------------+
Output: 
+---------+-----------+-------------------------+
| user_id | name      | mail                    |
+---------+-----------+-------------------------+
| 1       | Winston   | winston@leetcode.com    |
| 3       | Annabelle | bella-@leetcode.com     |
| 4       | Sally     | sally.come@leetcode.com |
+---------+-----------+-------------------------+
Explanation: 
The mail of user 2 does not have a domain.
The mail of user 5 has the # sign which is not allowed.
The mail of user 6 does not have the leetcode domain.
The mail of user 7 starts with a period.
```

> My Code
```sql
# Write your MySQL query statement below
(
    SELECT  u.name AS results
    FROM Users u INNER JOIN MovieRating mr
    USING(user_id)
    GROUP BY user_id
    ORDER BY COUNT(user_id) DESC, name
    LIMIT 1
)

UNION ALL

(
    SELECT m.title AS results
    FROM Movies m INNER JOIN MovieRating mr
    USING(movie_id)
    WHERE MONTH(created_at) = '02' AND YEAR(created_at) ='2020'
    GROUP BY title
    ORDER BY AVG(rating) DESC, title
    LIMIT 1
)
```
- <b> What is the difference between `UNION` and `UNION ALL`</b>
- what if user name and movie title is same. Does union will consider it or skipp?

