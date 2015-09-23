181. Employees Earning More Than Their Managers

The Employee table holds all employees including their managers. Every employee has an Id, and there is also a column for the manager Id.
+----+-------+--------+-----------+
| Id | Name  | Salary | ManagerId |
+----+-------+--------+-----------+
| 1  | Joe   | 70000  | 3         |
| 2  | Henry | 80000  | 4         |
| 3  | Sam   | 60000  | NULL      |
| 4  | Max   | 90000  | NULL      |
+----+-------+--------+-----------+


Given the Employee table, write a SQL query that finds out employees who earn more than their managers. For the above table, Joe is the only employee who earns more than his manager.
+----------+
| Employee |
+----------+
| Joe      |
+----------+


# Write your MySQL query statement below
SELECT t.Name FROM Employee t
LEFT JOIN Employee t2
ON t.ManagerId = t2.Id
WHERE t.Salary > t2.Salary

# Write your MySQL query statement below
SELECT t1.Name
FROM Employee t1
JOIN Employee t2
ON (t1.ManagerId=t2.Id) AND (t1.Salary>t2.Salary)
