# Write your MySQL query statement below

SELECT s.user_id, IFNULL( ROUND( SUM(action = 'confirmed')/COUNT(*) ,2), 0.00) AS confirmation_rate
FROM Signups as s LEFT JOIN Confirmations as c
ON s.user_id = c.user_id
GROUP BY s.user_id;


-- SUM counts total confirmed
-- COUNT counts total s.user_id which we stricted to 1 using group by
-- ROUND(3,2)= 3.00, it rounds 3 to 3.00 upto 2 digits
-- IFNULL(expression, value_if_null), here we will show 3.00 , if null then 0.00