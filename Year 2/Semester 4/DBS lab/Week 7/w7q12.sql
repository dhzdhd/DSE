SET SERVEROUTPUT ON
DECLARE
    CURSOR c IS
        SELECT e.name, s.skillname, es.skill_experience
        FROM emp e
            JOIN emp_skill es ON e.empcode = es.empno
            JOIN skill s ON s.skillid = es.skillid
        WHERE s.skillname IN ('Full stack', 'Oracle', 'Android')
            AND es.skill_experience > 12;
BEGIN
    FOR i IN c LOOP
        dbms_output.put_line('Name: ' || i.name);
    END LOOP;

END;
/
