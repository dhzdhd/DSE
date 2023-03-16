# 5.1
SELECT name
FROM emp
WHERE designation = (
        SELECT designation
        FROM emp
        WHERE empcode = 100
    );

# 5.2
SELECT name
FROM emp
WHERE reports_to IN (
        SELECT empcode
        FROM emp
        WHERE name = 'VIJAY'
    );

# 5.3
SELECT
    name,
    designation,
    email
FROM emp
    NATURAL JOIN work_exp
WHERE prjid IN (
        SELECT prjid
        FROM emp
            NATURAL JOIN work_exp
        WHERE name = 'VIJAY'
    );

# 5.4
SELECT name
FROM emp e
    JOIN family_dependents f ON e.empcode = f.empno
WHERE relationship = 'DAGHTER';

# 5.5
#
SELECT DISTINCT name
FROM emp
WHERE name IN (
        SELECT name
        FROM work_exp w
            JOIN prj_details p ON w.prjid = p.prjid
            JOIN emp e ON e.empcode = w.empcode
        WHERE
            prj_name != 'SPYDER'
    );

# 5.6
SELECT name
FROM emp e
    JOIN emp_skill s ON e.empcode = s.empno
WHERE s.skillid = SOME (
        SELECT s.skillid
        FROM emp_skill s
            JOIN work_exp w ON s.empno = w.empcode
        WHERE w.prjid = 'P1'
    );

# 5.7
SELECT name
FROM emp
    NATURAL JOIN work_exp
WHERE work_experience > ALL (
        SELECT
            work_experience
        FROM work_exp
        WHERE
            prjid = 'P2'
    )
    AND prjid = 'P1';

# 5.8
SELECT DISTINCT name
FROM emp e
    JOIN work_exp w ON e.empcode = w.empcode
WHERE NOT EXISTS (
        SELECT *
        FROM
            work_exp ww,
            emp ee
        WHERE
            ee.empcode != 100
            AND ww.prjid != w.prjid
            AND ww.clientid != w.clientid
    );

# 5.9
SELECT DISTINCT name
FROM emp e
    JOIN work_exp w ON e.empcode = w.empcode
WHERE NOT EXISTS (
        SELECT *
        FROM work_exp
        WHERE w.prjid NOT IN (
                SELECT prjid
                FROM emp
                    NATURAL JOIN work_exp
                WHERE
                    empcode = 106
            )
    );

# 5.10
SELECT p.prj_name
FROM prj_details p
WHERE prj_id IN (
        SELECT prj_id
        FROM prj_details
            JOIN work_exp w ON prj_details.prjid = w.prjid
            JOIN emp e ON e.empcode = w.empcode
        WHERE
            p.budget_allocated > sum(e.salary)
    );

# 5.11
SELECT
    prj_name,
    count(empcode)
FROM work_exp
    NATURAL JOIN prj_details
WHERE rating IN ('A', 'B')
GROUP BY prj_name
ORDER BY count(empcode) DESC;

# 5.12
#
SELECT prj_name
FROM work_exp w
    JOIN prj_details p ON w.prjid = p.prjid
WHERE EXISTS (
        SELECT
            pp.prj_name,
            count(ww.empcode) empcount
        FROM work_exp ww
            JOIN prj_details pp ON ww.prjid = pp.prjid
        WHERE
            pp.prjid = p.prjid
        GROUP BY pp.prj_name
        HAVING empcount > 2
    );

# 5.13
SELECT name, count(f.empno)
FROM emp e
    JOIN family_dependents f ON e.empcode = f.empno
GROUP BY name;

# 5.14
SELECT sum(premium)
FROM medical_policy
GROUP BY
    TO_CHAR(policydate, 'YYYY');

# 5.15
WITH skexp(name, value) AS (
        SELECT
            e.name,
            sum(s.skill_experience)
        FROM emp e
            JOIN emp_skill s ON e.empcode = s.empno
        GROUP BY e.name
    )
SELECT name
FROM skexp
WHERE value > 20;

# 5.16
CREATE TABLE
    emp_prj(emp_name, budget, project_name) AS
SELECT
    e.name,
    p.budget_allocated,
    p.prj_name
FROM emp e, prj_details p;

INSERT INTO emp_prj
SELECT
    e.name,
    p.budget_allocated,
    p.prj_name
FROM work_exp w
    JOIN emp e ON w.empcode = e.empcode
    JOIN prj_details p ON w.prjid = p.prjid
WHERE e.empcode = 110;

# 5.17
UPDATE emp
SET
    salary = CASE
        WHEN designation = 'PROJEACT LEADER' THEN salary * 1.1
        WHEN designation = 'PRJOECT LEADER' THEN salary * 1.1
        WHEN designation = 'DEVELOPER' THEN salary * 1.05
    END;

# 5.18
CREATE VIEW
    emp_skill_experience(
        employee_name,
        skill_name,
        skill_experience
    ) AS
SELECT

# 5.19
CREATE
