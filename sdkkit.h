#ifndef SDK_KIT_H_
#define SDK_KIT_H_

#include <iostream>


extern char g_str[]; // 声明全局变量g_str

//////////////////////////////////////////////
void sdkkit_login();
void sdkkit_kitCenter();
void sdkkit_switchAccount();

void sdkkit_pay(int payAmount, std::string productId, std::string productName, std::string payProductNum,
                  std::string payOrderId, std::string payServerId, std::string payServerName,
                  std::string payGameLevel, std::string payRoleId, std::string payRoleLevel,
                  std::string payRoleName, std::string payUserId, std::string payUserName,
                  std::string payBlance, std::string extInfo);


void sdkkit_userCenter();

void sdkkit_logout();
void sdkkit_getOrderInfo(std::string payOrderId);
void sdkkit_floatWindow(bool value);
void sdkkit_exitGame();
//////////////////////////////////////////////

void sdkkit_onLogin(std::string userMark, std::string userType,
            std::string serverNo, std::string roleServerName);

void sdkkit_onPay(int amount, std::string serverNo, std::string userMark,
            std::string roleMark, std::string orderNumber, std::string upgrade,
            std::string productDesc, std::string roleName, std::string roleServerName);

void sdkkit_onUpgrade(std::string userMark, std::string serverNo,
            std::string upgrade, std::string roleId, std::string roleName,
            std::string roleServerName);

void sdkkit_onCreateRole(std::string userMark, std::string roleMark,
            std::string serverNo, std::string roleName);

void sdkkit_onButtonClick(std::string name, std::string userMark);

void sdkkit_onServerRoleInfo(std::string roleId, int roleLevel,
            std::string roleName, std::string rolePartyName, std::string roleVipLevel);

//////////////////////////////////////////////

///////////////////以下函数请实现//////////////////////////
void SDKKitPlateformCallBackImplWrapper_initCallBack(int retStatus, std::string retMessage);

void SDKKitPlateformCallBackImplWrapper_loginCallBack(int retStatus, std::string s_retMessage, std::string s_loginUserId, std::string s_loginAuthToken, std::string cpId);

void SDKKitPlateformCallBackImplWrapper_logoutCallBack(int retStatus, std::string s_retMessage);

void SDKKitPlateformCallBackImplWrapper_payCallBack(int retStatus, std::string s_retMessage,
        std::string s_loginUserId, std::string s_loginAuthToken, std::string s_loginServerId, std::string s_payKitOrderId);

void SDKKitPlateformCallBackImplWrapper_getOrderResultCallBack(int retStatus, std::string s_retMessage);

void SDKKitPlateformCallBackImplWrapper_exitGameCallBack(int retStatus, std::string s_retMessage);


#endif