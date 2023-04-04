SET SERVEROUTPUT ON
DECLARE
    v_emprow emp%ROWTYPE;
    v_paycheck pay_check%ROWTYPE;
    v_ibs NUMBER;
    v_da NUMBER;
    v_pf NUMBER;
    v_mgs NUMBER;
BEGIN
    SELECT * INTO v_emprow
    FROM emp
    WHERE empcode = 100 AND ROWNUM = 1;

    SELECT * INTO v_paycheck
    FROM pay_check
    WHERE empcode = 100 AND ROWNUM = 1 AND TO_CHAR(pay_date, 'MM-YY') = '01-21';

    v_ibs := v_emprow.salary + v_paycheck.regular_increment;
    v_da := 0.5 * v_ibs;
    v_pf := 0.12 * v_ibs;
    v_mgs := v_emprow.salary + v_paycheck.regular_increment + v_da + v_pf;

    dbms_output.put_line('Name: ' || v_emprow.name);
    dbms_output.put_line('Basic_Salary: ' || v_emprow.salary);
    dbms_output.put_line('Regular Increment: ' || v_paycheck.regular_increment);
    dbms_output.put_line('Increased basic salary: ' || v_ibs);
    dbms_output.put_line('Performance incentive: ' || v_paycheck.performance_incentive);
    dbms_output.put_line('DA: ' || v_da);
    dbms_output.put_line('PF: ' || v_pf);
    dbms_output.put_line('Other incentive: ' || v_paycheck.other_incentives);
    dbms_output.put_line('Advance tax paid: ' || v_paycheck.advance_tax);
    dbms_output.put_line('Monthly Gross Salary: ' || v_mgs);
    dbms_output.put_line('Monthly Take home salary: ' || (v_mgs - v_pf - v_paycheck.advance_tax));

END;
/
