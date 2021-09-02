#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on 2.09.2021

@author: honepa
"""

x1 = 6
y1 = 1

x2 = 11
y2 = 6

def chek_line(x, y, x1, x2, y1, y2):
    if y == (x * (y2 - y1) - x1 * (y2 + y1) + y1 * (x2 + x1))/(x2 - x1):
        return 1
    else:
        return 0
    
counter = 0

for x in range(x1, x2 + 1):
    for y in range(y1, y2 + 1):
        if chek_line(x, y, x1, x2, y1, y2):
            counter = counter + 1
            print(str(x) + " " + str(y) + " " + str(counter))
print(counter)            