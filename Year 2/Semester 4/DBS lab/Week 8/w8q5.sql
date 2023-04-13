SET SERVEROUTPUT ON

CREATE OR REPLACE FUNCTION fetch_client(
    v_code IN VARCHAR2
) RETURN client.name%TYPE AS
    v_name client.name%TYPE;
BEGIN
    SELECT name
    INTO v_name
    FROM client
    WHERE phone LIKE (v_code || '%') AND ROWNUM = 1;

    RETURN v_name;
END;
/

DECLARE
    v_code VARCHAR2(3) := '&code';
    v_name client.name%TYPE;
BEGIN
    v_name := fetch_client(v_code);
    dbms_output.put_line('Name ' || v_name);
END;
/
