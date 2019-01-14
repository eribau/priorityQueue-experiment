set terminal png
set output "sched_list.png"

set title "Schedule: linked list"

set key right center

set xlabel "time(ms)"

set ylabel "iterations"

plot  "sched_list.dat" u 2:1 w linespoints title "linked list"
