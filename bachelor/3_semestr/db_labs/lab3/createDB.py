#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Nov  9 15:04:25 2020

@author: honepa
"""

import sqlite3

conn = sqlite3.connect('lab3.db')

c = conn.cursor()

c.execute('''CREATE TABLE workes (ID INTEGER PRIMARY KEY,
                                  Name TEXT,
                                  Phone_num INTEGER,
                                  Zp INTEGER,
                                  Adress TEXT,
                                  TimeWork INTEGER)''')
c.execute('''INSERT INTO workes VALUES ('1', 'Lane', '5566', '54', 'fs', '5')''')
c.execute('''INSERT INTO workes VALUES ('2', 'Jane', '5577', '55', 'asf', '3')''')
c.execute('''INSERT INTO workes VALUES ('3', 'Kane', '7766', '56', 'aas', '2')''')
c.execute('''INSERT INTO workes VALUES ('4', 'Pane', '8866', '57', 'avsd', '9')''')
c.execute('''INSERT INTO workes VALUES ('5', 'Wane', '5588', '58', 'ger', '10')''')

conn.commit()
conn.close()