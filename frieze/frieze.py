class Frieze ():
	def __init__ (self, filepath):
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

		# calculate period
		self.period = 0
		for period in range(1, self.length):
			if self.checkPeriod(period):
				self.period = period
				break
				# print(self.period)
		if self.period == 0:
			raise FriezeError('Input does not represent a frieze.')

	def checkPeriod (self, period):
		for row in self.pattern:
			for j in range(0, period):
				if row[j] != row[j + period]:
					return False
		return True

	def isVertiRef (self):
		axisStart = self.period // 2
		axisEnd = axisStart + self.period
		for axis in range(axisStart, axisEnd + 1):
			if self.isVertiRefByLine(axis) or self.isVertiRefByColumn(axis):
				return True
		return False

	def isVertiRefByLine (self, axis):
		pat = self.pattern
		for left in range(axis - (self.period // 2), axis + 1):
			right = axis * 2 - left
			for i in range(0, self.height):
				# 0001 => |
				if ((pat[i][left] & 1) and not (pat[i][right] & 1)):
					return False
				# 0010 => /
				if ((pat[i][left] & 2) and not (pat[i - 1][right - 1] & 8)):
					return False
				# 0100 => -
				if ((pat[i][left] & 4) and not (pat[i][right - 1] & 4)):
					return False
				# 1000 => \
				if ((pat[i][left] & 8) and not (pat[i + 1][right - 1] & 2)):
					return False
				# 0000 => blank
				if ((pat[i][left] == 0) and (pat[i][right] & 4)):
					return False
		return True

	def isVertiRefByColumn (self, axis):
		pat = self.pattern
		for left in range(axis - (self.period // 2), axis + 1):
			right = axis * 2 - left
			for i in range(0, self.height):
				# 0001 => |
				if ((pat[i][left] & 1) and not (pat[i][right + 1] & 1)):
					return False
				# 0010 => /
				if ((pat[i][left] & 2) and not (pat[i - 1][right] & 8)):
					return False
				# 0100 => -
				if ((pat[i][left] & 4) and not (pat[i][right] & 4)):
					return False
				# 1000 => \
				if ((pat[i][left] & 8) and not (pat[i + 1][right] & 2)):
					return False
				# 0000 => blank
				if ((pat[i][left] == 0) and (pat[i][right] & 4)):
					return False
		return True

	def isHorizRef (self):
		pat = self.pattern
		for upper in range(0, self.height):
			lower = self.height - 1 - upper
			for j in range(0, self.length):
				# 0001 => |
				if ((pat[upper][j] & 1) and (not (pat[lower + 1][j]))):
					return False
				# 0010 => /
				if ((pat[upper][j] & 2) and (not (pat[lower][j] & 8))):
					return False
				# 0100 => -
				if ((pat[upper][j] & 4) and (not (pat[lower][j] & 4))):
					return False
				# 1000 => \
				if ((pat[upper][j] & 8) and (not (pat[lower][j] & 2))):
					return False
				# 0000 => blank
				if ((pat[upper][j] == 0) and (pat[lower][j] & 14)):
					return False
		return True

	def isGlide (self):
		pat = self.pattern
		g = self.period // 2
		for upper in range(0, self.height):
			lower = self.height - 1 - upper
			for j in range(0, self.period + 1):
				# 0001 => |
				if ((pat[upper][j] & 1) and (not (pat[lower + 1][j + g]))):
					return False
				# 0010 => /
				if ((pat[upper][j] & 2) and (not (pat[lower][j + g] & 8))):
					return False
				# 0100 => -
				if ((pat[upper][j] & 4) and (not (pat[lower][j + g] & 4))):
					return False
				# 1000 => \
				if ((pat[upper][j] & 8) and (not (pat[lower][j + g] & 2))):
					return False
				# 0000 => blank
				if ((pat[upper][j] == 0) and (pat[lower][j + g] & 14)):
					return False
		return True

	def isRotation (self):
		pat = self.pattern
		for i in range(0, self.height):
			for j in range(0, self.period):
				m = self.height - 1 - i
				n = self.period - j
				if ((pat[i][j] & 1) and (not (pat[m + 1][n] & 1))):
					return False
				if ((pat[i][j] & 2) and (not (pat[m + 1][n - 1] & 2))):
					return False
				if ((pat[i][j] & 4) and (not (pat[m][n - 1] & 4))):
					return False
				if ((pat[i][j] & 8) and (not (pat[m - 1][n - 1] & 8))):
					return False
		return True

	def analyse (self):
		analyseMsg = (
			' only.',
			'\n        and vertical reflection only.',
			'\n        and horizontal reflection only.',
			'\n        and glided horizontal reflection only.',
			'\n        and rotation only.',
			',\n        glided horizontal and vertical reflections, and rotation only.',
			',\n        horizontal and vertical reflections, and rotation only.'
		)
		message = 'Pattern is a frieze of period ' + str(self.period) + ' that '
		message += 'is invariant under translation'
		if (self.isVertiRef()):
			if (self.isHorizRef()):
				print(message + analyseMsg[6])
			elif (self.isGlide()):
				print(message + analyseMsg[5])
			else:
				print(message + analyseMsg[1])
		else:
			if (self.isHorizRef()):
				print(message + analyseMsg[2])
			elif (self.isGlide()):
				print(message + analyseMsg[3])
			elif (self.isRotation()):
				print(message + analyseMsg[4])
			else:
				print(message + analyseMsg[0])

# define class FriezeError
class FriezeError (Exception):
	def __init__(self, errmsg):
		self.errmsg = errmsg

for i in range(1, 8):
	filename = 'frieze_' + str(i) + '.txt'
	frieze = Frieze(filename)
	# print('file = ', filename)
	# print('height =', frieze.height)
	# print('length =', frieze.length)
	# print('isVertRef = ', frieze.isVertiRef())
	# print('isHoriRef = ', frieze.isHorizRef())
	# print('isGlide =', frieze.isGlide())
	# print('isRotation =', frieze.isRotation())
	frieze.analyse()
