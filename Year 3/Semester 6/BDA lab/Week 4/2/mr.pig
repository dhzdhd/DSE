data = LOAD '/deep/input.txt' USING PigStorage();
words = FOREACH data GENERATE FLATTEN(TOKENIZE($0, ' ')) AS word;
grouped = GROUP words BY word;
counts = FOREACH grouped GENERATE group, COUNT(words);
STORE counts INTO '/deep/out';
