# Write your MySQL query statement below
SELECT d.name Department, e.name Employee, e.salary Salary
FROM employee e JOIN department d ON e.departmentId = d.id
WHERE e.salary  >= IFNULL((SELECT DISTINCT e1.salary FROM employee e1 WHERE e1.departmentId = e.departmentId ORDER BY e1.salary DESC LIMIT 2,1), -1);