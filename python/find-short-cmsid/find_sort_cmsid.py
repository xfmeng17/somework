f_in = open("log2019081017.log.[193803][9.92.188.138_15000]")
f_out = open("log2019081017.out", "w")

count_all = 0
count_short = 0
while 1:
	line = f_in.readline()
	if not line:
		break
	if line.startswith("cmsid"):
		count_all += 1
		if len(line) < 25:
			f_out.write(line)
			count_short += 1

f_out.write("count_all=" + str(count_all) + ", ")
f_out.write("count_short=" + str(count_short))

