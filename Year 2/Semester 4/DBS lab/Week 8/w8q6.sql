SET SERVEROUTPUT ON

CREATE OR REPLACE FUNCTION fetch_email(
    v_name IN emp.name%TYPE,
    v_eno IN emp.empcode%TYPE
) RETURN VARCHAR2 IS
BEGIN
    RETURN (v_name || '_' || v_eno || '@digisol.com');
END;
/

DECLARE
    v_name emp.name%TYPE := '&name';
    v_eno emp.empcode%TYPE := &eno;
    v_email emp.email%TYPE;
BEGIN
    v_email := fetch_email(v_name, v_eno);
    dbms_output.put_line(v_email);
END;
/
