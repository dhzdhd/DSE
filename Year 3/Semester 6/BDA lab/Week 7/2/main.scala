import org.apache.spark.sql.functions._
import org.apache.spark.sql.types._

val df = spark.read
  .format("csv")
  .option("header", "true")
  .option("inferSchema", "true")
  .option("timestampFormat", "yyyy-MM-dd HH:mm:ss")
  .load("data.csv")

val finalDf = df.withColumn("timestamp", col("timestamp").cast(TimestampType))
finalDf
  .groupBy($"user_id")
  .agg(max($"timestamp").alias("max"), min($"timestamp").alias("min"))
  .select($"user_id", ($"max" - $"min").alias("interval"))
  .orderBy($"user_id")
  .show()
