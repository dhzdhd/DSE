# Change skillexperience to skill_experience
# Change start_date to strat_date

# 4.1
SELECT * FROM client;

# 4.2
SELECT name, phone, email FROM emp WHERE designation = 'DEVELOPER';

# 4.3
SELECT name FROM emp WHERE reports_to= 106;

# 4.4
SELECT name, email 
FROM emp 
WHERE designation = 'TECHNICAL HEAD' AND qualification = 'BTECH';

# 4.5
SELECT name
FROM emp
WHERE salary >= 100000 AND salary <= 200000;

SELECT name
FROM emp
WHERE salary BETWEEN 100000 AND 200000;

# 4.6
SELECT skillid 
FROM emp 
JOIN emp_skill ON emp.empcode = emp_skill.empno 
WHERE empcode = 101;

# 4.7
SELECT skillname 
FROM emp 
JOIN emp_skill ON emp.empcode = emp_skill.empno 
JOIN skill ON emp_skill.skillid = skill.skillid 
WHERE empcode = 101;

# 4.8
SELECT empcode
FROM work_exp
WHERE clientid IN ('C1', 'C2') AND rating IN ('A', 'B');

# 4.9
SELECT name
FROM work_exp NATURAL JOIN emp
WHERE clientid = 'C2' AND rating = 'B';

# 4.10
SELECT count(f.dep_name)
FROM emp e JOIN family_dependents f ON e.empcode = f.empno
WHERE e.name = 'RAVI'; 

# 4.11
SELECT name, designation, (salary * 12) Annual_Salary
FROM emp;

# 4.12
# Works but doesnt show NULL
SELECT name, dep_name
FROM emp e LEFT JOIN family_dependents f ON e.empcode = f.empno;

# 4.13
SELECT name, prj_name 
FROM emp e JOIN prj_details p ON e.empcode = p.lead_by_empcode
WHERE p.actual_end_date <= p.end_date AND p.actual_budget <= p.budget_allocated;

# 4.14
SELECT name, salary, p.*
FROM emp JOIN pay_check p ON emp.empcode = p.empcode
WHERE pay_date LIKE '%MAR%';

# 4.15
SELECT e.name, ee.name, ee.phone
FROM emp e JOIN emp ee ON e.reports_to = ee.empcode;

# 4.16
SELECT *
FROM prj_details
ORDER BY actual_end_date DESC;

# 4.17
SELECT e.name, s.skillname 
FROM emp e
JOIN emp_skill es ON e.empcode = es.empno 
JOIN skill s ON es.skillid = s.skillid 
ORDER BY e.empcode ASC, es.skill_experience DESC;

# 4.18
SELECT name, dep_name, age
FROM emp NATURAL JOIN family_dependents
WHERE relationship = 'SON'
ORDER BY name ASC, age DESC;

# 4.19
SELECT e.name, p.prj_name
FROM emp e JOIN prj_details p ON e.empcode = p.lead_by_empcode
ORDER BY e.name ASC, p.prj_name DESC;

# 4.20
SELECT e.name
FROM emp e JOIN prj_details p ON e.empcode = p.lead_by_empcode
WHERE p.prj_name = 'SPYDER'
UNION
SELECT e.name
FROM emp e JOIN prj_details p ON e.empcode = p.lead_by_empcode
WHERE p.prj_name = 'APOLLO';

# 4.21
SELECT e.name 
FROM emp e
JOIN emp_skill es ON e.empcode = es.empno 
JOIN skill s ON es.skillid = s.skillid
WHERE s.skillname = 'Oracle'
INTERSECT
SELECT e.name 
FROM emp e
JOIN emp_skill es ON e.empcode = es.empno 
JOIN skill s ON es.skillid = s.skillid
WHERE s.skillname = 'AZURE';

# 4.22
SELECT e.name
FROM emp e JOIN prj_details p ON e.empcode = p.lead_by_empcode
MINUS
SELECT e.name
FROM emp e JOIN prj_details p ON e.empcode = p.lead_by_empcode
WHERE p.prj_name = 'JUPITOR';

# 4.23
SELECT name
FROM emp
WHERE reports_to IS NULL;

# 4.24
SELECT name, email
FROM emp
WHERE name LIKE 'RA%';

# 4.25
SELECT prj_name
FROM prj_details
WHERE STRAT_DATE BETWEEN '01-JAN-2020' AND '31-DEC-2020';

# 4.26
SELECT e.name
FROM emp e JOIN emp_skill s ON e.empcode = s.empno
WHERE s.skillid IN 
	((SELECT skillid
	FROM emp_skill
	WHERE empno = 101));