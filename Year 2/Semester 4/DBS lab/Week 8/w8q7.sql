CREATE OR REPLACE PACKAGE dbs AS
    FUNCTION fetch_name(v_empno IN emp.empcode%TYPE) RETURN VARCHAR2;
    PROCEDURE display_names(v_prjid IN prj_details.prjid%TYPE);
    PROCEDURE display_project(v_date IN prj_details.strat_date%TYPE);
    PROCEDURE display_details(v_id IN emp_skill.skillid%TYPE);
    FUNCTION number_emp(v_desg IN emp.designation%TYPE) RETURN NUMBER;
END dbs;
/

CREATE OR REPLACE PACKAGE BODY dbs AS
    FUNCTION fetch_name(v_empno IN emp.empcode%TYPE) RETURN VARCHAR2 AS
        v_name emp.name%TYPE;
        BEGIN
            SELECT ee.name
            INTO v_name
            FROM emp e JOIN emp ee ON e.empcode = ee.empcode
            WHERE e.reports_to = ee.empcode AND e.empcode = v_empno AND ROWNUM = 1;

            RETURN v_name;
        END;
    END;

    PROCEDURE display_names(v_prjid IN prj_details.prjid%TYPE) AS
        CURSOR c(v_prjid prj_details.prjid%TYPE) AS
            SELECT e.name
            FROM work_exp w JOIN emp e ON w.empcode = e.empcode
            JOIN prj_details p ON p.prjid = w.prjid
            WHERE p.prjid = v_prjid;
        BEGIN
            FOR i IN c(v_prjid) LOOP
                dbms_output.put_line(i);
            END LOOP;
        END;
    END;

    PROCEDURE display_project(v_date IN prj_details.strat_date%TYPE) AS
        v_prjname prj_details.prj_name%TYPE;
        BEGIN
            SELECT prj_name
            INTO v_prjname
            FROM prj_details
            WHERE strat_date = v_date AND ROWNUM = 1;

            dbms_output.put_line("Name: " || v_prjname);
        END;
    END;

    PROCEDURE display_details(v_id IN emp_skill.skillid%TYPE) AS
        CURSOR c IS
            SELECT DISTINCT s.skillid, s.empno, e.name, s.skill_exp
            FROM emp e JOIN emp_skill s ON e.empcode = s.empno
            WHERE s.skillid = v_id;
        BEGIN
            FOR i IN c LOOP
                dbms_output.put_line(i.skillid || ' ' || i.name || ', exp: ' || i.skill_exp);
            END LOOP;
        END;
    END;

    FUNCTION number_emp(v_desg IN emp.designation%TYPE) RETURN NUMBER AS
        v_count NUMBER;
        BEGIN
            SELECT count(empcode), designation
            INTO v_count
            FROM emp
            WHERE designation = v_desg
            GROUP BY designation;

            RETURN v_count;
        END;
    END;
END dbs;
/

SET SERVEROUTPUT ON

DECLARE
    v_empno emp.empcode%TYPE := &empcode;
    v_name emp.name%TYPE;
    v_prjid prj_details.prjid%TYPE := '&prjid';
    v_date prj_details.strat_date%TYPE := '&strtdate';
    v_id emp_skill.skillid%TYPE := '&sid';
    v_desg emp.designation%TYPE := '&desg';
    v_count NUMBER;
BEGIN
    v_name = dbs.fetch_name(v_empno);
    dbms_output.put_line('Name: ' || v_name);

    dbs.display_names(v_prjid);
    dbs.display_project(v_date);
    dbs.display_details(v_id);

    v_count = dbs.number_emp(v_desg);
    dbms_output.put_line('Count: ' || v_count);
END;
/
