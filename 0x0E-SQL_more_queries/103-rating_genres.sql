-- Lists all genres in the database hbtn_0d_tvshows_rate by their rating
-- Results must be sorted in descending order by their rating
-- The database name will be passed as an argument of the mysql command
SELECT
    tg.name AS 'name',
    SUM(tsr.rate) AS 'rating'
FROM
    tv_genres tg
LEFT JOIN
    tv_show_genres tsg
ON
    tg.id = tsg.genre_id
LEFT JOIN
    tv_show_ratings tsr
ON
    tsg.show_id = tsr.show_id
GROUP BY
    name
ORDER BY
    rating DESC;
