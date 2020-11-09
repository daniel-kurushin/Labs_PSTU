#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Nov  9 16:03:16 2020

@author: honepa
"""

import sqlite3

conn = sqlite3.connect('lab3.db')

c = conn.cursor()

c.execute("SELECT ID, Name, Phone_num, Zp FROM workes;")
result = c.fetchall()
print(result)

c.execute("SELECT ID, Name, Adress FROM workes ORDER BY ADRESS;")
result = c.fetchall()
print(result)

c.execute("SELECT ID, Name, TimeWork FROM workes WHERE TimeWork > 4;")
result = c.fetchall()
print(result)