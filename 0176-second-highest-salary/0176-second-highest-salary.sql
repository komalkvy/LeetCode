# Write your MySQL query statement below

SELECT
CASE
    WHEN count(*) = 0 Then null
    ELSE salary
END As SecondHighestSalary
FROM(
SELECT *,
ROW_NUMBER() OVER (ORDER BY salary DESC) as r
FROM (SELECT DISTINCT salary FROM Employee) as A) As B
where r = 2;