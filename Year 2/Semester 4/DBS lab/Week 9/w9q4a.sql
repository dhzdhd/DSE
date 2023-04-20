SET SERVEROUTPUT ON

CREATE OR REPLACE TRIGGER obsolete_record
BEFORE DELETE
ON skill
FOR EACH ROW
DECLARE
    v_count NUMBER;
    v_max emp_skill.skill_experience%TYPE;
BEGIN
    SELECT COUNT(*), MAX(skill_experience)
    INTO v_count, v_max
    FROM emp_skill
    WHERE skillid = :old.skillid;

    dbms_output.put_line(v_count);

    IF v_count > 1 THEN
        DELETE FROM emp_skill
        WHERE skillid = :old.skillid
        AND skill_experience != v_max;

        raise_application_error(-20111, 'Max exp not deleted');
    ELSE
        raise_application_error(-20111, 'Too few employees to delete');
    END IF;
END;
/

-- delete from skill where skillid='S1';
