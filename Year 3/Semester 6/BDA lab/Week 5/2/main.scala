val rdd =
    sc.textFile("data.csv")
    .map(_.split(","))
    .map(x => List(x(1), x(2).toInt * 2, x(3)))

println(rdd.collect())
