#ifndef DATE_TIME_H
#define DATE_TIME_H
#define MAX_RTC_DEV_NAME 16
typedef struct{
	u16 year;
	u8  mon;
	u8  day;
	u8  week;
	u8  hour;
	u8  min;
	u8  sec;	
}TDateTime;

typedef struct{
	unsigned  int sec:6;
	unsigned  int min:6;
	unsigned  int hour:5;
	unsigned  int day:5;
	unsigned  int mon:4;
	unsigned  int year:6;
}TZipDateTime;

typedef union 
{
	TZipDateTime dt;
	unsigned     value;
}TZipDateTimeDef;

typedef BOOL (*Get_DateTime)(TDateTime* dt);
typedef BOOL (*Set_DateTime)(TDateTime* dt);
typedef struct{
	char name[MAX_RTC_DEV_NAME];
	Get_DateTime get_datetime;
	Set_DateTime set_datetime;
	
}RTC_Device;
BOOL get_datetime(TDateTime* dt);
BOOL set_datetime(TDateTime* dt);
BOOL valid_datetime(TDateTime* dt);
BOOL get_zipdatetime(TZipDateTimeDef* zdt);
BOOL set_zipdatetime(TZipDateTimeDef* zdt);


BOOL datetime_unzip(unsigned int zip_value,TDateTime *dt);
unsigned int datetime_zip(TDateTime* in_dt);
unsigned long datetime_mktime (TDateTime* dt);
void datetime_convert(u32 TimeVar,TDateTime* dt);

u16  get_year(void);
u8   get_mon(void);
u8   get_day(void);
u8   get_hour(void);
u8	 get_min(void);
u8   get_sec(void);
BOOL register_rtc(RTC_Device* dev);
#endif

