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
LOAD DATA LOCAL INPATH '/workdir/data.csv' INTO TABLE extern;
LOAD DATA LOCAL INPATH '/workdir/data.csv' INTO TABLE intern;

-- 5
set hive.exec.dynamic.partition.mode=nonstrict;

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

INSERT OVERWRITE TABLE extpart PARTITION(gender) SELECT employee_id, birthday, first_name, family_name, work_day, gender FROM extern;
-- LOAD DATA LOCAL INPATH 'data.csv' INTO TABLE extpart PARTITION(gender="M");
-- LOAD DATA LOCAL INPATH 'data.csv' INTO TABLE extpart PARTITION(gender="F");

-- 6
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

-- 11      1961-02-14      Robert  Taylor  M       Thursday
-- 5       1965-03-28      David   Brown   M       Friday
-- 15      1968-09-17      Christopher     Martin  M       Monday
-- 1       1970-01-01      John    Doe     M       Monday
-- 17      1972-07-10      Andrew  White   M       Wednesday
-- 13      1977-01-31      Joseph  Moore   M       Saturday
-- 7       1978-11-18      Daniel  Miller  M       Sunday
-- 19      1980-11-22      Joshua  Garcia  M       Friday
-- 3       1982-09-22      Michael Johnson M       Wednesday
-- 9       1986-06-29      Matthew Wilson  M       Tuesday

SELECT * FROM extpart WHERE gender='F' ORDER BY birthday LIMIT 10;

-- 8       1973-04-02      Olivia  Davis   F       Monday
-- 20      1974-08-05      Sophia  Martinez        F       Saturday
-- 2       1975-05-15      Jane    Smith   F       Tuesday
-- 16      1983-12-25      Emma    Thompson        F       Tuesday
-- 12      1985-10-20      Mia     Thomas  F       Friday
-- 4       1988-12-10      Emily   Williams        F       Thursday
-- 14      1990-06-08      Ava     Jackson F       Sunday
-- 6       1991-07-05      Sophia  Jones   F       Saturday
-- 10      1994-08-12      Isabella        Anderson        F       Wednesday
-- 18      1996-03-18      Abigail Harris  F       Thursday

-- 8
SELECT * FROM extern ORDER BY birthday LIMIT 10;

-- 11      1961-02-14      Robert  Taylor  M       Thursday
-- 5       1965-03-28      David   Brown   M       Friday
-- 15      1968-09-17      Christopher     Martin  M       Monday
-- 1       1970-01-01      John    Doe     M       Monday
-- 17      1972-07-10      Andrew  White   M       Wednesday
-- 8       1973-04-02      Olivia  Davis   F       Monday
-- 20      1974-08-05      Sophia  Martinez        F       Saturday
-- 2       1975-05-15      Jane    Smith   F       Tuesday
-- 13      1977-01-31      Joseph  Moore   M       Saturday
-- 7       1978-11-18      Daniel  Miller  M       Sunday

-- 9
ALTER TABLE intern ADD COLUMNS (dept STRING);
DROP TABLE intern;
