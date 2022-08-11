-- Lists all shows from hbtn_0d_tvshows_rate by their rating
-- Results must be sorted in descending order by the rating
-- The database name will be passed as an argument of the mysql command
SELECT
    ts.title AS 'title',
    SUM(tsr.rate) AS 'rating'
FROM
    tv_shows ts
LEFT JOIN
    tv_show_ratings tsr
ON
    ts.id = tsr.show_id
GROUP BY
    title
ORDER BY
    rating DESC;
