# Write violated records (with only correct records) and own ones

# 3.0
# We change the order of the INSERT's due to recursive relationship in emp

INSERT INTO emp VALUES(106, 'PRSAD', 'PHD', 9887875897, 'prasad@digisol.com', 'CEO', 300000, NULL);
INSERT INTO emp VALUES(110, 'BHASKAR', 'MTECH', 9887875477, 'bhaskar@digisol.com', 'PROJECT DIRECTOR', 200000, 106);
INSERT INTO emp VALUES(105, 'MANISH', 'MCA', 9887876877, 'manish@digisol.com', 'DEVELOPER', 100000, 106);
INSERT INTO emp VALUES(102, 'VIJAY', 'BTECH', 9887875779, 'vijay@digisol.com', 'PROJECT MANAGER', 140000, 110);

# PRIMARY KEY violated
# Change 106 to another value to resolve
INSERT INTO emp VALUES(115, 'RAJ', 'MSC', 9887875877, 'raj@digisol.com', 'PROJECT LEADER', 120000, 110);

# PRIMARY KEY violated
# Change 102 to another value to resolve
INSERT INTO emp VALUES(114, 'RAKESH', 'MTECH', 9807875877, 'rakesh@digisol.com', 'PROJECT LEADER', 120000, 110);

# UNIQUE email violated and valid designation violated
# Rename email and designation
INSERT INTO emp VALUES(108, 'RAKESH', 'MTECH', 9807875827, 'rakesh1@digisol.com', 'DEVELOPER', 100000, 110);

# UNIQUE qualification violated
# Rename quali
INSERT INTO emp VALUES(109, 'VINAY', 'MCA', 9807075877, 'vinay@digisol.com', 'DEVELOPER', 100000, 110);

# PRIMARY KEY violated and valid designation violated
# Change 110 to another value to resolve and rename designation
INSERT INTO emp VALUES(113, 'ATUL', 'MTECH', 9807805877, 'atul@digisol.com', 'TECHNICAL HEAD', 140000, 110);

# UNIQUE email violated and CHECK violated (@digital.com)
# Rename email
INSERT INTO emp VALUES(111, 'RAJ', 'MTECH', 9807875270, 'raj1@digisol.com', 'DEVELOPER', 100000, 110);

INSERT INTO emp VALUES(101, 'RAVI', 'MTECH', 9887875778, 'ravi@digisol.com', 'PROJECT LEADER', 120000, 102);

# PRIMARY KEY violated
# Change 108 to another value to resolve
INSERT INTO emp VALUES(112, 'AJAY', 'BTECH', 9887875737, 'ajay@digisol.com', 'TECHNICAL HEAD', 160000, 102);

INSERT INTO emp VALUES(100, 'RAJESH', 'BTECH', 9887875777, 'rajesh@digisol.com', 'DEVELOPER', 100000, 101);

# Own values
INSERT INTO emp VALUES(116, 'GAGAN', 'BTECH', 9887875701, 'gagan@digisol.com', 'DEVELOPER', 100000, 101);
INSERT INTO emp VALUES(117, 'SANATH', 'BTECH', 9887875700, 'sanath@digisol.com', 'DEVELOPER', 100000, 101);


# 3.1

INSERT INTO skill VALUES('S1', 'Full stack');
INSERT INTO skill VALUES('S2', 'Python');
INSERT INTO skill VALUES('S3', 'Java');
INSERT INTO skill VALUES('S4', 'C++');
INSERT INTO skill VALUES('S6', 'Oracle');
INSERT INTO skill VALUES('S7', 'Android');
INSERT INTO skill VALUES('S8', 'AZURE');
INSERT INTO skill VALUES('S9', 'DOT NET');
INSERT INTO skill VALUES('S10', 'IOS');

# Own values
INSERT INTO skill VALUES('S11', 'Rust');
INSERT INTO skill VALUES('S12', 'Haskell');


# 3.2

INSERT INTO client VALUES('C1', 'ABC', '+48-87489389', 'aaa@abc.com');
INSERT INTO client VALUES('C2', 'LTS', '+91-78389397', 'bbb@lts.com');
INSERT INTO client VALUES('C3', 'RK', '+44-67838934', 'ccc@rk.com');
INSERT INTO client VALUES('C4', 'MMA', '+31-77839093', 'ddd@mma.com');
INSERT INTO client VALUES('C5', 'AKS', '+81-66822903', 'eee@aks.com');

# CHECK phone format failed
# Change phoneno valid phoneno
INSERT INTO client VALUES('C6', 'GKS', '+81-75628982', 'fff@gks.com');

# ??? & asks for values ???
INSERT INTO client VALUES('C7', 'B&B', '+91-64839839', 'ggg@bb.com');

# CHECK phone format failed
# Change phoneno valid phoneno
INSERT INTO client VALUES('C8', 'ABT', '+91-67554667', 'hhh@abt.com');

INSERT INTO client VALUES('C9', 'XYZ', '+81-87489389', 'xyz@ab.com');

# Own values
INSERT INTO client VALUES('C10', 'XYP', '+44-87489389', 'xyp@ab.com');
INSERT INTO client VALUES('C11', 'XYQ', '+91-87489689', 'xyq@ab.com');


# 3.3

INSERT INTO emp_skill VALUES(100, 'S1', 15);
INSERT INTO emp_skill VALUES(100, 'S3', 15);
INSERT INTO emp_skill VALUES(101, 'S1', 6);
INSERT INTO emp_skill VALUES(101, 'S2', 10);
INSERT INTO emp_skill VALUES(102, 'S4', 18);
INSERT INTO emp_skill VALUES(110, 'S1', 14);
INSERT INTO emp_skill VALUES(110, 'S6', 20);
INSERT INTO emp_skill VALUES(106, 'S2', 10);
INSERT INTO emp_skill VALUES(106, 'S6', 12);
INSERT INTO emp_skill VALUES(106, 'S8', 10);
INSERT INTO emp_skill VALUES(108, 'S9', 5);
INSERT INTO emp_skill VALUES(108, 'S6', 18);
INSERT INTO emp_skill VALUES(105, 'S7', 12);
INSERT INTO emp_skill VALUES(105, 'S10', 11);

# COMPOSITE PKEY violated
INSERT INTO emp_skill VALUES(110, 'S2', 7);

# Own values
INSERT INTO emp_skill VALUES(100, 'S2', 15);
INSERT INTO emp_skill VALUES(105, 'S9', 15);


# 3.5

# Convert date
INSERT INTO prj_details VALUES('P1', 'SPYDER', TO_DATE('10-01-2020', 'DD-MM-YYYY'), '11-OCT-2022', '12-OCT-2022', 102, 2000000, 1990000);
INSERT INTO prj_details VALUES('P2', 'APOLLO', TO_DATE('01-01-2019', 'DD-MM-YYYY'), '10-JUL-2021', TO_DATE('30-12-2021', 'DD-MM-YYYY'), 108, 3000000, 3600000);
INSERT INTO prj_details VALUES('P3', 'UNICORN', TO_DATE('03-09-2021', 'DD-MM-YYYY'), '10-OCT-2023', '12-OCT-2023', 106, 7500000, 8000000);
INSERT INTO prj_details VALUES('P4', 'ZEUS', TO_DATE('28-02-2020', 'DD-MM-YYYY'), '09-JUN-2021', TO_DATE('10-01-2022', 'DD-MM-YYYY'), 110, 5500000, 5000000);
INSERT INTO prj_details VALUES('P5', 'JUPITOR', TO_DATE('07-08-2018', 'DD-MM-YYYY'), '04-FEB-2020', '01-NOV-2020', 110, 9000000, 9000000);

# Date format not recognised & end date smaller than start
INSERT INTO prj_details VALUES('P6', 'MARS', TO_DATE('21-02-2020', 'DD-MM-YYYY'), '07-AUG-2020', '08-AUG-2020', 110, 9000000, 9000000);

# Cannot insert NULL into PKEY column
INSERT INTO prj_details VALUES('P7', 'XXX', '07-FEB-2020', '07-AUG-2020', '08-AUG-2020', 110, 9000000, 9000000);

# Own values
INSERT INTO prj_details VALUES('P8', 'ARTEMIS', '07-FEB-2020', '07-NOV-2020', '08-NOV-2020', 111, 9200000, 9000000);
INSERT INTO prj_details VALUES('P9', 'HADES', '07-JAN-2020', '07-DEC-2020', '08-DEC-2020', 112, 8000000, 9000000);


# 3.4

INSERT INTO work_exp VALUES(100, 'P1', 20, 'C1', 'A');
INSERT INTO work_exp VALUES(100, 'P3', 15, 'C3', 'A');
INSERT INTO work_exp VALUES(101, 'P1', 16, 'C1', 'A');
INSERT INTO work_exp VALUES(102, 'P2', 18, 'C2', 'B');
INSERT INTO work_exp VALUES(102, 'P1', 18, 'C1', 'A');
INSERT INTO work_exp VALUES(108, 'P2', 12, 'C2', 'C');
INSERT INTO work_exp VALUES(106, 'P3', 20, 'C3', 'C');
INSERT INTO work_exp VALUES(106, 'P4', 10, 'C4', 'C');
INSERT INTO work_exp VALUES(105, 'P2', 19, 'C2', 'B');
INSERT INTO work_exp VALUES(110, 'P4', 12, 'C4', 'B');
INSERT INTO work_exp VALUES(110, 'P5', 16, 'C8', 'A');

# ABC rating only
INSERT INTO work_exp VALUES(105, 'P5', 5, 'C5', 'C');

INSERT INTO work_exp VALUES(111, 'P5', 5, 'C5', 'C');

# Own values
INSERT INTO work_exp VALUES(100, 'P2', 16, 'C1', 'A');
INSERT INTO work_exp VALUES(100, 'P4', 22, 'C1', 'A');


# 3.6

# Convert date
INSERT INTO medical_policy VALUES(100, 'MED001', 10000, TO_DATE('10-12-2020', 'DD-MM-YYYY'));
INSERT INTO medical_policy VALUES(101, 'MED003', 12000, TO_DATE('15-12-2020', 'DD-MM-YYYY'));
INSERT INTO medical_policy VALUES(100, 'MED001', 10000, TO_DATE('10-01-2021', 'DD-MM-YYYY'));
INSERT INTO medical_policy VALUES(101, 'MED003', 12000, TO_DATE('15-01-2021', 'DD-MM-YYYY'));

# Parent empno not found
INSERT INTO medical_policy VALUES(101, 'MED004', 9000, TO_DATE('21-01-2021', 'DD-MM-YYYY'));

# Own values
INSERT INTO medical_policy VALUES(100, 'MED005', 10000, TO_DATE('30-01-2021', 'DD-MM-YYYY'));
INSERT INTO medical_policy VALUES(101, 'MED005', 11000, TO_DATE('21-02-2021', 'DD-MM-YYYY'));


# 3.7

INSERT INTO family_dependents VALUES(100, 'AJITH', 'SON', 12);
INSERT INTO family_dependents VALUES(100, 'PRITHVI', 'DAGHTER', 9);
INSERT INTO family_dependents VALUES(101, 'AARYA', 'DAGHTER', 17);
INSERT INTO family_dependents VALUES(101, 'AKANKSH', 'SON', 11);
INSERT INTO family_dependents VALUES(101, 'ANITHA', 'SPOUSE', 43);

# Own values
INSERT INTO family_dependents VALUES(101, 'RAVI', 'SON', 2);
INSERT INTO family_dependents VALUES(101, 'RAJ', 'SON', 5);


# 3.8

# Convert date
INSERT INTO pay_check VALUES(100, TO_DATE('01-12-2020', 'DD-MM-YYYY'), 2000, NULL, NULL, NULL, 2500, 5000);
INSERT INTO pay_check VALUES(101, TO_DATE('01-12-2020', 'DD-MM-YYYY'), 3000, NULL, NULL, NULL, 5000, 7000);
INSERT INTO pay_check VALUES(102, TO_DATE('01-12-2020', 'DD-MM-YYYY'), 3000, NULL, NULL, NULL, 3600, 7000);
INSERT INTO pay_check VALUES(100, TO_DATE('01-01-2021', 'DD-MM-YYYY'), 3000, NULL, NULL, NULL, 450, 4000);
INSERT INTO pay_check VALUES(101, TO_DATE('01-01-2021', 'DD-MM-YYYY'), 5000, NULL, NULL, NULL, 2100, 4000);
INSERT INTO pay_check VALUES(102, TO_DATE('01-01-2021', 'DD-MM-YYYY'), 5000, NULL, NULL, NULL, NULL, 9000);

# Parent id not found
INSERT INTO pay_check VALUES(102, TO_DATE('02-01-2021', 'DD-MM-YYYY'), 7000, NULL, NULL, NULL, 900, 3000);

# Own values
INSERT INTO pay_check VALUES(101, TO_DATE('01-09-2021', 'DD-MM-YYYY'), 5000, NULL, NULL, NULL, 2500, 5000);
INSERT INTO pay_check VALUES(100, TO_DATE('01-09-2021', 'DD-MM-YYYY'), 9000, NULL, NULL, NULL, 2300, 5600);


# 3.9

COMMIT;

# Child foreign key record violated
DELETE FROM emp WHERE empcode = 100;


# 3.10

# Invalid email ID
UPDATE emp SET email = 'rajesh@digisol.com' WHERE empcode = 100;


# 3.11

UPDATE work_exp SET prjid = 'P9' where empcode = 111;


# 3.12

COMMIT;
DELETE FROM client WHERE clientid = 'C1';


# 3.13

COMMIT;
DELETE FROM family_dependents WHERE empno = 100;
ROLLBACK;


# 3.14

UPDATE emp SET salary = salary + (salary * 1 / 100) WHERE designation = 'DEVELOPER';


# 3.15

# UNQ violated
UPDATE emp SET empcode = 106 WHERE empcode = 108;


# 3.16

# UNQ violated
UPDATE emp SET empcode = 118 WHERE empcode = 108;