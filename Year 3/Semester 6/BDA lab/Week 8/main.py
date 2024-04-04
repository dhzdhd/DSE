from pyspark.sql import SparkSession

spark = SparkSession \
    .builder \
    .appName("Week 8") \
    .getOrCreate()

df = spark.read.load("data.csv", format="csv", inferSchema="true", header="true")
repl_df = df.na.replace({"Checking": "Cash"})
repl_df.show()
