for i in $(seq 799 999); do
    mv ./train/cats/cat.$i.jpg ./test/cats/cat.$i.jpg
    mv ./train/dogs/dog.$i.jpg ./test/dogs/dog.$i.jpg
done

for i in $(seq 2299 2499); do
    mv ./validation/cats/cat.$i.jpg ./test/cats/cat.$i.jpg
    mv ./validation/dogs/dog.$i.jpg ./test/dogs/dog.$i.jpg
done
