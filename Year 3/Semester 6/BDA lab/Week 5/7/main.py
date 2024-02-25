import pyspark

sc = pyspark.SparkContext()

# Parallelized
rddPar = sc.parallelize(
    [
        [1, 2, 3, 4, 5],
        [1, 2, 3, 4, 5],
        [1, 2, 3, 4, 5],
        [1, 2, 3, 4, 5],
        [1, 2, 3, 4, 5],
    ]
)

# Derived
rddDer = rddPar.map(lambda xs: sum(xs))

# External
rddExt = sc.textFile("./data.csv")

print(f"Parallelized: {rddPar.collect()}")
print(f"Derived: {rddDer.collect()}")
print(f"External: {rddExt.collect()}")

rddPar.saveAsTextFile("./parout")
rddDer.saveAsTextFile("./derout")
rddExt.saveAsTextFile("./extout")
