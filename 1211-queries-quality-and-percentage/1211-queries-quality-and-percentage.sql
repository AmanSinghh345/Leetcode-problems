# Write your MySQL query statement below
select query_name,round(sum(rating/position)*1.0/count(*),2) as quality,
round(sum(if(rating<3,1,0))*100.0/count(*),2) as poor_query_percentage 
from queries
group by query_name;