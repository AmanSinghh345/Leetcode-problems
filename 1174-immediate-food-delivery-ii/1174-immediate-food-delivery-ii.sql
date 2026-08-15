# Write your MySQL query statement below
select round(avg(if(d1.order_date=d1.customer_pref_delivery_date,1,0))*100.0,2) as immediate_percentage 
from delivery d1
where (customer_id,order_date) IN (
    select customer_Id,min(order_date)
    from delivery 
    group by customer_id
);