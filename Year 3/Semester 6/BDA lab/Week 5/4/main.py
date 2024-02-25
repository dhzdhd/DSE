import pyspark

sc = pyspark.SparkContext()
rdd = sc.textFile("./input.txt")

records = rdd.flatMap(lambda x: x.split())

print(records.collect())
records.saveAsTextFile("./out")
