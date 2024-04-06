val df = spark.read
  .format("csv")
  .option("header", "true")
  .option("inferSchema", "true")
  .load("data.csv")

df.printSchema()
df.take(5)

df.groupBy("user_id", "action").count().show()

val order = df.groupBy("action").count().orderBy(desc("count"))
