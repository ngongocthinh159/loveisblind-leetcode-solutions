# Write your MySQL query statement below
SELECT IFNULL ((SELECT DISTINCT e.salary
FROM employee e
ORDER BY e.salary DESC
LIMIT 1,1), NULL) SecondHighestSalary;
