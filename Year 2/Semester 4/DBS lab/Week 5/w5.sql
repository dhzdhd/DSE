# 5.1
SELECT e.name
FROM emp e, emp ee
WHERE e.designation = ee.designation AND ee.empcode = 100;
