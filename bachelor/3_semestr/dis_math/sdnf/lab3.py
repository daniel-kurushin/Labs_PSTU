#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jan 10 12:55:36 2021

@author: honepa
"""

from sympy.logic import SOPform                                         
import numpy as np
from sympy import symbols
import pandas as pd

x, y, z = symbols('x y z')
minterms  = []
dontcares = []
xyz = [[0, 0, 0],
       [0, 0, 1],
       [0, 1, 0],
       [0, 1, 1],
       [1, 0, 0],
       [1, 0, 1],
       [1, 1, 0],
       [1, 1, 1]]
    
if __name__== "__main__":
    vec = np.array([int(vec) for vec in input("input vec").split()]) #ввод вектора исходной функции
    #vec = np.array([1, 1, 0, 1, 1, 0, 0, 1])
    if len(vec) == 8:    #если количество элементов исходного вектора не равно 8 то программа не будет выполняться
        for i in range(len(vec)):
            if vec[i]:
                minterms += [xyz[i]] #заполнеие списка значениемями таблицы истинности при которых значения вктора равно 1
            else:
                dontcares += [xyz[i]] #заполнеие списка значениемями таблицы истинности при которых значения вктора равно 0
        r = pd.DataFrame(minterms) # инициализация таблицы для вывода сднф
        for i in range(len(minterms)): #инверсия элементов таблицы
            for j in range(3):
                if r.iloc[i, j]:
                    r.iloc[i, j] = 0
                else:
                    r.iloc[i, j] = 1
        #выполнение сднф
        sdnf = (r.apply(lambda r: '({}&{}&{})'.format('~'*r[0] + 'x', '~'*r[1] + 'y', '~'*r[2] + 'z'), axis=1).str.cat(sep = ' | '))
        print("СДНФ:")
        print(sdnf) #вывод сднф пользователю
        print("Минимизированная ДНФ")
        print(SOPform([x, y, z], minterms)) #вывод минимизированной сднф
    
  