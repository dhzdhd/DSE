SET SERVEROUTPUT ON
DECLARE
    CURSOR c IS
        SELECT name, salary, regular_increment, performance_incentive, advance_tax, other_incentives
        FROM emp NATURAL JOIN pay_check
        WHERE TO_CHAR(pay_date, 'MM-YY') = '01-21';

    v_emprow emp%ROWTYPE;
    v_paycheck pay_check%ROWTYPE;
    v_ibs NUMBER;
    v_da NUMBER;
    v_pf NUMBER;
    v_mgs NUMBER;
BEGIN
    FOR i IN c LOOP
        v_ibs := i.salary + i.regular_increment;
        v_da := 0.5 * v_ibs;
        v_pf := 0.12 * v_ibs;
        v_mgs := i.salary + i.regular_increment + v_da + v_pf;

        dbms_output.put_line('Name: ' || i.name);
        dbms_output.put_line('Basic_Salary: ' || i.salary);
        dbms_output.put_line('Regular Increment: ' || i.regular_increment);
        dbms_output.put_line('Increased basic salary: ' || v_ibs);
        dbms_output.put_line('Performance incentive: ' || i.performance_incentive);
        dbms_output.put_line('DA: ' || v_da);
        dbms_output.put_line('PF: ' || v_pf);
        dbms_output.put_line('Other incentive: ' || i.other_incentives);
        dbms_output.put_line('Advance tax paid: ' || i.advance_tax);
        dbms_output.put_line('Monthly Gross Salary: ' || v_mgs);
        dbms_output.put_line('Monthly Take home salary: ' || (v_mgs - v_pf - i.advance_tax));
        dbms_output.put_line('...');
    END LOOP;

END;
/
