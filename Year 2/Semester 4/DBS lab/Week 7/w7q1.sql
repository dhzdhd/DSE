SET SERVEROUTPUT ON
DECLARE
    num NUMBER := &num;
    res NUMBER := 0;
BEGIN
    WHILE num > 0 LOOP
        res := res * 10 + REMAINDER(num, 10);
        num := FLOOR(num / 10);
    END LOOP;
    dbms_output.put_line(res);
END;
/
