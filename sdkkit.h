#ifndef SDK_KIT_H_
#define SDK_KIT_H_

#include <iostream>
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}


void initLuaFrame(lua_State* ls);


//////////////////////////////////////////////
void sdkkit_login();

void sdkkit_pay(int payAmount, std::string productId, std::string productName, std::string payProductNum,
                  std::string payOrderId, std::string payServerId, std::string payServerName,
                  std::string payGameLevel, std::string payRoleId, std::string payRoleLevel,
                  std::string payRoleName, std::string payUserId, std::string payUserName,
                  std::string payBlance, std::string extInfo);


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

void sdkkit_onServerRoleInfo(std::string roleId, std::string roleName, 
      int roleLevel, std::string serverId, std::string serverName, 
      std::string rolePartyName, std::string roleVipLevel);

void sdkkit_onButtonClick(std::string name, std::string userMark);

void sdkkit_onCreateRole(std::string userId, std::string roleId,
            std::string roleName, std::string serverId, std::string serverName)

//////////////////////////////////////////////


#endif