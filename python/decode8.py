import chardet

a = b"\345\245\245\347\211\271\346\233\274\347\216\251\345\205\267"
fencoding = chardet.detect(a)  
print(fencoding)
a = a.decode('utf-8')
print(a)
