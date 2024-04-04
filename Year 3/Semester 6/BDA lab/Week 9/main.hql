-- 1
CREATE DATABASE Employee;

-- 2
SHOW DATABASES;

-- 3
USE Employee;

CREATE EXTERNAL TABLE extern (
	employee_id INT,
	birthday DATE,
	first_name STRING,
	family_name STRING,
	gender STRING,
	work_day STRING
) 
	ROW FORMAT DELIMITED
	FIELDS TERMINATED BY ','
	STORED AS TEXTFILE
	LOCATION '/workdir/extern';

CREATE TABLE intern (
	employee_id INT,
	birthday DATE,
	first_name STRING,
	family_name STRING,
	gender STRING,
	work_day STRING
) 
	ROW FORMAT DELIMITED
	FIELDS TERMINATED BY ','
	STORED AS TEXTFILE
	LOCATION '/workdir/intern';

-- 4
LOAD DATA LOCAL INPATH '/workdir/data.csv' INTO extern;
LOAD DATA LOCAL INPATH '/workdir/data.csv' INTO intern;

-- 5
CREATE EXTERNAL TABLE extpart (
	employee_id INT,
	birthday DATE,
	first_name STRING,
	family_name STRING,
	work_day STRING
) 
	PARTITIONED BY (gender STRING)
	ROW FORMAT DELIMITED
	FIELDS TERMINATED BY ','
	STORED AS TEXTFILE
	LOCATION '/workdir/extpart';

INSERT OVERWRITE TABLE extpart PARTITION(gender) SELECT * FROM extern;

-- 6
set hive.exec.dynamic.partition.mode=nonstrict

CREATE EXTERNAL TABLE extbuc (
	employee_id INT,
	birthday DATE,
	first_name STRING,
	family_name STRING,
	gender STRING,
	work_day STRING
)
	CLUSTERED BY (gender) INTO 3 BUCKETS
	ROW FORMAT DELIMITED
	FIELDS TERMINATED BY ','
	STORED AS TEXTFILE
	LOCATION '/workdir/extbuc';

INSERT OVERWRITE TABLE extbuc SELECT * FROM extern;

-- 7
SELECT * FROM extpart WHERE gender='M' ORDER BY birthday LIMIT 10;
SELECT * FROM extpart WHERE gender='F' ORDER BY birthday LIMIT 10;

-- 8
SELECT * FROM extern WHERE gender='M' ORDER BY birthday LIMIT 10;

-- 9
ALTER TABLE intern ADD COLUMNS (dept STRING);
DROP TABLE intern;

