#include "SdkkitJniHelper.h"
#include "sdkkit.h"

#include <jni.h>
#include <iostream>
#include <map>
#include "fflua.h"

using namespace std;
using namespace ff;

#ifdef __ANDROID__
#include <android/log.h>
#endif


extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}


#define  LOG_TAG    "SDKKIT"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)


//////////////////////////////////////////////
void sdkkit_login();
void sdkkit_switchAccount();

void sdkkit_pay(int payAmount, std::string payRate, std::string payProductNum,
            std::string payOrderId, std::string payServerId, std::string payServerName,
            std::string payGameLevel, std::string payRoleId, std::string payRoleLevel,
            std::string payRoleName, std::string payUserId, std::string payUserName,
            std::string payBlance, std::string extInfo);

void sdkkit_pay_ext(int payAmount, std::map<std::string, std::string> data);

void sdkkit_userCenter();

void sdkkit_logout();
void sdkkit_getOrderInfo(std::string payOrderId);
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

static fflua_t* m_fflua_ptr;

void initLuaFrame(lua_State* ls)
{
    m_fflua_ptr = new fflua_t(ls);

    // 绑定c++函数到lua
    fflua_register_t<>(ls).def(&sdkkit_login, "sdkkit_login");
    fflua_register_t<>(ls).def(&sdkkit_logout, "sdkkit_logout");
    fflua_register_t<>(ls).def(&sdkkit_kitCenter, "sdkkit_kitCenter");
    fflua_register_t<>(ls).def(&sdkkit_switchAccount, "sdkkit_switchAccount");
    fflua_register_t<>(ls).def(&sdkkit_pay_ext, "sdkkit_pay");
    fflua_register_t<>(ls).def(&sdkkit_userCenter, "sdkkit_userCenter");
    fflua_register_t<>(ls).def(&sdkkit_getOrderInfo, "sdkkit_getOrderInfo");
    fflua_register_t<>(ls).def(&sdkkit_exitGame, "sdkkit_exitGame");


    fflua_register_t<>(ls).def(&sdkkit_onLogin, "sdkkit_onLogin");
    fflua_register_t<>(ls).def(&sdkkit_onPay, "sdkkit_onPay");
    fflua_register_t<>(ls).def(&sdkkit_onUpgrade, "sdkkit_onUpgrade");
    fflua_register_t<>(ls).def(&sdkkit_onCreateRole, "sdkkit_onCreateRole");
    fflua_register_t<>(ls).def(&sdkkit_onButtonClick, "sdkkit_onButtonClick");
    fflua_register_t<>(ls).def(&sdkkit_onServerRoleInfo, "sdkkit_onServerRoleInfo");

}


void SDKKitPlateformCallBackImplWrapper_initCallBack(int retStatus, std::string retMessage)
{
    LOGD("call SDKKitPlateformCallBackImplWrapper_initCallBack");
}


void SDKKitPlateformCallBackImplWrapper_loginCallBack(int retStatus, std::string s_retMessage, std::string s_loginUserId, std::string s_loginUserName, std::string s_loginAuthToken, std::string s_loginOpenId)
{
    LOGD("call lua SDKKitPlateformCallBackImplWrapper_loginCallBack");
    m_fflua_ptr->call<void>("SDKKitPlateformCallBackImplWrapper_loginCallBack", retStatus, s_retMessage, s_loginUserId, s_loginUserName, s_loginAuthToken, s_loginOpenId);
}

void SDKKitPlateformCallBackImplWrapper_logoutCallBack(int retStatus, std::string s_retMessage)
{
    LOGD("call lua SDKKitPlateformCallBackImplWrapper_logoutCallBack");
    m_fflua_ptr->call<void>("SDKKitPlateformCallBackImplWrapper_logoutCallBack", retStatus, s_retMessage);
}

void SDKKitPlateformCallBackImplWrapper_payCallBack(int retStatus, std::string s_retMessage,
        std::string s_loginUserId, std::string s_loginAuthToken, std::string s_loginServerId, std::string s_payKitOrderId)
{
    LOGD("call lua SDKKitPlateformCallBackImplWrapper_payCallBack");
    m_fflua_ptr->call<void>("SDKKitPlateformCallBackImplWrapper_payCallBack", retStatus, s_retMessage, s_loginUserId, s_loginAuthToken, s_loginServerId, s_payKitOrderId);
}

void SDKKitPlateformCallBackImplWrapper_getOrderResultCallBack(int retStatus, std::string s_retMessage)
{
    LOGD("call lua SDKKitPlateformCallBackImplWrapper_getOrderResultCallBack");
    m_fflua_ptr->call<void>("SDKKitPlateformCallBackImplWrapper_getOrderResultCallBack", retStatus, s_retMessage);
}

void SDKKitPlateformCallBackImplWrapper_exitGameCallBack(int retStatus, std::string s_retMessage)
{
    LOGD("call lua SDKKitPlateformCallBackImplWrapper_exitGameCallBack");
    m_fflua_ptr->call<void>("SDKKitPlateformCallBackImplWrapper_exitGameCallBack", retStatus, s_retMessage);
}


//////////////////////////////////////////////
void sdkkit_login()
{
    LOGD("sdkkit  login");

	//函数信息结构体
    sdkkit::JniMethodInfo minfo;

    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/hjr/sdkkit/sdknative/SDKKitPlateformBusinessImplWrapper",/*类的路径*/
                                                 "login",/*函数名*/
                                                 "()V");/*函数类型简写*/
    if (isHave)
    {
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
    }
}

std::string sdkkit_easy_get(std::map<std::string, std::string> dataMap, std::string key)
{
    std::map<std::string, std::string>::iterator ii = dataMap.find(key);
    if ( ii == dataMap.end() ) {
        return "";
    } else {
        return ii->second;
    }
}

void sdkkit_pay_ext(int payAmount, std::map<std::string, std::string> data)
{
    sdkkit_pay(payAmount, data["productId"], data["productName"], data["payProductNum"], data["payOrderId"], data["payServerId"],\
        data["payServerName"], data["payGameLevel"], data["payRoleId"], data["payRoleLevel"], data["payRoleName"], data["payUserId"],\
        data["payUserName"], data["payBlance"],data["extInfo"]);
}


void sdkkit_pay(int payAmount, std::string productId, std::string productName, std::string payProductNum,
			std::string payOrderId, std::string payServerId, std::string payServerName,
			std::string payGameLevel, std::string payRoleId, std::string payRoleLevel,
			std::string payRoleName, std::string payUserId, std::string payUserName,
			std::string payBlance, std::string extInfo)
{
    LOGD("sdkkit  pay");
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/hjr/sdkkit/sdknative/SDKKitPlateformBusinessImplWrapper",/*类的路径*/
                                                 "pay",/*函数名*/
                                                 "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/
    
    if (isHave)
    {
        jint j_payAmount = payAmount;
        jstring j_productId = minfo.env->NewStringUTF(productId.c_str());
        jstring j_productName = minfo.env->NewStringUTF(productName.c_str());
        jstring j_payProductNum = minfo.env->NewStringUTF(payProductNum.c_str());
        jstring j_payOrderId = minfo.env->NewStringUTF(payOrderId.c_str());
        jstring j_payServerId = minfo.env->NewStringUTF(payServerId.c_str());
        jstring j_payServerName = minfo.env->NewStringUTF(payServerName.c_str());
        jstring j_payGameLevel = minfo.env->NewStringUTF(payGameLevel.c_str());
        jstring j_payRoleId = minfo.env->NewStringUTF(payRoleId.c_str());
        jstring j_payRoleLevel = minfo.env->NewStringUTF(payRoleLevel.c_str());
        jstring j_payRoleName = minfo.env->NewStringUTF(payRoleName.c_str());
        jstring j_payUserId = minfo.env->NewStringUTF(payUserId.c_str());
        jstring j_payUserName = minfo.env->NewStringUTF(payUserName.c_str());
        jstring j_payBlance = minfo.env->NewStringUTF(payBlance.c_str());
        jstring j_extInfo = minfo.env->NewStringUTF(extInfo.c_str());

        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_payAmount,
            j_productId, j_productName, j_payProductNum, j_payOrderId, j_payServerId, j_payServerName, j_payGameLevel,
            j_payRoleId, j_payRoleLevel, j_payRoleName, j_payUserId, j_payUserName, j_payBlance, j_extInfo);
    }

}

void sdkkit_userCenter()
{
    LOGD("sdkkit  userCenter");
	//函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/hjr/sdkkit/sdknative/SDKKitPlateformBusinessImplWrapper",/*类的路径*/
                                                 "userCenter",/*函数名*/
                                                 "()V");/*函数类型简写*/
    
    if (isHave)
    {
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
    }

}

void sdkkit_logout()
{
    LOGD("sdkkit  logout");
	//函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/hjr/sdkkit/sdknative/SDKKitPlateformBusinessImplWrapper",/*类的路径*/
                                                 "logout",/*函数名*/
                                                 "()V");/*函数类型简写*/
    
    if (isHave)
    {
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
    }

}

void sdkkit_getOrderInfo(std::string payOrderId)
{
    LOGD("sdkkit  getOrderInfo %s", payOrderId.c_str());
	//函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/hjr/sdkkit/sdknative/SDKKitPlateformBusinessImplWrapper",/*类的路径*/
                                                 "getOrderInfo",/*函数名*/
                                                 "(Ljava/lang/String;)V");/*函数类型简写*/
    
    if (isHave)
    {
        jstring id = minfo.env->NewStringUTF(payOrderId.c_str());
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, id);
    }

}


void sdkkit_exitGame()
{
    LOGD("sdkkit  exitGame");
	//函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/hjr/sdkkit/sdknative/SDKKitPlateformBusinessImplWrapper",/*类的路径*/
                                                 "exitGame",/*函数名*/
                                                 "()V");/*函数类型简写*/
    
    if (isHave)
    {
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
    }

}

/////////////////////////////////////////////////////////

void sdkkit_onLogin(std::string userId, std::string serverId)
{
    LOGD("sdkkit  onLogin");
   //函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/hjr/sdkkit/sdknative/SDKKitPlatformCollectionsImplWrapper",/*类的路径*/
                                                 "onLogin",/*函数名*/
                                                 "(Ljava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/
    
    if (isHave)
    {
        jstring j_userId = minfo.env->NewStringUTF(userId.c_str());
        jstring j_serverId = minfo.env->NewStringUTF(serverId.c_str());
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_userId, j_serverId);
    }

}

void sdkkit_onPay(int amount, std::string serverId, std::string serverName,
            std::string userId, std::string roleId, std::string orderNumber,
            std::string roleGrade, std::string roleName, std::string productDesc);
{
    LOGD("sdkkit  onPay");
    //函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/hjr/sdkkit/sdknative/SDKKitPlatformCollectionsImplWrapper",/*类的路径*/
                                                 "onPay",/*函数名*/
                                                 "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/
    
    if (isHave)
    {
        jint j_amount = amount;
        jstring j_serverId = minfo.env->NewStringUTF(serverId.c_str());
        jstring j_serverName = minfo.env->NewStringUTF(serverName.c_str());
        jstring j_userId = minfo.env->NewStringUTF(userId.c_str());
        jstring j_roleId = minfo.env->NewStringUTF(roleId.c_str());
        jstring j_orderNumber = minfo.env->NewStringUTF(orderNumber.c_str());
        jstring j_roleGrade = minfo.env->NewStringUTF(roleGrade.c_str());
        jstring j_roleName = minfo.env->NewStringUTF(roleName.c_str());
        jstring j_productDesc = minfo.env->NewStringUTF(productDesc.c_str());
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_amount,
            j_serverId, j_serverName, j_userId, j_roleId, j_orderNumber,
            j_roleGrade, j_roleName, j_productDesc);
    }

}

void sdkkit_onUpgrade(std::string userId, std::string serverId,
            std::string roleGrade, std::string roleId, std::string roleName,
            std::string roleServerName);
{
    LOGD("sdkkit  onUpgrade");
    //函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/hjr/sdkkit/sdknative/SDKKitPlatformCollectionsImplWrapper",/*类的路径*/
                                                 "onUpgrade",/*函数名*/
                                                 "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/
    
    if (isHave)
    {
        jstring j_userId = minfo.env->NewStringUTF(userId.c_str());
        jstring j_serverId = minfo.env->NewStringUTF(serverId.c_str());
        jstring j_roleGrade = minfo.env->NewStringUTF(roleGrade.c_str());
        jstring j_roleId = minfo.env->NewStringUTF(roleId.c_str());
        jstring j_roleName = minfo.env->NewStringUTF(roleName.c_str());
        jstring j_roleServerName = minfo.env->NewStringUTF(roleServerName.c_str());
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_userId,
            j_serverId, j_roleGrade, j_roleId, j_roleName, j_roleServerName);
    }

}

void sdkkit_onServerRoleInfo(std::string roleId, std::string roleName, 
      int roleLevel, std::string serverId, std::string serverName, 
      std::string rolePartyName, std::string roleVipLevel);
{
    LOGD("sdkkit  onCreateRole");
   //函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/hjr/sdkkit/sdknative/SDKKitPlatformCollectionsImplWrapper",/*类的路径*/
                                                 "onCreateRole",/*函数名*/
                                                 "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/
    
    if (isHave)
    {
        jstring j_roleId = minfo.env->NewStringUTF(roleId.c_str());
        jstring j_roleName = minfo.env->NewStringUTF(roleName.c_str());
        jint j_roleLevel = roleLevel;
        jstring j_serverId = minfo.env->NewStringUTF(serverId.c_str());
        jstring j_serverName = minfo.env->NewStringUTF(serverName.c_str());
        jstring j_rolePartyName = minfo.env->NewStringUTF(rolePartyName.c_str());
        jstring j_roleVipLevel = minfo.env->NewStringUTF(roleVipLevel.c_str());
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_roleId,
            j_roleName, roleLevel, j_serverId, j_serverName, j_rolePartyName, j_roleVipLevel);
    }

}

void sdkkit_onButtonClick(std::string userId, std::string buttonName)
{
    LOGD("sdkkit  onButtonClick");
    //函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/hjr/sdkkit/sdknative/SDKKitPlatformCollectionsImplWrapper",/*类的路径*/
                                                 "onButtonClick",/*函数名*/
                                                 "(Ljava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/
    
    if (isHave)
    {
        jstring j_userId = minfo.env->NewStringUTF(userId.c_str());
        jstring j_buttonName = minfo.env->NewStringUTF(buttonName.c_str());
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_userId, j_buttonName);
    }

}

void sdkkit_onCreateRole(std::string userId, std::string roleId,
            std::string roleName, std::string serverId, std::string serverName)
{
    LOGD("sdkkit  onServerRoleInfo");
   //函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/hjr/sdkkit/sdknative/SDKKitPlatformCollectionsImplWrapper",/*类的路径*/
                                                 "onServerRoleInfo",/*函数名*/
                                                 "(Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/
    
    if (isHave)
    {
        jstring j_userId = minfo.env->NewStringUTF(userId.c_str());
        jstring j_roleId = minfo.env->NewStringUTF(roleId.c_str());
        jstring j_roleName = minfo.env->NewStringUTF(roleName.c_str());
        jstring j_serverId = minfo.env->NewStringUTF(serverId.c_str());
        jstring j_serverName = minfo.env->NewStringUTF(serverName.c_str());
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_userId, j_roleId,
            j_roleName, j_serverId, j_serverName);
    }

}


#ifdef __cplusplus
extern "C" {
#endif
/**
 * 初始化回调
 * @param retStatus
 * @param retMessage
 */
JNIEXPORT void JNICALL Java_com_hjr_sdkkit_sdknative_SDKKitPlateformCallBackImplWrapper_initCallBackJni(JNIEnv * env, jobject arg, jint retStatus, jstring retMessage)
{
    LOGD("Java_com_hjr_sdkkit_sdknative_SDKKitPlateformCallBackImplWrapper_initCallBack");
    std::string s_retMessage = sdkkit::JniHelper::jstring2string(retMessage);
    LOGD("Java_com_hjr_sdkkit_sdknative_SDKKitPlateformCallBackImplWrapper_initCallBack %s", s_retMessage.c_str());
    //LOGD(retStatus)
    //  LOGD(retMessage);
    SDKKitPlateformCallBackImplWrapper_initCallBack(retStatus, s_retMessage);
}

/**
 * 登录回调
 * @param response
 * @param retStatus
 * @param retMessage
 */
JNIEXPORT void JNICALL Java_com_hjr_sdkkit_sdknative_SDKKitPlateformCallBackImplWrapper_loginCallBackJni(JNIEnv * env, jobject arg, jint retStatus,
            jstring retMessage, jstring loginUserId, jstring loginUserName,
            jstring loginAuthToken, jstring loginOpenId)
{
    LOGD("Java_com_hjr_sdkkit_sdknative_SDKKitPlateformCallBackImplWrapper_loginCallBack");
    std::string s_retMessage = sdkkit::JniHelper::jstring2string(retMessage);
    std::string s_loginUserId = sdkkit::JniHelper::jstring2string(loginUserId);
    std::string s_loginUserName = sdkkit::JniHelper::jstring2string(loginUserName);
    std::string s_loginAuthToken = sdkkit::JniHelper::jstring2string(loginAuthToken);
    std::string s_loginOpenId = sdkkit::JniHelper::jstring2string(loginOpenId);

    SDKKitPlateformCallBackImplWrapper_loginCallBack(retStatus, s_retMessage, s_loginUserId, s_loginUserName, s_loginAuthToken, s_loginOpenId);

}

/**
 * 注销回调
 * @param response
 * @param retStatus
 * @param retMessage
 */
JNIEXPORT void JNICALL Java_com_hjr_sdkkit_sdknative_SDKKitPlateformCallBackImplWrapper_logoutCallBackJni(JNIEnv * env, jobject arg, jint retStatus, jstring retMessage)
{
    LOGD("Java_com_hjr_sdkkit_sdknative_SDKKitPlateformCallBackImplWrapper_logoutCallBack");
    std::string s_retMessage = sdkkit::JniHelper::jstring2string(retMessage);

    SDKKitPlateformCallBackImplWrapper_logoutCallBack(retStatus, s_retMessage);
}

//  /**
//   * 切换账户回调
//   * @param response
//   * @param retStatus
//   * @param retMessage
//   */
//  void switchAccountCallBack(SDKKitResponse response, int retStatus,String retMessage);

/**
 * 支付回调
 * @param response
 * @param retStatus
 * @param retMessage
 */
JNIEXPORT void JNICALL Java_com_hjr_sdkkit_sdknative_SDKKitPlateformCallBackImplWrapper_payCallBackJni(JNIEnv * env, jobject arg, jint retStatus, jstring retMessage,
            jstring payKitOrderId)
{
    LOGD("Java_com_hjr_sdkkit_sdknative_SDKKitPlateformCallBackImplWrapper_payCallBack");
    std::string s_retMessage = sdkkit::JniHelper::jstring2string(retMessage);
    std::string s_payKitOrderId = sdkkit::JniHelper::jstring2string(payKitOrderId);

    SDKKitPlateformCallBackImplWrapper_payCallBack(retStatus, s_retMessage,
        s_payKitOrderId);
}

//  void kitCenterCallBack(SDKKitResponse response, int retStatus,String retMessage);
//  
//  
//  void userCenterCallBack(SDKKitResponse response, int retStatus,String retMessage);

/**
 * 获取订单最终结果
 * @param response
 * @param retStatus
 * @param retMessage
 */
JNIEXPORT void JNICALL Java_com_hjr_sdkkit_sdknative_SDKKitPlateformCallBackImplWrapper_getOrderResultCallBackJni(JNIEnv * env, jobject arg, jint retStatus, jstring retMessage)
{
    LOGD("Java_com_hjr_sdkkit_sdknative_SDKKitPlateformCallBackImplWrapper_getOrderResultCallBack");
    std::string s_retMessage = sdkkit::JniHelper::jstring2string(retMessage);
    SDKKitPlateformCallBackImplWrapper_getOrderResultCallBack(retStatus, s_retMessage);

}

/**
 * 退出游戏
 * @param retStatus
 * @param retMessage
 */
JNIEXPORT void JNICALL Java_com_hjr_sdkkit_sdknative_SDKKitPlateformCallBackImplWrapper_exitGameCallBackJni(JNIEnv * env, jobject arg, jint retStatus, jstring retMessage)
{
    LOGD("Java_com_hjr_sdkkit_sdknative_SDKKitPlateformCallBackImplWrapper_exitGameCallBack");
    std::string s_retMessage = sdkkit::JniHelper::jstring2string(retMessage);
    LOGD("Java_com_hjr_sdkkit_sdknative_SDKKitPlateformCallBackImplWrapper_exitGameCallBack %s", s_retMessage.c_str());
    SDKKitPlateformCallBackImplWrapper_exitGameCallBack(retStatus, s_retMessage);
}

JNIEXPORT void JNICALL Java_com_hjr_sdkkit_sdknative_SDKKitPlatformJniHelper_nativeSetContextJni(JNIEnv * env, jobject thiz, jobject context)
 {
    static JavaVM *jvm;

    LOGD("Java_com_hjr_sdkkit_sdknative_SDKKitPlatformJniHelper_nativeSetContextJni");

    int status = env->GetJavaVM(&jvm);
    if(status != 0) {
        LOGE("getJavaVM error!!!!!");
    }

    sdkkit::JniHelper::setJavaVM(jvm);

    sdkkit::JniHelper::setClassLoaderFrom(context);

}

#ifdef __cplusplus
}
#endif

