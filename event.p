set terminal png
set output "event.png"

set title "Event: heap and list"

set key right center

set xlabel "time(ms)"

set ylabel "iterations"

plot  "event_list.dat" u 2:1 w linespoints title "linked list", \
      "event_heap_1000.dat" u 2:1 w linespoints title "heap"