# Write your MySQL query statement below
SELECT query_name, 
        ROUND( SUM(rating/position)/COUNT(query_name) ,2) AS quality,
        ROUND(SUM(IF(rating < 3, 1, 0)) * 100/COUNT(query_name),2) AS poor_query_percentage
FROM Queries
WHERE query_name IS NOT NULL
GROUP BY query_name;
-- SUM(IF(rating < 3, 1, 0)) * 100
-- it means if rating < 3 then 1 or else 0
-- ROUND( SUM(rating/position)/COUNT(query_name) ,2) AS quality, OR,AVG(rating/position)