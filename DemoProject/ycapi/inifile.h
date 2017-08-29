/**
 * @file
 * @brief initialization file read and write API
 *	-size of the ini file must less than 1M
 *	-after '=' in key value pair, can not support empty char. this would not like WIN32 API
 *	-support comment using ';' prefix
 *	-can not support multi line
 * @author Deng Yangjun
 * @date 2007-1-9
 * @version 0.2
 */
 
#ifndef INI_FILE_H_
#define INI_FILE_H_

#ifdef __cplusplus
extern "C"
{

#endif

//int read_ini_string( const char *section, const char *key,char *value, int size,const char *default_value, const char *file);
//int read_ini_int( const char *section, const char *key,int default_value, const char *file);
//int write_ini_string( const char *section, const char *key,const char *value, const char *file);

int  WritePrivateProfileString(  const char * lpAppName,  const char * lpKeyName,  const char * lpString,  const char * lpFileName);

int  WritePrivateProfileInt( const char * lpAppName, const char * lpKeyName, int Value,const char * lpFileName);

int GetPrivateProfileInt(  const char * lpAppName,const char * lpKeyName,int nDefault, const char * lpFileName );

int GetPrivateProfileString(  const char * lpAppName, const char * lpKeyName,  const char * lpDefault, const char *  lpReturnedString, int   Size, const char * lpFileName );

#ifdef __cplusplus
}; //end of extern "C" {
#endif

#endif //end of INI_FILE_H_

