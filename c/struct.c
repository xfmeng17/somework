#include <stlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tagIOStat {
	uint32_t m_uConnection;
	uint32_t m_uDealAcceptQueueCountMinute;
	uint32_t m_uDealAcceptQueueCountLastMinute;
	uint32_t m_uDealAcceptQueueCountSecond;
	uint32_t m_uDealAcceptQueueCountLastSecond;
	int64_t m_iAcceptQueueDelayMinute;
	int64_t m_iAcceptQueueDelayLastMinute;
	int64_t m_iAcceptQueueDelaySecond;
	int64_t m_iAcceptQueueDelayLastSecond;

	uint64_t m_uSendBytesMinute;
	uint64_t m_uSendBytesLastMinute;
	uint64_t m_uSendBytesSecond;
	uint64_t m_uSendBytesLastSecond;
	uint64_t m_uRecvBytesMinute;
	uint64_t m_uRecvBytesLastMinute;
	uint64_t m_uRecvBytesSecond;
	uint64_t m_uRecvBytesLastSecond;
	uint32_t m_uRequestCountMinute;
	uint32_t m_uRequestCountLastMinute;
	uint32_t m_uRequestCountSecond;
	uint32_t m_uRequestCountLastSecond;
	uint32_t m_uResponseCountMinute;
	uint32_t m_uResponseCountLastMinute;
	uint32_t m_uResponseCountSecond;
	uint32_t m_uResponseCountLastSecond;
	uint32_t m_uSendErrorCountMinute;
	uint32_t m_uSendErrorCountLastMinute;
	uint32_t m_uSendErrorCountSecond;
	uint32_t m_uSendErrorCountLastSecond;
	uint32_t m_uRecvErrorCountMinute;
	uint32_t m_uRecvErrorCountLastMinute;
	uint32_t m_uRecvErrorCountSecond;
	uint32_t m_uRecvErrorCountLastSecond;
	uint32_t m_uFastRejectAfterReadCountMinute;
	uint32_t m_uFastRejectAfterReadCountLastMinute;
	uint32_t m_uFastRejectAfterReadCountSecond;
	uint32_t m_uFastRejectAfterReadCountLastSecond;

	uint32_t m_uInQueueErrorCountMinute;
	uint32_t m_uInQueueErrorCountLastMinute;
	uint32_t m_uInQueueErrorCountSecond;
	uint32_t m_uInQueueErrorCountLastSecond;

	uint32_t m_uDealOutQueueCountMinute;
	uint32_t m_uDealOutQueueCountLastMinute;
	uint32_t m_uDealOutQueueCountSecond;
	uint32_t m_uDealOutQueueCountLastSecond;
	int64_t m_iOutQueueDelayMinute;
	int64_t m_iOutQueueDelayLastMinute;
	int64_t m_iOutQueueDelaySecond;
	int64_t m_iOutQueueDelayLastSecond;

	uint32_t m_uOutQueueMissCountMinute;
	uint32_t m_uOutQueueMissCountLastMinute;
	uint32_t m_uOutQueueMissCountSecond;
	uint32_t m_uOutQueueMissCountLastSecond;

	uint32_t m_uAcceptQueueSize;
	uint64_t m_uAcceptQueueBufSize;
	uint32_t m_uInQueueSize;
	uint64_t m_uInQueueBufSize;
	uint32_t m_uOutQueueSize;
	uint64_t m_uOutQueueBufSize;
} IOStat;


int main() {
	IOStat* m_pstIOStat = (IOStat*)calloc(uCount, sizeof(IOStat));

}
