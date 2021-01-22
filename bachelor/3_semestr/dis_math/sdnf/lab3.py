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
    vec = np.array([int(vec) for vec in input("input vec").split()])
    #vec = np.array([1, 1, 0, 1, 1, 0, 0, 1])
    if len(vec) == 8:    
        for i in range(len(vec)):
            if vec[i]:
                minterms += [xyz[i]]
            else:
                dontcares += [xyz[i]]
        r = pd.DataFrame(minterms)
        for i in range(len(minterms)):
            for j in range(3):
                if r.iloc[i, j]:
                    r.iloc[i, j] = 0
                else:
                    r.iloc[i, j] = 1
        sdnf = (r.apply(lambda r: '({}&{}&{})'.format('~'*r[0] + 'x', '~'*r[1] + 'y', '~'*r[2] + 'z'), axis=1).str.cat(sep = ' | '))
        print("СДНФ:")
        print(sdnf)
        print("Минимизированная ДНФ")
        print(SOPform([x, y, z], minterms))
    
  