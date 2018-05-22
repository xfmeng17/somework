#!/usr/bin/env python3
# -*- coding: utf8 -*-

matrix = list()
with open ('frieze_2.txt', 'r') as f:
	for line in f.readlines():
		line = line.strip()
		if not len(line):
			continue
		matrix.append(list(map(int, line.split())))

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

def vertical_at_axis(pat, x_axis):
	height = len(pat)
	length = len(pat[0])
	offset = 1 if length % 2 == 0 else 0

	for y_lf in range(0, height):
		lf_most = (x_axis - (length // 2) + offset) % length
		rt_most = length - 1 - lf_most
		for x_lf in range(0, length):
			x_rt = (x_lf + ((x_axis - x_lf) * 2) + offset) % length
			y_rt = y_lf

			# 0001 => |
			if (pat[y_lf][x_lf] & 1):
				if (not (pat[y_rt][x_rt] & 1)):
					return False
			# 0010 => /
			elif (pat[y_lf][x_lf] & 2):
				x_rt = x_rt - 1
				y_rt = y_rt - 1
				if (x_rt < lf_most or y_rt < 0):
					return False
				if (not (pat[y_rt][x_rt] & 8)):
					return False
			# 0100 => -
			elif (pat[y_lf][x_lf] & 4):
				x_rt = x_rt - 1
				if (x_rt < lf_most):
					return False
				if (not (pat[y_rt][x_rt] & 4)):
					return False
			# 1000 => /
			elif (pat[y_lf][x_lf] & 8):
				x_rt = x_rt + 1
				y_rt = y_rt + 1
				if (x_rt > rt_most or y_rt > height - 1):
					return False
				if (not (pat[y_rt][x_rt] & 2)):
					return False
			# 0000 => blank
			else:
				if pat[y_rt][x_rt]:
					return False

	return True

def vertical(pat):
	for x_axis in range(0, len(pat[0])):
		if (vertical_at_axis(pat, x_axis)):
			return True
	return False

period = get_period(matrix)
pattern = list()
for row in matrix:
	pattern.append(row[0: period])
print(pattern)

print(vertical(pattern))
