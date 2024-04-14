data = LOAD '/data.csv' USING PigStorage('|') AS (id: chararray, from: chararray, to: bag{()});
gen = FOREACH data GENERATE id, from, FLATTEN(to);
STORE gen INTO '/out';
