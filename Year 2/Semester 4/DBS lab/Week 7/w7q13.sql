SET SERVEROUTPUT ON
DECLARE
    CURSOR c(v_clientid work_exp.clientid%TYPE, v_rating work_exp.rating%TYPE) IS
        SELECT empcode, name, designation, clientid, rating
        FROM emp NATURAL JOIN work_exp
        WHERE rating = v_rating AND clientid = v_clientid;

    v_client work_exp.clientid%TYPE := '&vc';
    v_rating work_exp.rating%TYPE := '&vr';
BEGIN
    FOR i IN c(v_client, v_rating) LOOP
        dbms_output.put_line('Code: ' || i.empcode);
        dbms_output.put_line('Name: ' || i.name);
        dbms_output.put_line('Designation: ' || i.designation);
    END LOOP;

END;
/
