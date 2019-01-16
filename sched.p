set terminal png
set output "sched.png"

set title "Schedule: heap and list"

set key right center

set ylabel "time(ms)"

set xlabel "iterations"

plot  "sched_heap_1000.dat" u 2:1 w linespoints title "heap", \
      "sched_list.dat" u 2:1 w linespoints title "linked list"
