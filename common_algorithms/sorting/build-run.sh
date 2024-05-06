make clean 

perl -pi -e 's/LEN 1000/LEN 10000/g' ~/Development/github/computer_science/common_algorithms/sorting/merge_sort.c
perl -pi -e 's/LEN 1000/LEN 10000/g' ~/Development/github/computer_science/common_algorithms/sorting/insertion_sort.c

make 

time ./insertion
time ./merge 

make clean 
