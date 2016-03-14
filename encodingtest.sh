for file in *; do
    ./ahencode $file | ./ahdecode | diff - $file
    ./ahencode -s $file | ./ahdecode -s | diff - $file
done
