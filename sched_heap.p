set terminal png
set output "sched_heap.png"

set title "Schedule: heap"

set key right center

set xlabel "time(ms)"

set ylabel "iterations"

plot  "sched_heap_1000.dat" u 2:1 w linespoints title "heap"