#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on 2.09.2021

@author: honepa
"""

def chek_line(x, y, x1, x2, y1, y2):
    if y == (x * (y2 - y1) - x1 * (y2 + y1) + y1 * (x2 + x1))/(x2 - x1):
        return 1
    else:
        return 0

def line(y, x1, y1, x2, y2):
    return (y * (x2 - x1) - y1 * (x2 + x1) + x1 * (y2 + y1))/(y2 - y1)

def ceil(num):
    if type(num) == type(6.5):
        return int(num) + 1
    elif type(num) == type(6):
        return num
    else:
        return 0

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

def chek_not_y():    
    for i in range(len(points)):
        if i != len(points) - 1:
            if not points[i][0] == points[i + 1][0]:
                if not points[i][1] == points[i + 1][1]:
                    if not (points[i + 1][1] - points[i][1])/(points[i + 1][0] - points[i][0]) == 1:
                        if not (points[i + 1][1] - points[i][1])/(points[i + 1][0] - points[i][0]) == -1:
                            if points[i][1] < points[i + 1][1]:
                                for y in range(points[i][1] + 1, points[i + 1][1]):
                                    find = list()
                                    find.append(line(y, points[i][0], points[i][1], points[i+1][0], points[i+1][1]))
                                    find.append(y)
                                    ext_points.append(find)
                            elif points[i][1] > points[i+1][1]:
                                for y in range(points[i+1][1] + 1, points[i][1]):
                                    find = list()
                                    find.append(line(y, points[i][0], points[i][1], points[i+1][0], points[i+1][1]))
                                    find.append(y)
                                    ext_points.append(find)
        elif i == len(points):
            if not points[i][0] == points[0][0]:
                if not points[i][1] == points[0][1]:
                    if not (points[0][1] - points[i][1])/(points[0][0] - points[i][0]) == 1:
                        if not (points[0][1] - points[i][1])/(points[0][0] - points[i][0]) == -1:
                            if points[i][1] < points[0][1]:
                                for y in range(points[i][1] + 1, points[0][1]):
                                    find = list()
                                    find.append(line(y, points[i][0], points[i][1], points[0][0], points[0][1]))
                                    find.append(y)
                                    ext_points.append(find)
                            elif points[i][1] > points[0][1]:
                                for y in range(points[0][1] + 1, points[i][1]):
                                    find = list()
                                    find.append(line(y, points[i][0], points[i][1], points[0][0], points[0][1]))
                                    find.append(y)
                                    ext_points.append(find)
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

def count_ceil(x0, x1):
    counter = 0 
    if type(x0) == type(x1) == type(1): 
        counter = x1 - x0 - 1 
        return counter 
    elif type(x0) == type(1) and type(x1) == type(6.5): 
        counter = ceil(x1) -x0 - 1 
        return counter 
    elif type(x0) == type(6.5) and type(x1) == type(1): 
        counter = x1 - ceil(x0) 
        return counter 
    elif type(x0) == type(6.5) and type(x1) == type(6.5): 
        counter = ceil(x1) - ceil(x0) 
        return counter 
    else:
        return 0 

def count_inter_points():
    counter = 0
    return counter

if __name__ == '__main__':
    """
    points = [
            [6, 1],
            [1, 3],
            [5, 5],
            [3, 8],
            [6, 10],
            [9, 8],
            [7, 5],
            [11, 3]]
    """
    """
    points = [
            [6, 1],
            [1, 2],
            [1, 5],
            [3, 7],
            [7, 6],
            [6, 4],
            [9, 4]]
    """
    
    points = [
            [6, 1],
            [1, 6],
            [6, 11],
            [11, 6]]
    
    """
    points = [
            [1, 1],
            [1, 2],
            [2, 4],
            [3, 2],
            [5, 2],
            [6, 4],
            [7, 2],
            [8, 2],
            [9, 4],
            [10, 2],
            [10, 1]]
    """
    ext_points = list()
    
    counter_ext = 0
    for i in range(len(points)):
        if i != len(points) - 1:
            counter_ext += count_ext_points(points[i][0], points[i][1], points[i + 1][0], points[i + 1][1]) - 2
        elif i == len(points) - 1:
            counter_ext += count_ext_points(points[i][0], points[i][1], points[0][0], points[0][1]) - 2
    counter_ext += len(points)
    print(counter_ext)
    
    #print(all_points)
    ext_points = [x for x in ext_points if x not in points]
    for i in range(len(points)):
        ext_points.append(points[i])
    print(ext_points)
    print(len(ext_points))
    
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
    
    chek_not_y()
    print(ext_points)
    
    counter_inter = 0
    
    for y in range(maxy, miny, -1):
        now_x = list()
        for i in range(len(ext_points)):
            if ext_points[i][1] == y:
                now_x.append(ext_points[i][0])
        now_x.sort()
        #print(now_x)
        if len(now_x) % 2 == 0:
            for i in range(0, len(now_x), 2):
                counter_inter += count_ceil(now_x[i], now_x[i + 1])
        elif len(now_x) % 2 != 0:
            for i in range(len(now_x) - 1):
                for j in range(ceil(now_x[i]), ceil(now_x[i + 1]) - 1):
                    counter_inter += 1
        print(str(now_x) + " " + str(counter_inter))
        del now_x                        
    print(counter_inter)
    print(counter_inter + (counter_ext * 0.5) - 1)