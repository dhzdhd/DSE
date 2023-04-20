SET SERVEROUTPUT ON

CREATE OR REPLACE TRIGGER valid_emp
BEFORE INSERT OR UPDATE OF lead_by_empcode
ON prj_details
FOR EACH ROW
DECLARE
    v_desg emp.designation%TYPE;
    v_skillexp emp_skill.skill_experience%TYPE;
BEGIN
    SELECT e.designation, s.skill_experience
    INTO v_desg, v_skillexp
    FROM emp e JOIN emp_skill s ON e.empcode = s.empno
               JOIN prj_details p ON p.lead_by_empcode = e.empcode
    WHERE p.lead_by_empcode = :new.lead_by_empcode AND ROWNUM = 1;

    IF v_desg NOT IN ('PROJEACT LEADER', 'PROJECT MANAGER') AND v_skillexp < 18 THEN
        raise_application_error(-20111, 'Not eligible');
    END IF;
END;
/

-- INSERT INTO prj_details VALUES('P10', 'HADESS', '07-JAN-2020', '07-DEC-2020', '08-DEC-2020', 110, 8000000, 9000000);
