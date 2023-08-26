counter=0
for i in ./train/trainA/*; do
    if [ $counter -eq 150 ]; then
        break
    fi

    mv $i ./validation/valA/$(basename "$i")
    counter=`expr $counter + 1`
done

counter=0
for i in ./train/trainB/*; do
    if [ $counter -eq 150 ]; then
        break
    fi

    mv $i ./validation/valB/$(basename "$i")
    counter=`expr $counter + 1`
done
