#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Apr 29 11:50:37 2021

@author: honepa
"""
from arr import x
from graphviz import Source
import numpy as np

counter = 0
for i in range(len(x)):
    for j in range(counter):
        x[i][j] = 0
    counter = counter + 1

temp= "digraph G {"
incent_str = str()
count = int()
for i in range(len(x)):
    for j in range(len(x)):
        if(x[i][j]):
            temp += " " + str(i + 1) + " -- " + str(j + 1) + " "
            incent_str += "|"+ str(i + 1) + "-" + str(j + 1) + "|"
            count += 1

temp += "}"

incent_arr = np.zeros((len(x), count), dtype=int)

counter = 0

for i in range(len(x)):
    for j in range(len(x)):
        if(x[i][j]):
            incent_arr[i][counter] = 1
            incent_arr[j][counter] = 1
            counter += 1
print("Матрица инцидентности:")
print(" " + incent_str)

for i in range(len(x)):
    print(i + 1, end='')
    for j in range(count):
        print("  " + str(incent_arr[i][j]) + "  ", end='')
    print('\n')
s = Source(temp, filename="graph.gv", format="png")
s.view()
