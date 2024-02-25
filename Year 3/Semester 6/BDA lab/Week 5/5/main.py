import pyspark

sc = pyspark.SparkContext()
rdd = sc.textFile("./data.csv")

records = (
    rdd.map(lambda x: x.split(","))
    .groupBy(lambda xs: xs[1])
    .map(lambda t: (t[0], t[1].data))
)

print(records.collect())
records.saveAsTextFile("./out")
