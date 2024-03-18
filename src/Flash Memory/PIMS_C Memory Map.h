// The Website that the TCP server is serving (Lowest 128Mb Segment)
#define WEBSITE_BEGIN 0x00000000
#define WEBSITE_END 0x00FFFFFF

// Debug Logger File (Second 128Mb Segment)
#define LOGFILE 0x01000000
#define LOGFILE_END 0x01FFFFFF

// Store the last 10 readings for each of the PIMS Systems in the network (Third 128Mb Segment)
#define PIMS_READINGS 0x02FFFFFF
#define PIMS_READINGS_END 0x02FFFFFF

