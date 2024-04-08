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