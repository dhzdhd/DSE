CREATE OR REPLACE PACKAGE dbs AS
    FUNCTION fetch_name(v_empno IN emp.empcode%TYPE) RETURN VARCHAR2 AS
        v_name emp.name%TYPE;
        BEGIN
            SELECT ee.name
            INTO v_name
            FROM emp e JOIN emp ee WHERE e.empcode = ee.empcode
            WHERE e.reports_to = ee.empcode AND e.empcode = v_empno AND ROWNUM = 1;

            RETURN v_name;
        END;
    END fetch_name;

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
    END display_names;

    PROCEDURE display_project(v_date IN prj_details.strat_date%TYPE) AS
        v_prjname prj_details.prj_name%TYPE;
        BEGIN
            SELECT prj_name
            INTO v_prjname
            FROM prj_details
            WHERE strat_date = v_date AND ROWNUM = 1;

            dbms_output.put_line("Name: " || v_prjname);
        END;
    END display_project;

    PROCEDURE display_details() AS
        BEGIN
        END;
    END display_details;

    FUNCTION number_emp() RETURN NUMBER AS
        BEGIN
        END;
    END number_emp;
END dbs;
