SET SERVEROUTPUT ON

CREATE OR REPLACE TRIGGER monitor_date
BEFORE UPDATE OF actual_end_date, actual_budget OR INSERT
ON prj_details
FOR EACH ROW
DECLARE
    v_range VARCHAR2(20);
    v_add NUMBER;
BEGIN
    v_range := :new.actual_end_date - :new.end_date;
    v_add := :new.actual_budget - :new.budget_allocated;
    dbms_output.put_line(v_range);
    dbms_output.put_line(v_add);
    dbms_output.put_line(0.15 * :new.budget_allocated);

    IF v_range >= 90 OR v_add > 0.15 * :new.budget_allocated THEN
        dbms_output.put_line('Need to take approval through proper channel');
        raise_application_error(-20111, 'Need approval');
    END IF;
END;
/

-- INSERT INTO prj_details VALUES('P10', 'HADESS', '07-JAN-2020', '08-JAN-2021', '09-JAN-2022', 110, 8000000, 9000000);
