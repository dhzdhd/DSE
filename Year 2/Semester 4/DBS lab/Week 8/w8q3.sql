SET SERVEROUTPUT ON

CREATE OR REPLACE PROCEDURE additional_budget(pid IN VARCHAR2,extra_bud OUT NUMBER) IS
    v_prjrow prj_details%ROWTYPE;
    v_edays NUMBER;
    v_bpd NUMBER;
    v_days NUMBER;
BEGIN
    SELECT * INTO v_prjrow
    FROM prj_details
    WHERE prjid = pid;

    SELECT TO_DATE(v_prjrow.actual_end_date,'dd-mm-yyyy') - TO_DATE(v_prjrow.end_date,'dd-mm-yyyy')
    INTO v_edays FROM dual;

    SELECT TO_DATE(v_prjrow.end_date,'dd-mm-yyyy') - TO_DATE(v_prjrow.strat_date,'dd-mm-yyyy')
    INTO v_days FROM dual;

    v_bpd := v_prjrow.budget_allocated / v_days;

    extra_bud := v_edays * v_bpd;
END additional_budget;
/

SET SERVEROUTPUT ON
DECLARE
    v_ebud NUMBER;
    v_plname emp.name%TYPE;
    v_pid prj_details.prjid%TYPE := '&id';
    v_rname emp.name%type;
    v_remail emp.email%TYPE;
BEGIN
    additional_budget(v_pid,v_ebud);

    SELECT name INTO v_plname
    FROM emp e JOIN prj_details p ON e.empcode = p.lead_by_empcode
    WHERE p.prjid = v_pid;

    SELECT name,email INTO v_rname,v_remail
    FROM emp
    WHERE empcode = (SELECT reports_to
                     FROM emp
                     WHERE name = v_plname);

    dbms_output.put_line('Name of the leader:' || v_plname);
    dbms_output.put_line('Name and email of the employee who leader reports to:' || v_rname || ' ' || v_remail);
    dbms_output.put_line('Additional budget needed:' || TRUNC(v_ebud,2));
END;
/
