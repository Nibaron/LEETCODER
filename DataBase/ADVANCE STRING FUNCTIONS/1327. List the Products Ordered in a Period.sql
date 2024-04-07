
# Write your MySQL query statement below
SELECT p.product_name,
    SUM(unit) AS unit
FROM Products p INNER JOIN Orders o
ON p.product_id = o.product_id
WHERE o.order_date BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY product_name
HAVING unit>=100;


-- name, amt
-- >= 100 units, feb 2020

SELECT p.product_name,  SUM(o.unit)  AS unit
FROM Products p LEFT JOIN Orders o
ON p.product_id = o.product_id
WHERE  DATE_FORMAT(order_date,  '%Y-%m')  =  '2020-02'
GROUP  BY p.product_name
HAVING  SUM(o.unit)  >=  100;
