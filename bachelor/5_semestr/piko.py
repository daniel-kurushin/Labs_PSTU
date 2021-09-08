#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on 2.09.2021

@author: honepa
"""
import os
from points import points

def chek_line(x, y, x1, x2, y1, y2):
    return y == (x * (y2 - y1) - x1 * (y2 + y1) + y1 * (x2 + x1))/(x2 - x1):

def count_pipe_line(x1, y1, x2, y2):
    counter = 0
    if y1 < y2:
        for y in range(y1, y2 + 1):
            find = list()
            find.append(x1)
            find.append(y)
            ext_points.append(find)
            del find
            counter += 1
        return counter
    elif y1 > y2:
        for y in range(y2, y1 + 1):
            find = list()
            find.append(x1)
            find.append(y)
            ext_points.append(find)
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
            ext_points.append(find)
            del find
            counter += 1
        return counter
    elif x1 > x2:
        for x in range(x2, x1 + 1):
            find = list()
            find.append(x)
            find.append(y1)
            ext_points.append(find)
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
                    ext_points.append(find)
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
                    ext_points.append(find)
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
                    ext_points.append(find)
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
                    ext_points.append(find)
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

def point_in_field(point):
    x_point = point[0]
    y_point = point[1]
    in_field = False
    for i in range(len(points)):
        if i != len(points) - 1:
            x_first = points[i][0]
            y_first = points[i][1]
            x_second = points[i + 1][0]
            y_second = points[i + 1][1]
            if (y_first < y_point and y_point <= y_second) or (y_second < y_point and y_point <= y_first):
                if (x_first + (y_point - y_first) / (y_second - y_first) * (x_second - x_first)) < x_point:
                    in_field = not in_field
        else:
            x_first = points[i][0]
            y_first = points[i][1]
            x_second = points[0][0]
            y_second = points[0][1]
            if (y_first < y_point and y_point <= y_second) or (y_second < y_point and y_point <= y_first):
                if (x_first + (y_point - y_first) / (y_second - y_first) * (x_second - x_first)) < x_point:
                    in_field = not in_field
    return in_field

def count_inter_points():
    counter_inter = 0
    min_x, max_x = min([x[0] for x in points ]), max([x[0] for x in points ])
    min_y, max_y = min([x[1] for x in points ]), max([x[1] for x in points ])
    for x in range(min_x, max_x + 1):
        for y in range(min_y, max_y + 1):
            point = list()
            point.append(x); point.append(y)
            if point not in ext_points and point_in_field(point):
                inter_points.append(point)
                counter_inter += 1
            del point
    return counter_inter
            
    

if __name__ == '__main__':
    inter_points = list()
    ext_points = list()        
    counter_ext = 0
    for i in range(len(points)):
        if i != len(points) - 1:
            counter_ext += count_ext_points(points[i][0], points[i][1], points[i + 1][0], points[i + 1][1]) - 2
        elif i == len(points) - 1:
            counter_ext += count_ext_points(points[i][0], points[i][1], points[0][0], points[0][1]) - 2
    ext_points = [x for x in ext_points if x not in points]
    for i in range(len(points)):
        ext_points.append(points[i])
    clear_points = list()
    for i in ext_points:
        if i not in clear_points:
            clear_points.append(i)
    ext_points = clear_points
    G = len(ext_points)
    B = count_inter_points()
    S = 0
    S = B + G / 2 - 1 
    answer = "S = " + str(B) + str(" + ") + str(G) + " / 2 - 1 = " + str(S)
    print(answer)
    
    ans = open("answer", 'w')
    ans.write(answer)
    ans.close()
    
    file_ext_points = open("ext_points", 'w')
    file_points = open("points", 'w')
    file_inter_points = open("inter_points", 'w')
    
    for i in range(len(ext_points)):
        poin = str(ext_points[i][0]) + " " + str(ext_points[i][1])
        file_ext_points.write(poin + '\n')
    file_ext_points.close()
    for i in range(len(points)):
        poin = str(points[i][0]) + " " + str(points[i][1])
        file_points.write(poin + '\n')
    poin = str(points[0][0]) + " " + str(points[0][1])
    file_points.write(poin + '\n')
    file_points.close()
    for i in range(len(inter_points)):
        poin = str(inter_points[i][0]) + " " + str(inter_points[i][1])
        file_inter_points.write(poin + '\n')
    file_inter_points.close()
    os.system("./ploting.sh")
