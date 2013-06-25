#include <windows.h>
#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>
#include <shlwapi.h>
#include <stdio.h>

#pragma comment(lib,"odbc32.lib")
#pragma comment(lib,"shlwapi.lib")

char szDatabaseParam[]="database",
     szGetBalanceStatement[]="select Rest,Account from Account";

char *GrabBalance(char *lpPath)
{
    char *lpBalance=NULL;
    if (lpPath)
    {
        SQLHENV hEnv;
        SQLHANDLE hConn,hBalance;
        SQLAllocHandle(SQL_HANDLE_ENV,NULL,&hEnv);
        SQLSetEnvAttr(hEnv,SQL_ATTR_ODBC_VERSION,(void *)SQL_OV_ODBC3,NULL);
        SQLAllocHandle(SQL_HANDLE_DBC,hEnv,&hConn);

        char szConfig[MAX_PATH];
        PathCombineA(szConfig,lpPath,"exe\\default.cfg");
        bool bUseAlias=GetPrivateProfileIntA(szDatabaseParam,"aliasconnect",0,szConfig);
        char szUser[20];
        GetPrivateProfileStringA(szDatabaseParam,"username",0,szUser,20,szConfig);

        do
        {
            if (bUseAlias)
            {
                char szAlias[200];
                int dwLen=GetPrivateProfileStringA(szDatabaseParam,"alias",0,szAlias,200,szConfig);
                char szStr[512];
                SQLSMALLINT tmp;
                SQLRETURN retcode=SQLConnectA(hConn,(SQLCHAR*)szAlias,dwLen,(SQLCHAR*)szUser,lstrlenA(szUser),(SQLCHAR*)"sql",3);
                if ((retcode != SQL_SUCCESS) && (retcode != SQL_SUCCESS_WITH_INFO))
                    break;
            }
            else
            {
                char szConnectString[400];
                int dwLen=GetPrivateProfileStringA(szDatabaseParam,"connectstring",0,szConnectString,200,szConfig);
                char *p;
                if (p=StrStrA(szConnectString,"%BSSRoot%"))
                {
                    char szTmpStr[200];
                    lstrcpyA(szTmpStr,p+sizeof("%BSSRoot%")-1);
                    lstrcpyA(p,lpPath);
                    p+=lstrlenA(lpPath);
                    lstrcpyA(p,szTmpStr);
                    dwLen=lstrlenA(szConnectString)+1;
                }
                if (szConnectString[dwLen-1] != ';')
                {
                    *(WORD*)&szConnectString[dwLen-1]=';';
                    dwLen++;
                }
                char szUserPassword[40];
                dwLen+=wsprintfA(szUserPassword,"UID=%s;PWD=sql;",szUser);
                lstrcatA(szConnectString,szUserPassword);
                char szStr[512];
                SQLSMALLINT tmp;
                SQLRETURN retcode=SQLDriverConnectA(hConn,NULL,(SQLCHAR*)szConnectString,dwLen,(unsigned char *)szStr,sizeof(szStr),&tmp,SQL_DRIVER_COMPLETE);
                if ((retcode != SQL_SUCCESS) && (retcode != SQL_SUCCESS_WITH_INFO))
                    break;
            }
            SQLHANDLE hBalance;
            SQLAllocHandle(SQL_HANDLE_STMT,hConn,&hBalance);
            SQLPrepareA(hBalance,(SQLCHAR*)szGetBalanceStatement,sizeof(szGetBalanceStatement));
            SQLINTEGER tmp=0;
            SQLDOUBLE Rest=0;
            SQLBindCol(hBalance,1,SQL_C_DOUBLE,&Rest,sizeof(Rest),&tmp);
            SQLCHAR Account[25]={0};
            SQLBindCol(hBalance,2,SQL_C_CHAR,&Account,sizeof(Account),&tmp);
            SQLExecute(hBalance);

            lpBalance=(char*)malloc(1024);
            char *p=lpBalance;
            SQLRETURN dwRet;
            while (((dwRet=SQLFetch(hBalance)) == SQL_SUCCESS) || (dwRet == SQL_SUCCESS_WITH_INFO))
            {
                char szTmp[200];
                DWORD dwLen=sprintf(szTmp,"%s: %f",Account,Rest);
                if (p != lpBalance)
                {
                    *(WORD*)&p='; ';
                    p+=2;
                }
                lstrcpyA(p,szTmp);
                p+=dwLen;
            }
            realloc(lpBalance,p-lpBalance);
            SQLCloseCursor(hBalance);
            SQLFreeHandle(SQL_HANDLE_STMT,hBalance);
        }
        while (false);

        SQLDisconnect(hConn);
        SQLFreeHandle(SQL_HANDLE_DBC,hConn);
        SQLFreeHandle(SQL_HANDLE_ENV,hEnv);
        SQLFreeHandle(SQL_HANDLE_ENV,hBalance);
    }
    return lpBalance;
}

