SET SERVEROUTPUT ON DECLARE v_row emp % ROWTYPE;

v_empcode NUMBER := & empcode;

BEGIN
SELECT * INTO v_row
FROM emp
WHERE
    empcode = v_empcode
    AND ROWNUM = 1;

dbms_output.put_line(
    'Name ' || v_row.name || ' Qual ' || v_row.qualification || ' Salary ' || v_row.salary
);

END;

/
