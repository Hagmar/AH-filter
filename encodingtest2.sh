# Requirements: ahencode and ahdecode in the working directory
# Run the script to begin testing. If the only output is periods,
# your programs are working together

# ./ahencodingtest.sh [-s] [N [BS]]
# If -s is provided, it will be passed to the encoder and decoder as well
# If N is provided, only N tests will be run
# If BS is provided, the test will generate and test with files
# with BS number of bytes (default 512)

function encodetest {
    # Create a test file with random data, removing null bytes
    dd if=/dev/urandom bs="$bs" count=1 2>/dev/null | tr -d '\000' > encodingtest.data
    # Add a newline to test data
    echo >> encodingtest.data
    # Encode, decode and compare to input data
    ./ahencode $space < encodingtest.data | ./ahdecode $space | diff - encodingtest.data
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
