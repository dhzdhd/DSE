import pyspark

sc = pyspark.SparkContext()
rdd = sc.textFile("./data.csv")

records = rdd.map(lambda row: row.split(",")[1:]).map(
    lambda xs: [xs[0], int(xs[1]) * 2, int(xs[2])]
)

print(records.collect())
records.saveAsTextFile("./out")
