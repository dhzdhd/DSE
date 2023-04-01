SET SERVEROUTPUT ON
DECLARE
    CURSOR c IS
        SELECT name, salary, regular_increment, performance_incentive, advance_tax, other_incentives 
        FROM emp NATURAL JOIN pay_check
        WHERE TO_CHAR(pay_date, 'MM-YY') = '01-21'; 

    v_accno account.account_number%TYPE := &accno;
    v_wamount NUMBER := &wamount;
    v_balance account.balance%TYPE;
    v_final NUMBER;
BEGIN
    SELECT balance INTO v_balance
    FROM account
    WHERE account_number = v_accno AND ROWNUM = 1;

    v_final := v_balance - v_wamount;

    IF v_final > 1000 THEN
        UPDATE account
        SET balance = v_final
        WHERE account_number = v_accno;

        dbms_output.put_line('Current balance: ' || v_balance);
        dbms_output.put_line('Withdrawal of ' || v_wamount || ' is successful.' );
        dbms_output.put_line('Updated current balance: ' || v_final);

    ELSE
        dbms_output.put_line('Current balance: ' || v_balance);
        dbms_output.put_line('Insufficient fund to withdraw, try with lesser withdrawal amount.');
    END IF;
END;
/