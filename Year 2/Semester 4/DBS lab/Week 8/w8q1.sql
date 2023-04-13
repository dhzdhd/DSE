SET SERVEROUTPUT ON

CREATE OR REPLACE PROCEDURE update_bal(
    v_accno IN account.account_number%TYPE,
    v_wamount IN NUMBER
) AS
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

DECLARE
    v_accno account.account_number%TYPE := &accno;
    v_wamount NUMBER := &wamount;
BEGIN
    update_bal(v_accno, v_wamount);
END;
/
