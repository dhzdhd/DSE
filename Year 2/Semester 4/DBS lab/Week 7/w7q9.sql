SET SERVEROUTPUT ON
DECLARE
    CURSOR c IS
        SELECT e.name, p.prj_name
        FROM emp e JOIN prj_details p ON e.empcode = p.lead_by_empcode
        WHERE p.actual_budget < p.budget_allocated;
BEGIN
    FOR i IN c LOOP
        dbms_output.put_line('Name: ' || i.name);
        dbms_output.put_line('Project: ' || i.prj_name);
        dbms_output.put_line('...');
    END LOOP;

END;
/
