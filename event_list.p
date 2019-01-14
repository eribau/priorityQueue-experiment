set terminal png
set output "event_list.png"

set title "Event: list"

set key right center

set xlabel "time(ms)"

set ylabel "iterations"

plot  "event_list.dat" u 2:1 w linespoints title "linked list"
