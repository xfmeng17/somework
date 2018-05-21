#!/usr/bin/env python3
# -*- coding: utf8 -*-

matrix = list()
with open ('frieze_1.txt', 'r') as f:
	for line in f.readlines():
		line = line.strip()
		if not len(line):
			continue
		matrix.append(line.split())

def check_input(matrix):
	height = len(matrix)
	if height < 2 or height > 16: return False
	length = len(matrix[0])
	if length < 4 or length > 50: return False
	for row in matrix:
		if len(row) != length: return False
		for col in row:
			if int(col) < 0 or int(col) > 15: return False
	return True

# print(check_input(matrix))

for row in matrix:
	str = ''
	for col in row:
		if int(col) & 1 : str += '|'
		elif int(col) & 2 : str += '/'
		elif int(col) & 4 : str += '-'
		elif int(col) & 8 : str += '\\'
		else: str += ' '
	# print(str)

def get_period(matrix):
	length = len(matrix[0]) - 1
	divisor = list(filter(lambda x : length % x == 0, range(1, length + 1)))
	for period in divisor:
		columns = list(filter(lambda x : x % period == 0, range(0, length)))
		if check_column(matrix, columns, period, length): return period
	return length

def check_column(matrix, columns, period, length):
	for x in columns:
		y = (x + period) % length
		for row in matrix:
			for i in range(0, period):
				if row[x + i] != row[y + i]: return False
	return True

print(get_period(matrix))

