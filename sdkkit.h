#ifndef SDK_KIT_H_
#define SDK_KIT_H_


#define HJR_USE_LUA_SDK 1

#include <iostream>
#include <map>

#ifdef HJR_USE_LUA_SDK

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

void initLuaFrame(lua_State* ls);

#endif



//////////////////////////////////////////////
void sdkkit_login();

void sdkkit_pay(int payAmount, std::string productId, std::string productName, std::string payProductNum,
                  std::string payOrderId, std::string payServerId, std::string payServerName,
                  std::string payGameLevel, std::string payRoleId, std::string payRoleLevel,
                  std::string payRoleName, std::string payUserId, std::string payUserName,
                  std::string payBlance, std::string extInfo);

void sdkkit_pay_ext(int payAmount, std::map<std::string, std::string> data); // lua 中sdkkit_pay绑定的是此函数

void sdkkit_userCenter();

void sdkkit_logout();
void sdkkit_getOrderInfo(std::string payOrderId);
void sdkkit_exitGame();

//////////////////////////////////////////////

void sdkkit_onLogin(std::string userId, std::string serverId);

void sdkkit_onPay(int amount, std::string serverId, std::string serverName,
            std::string userId, std::string roleId, std::string orderNumber,
            std::string roleGrade, std::string roleName, std::string productDesc);

void sdkkit_onUpgrade(std::string userId, std::string serverId,
            std::string roleGrade, std::string roleId, std::string roleName,
            std::string roleServerName);

void sdkkit_onCreateRole(std::string userId, std::string roleId,
            std::string roleName, std::string serverId, std::string serverName);

void sdkkit_onButtonClick(std::string userId, std::string buttonName);

void sdkkit_onServerRoleInfo(std::string roleId, std::string roleName, 
      int roleLevel, std::string serverId, std::string serverName, 
      std::string rolePartyName, std::string roleVipLevel);

//////////////////////////////////////////////

void SDKKitPlateformCallBackImplWrapper_initCallBack(int retStatus, std::string retMessage);

void SDKKitPlateformCallBackImplWrapper_loginCallBack(int retStatus, std::string s_retMessage, std::string s_loginUserId, std::string s_loginUserName, std::string s_loginAuthToken, std::string s_loginOpenId);

void SDKKitPlateformCallBackImplWrapper_logoutCallBack(int retStatus, std::string s_retMessage);

void SDKKitPlateformCallBackImplWrapper_payCallBack(int retStatus, std::string s_retMessage,
        std::string s_loginUserId, std::string s_loginAuthToken, std::string s_loginServerId, std::string s_payKitOrderId);

void SDKKitPlateformCallBackImplWrapper_getOrderResultCallBack(int retStatus, std::string s_retMessage);

void SDKKitPlateformCallBackImplWrapper_exitGameCallBack(int retStatus, std::string s_retMessage);

//////////////////////////////////////////////

#endif