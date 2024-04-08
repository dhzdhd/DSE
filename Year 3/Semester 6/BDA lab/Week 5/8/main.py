import pyspark

sc = pyspark.SparkContext()
rdd = sc.textFile("./data.csv")


def getPair(xs: list[str]):
    key = xs[2]
    val = xs[:1] + xs[3:]
    return (key, val)


rddSort = (
    rdd.map(lambda row: row.split(",")).map(lambda xs: (xs[0], xs[1:])).sortByKey()
)
rddGroup = (
    rdd.map(lambda row: row.split(","))
    .map(getPair)
    .groupByKey()
    .map(lambda t: (t[0], t[1].data))
)
rddCount = rdd.map(lambda row: row.split(",")).map(getPair).countByKey()

print(f"Sort: {rddSort.collect()}")
print(f"Group: {rddGroup.collect()}")
print(f"Count: {rddCount.items()}")

rddSort.saveAsTextFile("./sortout")
rddGroup.saveAsTextFile("./groupout")
