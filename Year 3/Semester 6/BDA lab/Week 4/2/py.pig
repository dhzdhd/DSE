REGISTER 'py_udfs.py' USING jython AS py_udfs;

-- Define the Python UDF
DEFINE count_word_occurrences(text:chararray) RETURNS bag{tuple(word:chararray, count:int)} {
  lines = text.split('\n');
  word_counts = {};
  for line in lines:
    for word in line.lower().split():
      if word in word_counts:
        word_counts[word] += 1
      else:
        word_counts[word] = 1
  return [(word, count) for word, count in word_counts.items()];
}

-- Load your data
data = LOAD './input.txt' USING PigStorage('\n');

-- Split the text into lines and call the UDF
words = FOREACH data GENERATE FLATTEN(count_word_occurrences($0)) AS (word, count);

-- Group and count the words
grouped = GROUP words BY word;
word_counts = FOREACH grouped GENERATE group, SUM(words.count);

-- Dump the results
DUMP word_counts;
