gnuplot -e "set ytics 1; set xtics 1; set grid; set title '$(cat answer)'; plot 'inter_points' w p, 'ext_points' w p, 'points' w l; pause -1"
