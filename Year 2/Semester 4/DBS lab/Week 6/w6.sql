-- 6.1

SELECT UPPER(name), LOWER(name), INITCAP(name) FROM emp;

-- 6.2

SELECT
    INITCAP(name) || ' Works as ' || INITCAP(designation)
FROM emp;

-- 6.3

SELECT LPAD(salary, 10, '*') FROM emp;

-- 6.4

SELECT RPAD(salary, 10, '*') FROM emp;

-- 6.5

SELECT LENGTH(name) FROM emp;

-- 6.6

SELECT SUBSTR(name, 3, 6) FROM emp;

-- 6.7

SELECT REPLACE(email, 'digisol', 'digitech') FROM emp;

-- 6.8

SELECT
    CONCAT(e.name, f.dep_name)
FROM emp e
    JOIN family_dependents f ON e.empcode = f.empno;

-- 6.9

SELECT clientid, LENGTH(name) FROM client;

-- 6.10

WITH a(value) AS (
        SELECT
            RTRIM(clientid)
        FROM client
    )
SELECT value, LENGTH(value)
FROM a;

-- 6.11

WITH a(value) AS (
        SELECT
            LTRIM(clientid)
        FROM client
    )
SELECT value, LENGTH(value)
FROM a;

WITH a(value) AS (
        SELECT TRIM(clientid)
        FROM client
    )
SELECT value, LENGTH(value)
FROM a;

-- 6.12

SELECT ASCII('A') FROM dual;

SELECT CHR(65) FROM dual;

-- 6.13

SELECT TRUNC(123.456, 2) FROM dual;

-- 6.14

SELECT POWER(4, 0.5) FROM dual;

SELECT POWER(4, 2) FROM dual;

SELECT POWER(4, 5) FROM dual;

-- 6.15

SELECT ROUND(123.456, 2) FROM dual;

-- 6.16

SELECT ABS(-123) FROM dual;

SELECT REMAINDER(123, 10) FROM dual;

-- 6.17

SELECT FLOOR(234.36) FROM dual;

SELECT FLOOR(-234.26) FROM dual;

SELECT CEIL(234.36) FROM dual;

SELECT CEIL(-234.26) FROM dual;

-- 6.18

SELECT
    TO_CHAR(strat_date, 'DD-Month-YYYY'),
    TO_CHAR(end_date, 'DD-Month-YYYY')
FROM prj_details;

-- 6.19

SELECT
    TO_CHAR(actual_end_date, 'Month'),
    TO_CHAR(actual_end_date, 'YYYY')
FROM prj_details;

-- 6.20

SELECT
    TO_CHAR(strat_date, 'Month'),
    TO_CHAR(strat_date, 'DD'),
    TO_CHAR(strat_date, 'YYYY')
FROM prj_details;

-- 6.21

SELECT
    prj_name,
    MONTHS_BETWEEN(strat_date, end_date)
FROM prj_details;

-- 6.22

SELECT prj_name, end_date, ADD_MONTHS(end_date, 2) FROM prj_details;

-- 6.23

SELECT NEXT_DAY(SYSDATE, 'THURSDAY') FROM dual;
