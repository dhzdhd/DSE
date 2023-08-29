# 1
cut -d',' -f3 data.csv | tail -10 | sort # only col
tail -10 data.csv | sort -t"," -k3       # all

# 2
tail -10 data.csv | sort -t"," -k4

# 3
tail -10 data.csv | sort -t"," -k10

# 4
tail -10 data.csv | sort -t"," -k4 -k3

# 5
cut -d"," -f1,2,5,7,10 data.csv

# 6
cut -d',' -f2 data.csv | tr a-z A-Z

# 7
tail -10 data.csv | sort -t"," -k5

# 8
tail -10 data.csv | sort -t"," -k6 -M -o Personnel_data_month2022.dat

# 9

# 10
