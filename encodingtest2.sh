function encodetest {
    # Create a test file with random data, removing null bytes
    dd if=/dev/urandom bs="$bs" count=1 2>/dev/null | tr -d '\000' > encodingtest.data
    ./ahencode $space < encodingtest.data | ./ahdecode $space | diff -Z - encodingtest.data
}

if [ $# -gt 0 -a "$1" = "-s" ]; then
    shift
    space="-s"
fi

bs="1k"
if [ $# -eq 0 ]; then
    while :; do
        encodetest
        echo -n .
    done
else
    if [ $# -gt 1 ]; then
        bs="$2"
    fi
    if [ $1 -gt 0 ]; then
        for i in `seq "$1"`; do
            encodetest
            echo -n .
        done
    fi
fi
echo
