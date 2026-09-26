-- Write your PostgreSQL query statement below
select today.id from weather today
join weather yesterday on today.recordDate - yesterday.recordDate = 1 and today.temperature > yesterday.temperature