SET SERVEROUTPUT ON
DECLARE
    word VARCHAR2(20) := '&word';
    res VARCHAR2(20) := '';
BEGIN
    FOR i IN REVERSE 1..LENGTH(word) LOOP
        res := res || SUBSTR(word, i, 1);
    END LOOP;
    
    IF res = word THEN
        dbms_output.put_line('Palindrome');
    ELSE
        dbms_output.put_line('Not palindrome');
    END IF;
END;
/
