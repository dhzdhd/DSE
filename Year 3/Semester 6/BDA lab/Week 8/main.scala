val df = spark.read
  .format("csv")
  .option("inferSchema", "true")
  .option("header", "true")
  .load("data.csv")

val replDf = df.na.replace("Card_type", Map("Checking" -> "Cash"))
replDf.show()
