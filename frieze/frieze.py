#!/usr/bin/env python3
# -*- coding: utf8 -*-

matrix = list()
with open ('frieze_7.txt', 'r') as f:
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
	# offset = 1 if length % 2 == 0 else 0

	for y_lf in range(0, height):
		for x_lf in range(0, length):
			x_rt = (x_lf + (x_axis - x_lf) * 2) % length
			y_rt = y_lf
			# 0001 => |
			if (pat[y_lf][x_lf] & 1):
				x_rt_tmp = (x_rt) % length
				if (not (pat[y_rt][x_rt_tmp] & 1)):
					print('|', x_lf, y_lf, x_rt_tmp, y_rt, 'x_axis=', x_axis)
					return False
			# 0010 => /
			if (pat[y_lf][x_lf] & 2):
				x_rt_tmp = (x_rt - 1) % length
				y_rt_tmp = (y_rt - 1)
				if (y_rt_tmp < 0):
					print('/Y', x_lf, y_lf, x_rt_tmp, y_rt_tmp, 'x_axis=', x_axis)
					return False
				if (not (pat[y_rt_tmp][x_rt_tmp] & 8)):
					print('/', x_lf, y_lf, x_rt_tmp, y_rt_tmp, 'x_axis=', x_axis)
					return False
			# 0100 => -
			if (pat[y_lf][x_lf] & 4):
				x_rt_tmp = (x_rt - 1) % length
				if (not (pat[y_rt][x_rt_tmp] & 4)):
					print('-', x_lf, y_lf, x_rt_tmp, y_rt, 'x_axis=', x_axis)
					return False
			# 1000 => \
			if (pat[y_lf][x_lf] & 8):
				x_rt_tmp = (x_rt - 1) % length
				y_rt_tmp = (y_rt + 1)
				if (y_rt_tmp >= height):
					print('\\Y', x_lf, y_lf, x_rt_tmp, y_rt_tmp, 'x_axis=', x_axis)
					return False
				if (not (pat[y_rt_tmp][x_rt_tmp] & 2)):
					print(pat[y_lf][x_lf])
					print('\\', x_lf, y_lf, x_rt_tmp, y_rt_tmp, 'x_axis=', x_axis)
					return False
			# 0000 => blank
			if (pat[y_lf][x_lf] == 0):
				x_rt_tmp = (x_rt) % length
				if (pat[y_rt][x_rt_tmp] & 4):
				# if (not (pat[y_rt][x_rt_tmp] & 5) and (pat[y_rt][x_rt_tmp] != 0)):
					print('*', x_lf, y_lf, x_rt_tmp, y_rt, 'x_axis=', x_axis)
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
for row in pattern:
	print(row)

print(vertical(pattern))
