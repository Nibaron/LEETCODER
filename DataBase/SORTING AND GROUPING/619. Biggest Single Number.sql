# Write your MySQL query statement below
SELECT max(num) AS num
FROM MyNumbers
WHERE num IN
(
    SELECT num FROM MyNumbers
    GROUP BY num
    HAVING COUNT(num) = 1
);


# Write your MySQL query statement below
select 
max(num) as num
from(
    select num from Mynumbers
    group by num
    having count(num)=1
)as subquery;