import webbrowser
import codecs
import time

for id in range(0, 8):
	url = "http://usering.webdev.com/usering/Downloader/fetch?type=day&id=" + str(id)
	time.sleep(1)
	webbrowser.open(url)
