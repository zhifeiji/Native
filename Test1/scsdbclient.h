/*
* =====================================================================================
Description:  本文件是天云星数据库（SCSDB）的API接口文件，提供用户通过客户端连接操作数据库的接口。
Version:	1.0
Created:	2013-07-11
Compiler:	g++
Author:		
Company:	深圳市汉云科技有限公司
* =====================================================================================
*/

#ifndef SCSDBCLINT_H
#define SCSDBCLINT_H

#if defined (__GNUC__) && defined(__unix__)
#define EXPORT_SCSDBCLIENT  __attribute__ ((__visibility__("default")))
#elif defined (_WIN32) || defined(_WIN64)
#ifdef SCSDBCLINET_DLL
#define EXPORT_SCSDBCLIENT  __declspec(dllexport)
#else
#define EXPORT_SCSDBCLIENT  __declspec(dllimport)
#endif
#endif

typedef void*	SCSDB;


//注意：在一个连接上执行的操作是串行化的，不支持并行操作。
//即不支持在多个线程中同时操作一个连接，这种操作容易引起数据的混乱
//但可以在多个线程中创建各自的连接，每个线程可以安全的操作自己的连接

#ifdef __cplusplus
extern "C"
{
#endif
	/************************************************************************************
	功能：	连接SCSDB服务器。
	参数：	[IN] host - 服务器IP
			[IN] user - 用户名
			[IN] passwd - 密码
			[IN] db - 用户希望连接的数据库。可为NULL
	返回值：如果连接成功，返回SCSDB连接句柄（在有些文档中也称连接描述符），
			后面对数据库的所有操作都要使用该句柄。
			如果连接失败，返回NULL。
	************************************************************************************/
	EXPORT_SCSDBCLIENT SCSDB scsdb_open(const char* host,const char* user,const char* passwd,const char* db);

	/************************************************************************************
	功能：	关闭与SCSDB服务器的连接。
	参数：	[IN] scsdb - SCSDB连接句柄（即scsdb_open连接成功的返回值）
	返回值：成功返回0，否则其他值。
			可通过scsdb_error_code和scsdb_error_string来分布获取错误码和错误消息。
	************************************************************************************/
	EXPORT_SCSDBCLIENT int scsdb_close(SCSDB scsdb);

	/************************************************************************************
	功能：	执行scsql指向的SCSQL语句。
	参数：	[IN] scsdb - SCSDB连接句柄（即scsdb_open连接成功的返回值）
			[IN] scsql - SCSQL语句的起始地址
			[IN] length - SCSQL语句的长度
	返回值：成功返回0，否则其他值。
			可通过scsdb_error_code和scsdb_error_string来分布获取错误码和错误消息。
	注：可通过scsdb_column_num来检查查询是否应该返回结果集。
		如果scsdb_column_num返回值>0，则此次查询应该返回结果集；否则，此次查询不返回结果集
	************************************************************************************/
	EXPORT_SCSDBCLIENT int scsdb_execute(SCSDB scsdb,const char* scsql, unsigned int length);

	/************************************************************************************
	功能：	获取最近一次执行的scsql语句查询到的结果集列数。
	参数：	[IN] scsdb - SCSDB连接句柄（即scsdb_open连接成功的返回值）
	返回值：结果集的列数。>=0。0表示没有结果集返回。
	************************************************************************************/
	EXPORT_SCSDBCLIENT int scsdb_colum_num(SCSDB scsdb);

	/************************************************************************************
	功能：	获取最近一次执行的scsql语句查询到的结果集行数。即将被废弃，
			在新程序中请不要再使用。
	参数：	[IN] scsdb - SCSDB连接句柄（即scsdb_open连接成功的返回值）
	返回值：结果集的行数。>=0。0表示结果集为空。
	************************************************************************************/
	EXPORT_SCSDBCLIENT long long scsdb_row_num(SCSDB scsdb);

	/************************************************************************************
	功能：	获取最近一次执行scsql语句后，数据库中受影响的记录的行数。
	参数：	[IN] scsdb - SCSDB连接句柄（即scsdb_open连接成功的返回值）
	返回值：受影响的记录的行数。>=0。0表示没有记录受影响，即没有记录被修改（增、删、改）。
	************************************************************************************/
	EXPORT_SCSDBCLIENT long long scsdb_affected_rows(SCSDB scsdb);

	/************************************************************************************
	功能：	当有结果集返回时，scsdb_read_row从结果集中读取下一行。
	参数：	[IN] scsdb - SCSDB连接句柄（即scsdb_open连接成功的返回值）
	返回值：0，从结果集中成功读取了一行
			__READ_ROW_END，结果集已读取完
			其他值，发生了错误。
	************************************************************************************/
	EXPORT_SCSDBCLIENT int scsdb_read_row(SCSDB scsdb);

	/************************************************************************************
	功能：	读取当前行中的第idx字段的的数据。
	参数：	[IN] scsdb - SCSDB连接句柄（即scsdb_open连接成功的返回值）
			[IN] idx - 将要读取的字段的序号
	返回值：指定字段的数据的地址/NULL。
	注意：序号从0开始计算。
	************************************************************************************/
	EXPORT_SCSDBCLIENT const char* scsdb_read_field(SCSDB scsdb, int idx);


	/************************************************************************************
	功能：	获取最后一次操作失败时的错误码
	参数：	[IN] scsdb - SCSDB连接句柄（即scsdb_open连接成功的返回值）
	返回值：错误码
	************************************************************************************/
	EXPORT_SCSDBCLIENT int scsdb_error_code(SCSDB scsdb);

	/************************************************************************************
	功能：	获取最后一次操作失败时的错误描述
	参数：	[IN] scsdb - SCSDB连接句柄（即scsdb_open连接成功的返回值）
	返回值：错误信息的具体描述。以'\0'结尾的字符串。
	************************************************************************************/
	EXPORT_SCSDBCLIENT const char* scsdb_error_string(SCSDB scsdb);

	/************************************************************************************
	功能：	获取第idx列的列名。
	参数：	[IN] scsdb - SCSDB连接句柄（即scsdb_open连接成功的返回值）
			[IN] idx - 将要查询列的序号。
	返回值：指定列的列名。以'\0'结尾的字符串。
	注意：序号从0开始计算。即若scsdb_colum_num返回结果集有3列，则各列依次为第0、1、2列。
	************************************************************************************/
	EXPORT_SCSDBCLIENT const char* scsdb_column_name(SCSDB scsdb, int idx);

	/************************************************************************************
	功能：	释放最近一次查询的结果集。
	参数：	[IN] scsdb - SCSDB连接句柄（即scsdb_open连接成功的返回值）
	返回值：成功为0，否则其他值
	************************************************************************************/
	EXPORT_SCSDBCLIENT int scsdb_release(SCSDB scsdb);

	/************************************************************************************
	功能：	获取自增长字段的下一个可用序列号
	参数：	[IN] scsdb - SCSDB连接句柄（即scsdb_open连接成功的返回值）
			[IN] db - 数据库名
			[IN] tbl - 表名
			[IN] col - 自增长字段名
	返回值：一个以NULL结尾的字符串序列号，如"12345"
	************************************************************************************/
	EXPORT_SCSDBCLIENT const char* scsdb_get_seq(SCSDB scsdb, const char *db, const char *tbl, const char *col);
	
	/************************************************************************************
	功能：	获取客户端和服务器端的版本信息
	参数：	[IN] scsdb - SCSDB连接句柄（即scsdb_open连接成功的返回值）
	返回值：一个以NULL结尾的字符串版本信息，
			格式如"Client Version is XX.XX.XX and Server Version is XX.XX.XX"
	************************************************************************************/
	EXPORT_SCSDBCLIENT const char* scsdb_get_ver(SCSDB scsdb);

	/************************************************************************************
	功能：	获取客户端库的版本信息
	参数：	无
	返回值：一个以NULL结尾的字符串版本信息，格式如"XX.XX.XX"。
	************************************************************************************/
	EXPORT_SCSDBCLIENT const char* scsdb_get_client_ver();

	//以下函数为了兼容以前版本而保留，在将来版本中可能会被废弃，请不要再使用
	//{为版本兼容而保留的函数

	//功能、参数意义与scsdb_execute相同，将被scsdb_execute替换
	EXPORT_SCSDBCLIENT int scsdb_executesql(SCSDB scsdb,const char* scsql);

	//功能、参数意义与scsdb_execute相同，将被scsdb_execute替换
	EXPORT_SCSDBCLIENT int scsdb_executesql_delay(SCSDB scsdb,const char* scsql);

	//功能、参数意义与scsdb_row_num相同，将被scsdb_row_num替换。已被废弃，请勿再使用。
	EXPORT_SCSDBCLIENT long scsdb_NumRow(SCSDB scsdb);

	//功能、参数意义与scsdb_read_row相同，将被scsdb_read_row替换
	EXPORT_SCSDBCLIENT int scsdb_ReadRow(SCSDB scsdb);

	//功能、参数意义与scsdb_colum_num相同，将被scsdb_colum_num替换
	EXPORT_SCSDBCLIENT int scsdb_NumFiles(SCSDB scsdb);

	//功能、参数意义与scsdb_read_field相同，将被scsdb_read_field替换
	EXPORT_SCSDBCLIENT char* scsdb_Files(SCSDB scsdb,int idx);

	//功能、参数意义与scsdb_error_code相同，将被scsdb_error_code替换
	EXPORT_SCSDBCLIENT int scsdb_geterror(SCSDB scsdb);

	//功能、参数意义与scsdb_error_string相同，将被scsdb_error_string替换
	EXPORT_SCSDBCLIENT char* scsdb_geterror_string(SCSDB scsdb);

	//功能、参数意义与scsdb_colum_num相同，将被scsdb_colum_num替换
	EXPORT_SCSDBCLIENT int scsdb_columnNum(SCSDB scsdb);

	//功能、参数意义与scsdb_column_name相同，将被scsdb_column_name替换
	EXPORT_SCSDBCLIENT char* scsdb_getcolumn(SCSDB scsdb, int idx);

	//功能、参数意义与scsdb_get_seq相同，将被scsdb_get_seq替换
	EXPORT_SCSDBCLIENT const char* scsdb_getseq(SCSDB scsdb, const char *db, const char *tbl, const char *col);

	//功能、参数意义与scsdb_get_ver相同，将被scsdb_get_ver替换
	EXPORT_SCSDBCLIENT const char* scsdb_getver(SCSDB scsdb);

	//}为版本兼容而保留的函数

#ifdef __cplusplus
}
#endif

#endif
