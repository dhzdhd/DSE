SET SERVEROUTPUT ON

DECLARE
    v_empcode work_exp.empcode%TYPE := &num;
    v_projid work_exp.prjid%TYPE := '&projid';
    v_rating work_exp.rating%TYPE;
    v_incentive NUMBER;
    v_emprow emp%ROWTYPE;
    v_prjname prj_details.prj_name%TYPE;
    v_tsal NUMBER;
BEGIN
    SELECT rating INTO v_rating
    FROM work_exp
    WHERE prjid = v_projid AND ROWNUM = 1;

    IF v_rating = 'A' THEN
        v_incentive := 9999;
    ELSIF v_rating = 'B' THEN
        v_incentive := 5000;
    ELSIF v_rating = 'C' THEN
        v_incentive := 3000;
    ELSE
        v_incentive := 0;
    END IF;

    SELECT * INTO v_emprow
    FROM emp
    WHERE empcode = v_empcode AND ROWNUM = 1;

    SELECT prj_name INTO v_prjname
    FROM prj_details
    WHERE prjid = v_projid AND ROWNUM = 1;

    v_tsal := v_emprow.salary + v_incentive;

    dbms_output.put_line('Employee Number:' || v_emprow.empcode);
    dbms_output.put_line('Employee Name:' || v_emprow.name);
    dbms_output.put_line('Salary:' || v_emprow.salary);
    dbms_output.put_line('Project Name:' || v_prjname);
    dbms_output.put_line('Rating:' || v_rating);
    dbms_output.put_line('Incentive:' || v_incentive);
    dbms_output.put_line('Total Salary:' || v_tsal);

    UPDATE pay_check
    SET other_incentives = v_incentive
    WHERE empcode = v_empcode;
END;
/
