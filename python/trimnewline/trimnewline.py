with open('input.txt', 'r') as inputFile:
	data = inputFile.read().replace('\n', '')

data = data.rstrip()

with open('output.txt', 'w') as outputFile:
    outputFile.write('%s' % data)
