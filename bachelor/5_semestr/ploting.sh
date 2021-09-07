gnuplot -e "set grid; set title '$(cat answer)'; plot 'inter_points' w p, 'ext_points' w p, 'ext_points' w l; pause -1"
