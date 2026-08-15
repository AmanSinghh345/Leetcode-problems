# Write your MySQL query statement below
select q1.query_name,
round((select avg(q4.rating/q4.position) from queries q4 where q4.query_name=q1.query_name group by q4.query_name),2) as quality,
round((select count(*) from 
queries q2 where q1.query_name=q2.query_name and q2.rating<3)*100.0/(select count(*) from queries q3 where q1.query_name=q3.query_name),2) as poor_query_percentage
from queries q1
group by q1.query_name;