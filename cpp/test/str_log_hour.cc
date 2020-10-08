#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>

static const int RcNano = 1000 * 1000 * 1000;
static const int RcMilli = 1000;

int main() {
	int64_t iTime = (int64_t)time(NULL) * RcNano;
	time_t t = iTime / RcNano;
	int64_t tMicro = iTime % RcNano / RcMilli;
	struct tm tm;
	localtime_r(&t, &tm);
	char sTmp[32];
	snprintf(sTmp, 31, "%04d%02d%02d%02d", tm.tm_year + 1900, tm.tm_mon + 1,
			tm.tm_mday, tm.tm_hour);
	std::string strLogHour(sTmp);
	std::cout << "strLogHour=" << strLogHour << std::endl;
}
