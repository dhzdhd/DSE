import pyspark

sc = pyspark.SparkContext()
rdd = sc.textFile("./data.csv")

records = rdd.collect()[:5]

print(records)
records.saveAsTextFile("./out")
