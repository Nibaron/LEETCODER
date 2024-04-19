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