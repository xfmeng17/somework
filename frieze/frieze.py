#!/usr/bin/env python3
# -*- coding: utf8 -*-

matrix = list()
file_name = 'frieze_2.txt'
with open (file_name, 'r') as f:
	for line in f.readlines():
		line = line.strip()
		if not len(line):
			continue
		matrix.append(list(map(int, line.split())))
print(file_name)

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

def vertical_at_axis(pat, shift):
	height = len(pat)
	length = len(pat[0])
	for y_start in range(0, height):
		for x_start in range(0, length):
			# 0001 => |
			if (pat[y_start][x_start] & 1):
				x_symme = ((length - 1) - (2 * shift) - x_start) % length
				x_symme = (x_symme + 1) % length
				y_symme = y_start
				if (not (pat[y_symme][x_symme] & 1)):
					print('|', x_start, y_start, x_symme, y_symme, 'shift=', shift)
					return False

			# 0010 => /
			if (pat[y_start][x_start] & 2):
				x_symme = ((length - 1) - (2 * shift) - x_start) % length
				y_symme = y_start - 1
				if (y_symme < 0):
					print("y_symme < 0")
					return False
				if (not (pat[y_symme][x_symme] & 8)):
					print('/', x_start, y_start, x_symme, y_symme, 'shift=', shift)
					return False

			# 0100 => -
			if (pat[y_start][x_start] & 4):
				x_symme = ((length - 1) - (2 * shift) - x_start) % length
				y_symme = y_start
				if (not (pat[y_symme][x_symme] & 4)):
					print('-', x_start, y_start, x_symme, y_symme, 'shift=', shift)
					return False

			# 1000 => \
			if (pat[y_start][x_start] & 8):
				x_symme = ((length - 1) - (2 * shift) - x_start) % length
				y_symme = y_start + 1
				if (y_symme >= height):
					print("y_symme >= height")
					return False
				if (not (pat[y_symme][x_symme] & 2)):
					print('\\', x_start, y_start, x_symme, y_symme, 'shift=', shift)
					return False

			# 0000 => blank
			if (pat[y_start][x_start] == 0):
				x_symme = ((length - 1) - (2 * shift) - x_start) % length
				y_symme = y_start
				if (pat[y_symme][x_symme] & 4):
					print('*', x_start, y_start, x_symme, y_symme, 'shift=', shift)
					return False
	return True

def vertical(pat):
	for shift in range(0, len(pat[0])):
		if (vertical_at_axis(pat, shift)):
			return True
	return False

period = get_period(matrix)
pattern = list()
for row in matrix:
	pattern.append(row[0: period - 1])
for row in pattern:
	print(row)
print(vertical(pattern))

pattern = list()
for row in matrix:
	pattern.append(row[0: period])
for row in pattern:
	print(row)
print(vertical(pattern))

pattern = list()
for row in matrix:
	pattern.append(row[0: period + 1])
for row in pattern:
	print(row)
print(vertical(pattern))
