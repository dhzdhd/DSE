import pyspark

sc = pyspark.SparkContext()

rdd = sc.textFile("input.txt")

counts = (
    rdd.flatMap(lambda line: line.split(" "))
    .map(lambda word: (word, 1))
    .reduceByKey(lambda x, y: x + y)
)

print(counts.collect())
counts.saveAsTextFile("./out")
