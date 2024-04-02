val rdd =
    sc.textFile("input.txt")
    .flatMap(_.split(" "))
    .map(x => (x, 1))
    .reduceByKey((x, st) => x + st)

println(rdd.collect())
