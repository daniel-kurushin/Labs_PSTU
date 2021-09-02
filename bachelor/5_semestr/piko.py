#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on 2.09.2021

@author: honepa
"""
from collections import OrderedDict

def chek_line(x, y, x1, x2, y1, y2):
    if y == (x * (y2 - y1) - x1 * (y2 + y1) + y1 * (x2 + x1))/(x2 - x1):
        return 1
    else:
        return 0

def count_pipe_line(x1, y1, x2, y2):
    counter = 0
    if y1 < y2:
        for y in range(y1, y2 + 1):
            find = list()
            find.append(x1)
            find.append(y)
            all_points.append(find)
            del find
            counter += 1
        return counter
    elif y1 > y2:
        for y in range(y2, y1 + 1):
            find = list()
            find.append(x1)
            find.append(y)
            all_points.append(find)
            del find
            counter += 1
        return counter
    else:
        return counter

def count_horizon_line(x1, y1, x2, y2):
    counter = 0
    if x1 < x2:
        for x in range(x1, x2 + 1):
            find = list()
            find.append(x)
            find.append(y1)
            all_points.append(find)
            del find
            counter += 1
        return counter
    elif x1 > x2:
        for y in range(x2, x1 + 1):
            find = list()
            find.append(x)
            find.append(y1)
            all_points.append(find)
            del find
            counter += 1
        return counter
    else:
        return counter

def count_pozitiveK_line(x1, y1, x2, y2):
    if x1 < x2:
        counter = 0
        for x in range(x1, x2 + 1):
            for y in range(y1, y2 + 1):
                if chek_line(x, y, x1, x2, y1, y2):
                    find = list()
                    find.append(x)
                    find.append(y)
                    all_points.append(find)
                    del find
                    counter += 1
        return counter
    elif x1 > x2:
        counter = 0
        for x in range(x2, x1 + 1):
            for y in range(y2, y1 + 1):
                if chek_line(x, y, x1, x2, y1, y2):
                    find = list()
                    find.append(x)
                    find.append(y)
                    all_points.append(find)
                    del find
                    counter += 1
        return counter
    else:
        return 0

def count_negativeK_line(x1, y1, x2, y2):
    if x1 > x2 and y1 < y2:
        counter = 0
        for x in range(x2, x1 + 1):
            for y in range(y1, y2 + 1):
                if chek_line(x, y, x1, x2, y1, y2):
                    find = list()
                    find.append(x)
                    find.append(y)
                    all_points.append(find)
                    del find
                    counter += 1                    
        return counter
    elif x1 < x2 and y1 > y2:
        counter = 0
        for x in range(x1, x2 + 1):
            for y in range(y2, y1 + 1):
                if chek_line(x, y, x1, x2, y1, y2):
                    find = list()
                    find.append(x)
                    find.append(y)
                    all_points.append(find)
                    del find
                    counter += 1
        return counter
    else:
        return 0

def count_ext_points(x1, y1, x2, y2):
    if(x1 == x2):
        return count_pipe_line(x1, y1, x2, y2)
    elif y1 == y2:
        return count_horizon_line(x1, y1, x2, y2)
    else:
        k = (y2 - y1) / (x2 - x1)
        if k > 0:
            return count_pozitiveK_line(x1, y1, x2, y2)
        elif k < 0:
            return count_negativeK_line(x1, y1, x2, y2)
        else:
            return 0

def count_inter_points():
    counter = 0
    return counter

if __name__ == '__main__':
    points = [
            [6, 1],
            [1, 6],
            [6, 11],
            [11, 6]]
    all_points = list()
    
    counter_ext = 0
    for i in range(len(points)):
        if i != len(points) - 1:
            counter_ext += count_ext_points(points[i][0], points[i][1], points[i + 1][0], points[i + 1][1]) - 2
        elif i == len(points) - 1:
            counter_ext += count_ext_points(points[i][0], points[i][1], points[0][0], points[0][1]) - 2
    counter_ext += len(points)
    print(counter_ext)
    
    #print(all_points)
    all_points = [x for x in all_points if x not in points]
    for i in range(len(points)):
        all_points.append(points[i])
    print(all_points)
    print(len(all_points))
    
    maxy = 0
    maxx = 0
    minx = points[0][0]
    miny = points[0][1]
    for i in range(len(points)):
        if minx > points[i][0]:
            minx = points[i][0]
        if miny > points[i][1]:
            miny = points[i][1]
        if maxy < points[i][1]:
            maxy = points[i][1]
        if maxx < points[i][0]:
            maxx = points[i][0]
    print("minx " + str(minx))
    print("miny " + str(miny))
    print("maxx " + str(maxx))
    print("maxy " + str(maxy))