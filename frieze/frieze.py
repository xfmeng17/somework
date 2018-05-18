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
	ret = list()
	height = len(matrix)
	if height >= 2 and height <= 16:
		length = len(matrix[0])
		for row in matrix:
			row = filter(lambda x: 0 <= int(x) <= 15, row)
			if len(row) != length:
				return False
			else:
				ret.append(row)
	else:
		return False
	return ret

print(check_input(matrix))
