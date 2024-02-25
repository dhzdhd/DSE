import pyspark

sc = pyspark.SparkContext()
rdd = sc.textFile("./data.csv")

records = rdd.map(lambda row: row.split(",")).filter(lambda xs: int(xs[-1]) > 50000)

print(records.collect())
records.saveAsTextFile("./out")
