#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jan 21 14:48:52 2021

@author: honepa
"""

import numpy as np
import random

simple_arr = np.array(['2', '3', '5', '7', '11', '13', '17', '19', '23', '29', '31', '37', '41', '43', '47', '53', '59', '61', '67', '71', '73', '79', '83', '89', '97'])
negativ_arr = ['-1', '-2', '-3', '-4', '-5', '-6', '-7', '-8', '-9', '-10', '-11', '-12', '-13', '-14', '-15', '-16', '-17', '-18', '-19', '-20', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13', '14', '15', '16', '17', '18', '19', '20']
random.seed()

def simple(num):
    arr_sim = set()
    i = 0
    while(i < num):
        arr_sim.add(simple_arr[i])
        i = i + 1
    return arr_sim

def natural(num):
    arr = set()
    i = 22
    while(i < num + 22):
        arr.add(negativ_arr[i])
        i = i + 1
    return arr

def positive(num):
    arr = set()
    i = 21
    num = num + 21
    while(i < num):
        arr.add(negativ_arr[i])
        i = i + 1
    return arr

def negativ(num):
    arr = set()
    for i in range(num):
        arr.add(negativ_arr[i])
    return arr

def even(num):
    arr_int = np.zeros(num)
    for i in range(num):
        arr_int[i] = random.randint(0, 1000) * 2
    arr = set(arr_int)
    return arr

def uneven(num):
    arr_int = np.zeros(num)
    for i in range(num):
        iint = random.randint(0, 1000)
        if (iint % 2 != 0) and ( iint != 0):
            arr_int[i] = iint
        else:
            i = i - 1
    arr = set(arr_int)
    return arr

def make_arr():
    arr = set()
    print("Выберите действие:")
    print("1. Ввести в ручную.")
    print("2. Простые числа.")
    print("3. Натуральные числа")
    print("4. Положительные числа")
    print("5. Отрицательные числа")
    print("6. Четные числа")
    print("7. Нечетные числа")
    chose = input("Введите номер выбранного варианта")
    num = int(input("Введите кол-во элементов (<20)"))
    if num > 20:
        num = 19
    if chose == '1':
        arr = set(input().split())
    elif chose == '2':
        #arr = np.zeros(num)
        arr = simple(num)
        #arr = set(arr)
    elif chose =='3':
        arr = natural(num)
    elif chose == '4':
        arr = positive(num)
    elif chose == '5':
        arr = negativ(num)
    elif chose == '6':
        arr = even(num)
    elif chose == '7':
        arr = uneven(num)
    print(arr)
    return arr

def chose_neg(a_arr, b_arr, c_arr):
    print("Над каким множеством выполнить операцию отрицание?(a, b, c)")
    chose = input()
    neg = set(negativ_arr)
    if chose == 'a':
        a_arr = neg - a_arr
        print(a_arr)
    elif chose == 'b':
        for i in range(len(b_arr)):
            num = random.randint(0, 33)
            if b_arr[i] == negativ_arr[num]:
                num = num - 1
                b_arr[i] = negativ_arr[num]
            else:
                b_arr[i] = negativ_arr[num]
        print(b_arr)
    else:
        for i in range(len(c_arr)):
            num = random.randint(0, 33)
            if c_arr[i] == negativ_arr[num]:
                num = num - 1
                c_arr[i] = negativ_arr[num]
            else:
                c_arr[i] = negativ_arr[num]
        print(c_arr)
    print("Выполнить операция отрицания ещё?")
    if input("1 - да, 2 - нет") == '1':
        chose_neg(a_arr, b_arr, c_arr)
    else:
        return 1

if __name__== "__main__":
    print("Множество а:")
    a = make_arr()
    print("Множество b:")
    b = make_arr()
    print("Множество c:")
    c = make_arr()
    
    print("Выполнить операцию отрицания над множествами?")
    if input("1 - да, 2 - нет") == '1':
        i = 1
        while i:
            print("Над каким множеством выполнить операцию отрицание?(a, b, c)")
            chose = input()
            neg = set(negativ_arr)
            if chose == 'a':
                a = neg - a
                print(a)
            elif chose == 'b':
                b = neg - b
                print(b)
            elif chose == 'c':
                c = neg - c
                print(c)
            print("Выполнить операция отрицания ещё?")
            if input("1 - да, 2 - нет") == '2':
                i = 0
    print(eval(input()))