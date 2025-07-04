-- Get the top-earning employee(s) in each department
WITH ranked_employees AS (
    SELECT 
        departmentId,
        name,
        salary,
        RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS salary_rank
    FROM 
        employee
)

SELECT 
    d.name AS Department,
    r.name AS Employee,
    r.salary
FROM 
    ranked_employees r
JOIN 
    Department d ON r.departmentId = d.id
WHERE 
    r.salary_rank = 1;