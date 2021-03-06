/* It had generated by DirectStruct v1.6.3 */
#ifndef _H_hetao_conf_
#define _H_hetao_conf_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if ( defined __unix ) || ( defined __linux__ )
#ifndef _WINDLL_FUNC
#define _WINDLL_FUNC
#endif
#elif ( defined _WIN32 )
#ifndef _WINDLL_FUNC
#define _WINDLL_FUNC		_declspec(dllexport)
#endif
#endif

#ifndef DSCTRUE
#define DSCTRUE	(unsigned char)'t'
#endif
#ifndef DSCFALSE
#define DSCFALSE	(unsigned char)'f'
#endif
#ifndef DSCNULL
#define DSCNULL	(unsigned char)127
#endif

#if ( defined __unix ) | ( defined __linux__ )
#include <arpa/inet.h>
#define SNPRINTF		snprintf
#elif ( defined _WIN32 )
#define SNPRINTF		_snprintf
#include "winsock.h"
#endif

#if ( defined __unix ) | ( defined __linux__ )
#ifndef longlong
#define longlong	long long
#define ulonglong	unsigned long long
#define LL(_ll_)	_ll_##LL
#define ULL(_ll_)	_ll_##ULL
#define LONGLONG_FORMAT_SPEC	"%lld"
#define ATOLL	atoll
#endif
#if ( defined _AIX )
#define __BIG_ENDIAN	BIG_ENDIAN
#define __LITTLE_ENDIAN	LITTLE_ENDIAN
#define __BYTE_ORDER	BYTE_ORDER
#endif
#elif ( defined _WIN32 )
#ifndef longlong
#define longlong	__int64
#define ulonglong	unsigned __int64
#define LL(_ll_)	_ll_
#define ULL(_ll_)	_ll_
#define LONGLONG_FORMAT_SPEC	"%I64"
#define ATOLL	_atoi64
#define __BIG_ENDIAN	4321
#define __LITTLE_ENDIAN	1234
#define __BYTE_ORDER	__LITTLE_ENDIAN
#endif
#endif

#ifndef NATOC
#define NATOC(_base_,_len_,_result_)	{char buf[3+1];memset(buf,0x00,sizeof(buf));strncpy(buf,_base_,3);_result_=(char)atoi(buf);}
#endif
#ifndef NATOS
#define NATOS(_base_,_len_,_result_)	{char buf[5+1];memset(buf,0x00,sizeof(buf));strncpy(buf,_base_,5);_result_=(short)atol(buf);}
#endif
#ifndef NATOI
#define NATOI(_base_,_len_,_result_)	{char buf[10+1];memset(buf,0x00,sizeof(buf));strncpy(buf,_base_,10);_result_=atoi(buf);}
#endif
#ifndef NATOLL
#define NATOLL(_base_,_len_,_result_)	{char buf[20+1];memset(buf,0x00,sizeof(buf));strncpy(buf,_base_,20);_result_=ATOLL(buf);}
#endif
#ifndef NATOF
#define NATOF(_base_,_len_,_result_)	{char buf[20+1];memset(buf,0x00,sizeof(buf));strncpy(buf,_base_,20);_result_=(float)atof(buf);}
#endif
#ifndef NATOLF
#define NATOLF(_base_,_len_,_result_)	{char buf[60+1];memset(buf,0x00,sizeof(buf));strncpy(buf,_base_,60);_result_=atof(buf);}
#endif
#ifndef NATOB
#define NATOB(_base_,_len_,_result_)	{if(memcmp(_base_,"true",4)==0)_result_=DSCTRUE;else _result_=DSCFALSE;}
#endif

typedef struct
{
	int	worker_processes ;
	int	cpu_affinity ;
	int	accept_mutex ;
	char	error_log[ 256 + 1 ] ;
	char	log_level[ 6 + 1 ] ;
	char	user[ 64 + 1 ] ;
	struct
	{
		int	max_http_session_count ;
		int	max_file_cache ;
	} limits ;
	struct
	{
		char	ip[ 15 + 1 ] ;
		int	port ;
		struct
		{
			char	certificate_file[ 256 + 1 ] ;
			char	certificate_key_file[ 256 + 1 ] ;
		} ssl ;
		struct
		{
			char	domain[ 256 + 1 ] ;
			char	wwwroot[ 1024 + 1 ] ;
			char	index[ 1024 + 1 ] ;
			char	access_log[ 256 + 1 ] ;
			struct
			{
				char	pattern[ 256 + 1 ] ;
				char	template[ 256 + 1 ] ;
			} rewrite [ 10 ] ;
			int	_rewrite_count ;
			int	_rewrite_size ;
			struct
			{
				char	forward_type[ 16 + 1 ] ;
				char	forward_rule[ 1 + 1 ] ;
				struct
				{
					char	certificate_file[ 256 + 1 ] ;
					char	certificate_key_file[ 256 + 1 ] ;
				} ssl ;
				struct
				{
					char	ip[ 15 + 1 ] ;
					int	port ;
				} forward_server [ 1000 ] ;
				int	_forward_server_count ;
				int	_forward_server_size ;
			} forward ;
		} website [ 64 ] ;
		int	_website_count ;
		int	_website_size ;
	} listen [ 16 ] ;
	int	_listen_count ;
	int	_listen_size ;
	struct
	{
		int	nodelay ;
		int	nolinger ;
	} tcp_options ;
	struct
	{
		int	compress_on ;
		int	timeout ;
		int	forward_disable ;
	} http_options ;
	struct
	{
		char	error_page_400[ 1024 + 1 ] ;
		char	error_page_401[ 1024 + 1 ] ;
		char	error_page_403[ 1024 + 1 ] ;
		char	error_page_404[ 1024 + 1 ] ;
		char	error_page_408[ 1024 + 1 ] ;
		char	error_page_500[ 1024 + 1 ] ;
		char	error_page_503[ 1024 + 1 ] ;
		char	error_page_505[ 1024 + 1 ] ;
	} error_pages ;
	struct
	{
		struct
		{
			char	type[ 50 + 1 ] ;
			char	mime[ 100 + 1 ] ;
			char	compress_enable ;
		} mime_type [ 256 ] ;
		int	_mime_type_count ;
		int	_mime_type_size ;
	} mime_types ;
} hetao_conf ;

_WINDLL_FUNC int DSCINIT_hetao_conf( hetao_conf *pst );

#include "fasterjson.h"

_WINDLL_FUNC int DSCSERIALIZE_JSON_hetao_conf( hetao_conf *pst , char *encoding , char *buf , int *p_len );
_WINDLL_FUNC int DSCSERIALIZE_JSON_DUP_hetao_conf( hetao_conf *pst , char *encoding , char **pp_base , int *p_buf_size , int *p_len );
_WINDLL_FUNC int DSCDESERIALIZE_JSON_hetao_conf( char *encoding , char *buf , int *p_len , hetao_conf *pst );

int DSCGetErrorLine_hetao_conf();

#endif
