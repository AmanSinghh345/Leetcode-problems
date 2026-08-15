
# Write your MySQL query statement below
select round(count(a2.player_id)/count(a1.player_id),2) as fraction from 
(select player_id,min(event_date) as first_login from activity group by player_id) a1 left join
activity a2 
on a1.player_id=a2.player_id
and a2.event_date=date_add(a1.first_login ,interval 1 day);