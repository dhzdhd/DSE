import pyspark

sc = pyspark.SparkContext()
rdd = sc.textFile("./data.csv")

rddSort = rdd.map(lambda row: row.split(",")).sortByKey()
rddGroup = rdd.map(lambda row: row.split(",")).groupByKey()
rddCount = rdd.map(lambda row: row.split(",")).countByKey()

print(f"Sort: {rddSort.collect()}")
print(f"Group: {rddGroup.collect()}")
print(f"Count: {rddCount.collect()}")

# rddSort.saveAsTextFile("./sortout")
# rddGroup.saveAsTextFile("./groupout")
# rddCount.saveAsTextFile("./countout")
