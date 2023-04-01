SET SERVEROUTPUT ON
DECLARE
    CURSOR c IS
        SELECT name, designation 
        FROM emp;
BEGIN
    FOR i IN c LOOP
        dbms_output.put_line('Name: ' || i.name);
        dbms_output.put_line('Designation: ' || i.designation);
        dbms_output.put_line('Email Generated: ' || INITCAP(i.name) || '.' || INITCAP(i.designation) || '@digisoul.com');
        dbms_output.put_line('...');
    END LOOP; 
END;
/