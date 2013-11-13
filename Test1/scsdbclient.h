/*
* =====================================================================================
Description:  ���ļ������������ݿ⣨SCSDB����API�ӿ��ļ����ṩ�û�ͨ���ͻ������Ӳ������ݿ�Ľӿڡ�
Version:	1.0
Created:	2013-07-11
Compiler:	g++
Author:		
Company:	�����к��ƿƼ����޹�˾��
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


//ע�⣺��һ��������ִ�еĲ����Ǵ��л��ģ���֧�ֲ��в�����
//����֧���ڶ���߳���ͬʱ����һ�����ӣ����ֲ��������������ݵĻ���
//�������ڶ���߳��д������Ե����ӣ�ÿ���߳̿��԰�ȫ�Ĳ����Լ�������

#ifdef __cplusplus
extern "C"
{
#endif
	/************************************************************************************
	���ܣ�	����SCSDB��������
	������	[IN] host - ������IP
			[IN] user - �û���
			[IN] passwd - ����
			[IN] db - �û�ϣ�����ӵ����ݿ⡣��ΪNULL
	����ֵ��������ӳɹ�������SCSDB���Ӿ��������Щ�ĵ���Ҳ����������������
			��������ݿ�����в�����Ҫʹ�øþ����
			�������ʧ�ܣ�����NULL��
	************************************************************************************/
	EXPORT_SCSDBCLIENT SCSDB scsdb_open(const char* host,const char* user,const char* passwd,const char* db);

	/************************************************************************************
	���ܣ�	�ر���SCSDB�����������ӡ�
	������	[IN] scsdb - SCSDB���Ӿ������scsdb_open���ӳɹ��ķ���ֵ��
	����ֵ���ɹ�����0����������ֵ��
			��ͨ��scsdb_error_code��scsdb_error_string���ֲ���ȡ������ʹ�����Ϣ��
	************************************************************************************/
	EXPORT_SCSDBCLIENT int scsdb_close(SCSDB scsdb);

	/************************************************************************************
	���ܣ�	ִ��scsqlָ���SCSQL��䡣
	������	[IN] scsdb - SCSDB���Ӿ������scsdb_open���ӳɹ��ķ���ֵ��
			[IN] scsql - SCSQL������ʼ��ַ
			[IN] length - SCSQL���ĳ���
	����ֵ���ɹ�����0����������ֵ��
			��ͨ��scsdb_error_code��scsdb_error_string���ֲ���ȡ������ʹ�����Ϣ��
	ע����ͨ��scsdb_column_num������ѯ�Ƿ�Ӧ�÷��ؽ������
		���scsdb_column_num����ֵ>0����˴β�ѯӦ�÷��ؽ���������򣬴˴β�ѯ�����ؽ����
	************************************************************************************/
	EXPORT_SCSDBCLIENT int scsdb_execute(SCSDB scsdb,const char* scsql, unsigned int length);

	/************************************************************************************
	���ܣ�	��ȡ���һ��ִ�е�scsql����ѯ���Ľ����������
	������	[IN] scsdb - SCSDB���Ӿ������scsdb_open���ӳɹ��ķ���ֵ��
	����ֵ���������������>=0��0��ʾû�н�������ء�
	************************************************************************************/
	EXPORT_SCSDBCLIENT int scsdb_colum_num(SCSDB scsdb);

	/************************************************************************************
	���ܣ�	��ȡ���һ��ִ�е�scsql����ѯ���Ľ����������������������
			���³������벻Ҫ��ʹ�á�
	������	[IN] scsdb - SCSDB���Ӿ������scsdb_open���ӳɹ��ķ���ֵ��
	����ֵ���������������>=0��0��ʾ�����Ϊ�ա�
	************************************************************************************/
	EXPORT_SCSDBCLIENT long long scsdb_row_num(SCSDB scsdb);

	/************************************************************************************
	���ܣ�	��ȡ���һ��ִ��scsql�������ݿ�����Ӱ��ļ�¼��������
	������	[IN] scsdb - SCSDB���Ӿ������scsdb_open���ӳɹ��ķ���ֵ��
	����ֵ����Ӱ��ļ�¼��������>=0��0��ʾû�м�¼��Ӱ�죬��û�м�¼���޸ģ�����ɾ���ģ���
	************************************************************************************/
	EXPORT_SCSDBCLIENT long long scsdb_affected_rows(SCSDB scsdb);

	/************************************************************************************
	���ܣ�	���н��������ʱ��scsdb_read_row�ӽ�����ж�ȡ��һ�С�
	������	[IN] scsdb - SCSDB���Ӿ������scsdb_open���ӳɹ��ķ���ֵ��
	����ֵ��0���ӽ�����гɹ���ȡ��һ��
			__READ_ROW_END��������Ѷ�ȡ��
			����ֵ�������˴���
	************************************************************************************/
	EXPORT_SCSDBCLIENT int scsdb_read_row(SCSDB scsdb);

	/************************************************************************************
	���ܣ�	��ȡ��ǰ���еĵ�idx�ֶεĵ����ݡ�
	������	[IN] scsdb - SCSDB���Ӿ������scsdb_open���ӳɹ��ķ���ֵ��
			[IN] idx - ��Ҫ��ȡ���ֶε����
	����ֵ��ָ���ֶε����ݵĵ�ַ/NULL��
	ע�⣺��Ŵ�0��ʼ���㡣
	************************************************************************************/
	EXPORT_SCSDBCLIENT const char* scsdb_read_field(SCSDB scsdb, int idx);


	/************************************************************************************
	���ܣ�	��ȡ���һ�β���ʧ��ʱ�Ĵ�����
	������	[IN] scsdb - SCSDB���Ӿ������scsdb_open���ӳɹ��ķ���ֵ��
	����ֵ��������
	************************************************************************************/
	EXPORT_SCSDBCLIENT int scsdb_error_code(SCSDB scsdb);

	/************************************************************************************
	���ܣ�	��ȡ���һ�β���ʧ��ʱ�Ĵ�������
	������	[IN] scsdb - SCSDB���Ӿ������scsdb_open���ӳɹ��ķ���ֵ��
	����ֵ��������Ϣ�ľ�����������'\0'��β���ַ�����
	************************************************************************************/
	EXPORT_SCSDBCLIENT const char* scsdb_error_string(SCSDB scsdb);

	/************************************************************************************
	���ܣ�	��ȡ��idx�е�������
	������	[IN] scsdb - SCSDB���Ӿ������scsdb_open���ӳɹ��ķ���ֵ��
			[IN] idx - ��Ҫ��ѯ�е���š�
	����ֵ��ָ���е���������'\0'��β���ַ�����
	ע�⣺��Ŵ�0��ʼ���㡣����scsdb_colum_num���ؽ������3�У����������Ϊ��0��1��2�С�
	************************************************************************************/
	EXPORT_SCSDBCLIENT const char* scsdb_column_name(SCSDB scsdb, int idx);

	/************************************************************************************
	���ܣ�	�ͷ����һ�β�ѯ�Ľ������
	������	[IN] scsdb - SCSDB���Ӿ������scsdb_open���ӳɹ��ķ���ֵ��
	����ֵ���ɹ�Ϊ0����������ֵ
	************************************************************************************/
	EXPORT_SCSDBCLIENT int scsdb_release(SCSDB scsdb);

	/************************************************************************************
	���ܣ�	��ȡ�������ֶε���һ���������к�
	������	[IN] scsdb - SCSDB���Ӿ������scsdb_open���ӳɹ��ķ���ֵ��
			[IN] db - ���ݿ���
			[IN] tbl - ����
			[IN] col - �������ֶ���
	����ֵ��һ����NULL��β���ַ������кţ���"12345"
	************************************************************************************/
	EXPORT_SCSDBCLIENT const char* scsdb_get_seq(SCSDB scsdb, const char *db, const char *tbl, const char *col);
	
	/************************************************************************************
	���ܣ�	��ȡ�ͻ��˺ͷ������˵İ汾��Ϣ
	������	[IN] scsdb - SCSDB���Ӿ������scsdb_open���ӳɹ��ķ���ֵ��
	����ֵ��һ����NULL��β���ַ����汾��Ϣ��
			��ʽ��"Client Version is XX.XX.XX and Server Version is XX.XX.XX"
	************************************************************************************/
	EXPORT_SCSDBCLIENT const char* scsdb_get_ver(SCSDB scsdb);

	/************************************************************************************
	���ܣ�	��ȡ�ͻ��˿�İ汾��Ϣ
	������	��
	����ֵ��һ����NULL��β���ַ����汾��Ϣ����ʽ��"XX.XX.XX"��
	************************************************************************************/
	EXPORT_SCSDBCLIENT const char* scsdb_get_client_ver();

	//���º���Ϊ�˼�����ǰ�汾���������ڽ����汾�п��ܻᱻ�������벻Ҫ��ʹ��
	//{Ϊ�汾���ݶ������ĺ���

	//���ܡ�����������scsdb_execute��ͬ������scsdb_execute�滻
	EXPORT_SCSDBCLIENT int scsdb_executesql(SCSDB scsdb,const char* scsql);

	//���ܡ�����������scsdb_execute��ͬ������scsdb_execute�滻
	EXPORT_SCSDBCLIENT int scsdb_executesql_delay(SCSDB scsdb,const char* scsql);

	//���ܡ�����������scsdb_row_num��ͬ������scsdb_row_num�滻���ѱ�������������ʹ�á�
	EXPORT_SCSDBCLIENT long scsdb_NumRow(SCSDB scsdb);

	//���ܡ�����������scsdb_read_row��ͬ������scsdb_read_row�滻
	EXPORT_SCSDBCLIENT int scsdb_ReadRow(SCSDB scsdb);

	//���ܡ�����������scsdb_colum_num��ͬ������scsdb_colum_num�滻
	EXPORT_SCSDBCLIENT int scsdb_NumFiles(SCSDB scsdb);

	//���ܡ�����������scsdb_read_field��ͬ������scsdb_read_field�滻
	EXPORT_SCSDBCLIENT char* scsdb_Files(SCSDB scsdb,int idx);

	//���ܡ�����������scsdb_error_code��ͬ������scsdb_error_code�滻
	EXPORT_SCSDBCLIENT int scsdb_geterror(SCSDB scsdb);

	//���ܡ�����������scsdb_error_string��ͬ������scsdb_error_string�滻
	EXPORT_SCSDBCLIENT char* scsdb_geterror_string(SCSDB scsdb);

	//���ܡ�����������scsdb_colum_num��ͬ������scsdb_colum_num�滻
	EXPORT_SCSDBCLIENT int scsdb_columnNum(SCSDB scsdb);

	//���ܡ�����������scsdb_column_name��ͬ������scsdb_column_name�滻
	EXPORT_SCSDBCLIENT char* scsdb_getcolumn(SCSDB scsdb, int idx);

	//���ܡ�����������scsdb_get_seq��ͬ������scsdb_get_seq�滻
	EXPORT_SCSDBCLIENT const char* scsdb_getseq(SCSDB scsdb, const char *db, const char *tbl, const char *col);

	//���ܡ�����������scsdb_get_ver��ͬ������scsdb_get_ver�滻
	EXPORT_SCSDBCLIENT const char* scsdb_getver(SCSDB scsdb);

	//}Ϊ�汾���ݶ������ĺ���

#ifdef __cplusplus
}
#endif

#endif
