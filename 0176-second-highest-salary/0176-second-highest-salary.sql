# Write your MySQL query statement below
with temp as (select salary , dense_rank() over( order by salary desc) as rnk from employee )
select max(salary) as SecondHighestSalary from temp where rnk=2;  
