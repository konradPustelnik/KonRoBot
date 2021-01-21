#!/bin/bash

BLUE='\033[0;96m'
RED='\033[0;31m'
NC='\033[0m'

run_makefile()
{
    make
}

run_cmake()
{
    cmake -H. -Bbuild \
        && cmake --build build
}

unit_tests_building()
{
    (
        cd tests \
            && cmake -H. -Bbuild \
                && cmake --build build \
                    && ./build/runTests
    )
}

output()
{
    echo -e ""$(date +"%T":"%N")" ${BLUE}[$3]${NC} $1 Started" \
        && $2 \
            && echo -e ""$(date +"%T":"%N")" ${BLUE}[$4]${NC} $1 Completed" \
                || { echo -e ""$(date +"%T":"%N")" ${RED}[$3] $1 Failed${NC}"; exit 1; }
}

output "Makefile" run_makefile "#     " "##    "
output "Cmake" run_cmake "###   " "####  "
output "Unit Tests" unit_tests_building "##### " "######"
