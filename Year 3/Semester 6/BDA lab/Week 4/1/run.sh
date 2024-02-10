echo "Locally"
pig -x local ./local.pig

echo
echo "Hadoop"
hadoop fs -put ./input.txt /deep/input.txt
pig -x mapreduce ./mr.pig
hadoop fs -ls /deep/out
hadoop fs -cat /deep/out/part-m-00000
hadoop fs -rm /deep/input.txt
hadoop fs -rm -r /deep/out
hadoop fs -ls /deep
