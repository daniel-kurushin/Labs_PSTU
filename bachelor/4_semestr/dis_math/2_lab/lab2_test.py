#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat May 22 13:08:47 2021

@author: honepa
 [0, 3, _, _, _, 2, _], # A
        [3, 0, 3, _, _, _, 6], # B
        [_, 3, 0, 3, 2, _, 1], # C
        [_, _, 3, 0, 5, _, _], # D
        [_, _, 2, 5, 0, 4, 3], # E
        [2, _, _, _, 4, 0, 3], # F
        [_, 6, 1, _, 3, 3, 0], 2 
"""
#import os
from graphviz import Source

class Graph:
    def __init__(self, vertex):
        self.V = vertex
        self.graph = []
 
    def add(self, u, v, w):
        self.graph.append([u, v, w])
 
 
    def search(self, parent, i):
        if parent[i] == i:
            return i
        return self.search(parent, parent[i])
 
    def apply_union(self, parent, rank, x, y):
        xroot = self.search(parent, x)
        yroot = self.search(parent, y)
        if rank[xroot] < rank[yroot]:
            parent[xroot] = yroot
        elif rank[xroot] > rank[yroot]:
            parent[yroot] = xroot
        else:
            parent[yroot] = xroot
            rank[xroot] += 1
 
    
    def draw_graph(self):
        temp = "graph G {"
        for i in range(self.V):
            temp += " %s -- %s [label=\"%s\"] " % (self.graph[i][0], self.graph[i][1], self.graph[i][2])
        temp += "}"
        s = Source(temp, filename="graph.gv", format="png")
        s.view()
    
    def kraskal(self):
        result = []
        e, i = 0, 0
        self.graph = sorted(self.graph, key=lambda item: item[2])
        parent = []
        rank = []
        for node in range(self.V):
            parent.append(node)
            rank.append(0)
        while e < self.V - 1:
            u, v, w = self.graph[i]
            i = i + 1
            x = self.search(parent, u)
            y = self.search(parent, v)
            if x != y:
                e = e + 1
                result.append([u, v, w])
                self.apply_union(parent, rank, x, y)
        for u, v, weight in result:
            print("Ребро:",u, v,end =" ")
            print("-",weight)
 
 
g = Graph(5)
g.add(0, 1, 4)
g.add(0, 3, 7)
g.add(1, 2, 6)
g.add(1, 3, 9)
g.add(2, 4, 3)
g.add(2, 3, 8)
g.kraskal()
g.draw_graph()