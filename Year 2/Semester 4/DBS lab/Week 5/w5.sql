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
SELECT DISTINCT name
FROM emp e
    JOIN family_dependents f ON e.empcode = f.empno
WHERE relationship = 'DAGHTER';

# 5.5
SELECT DISTINCT name
FROM emp e
    JOIN work_exp w ON e.empcode = w.empcode
    JOIN prj_details p ON w.prjid = p.prjid
WHERE name NOT IN (
        SELECT name
        FROM work_exp w
            JOIN prj_details p ON w.prjid = p.prjid
            JOIN emp e ON e.empcode = w.empcode
        WHERE
            prj_name = 'SPYDER'
    );

# 5.6
SELECT DISTINCT name
FROM emp e
    JOIN emp_skill s ON e.empcode = s.empno
WHERE s.skillid = SOME (
        SELECT s.skillid
        FROM emp_skill s
            JOIN work_exp w ON s.empno = w.empcode
        WHERE w.prjid = 'P1'
    );

# 5.7
SELECT DISTINCT name
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
WHERE
    e.empcode != 100
    AND EXISTS (
        SELECT *
        FROM work_exp w
        WHERE
            e.empcode = w.empcode
            AND w.prjid IN (
                SELECT prjid
                FROM work_exp
                WHERE
                    empcode = 100
            )
            AND w.clientid IN (
                SELECT
                    clientid
                FROM work_exp
                WHERE
                    empcode = 100
            )
    );

# 5.9
SELECT DISTINCT name
FROM emp e
WHERE
    e.empcode != 106
    AND NOT EXISTS (
        SELECT *
        FROM work_exp w
        WHERE
            e.empcode = w.empcode
            AND prjid NOT IN (
                SELECT prjid
                FROM work_exp
                WHERE
                    empcode = 106
            )
    );

# 5.10
SELECT p.prj_name
FROM prj_details p
WHERE p.budget_allocated > (
        SELECT sum(salary)
        FROM emp e
            JOIN work_exp w ON e.empcode = w.empcode
        WHERE
            w.prjid = p.prjid
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
SELECT DISTINCT prj_name
FROM work_exp w
    JOIN prj_details p ON w.prjid = p.prjid
WHERE 2 < (
        SELECT
            count(ww.empcode)
        FROM work_exp ww
            JOIN prj_details pp ON ww.prjid = pp.prjid
        WHERE
            pp.prjid = p.prjid
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
        name,
        skill_name,
        skill_experience
    ) AS
SELECT
    e.name,
    s.skillname,
    sk.skill_experience
FROM emp_skill sk
    JOIN emp e ON sk.empno = e.empcode
    JOIN skill s ON sk.skillid = s.skillid
WHERE sk.skill_experience > 20;

UPDATE emp_skill_experience
SET skill_experience = 5;

-- * No rows to update. Selecting * shows no rows as the constraint on the view (>20) is no longer satisfied

# 5.19
CREATE VIEW
    emp_designation(empno, name, salary) AS
SELECT empcode, name, salary
FROM emp
WHERE
    designation IN (
        'DEVELOPER',
        'PROJEACT LEADER',
        'PRJOECT LEADER'
    );

UPDATE emp_designation SET salary = 300000 WHERE name = 'MANISH';

-- * Rows are updated.

# 5.20
SELECT DISTINCT ee.name, (
        SELECT
            count(w.empcode)
        FROM emp e
            JOIN work_exp w ON e.empcode = w.empcode
        GROUP BY e.name
        HAVING
            e.name = ee.name
    ) project_count
FROM emp ee
    JOIN work_exp w ON ee.empcode = w.empcode;
