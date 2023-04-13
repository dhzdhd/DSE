SET SERVEROUTPUT ON

CREATE OR REPLACE PROCEDURE fetch_hr(
    v_skill IN emp_skill.skillid%TYPE,
    v_skillexp IN emp_skill.skill_experience%TYPE
) AS
    CURSOR c IS
        SELECT s.skillid, s.skill_experience, e.name
        FROM emp_skill s JOIN emp e ON e.empcode = s.empno
        WHERE s.skillid = v_skill AND s.skill_experience = v_skillexp;
BEGIN
    FOR i IN c LOOP
        dbms_output.put_line('Name: ' || i.name);
    END LOOP;
END;
/

DECLARE
    v_skill emp_skill.skillid%TYPE := '&skill';
    v_skillexp emp_skill.skill_experience%TYPE := &skexp;
BEGIN
    fetch_hr(v_skill, v_skillexp);
END;
/
