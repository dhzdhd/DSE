SET SERVEROUTPUT ON

CREATE OR REPLACE FUNCTION fetch_incentive(
    v_prjid IN work_exp.prjid%TYPE
) RETURN NUMBER AS
    v_incentive NUMBER := 0;
    CURSOR c IS
        SELECT rating
        FROM work_exp
        WHERE prjid = v_prjid;
BEGIN
    FOR i in C LOOP
        IF i.rating = 'A' THEN
            v_incentive := 30000;
        ELSIF i.rating = 'B' THEN
            v_incentive := 20000;
        ELSIF i.rating = 'C' THEN
            v_incentive := 10000;
        END IF;
    END LOOP;
    RETURN v_incentive;
END;
/

DECLARE
    v_prjid work_exp.prjid%TYPE := '&prjid';
    v_incentive NUMBER;
BEGIN
    v_incentive := fetch_incentive(v_prjid);
    dbms_output.put_line(v_incentive);
END;
/