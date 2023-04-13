SET SERVEROUTPUT ON

CREATE OR REPLACE PROCEDURE fetch_additional_budget(
    v_prjid IN prj_details.prjid%TYPE,
    v_ab OUT NUMBER
) AS
    v_prjd prj_details%ROWTYPE;
    v_pdc NUMBER;
BEGIN
    SELECT *
    INTO v_prjd
    FROM prj_details
    WHERE ROWNUM = 1 AND prjid = v_prjid;

    IF actual_end_date > end_date THEN
        v_pdc := v_prjd.budget_allocated / TO_CHAR(DATEDIFF(DAYS, v_prjd.strat_date, v_prjd.end_date), 'DD');
        v_ab := v_pdc * TO_CHAR(DATEDIFF(DAYS, v_prjd.end_date, v_prjd.actual_end_date), 'DD');
    END IF;
END;
/

DECLARE
    v_plname emp.name%TYPE;
    v_plcode emp.empcode%TYPE;
    v_prjid prj_details.prjid%TYPE := '%prjid';
    v_name emp.name%TYPE;
    v_email emp.email%TYPE;
    v_ab NUMBER;
BEGIN
    fetch_additional_budget(v_prjid, v_ab);

    SELECT e.name, e.empcode
    INTO v_plname, v_plcode
    FROM emp e JOIN prj_details p ON e.empcode = p.lead_by_empcode
    WHERE ROWNUM = 1 AND p.prjid = v_prjid;

    SELECT ee.name, ee.email
    INTO v_name, v_email
    FROM emp e JOIN emp ee ON ee.empcode = e.reports_to
    WHERE ROWNUM = 1 AND e.empcode = v_plcode;

    dbms_output.put_line("Project leader: " || v_plname);
    dbms_output.put_line("Reports to name: " || v_name || " and email " || v_email);
    dbms_output.put_line("Additional budget: " || v_ab);
END;
/
