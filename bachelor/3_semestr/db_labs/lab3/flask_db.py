#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Nov  9 16:50:18 2020

@author: honepa
"""

from flask import Flask, render_template, request
import sqlite3

app = Flask(__name__)


@app.route('/')
def index():
    return render_template('index.html')

@app.route('/request1', methods=['POST'])
def request1():
    conn = sqlite3.connect('lab3.db')
    c = conn.cursor()
    c.execute("SELECT ID, Name, Phone_num, Zp FROM workes;")
    result = c.fetchall()
    print(result)
    conn.commit()
    conn.close()
    return render_template('index.html', out = result)

@app.route('/request2', methods=['POST'])
def request2():
    conn = sqlite3.connect('lab3.db')
    c = conn.cursor()
    c.execute("SELECT ID, Name, Adress FROM workes ORDER BY ADRESS;")
    result = c.fetchall()
    print(result)
    conn.commit()
    conn.close()
    return render_template('index.html', out = result)

@app.route('/request3', methods=['POST'])
def request3():
    conn = sqlite3.connect('lab3.db')
    c = conn.cursor()
    c.execute("SELECT ID, Name, TimeWork FROM workes WHERE TimeWork > 4;")
    result = c.fetchall()
    print(result)
    conn.commit()
    conn.close()
    return render_template('index.html', out = result)

if __name__ == '__main__':
    app.run()