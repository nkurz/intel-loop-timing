for FUNCTION in  slow basic 0_add 1_add 2_add 3_add 4_add 5_add 6_add 7_add 8_add 9_add none
do 
    echo -n "$FUNCTION, "
    perf stat -x ", " -e cycles -r 4 intel-loop $FUNCTION
done