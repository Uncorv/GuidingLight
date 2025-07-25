#!/bin/bash

check_ret() {
    if [ $1 -ne 0 ]; then
        echo ""
        echo "!!! FAIL: $2"
        echo "********************************************************************************"
        echo ""
        exit $1
    else
        echo ""
        echo "*** SUCCESS: $2"
        echo "********************************************************************************"
        echo ""
    fi
}

if [ ! -d tmp ]; then
	mkdir -p tmp
fi

cd "source"

cmake -H. -B../tmp/release -DCMAKE_BUILD_TYPE=Release
check_ret $? "configure"

cmake --build ../tmp/release --config Release
check_ret $? "build"

# cd ./tmp/release && ctest --output-on-failure