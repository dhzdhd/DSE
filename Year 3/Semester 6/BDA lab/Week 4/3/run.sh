wget https://raw.githubusercontent.com/ashaypatil11/hadoop/main/movies.item -O ./data/movies.item
wget https://raw.githubusercontent.com/ashaypatil11/hadoop/main/ratings.data -O ./data/ratings.data

hadoop fs -mkdir /deep/3
hadoop fs -put ./data/movies.item /deep/3/
hadoop fs -put ./data/ratings.data /deep/3/

pig -x mapreduce ./main.pig
hadoop fs -ls /deep/out
hadoop fs -cat /deep/out/part-r-00000

hadoop fs -rm -r /deep/3
hadoop fs -rm -r /deep/out
hadoop fs -ls /deep
