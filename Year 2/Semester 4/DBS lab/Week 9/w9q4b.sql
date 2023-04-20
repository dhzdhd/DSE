SET SERVEROUTPUT ON

DECLARE
    v_skillid skill.skillid%TYPE := '&skill';
BEGIN
    DELETE FROM skill
    WHERE skillid = v_skillid;
END;
/
