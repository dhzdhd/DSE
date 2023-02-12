CREATE TABLE emp (
    empcode NUMBER(3) CONSTRAINT PK_EMPNO PRIMARY KEY,
    name VARCHAR2(10),
    qualification VARCHAR2(7) CONSTRAINT VALID_QUALIF CHECK(qualification IN ('BTECH', 'MTECH', 'MSC', 'MCA', 'PHD')),
    phone NUMBER(10),
    email VARCHAR2(20) CONSTRAINT EMAIL_DOMAIN CHECK(email LIKE '%@digisol.com'),
    designation VARCHAR2(20) CONSTRAINT VALID_DESIGNATION CHECK(designation IN ('DEVELOPER', 'PROJECT LEADER', 'PROJECT MANAGER', 'TECHNICAL HEAD', 'PROJECT DIRECTOR', 'CEO')),
    salary NUMBER(7) CONSTRAINT SALARY_RANGE CHECK(salary BETWEEN 97000 AND 300000)
);

CREATE TABLE skill (
    skillid CHAR(3) CONSTRAINT UNQ_SKILLID UNIQUE,
    skillname VARCHAR(20) CONSTRAINT UNQ_SKILNAME UNIQUE
);

CREATE TABLE emp_skill (
    empno NUMBER(3) CONSTRAINT FK_EMPNO REFERENCES emp(empcode),
    skillid CHAR(3) CONSTRAINT FK_SKILLID REFERENCES skill(skillid) ON DELETE CASCADE,
    skillexperience NUMBER(3) CONSTRAINT SKILLEXP_POSITIVE CHECK(skillexperience > 0)
);

CREATE TABLE client (
    clientid CHAR(3) CONSTRAINT PK_CLIENTID PRIMARY KEY CONSTRAINT STRTSWITH_C CHECK(clientid LIKE 'C%'),
    name VARCHAR2(10),
    phone CHAR(14) CONSTRAINT PHONE_FORMAT CHECK(phone LIKE '+91-__________' OR phone LIKE '+81-__________' OR phone LIKE '+31-__________' OR phone LIKE '+48-__________' OR phone LIKE '+44-__________')
);

CREATE TABLE prj_details (
    prjid CHAR(3) CONSTRAINT PK_PRJID PRIMARY KEY CHECK(prjid LIKE 'P%'),
    prj_name VARCHAR2(10),
    start_date DATE,
    end_date DATE,
    actual_end_date DATE,
    lead_by_empcode NUMBER(3) CONSTRAINT FK_LEAD_EMP REFERENCES emp(empcode),
    budget_allocated NUMBER(10, 1),
    actual_budget NUMBER(10, 1),
    CONSTRAINT END_DATE_GARTER_START_DATE CHECK(end_date > start_date),
    CONSTRAINT ACTUAL_DATE_LARGER CHECK(actual_end_date >= end_date)
);

CREATE TABLE work_exp (
    empcode NUMBER(3) CONSTRAINT FK_EMPCODE REFERENCES emp,
    prjid CHAR(3) CONSTRAINT FK_PRJID REFERENCES prj_details,
    work_experience NUMBER(3) CONSTRAINT WORK_EXP_POSITIVE CHECK(work_experience >= 0) NOT NULL,
    clientid CHAR(3) CONSTRAINT FK_CLIENTID REFERENCES client(clientid) ON DELETE SET NULL,
    rating CHAR(1) CONSTRAINT ABC_RATING_ONLY CHECK(rating IN('A', 'B', 'C')),
    CONSTRAINT PK_WORK_EXP PRIMARY KEY (empcode, prjid)
);

CREATE TABLE family_dependents (
    empno NUMBER(3) CONSTRAINT FK_EMP REFERENCES emp(empcode),
    dep_name VARCHAR(20),
    relationship VARCHAR(16),
    age NUMBER(3) CONSTRAINT VALID_AGE CHECK(age BETWEEN 1 AND 130),
    CONSTRAINT PK_FAMILY PRIMARY KEY (empno, dep_name)
);

CREATE TABLE medical_policy (
    empno NUMBER(3) CONSTRAINT FK_MEDICAL_EMP REFERENCES emp(empcode),
    policyno VARCHAR2(6) CONSTRAINT STARTS_WITH_MED CHECK(policyno LIKE 'MED%'),
    premium NUMBER(5) CONSTRAINT PREMIUM_POSITIVE CHECK(premium > 0),
    policydate DATE,
    CONSTRAINT PK_MED_POLICY PRIMARY KEY (empno, policyno)
);

CREATE TABLE pay_check (
    empcode NUMBER(3) CONSTRAINT FK_PAY_EMP REFERENCES emp(empcode),
    pay_date DATE,
    regular_increment NUMBER(4) CONSTRAINT VALID_REGU_INCENTIVE CHECK(regular_increment IN (2000, 3000, 5000, 7000, 9000)),
    performance_incentive NUMBER(5),
    da NUMBER(7),
    pf NUMBER(6),
    other_incentives NUMBER(4),
    advance_tax NUMBER(5),
    CONSTRAINT PK_PAY_CHECK PRIMARY KEY (empcode, pay_date)
);







