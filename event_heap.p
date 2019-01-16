set terminal png
set output "event_heap.png"

set title "Event: heap"

set key right center

set ylabel "time(ms)"

set xlabel "iterations"

plot  "event_heap_1000.dat" u 2:1 w linespoints title "heap"
