class Frieze():
	def __init__(self, filepath):
		self.pattern = list()

		# read pattern from file
		with open (filepath, 'r') as file:
			for line in file.readlines():
				line = line.strip()
				if not len(line):
					continue
				self.pattern.append(list(map(int, line.split())))

		# 1. basic conditions: check height, length and number
		self.height = len(self.pattern)
		if self.height < 3 or self.height > 17:
			raise FriezeError('Incorrect input.')
		self.length = len(self.pattern[0])
		if self.length < 5 or self.length > 50:
			raise FriezeError('Incorrect input.')
		for row in self.pattern:
			if len(row) != self.length:
				raise FriezeError('Incorrect input.')
			for num in row:
				if num < 0 or num > 15:
					raise FriezeError('Incorrect input.')
		# 2. further contions:
		# check first line must be 4 or 12 
		# and last line must in [4, 8) except the last column
		for j in range(0, self.length - 1):
			if self.pattern[0][j] != 4 and self.pattern[0][j] != 12:
				raise FriezeError('Input does not represent a frieze.')
			if self.pattern[self.height - 1][j] < 4 or self.pattern[self.height - 1][j] > 8:
				raise FriezeError('Input does not represent a frieze.')
		# check last column must be 0 or 1
		for i in range(0, self.height):
			if self.pattern[i][self.length - 1] != 0 and self.pattern[i][self.length - 1] != 1:
				raise FriezeError('Input does not represent a frieze.')
		# check cross
		for i in range(0, self.height - 1):
			for j in range(0, self.length):
				if (self.pattern[i][j] & 8 and self.pattern[i + 1][j] & 2):
					raise FriezeError('Input does not represent a frieze.')
		# check other further conditions..

# define class FriezeError
class FriezeError(Exception):
	def __init__(self, errmsg):
		self.errmsg = errmsg

# from frieze import *
# frieze = Frieze('frieze_1.txt')