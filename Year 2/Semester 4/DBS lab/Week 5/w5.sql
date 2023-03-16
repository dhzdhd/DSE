# 5.1
SELECT name
FROM emp
WHERE designation =
	(SELECT designation
	FROM emp
	WHERE empcode = 100);

# 5.2
SELECT name
FROM emp
WHERE reports_to IN
	(SELECT empcode
	FROM emp
	WHERE name = 'VIJAY');

# 5.3
SELECT name, designation, email
FROM emp NATURAL JOIN work_exp
WHERE prjid IN
	(SELECT prjid
	FROM emp NATURAL JOIN work_exp
	WHERE name = 'VIJAY');

# 5.4
SELECT name
FROM emp e JOIN family_dependents f ON e.empcode = f.empno
WHERE relationship = 'DAGHTER';

# 5.5
SELECT name
FROM emp NATURAL JOIN work_exp
WHERE name NOT IN
	(SELECT name
	FROM work_exp w
	JOIN prj_details p ON w.prjid = p.prjid
	JOIN emp e ON e.empcode = w.empcode
	WHERE prj_name = 'SPYDER');

# 5.6
SELECT name
FROM emp e JOIN emp_skill s ON e.empcode = s.empno
WHERE s.skillid = SOME
	(SELECT s.skillid
	FROM emp_skill s JOIN work_exp w ON s.empno = w.empcode
	WHERE w.prjid = 'P1');

# 5.7
SELECT name
FROM emp NATURAL JOIN work_exp
WHERE work_experience > ALL
	(SELECT work_experience
	FROM work_exp
	WHERE prjid = 'P2')
AND prjid = 'P1';

# 5.8
SELECT DISTINCT name
FROM emp e JOIN work_exp w ON e.empcode = w.empcode
WHERE  NOT EXISTS
	(SELECT *
	FROM work_exp ww, emp ee
	WHERE ee.empcode != 100
	AND ww.prjid != w.prjid
	AND ww.clientid != w.clientid);

# 5.9
SELECT DISTINCT name
FROM emp e JOIN work_exp w ON e.empcode = w.empcode
WHERE NOT EXISTS
	(SELECT *
	FROM work_exp
	WHERE w.prjid NOT IN
		(SELECT prjid
		FROM emp NATURAL JOIN work_exp
		WHERE empcode = 106));

# 5.10
SELECT p.prj_name
FROM prj_details p
WHERE prj_id IN
	(SELECT prj_id
	FROM prj_details
	JOIN work_exp w ON prj_details.prjid = w.prjid
	JOIN emp e ON e.empcode = w.empcode
	WHERE p.budget_allocated > sum(e.salary));

# 5.11
SELECT prj_name,
