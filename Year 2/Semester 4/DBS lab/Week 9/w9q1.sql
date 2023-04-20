SET SERVEROUTPUT ON

CREATE OR REPLACE TRIGGER salary_hike
BEFORE UPDATE OF salary
ON emp
FOR EACH ROW
DECLARE
    v_range emp.salary%TYPE;
    v_text VARCHAR(20) := 'Out of range';
BEGIN
    v_range := :new.salary - :old.salary;

    CASE :old.designation
    WHEN 'DEVELOPER' THEN
        IF v_range > 1000 OR :new.salary NOT BETWEEN 97000 AND 120000 THEN
            raise_application_error(-20111, v_text);
        END IF;
    WHEN 'PROJEACT LEADER' THEN
        IF v_range > 2000 OR :new.salary NOT BETWEEN 110000 AND 140000 THEN
            raise_application_error(-20111, v_text);
        END IF;
    WHEN 'PROJECT MANAGER' THEN
        IF v_range > 3000 OR :new.salary NOT BETWEEN 120000 AND 160000 THEN
            raise_application_error(-20111, v_text);
        END IF;
    WHEN 'TECHNICAL HEAD' THEN
        IF v_range > 3000 OR :new.salary NOT BETWEEN 140000 AND 200000 THEN
            raise_application_error(-20111, v_text);
        END IF;
    WHEN 'PROJECT DIRECTOR' THEN
        IF v_range > 10000 OR :new.salary NOT BETWEEN 210000 AND 270000 THEN
            raise_application_error(-20111, v_text);
        END IF;
    WHEN 'CEO' THEN
        IF v_range > 20000 OR :new.salary NOT BETWEEN 220000 AND 300000 THEN
            raise_application_error(-20111, v_text);
        END IF;
    END CASE;
END;
/

-- update emp set salary = 200000 where name = 'GAGAN';
