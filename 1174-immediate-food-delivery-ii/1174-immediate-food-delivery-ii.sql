# Write your MySQL query statement below
with rankedDeliveries as (select order_date,customer_pref_delivery_date,
row_number() over(partition by customer_id order by order_date) as order_rank from delivery) 
select round(avg(if(order_date=customer_pref_delivery_date,1,0))*100,2) as 
immediate_percentage 
from rankedDeliveries where order_rank=1;