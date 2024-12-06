emp_id, mgr_id, emp_sal // emp

SELECT e.emp_id from emp as e join emp as m where e.mgr_id == m.emp_id && e.emp_sal > m.emp_sal;

SELECT e.emp_id from emp as e where e.emp_sal > (select emp_sal form emp where emp_id = e.mgr_id);


CREATE TABLE Worker (
    WORKER_ID INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    FIRST_NAME CHAR(25),
    LAST_NAME CHAR(25),
    SALARY INT(15),
    JOINING_DATE DATETIME,
    DEPARTMENT CHAR(25)
);

Write an SQL to fetch full name and salary of all the workers.

Select FIRST_NAME + " " + LAST_NAME as FULL_NAME, SALARY from Worker;

Select FIRST_NAME from Worker where FIRST_NAME like "%A%" and SALARY >= 100000 and SALARY <= 500000;

Select DEPARTMENT from Worker Group by DEPARTMENT;
Select Distinct DEPARTMENT from Worker;

Write an SQL to fetch number workers joined the company on a particular date '2-5-2022' in each deparatment.

Select COUNT(*) as NO_OF_Joined, DEPARTMENT from Worker where JOINING_DATE == '2-5-2022' GROUP BY DEPARTMENT;

head and tail
-chmod 

NATURAL JOIN
