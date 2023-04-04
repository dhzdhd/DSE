SET SERVEROUTPUT ON
DECLARE
    CURSOR c IS
        SELECT name, SUM(work_experience) AS total_work_exp
        FROM emp NATURAL JOIN work_exp
        GROUP BY name
        ORDER BY SUM(work_experience) DESC;

        v_count NUMBER := 0;
BEGIN
    FOR i IN c LOOP
        v_count := v_count + 1;

        dbms_output.put_line('Name: ' || i.name);
        dbms_output.put_line('Total work experience: ' || i.total_work_exp);

        IF v_count = 5 THEN
            EXIT;
        END IF;
    END LOOP;

END;
/
