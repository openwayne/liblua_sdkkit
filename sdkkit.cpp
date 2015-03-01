#include "SdkkitJniHelper.h"
#include "sdkkit.h"

#include <jni.h>
#include <iostream>
#include <map>

using namespace std;


#ifdef __ANDROID__
#include <android/log.h>
#endif

#define  LOG_TAG    "SDKKIT"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)


//////////////////////////////////////////////
void sdkkit_login();
void sdkkit_kitCenter();
void sdkkit_switchAccount();

void sdkkit_pay(int payAmount, std::string payRate, std::string payProductNum,
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

static fflua_t* m_fflua_ptr;

void initLuaFrame(lua_State* ls)
{
    m_fflua_ptr = new fflua(ls);
}

//////////////////////////////////////////////
void sdkkit_login()
{
    LOGD("sdkkit  login");

	//函数信息结构体
    sdkkit::JniMethodInfo minfo;

    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/gameworks/sdkkit/sdknative/GWPlateformBusinessImplWrapper",/*类的路径*/
                                                 "login",/*函数名*/
                                                 "()V");/*函数类型简写*/
    if (isHave)
    {
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
    }
}

void sdkkit_kitCenter()
{
    LOGD("sdkkit  kitCenter");

	//函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/gameworks/sdkkit/sdknative/GWPlateformBusinessImplWrapper",/*类的路径*/
                                                 "kitCenter",/*函数名*/
                                                 "()V");/*函数类型简写*/
    
    if (isHave)
    {
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
    }
}

void sdkkit_switchAccount()
{
    LOGD("sdkkit  switchAccount");
	//函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/gameworks/sdkkit/sdknative/GWPlateformBusinessImplWrapper",/*类的路径*/
                                                 "switchAccount",/*函数名*/
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


void sdkkit_pay(int payAmount, std::string productId, std::string productName, std::string payProductNum,
			std::string payOrderId, std::string payServerId, std::string payServerName,
			std::string payGameLevel, std::string payRoleId, std::string payRoleLevel,
			std::string payRoleName, std::string payUserId, std::string payUserName,
			std::string payBlance, std::string extInfo)
{
    LOGD("sdkkit  pay");
	//函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/gameworks/sdkkit/sdknative/GWPlateformBusinessImplWrapper",/*类的路径*/
                                                 "pay",/*函数名*/
                                                 "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/
    
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
                                                 "com/gameworks/sdkkit/sdknative/GWPlateformBusinessImplWrapper",/*类的路径*/
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
                                                 "com/gameworks/sdkkit/sdknative/GWPlateformBusinessImplWrapper",/*类的路径*/
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
                                                 "com/gameworks/sdkkit/sdknative/GWPlateformBusinessImplWrapper",/*类的路径*/
                                                 "getOrderInfo",/*函数名*/
                                                 "(Ljava/lang/String;)V");/*函数类型简写*/
    
    if (isHave)
    {
        jstring id = minfo.env->NewStringUTF(payOrderId.c_str());
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, id);
    }

}

void sdkkit_floatWindow(bool value)
{
    LOGD("sdkkit  floatWindow");
	//函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/gameworks/sdkkit/sdknative/GWPlateformBusinessImplWrapper",/*类的路径*/
                                                 "floatWindow",/*函数名*/
                                                 "(Z)V");/*函数类型简写*/
    
    if (isHave)
    {
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
    }

}

void sdkkit_exitGame()
{
    LOGD("sdkkit  exitGame");
	//函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/gameworks/sdkkit/sdknative/GWPlateformBusinessImplWrapper",/*类的路径*/
                                                 "exitGame",/*函数名*/
                                                 "()V");/*函数类型简写*/
    
    if (isHave)
    {
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
    }

}

/////////////////////////////////////////////////////////

void sdkkit_onLogin(std::string userMark, std::string userType,
            std::string serverNo, std::string roleServerName)
{
    LOGD("sdkkit  onLogin");
   //函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/gameworks/sdkkit/sdknative/GWPlatformCollectionsImplWrapper",/*类的路径*/
                                                 "onLogin",/*函数名*/
                                                 "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/
    
    if (isHave)
    {
        jstring j_userMark = minfo.env->NewStringUTF(userMark.c_str());
        jstring j_userType = minfo.env->NewStringUTF(userType.c_str());
        jstring j_serverNo = minfo.env->NewStringUTF(serverNo.c_str());
        jstring j_roleServerName = minfo.env->NewStringUTF(roleServerName.c_str());
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_userMark,
            j_userType, j_serverNo, j_roleServerName);
    }

}

void sdkkit_onPay(int amount, std::string serverNo, std::string userMark,
            std::string roleMark, std::string orderNumber, std::string upgrade,
            std::string productDesc, std::string roleName, std::string roleServerName)
{
    LOGD("sdkkit  onPay");
    //函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/gameworks/sdkkit/sdknative/GWPlatformCollectionsImplWrapper",/*类的路径*/
                                                 "onPay",/*函数名*/
                                                 "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/
    
    if (isHave)
    {
        jint j_amount = amount;
        jstring j_serverNo = minfo.env->NewStringUTF(serverNo.c_str());
        jstring j_userMark = minfo.env->NewStringUTF(userMark.c_str());
        jstring j_roleMark = minfo.env->NewStringUTF(roleMark.c_str());
        jstring j_orderNumber = minfo.env->NewStringUTF(orderNumber.c_str());
        jstring j_upgrade = minfo.env->NewStringUTF(upgrade.c_str());
        jstring j_productDesc = minfo.env->NewStringUTF(productDesc.c_str());
        jstring j_roleName = minfo.env->NewStringUTF(roleName.c_str());
        jstring j_roleServerName = minfo.env->NewStringUTF(roleServerName.c_str());
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_amount,
            j_serverNo, j_userMark, j_roleMark, j_orderNumber, j_upgrade,
            j_productDesc, j_roleName, j_roleServerName);
    }

}

void sdkkit_onUpgrade(std::string userMark, std::string serverNo,
            std::string upgrade, std::string roleId, std::string roleName,
            std::string roleServerName)
{
    LOGD("sdkkit  onUpgrade");
    //函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/gameworks/sdkkit/sdknative/GWPlatformCollectionsImplWrapper",/*类的路径*/
                                                 "onUpgrade",/*函数名*/
                                                 "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/
    
    if (isHave)
    {
        jstring j_userMark = minfo.env->NewStringUTF(userMark.c_str());
        jstring j_serverNo = minfo.env->NewStringUTF(serverNo.c_str());
        jstring j_upgrade = minfo.env->NewStringUTF(upgrade.c_str());
        jstring j_roleId = minfo.env->NewStringUTF(roleId.c_str());
        jstring j_roleName = minfo.env->NewStringUTF(roleName.c_str());
        jstring j_roleServerName = minfo.env->NewStringUTF(roleServerName.c_str());
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_userMark,
            j_serverNo, j_upgrade, j_roleId, j_roleName, j_roleServerName);
    }

}

void sdkkit_onCreateRole(std::string userMark, std::string roleMark,
            std::string serverNo, std::string roleName)
{
    LOGD("sdkkit  onCreateRole");
   //函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/gameworks/sdkkit/sdknative/GWPlatformCollectionsImplWrapper",/*类的路径*/
                                                 "onCreateRole",/*函数名*/
                                                 "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/
    
    if (isHave)
    {
        jstring j_userMark = minfo.env->NewStringUTF(userMark.c_str());
        jstring j_roleMark = minfo.env->NewStringUTF(roleMark.c_str());
        jstring j_serverNo = minfo.env->NewStringUTF(serverNo.c_str());
        jstring j_roleName = minfo.env->NewStringUTF(roleName.c_str());
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_userMark,
            j_roleMark, j_serverNo, j_roleName);
    }

}

void sdkkit_onButtonClick(std::string name, std::string userMark)
{
    LOGD("sdkkit  onButtonClick");
    //函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/gameworks/sdkkit/sdknative/GWPlatformCollectionsImplWrapper",/*类的路径*/
                                                 "onButtonClick",/*函数名*/
                                                 "(Ljava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/
    
    if (isHave)
    {
        jstring j_name = minfo.env->NewStringUTF(name.c_str());
        jstring j_userMark = minfo.env->NewStringUTF(userMark.c_str());
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_name, j_userMark);
    }

}

void sdkkit_onServerRoleInfo(std::string roleId, int roleLevel,
            std::string roleName, std::string rolePartyName, std::string roleVipLevel)
{
    LOGD("sdkkit  onServerRoleInfo");
   //函数信息结构体
    sdkkit::JniMethodInfo minfo;
    bool isHave = sdkkit::JniHelper::getStaticMethodInfo(minfo,/*sdkkit::JniMethodInfo的引用*/
                                                 "com/gameworks/sdkkit/sdknative/GWPlatformCollectionsImplWrapper",/*类的路径*/
                                                 "onServerRoleInfo",/*函数名*/
                                                 "(Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");/*函数类型简写*/
    
    if (isHave)
    {
        jstring j_roleId = minfo.env->NewStringUTF(roleId.c_str());
        jint j_roleLevel = roleLevel;
        jstring j_roleName = minfo.env->NewStringUTF(roleName.c_str());
        jstring j_rolePartyName = minfo.env->NewStringUTF(rolePartyName.c_str());
        jstring j_roleVipLevel = minfo.env->NewStringUTF(roleVipLevel.c_str());
        //CallStaticVoidMethod调用java函数，并把返回值赋值给activityObj
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, j_roleId, j_roleLevel,
            j_roleName, j_rolePartyName, j_roleVipLevel);
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
JNIEXPORT void JNICALL Java_com_gameworks_sdkkit_sdknative_GWSDKKitPlateformCallBackImplWrapper_initCallBackJni(JNIEnv * env, jobject arg, jint retStatus, jstring retMessage)
{
    LOGD("Java_com_gameworks_sdkkit_sdknative_GWSDKKitPlateformCallBackImplWrapper_initCallBack");
    std::string s_retMessage = sdkkit::JniHelper::jstring2string(retMessage);
    LOGD("Java_com_gameworks_sdkkit_sdknative_GWSDKKitPlateformCallBackImplWrapper_initCallBack %s", s_retMessage.c_str());
    //LOGD(retStatus)
    //  LOGD(retMessage);
    //sdkkit_fflua->call<bool>("GWSDKKitPlateformCallBackImplWrapper_initCallBack", retStatus, retMessage);
    SDKKitPlateformCallBackImplWrapper_initCallBack(retStatus, s_retMessage);
}

/**
 * 登录回调
 * @param response
 * @param retStatus
 * @param retMessage
 */
JNIEXPORT void JNICALL Java_com_gameworks_sdkkit_sdknative_GWSDKKitPlateformCallBackImplWrapper_loginCallBackJni(JNIEnv * env, jobject arg, jint retStatus,
            jstring retMessage, jstring loginUserId, jstring loginAuthToken, jstring cpId)
{
    LOGD("Java_com_gameworks_sdkkit_sdknative_GWSDKKitPlateformCallBackImplWrapper_loginCallBack");
    std::string s_retMessage = sdkkit::JniHelper::jstring2string(retMessage);
    std::string s_loginUserId = sdkkit::JniHelper::jstring2string(loginUserId);
    std::string s_loginAuthToken = sdkkit::JniHelper::jstring2string(loginAuthToken);
    std::string s_cpId = sdkkit::JniHelper::jstring2string(cpId);
    SDKKitPlateformCallBackImplWrapper_loginCallBack(retStatus, s_retMessage, s_loginUserId, s_loginAuthToken, s_cpId);

}

/**
 * 注销回调
 * @param response
 * @param retStatus
 * @param retMessage
 */
JNIEXPORT void JNICALL Java_com_gameworks_sdkkit_sdknative_GWSDKKitPlateformCallBackImplWrapper_logoutCallBackJni(JNIEnv * env, jobject arg, jint retStatus, jstring retMessage)
{
    LOGD("Java_com_gameworks_sdkkit_sdknative_GWSDKKitPlateformCallBackImplWrapper_logoutCallBack");
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
JNIEXPORT void JNICALL Java_com_gameworks_sdkkit_sdknative_GWSDKKitPlateformCallBackImplWrapper_payCallBackJni(JNIEnv * env, jobject arg, jint retStatus, jstring retMessage,
            jstring loginUserId, jstring loginAuthToken, jstring loginServerId,
            jstring payKitOrderId)
{
    LOGD("Java_com_gameworks_sdkkit_sdknative_GWSDKKitPlateformCallBackImplWrapper_payCallBack");
    std::string s_retMessage = sdkkit::JniHelper::jstring2string(retMessage);
    std::string s_loginUserId = sdkkit::JniHelper::jstring2string(loginUserId);
    std::string s_loginAuthToken = sdkkit::JniHelper::jstring2string(loginAuthToken);
    std::string s_loginServerId = sdkkit::JniHelper::jstring2string(loginServerId);
    std::string s_payKitOrderId = sdkkit::JniHelper::jstring2string(payKitOrderId);

    SDKKitPlateformCallBackImplWrapper_payCallBack(retStatus, s_retMessage,
        s_loginUserId, s_loginAuthToken, s_loginServerId, s_payKitOrderId);
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
JNIEXPORT void JNICALL Java_com_gameworks_sdkkit_sdknative_GWSDKKitPlateformCallBackImplWrapper_getOrderResultCallBackJni(JNIEnv * env, jobject arg, jint retStatus, jstring retMessage)
{
    LOGD("Java_com_gameworks_sdkkit_sdknative_GWSDKKitPlateformCallBackImplWrapper_getOrderResultCallBack");
    std::string s_retMessage = sdkkit::JniHelper::jstring2string(retMessage);
    SDKKitPlateformCallBackImplWrapper_getOrderResultCallBack(retStatus, s_retMessage);

}

/**
 * 退出游戏
 * @param retStatus
 * @param retMessage
 */
JNIEXPORT void JNICALL Java_com_gameworks_sdkkit_sdknative_GWSDKKitPlateformCallBackImplWrapper_exitGameCallBackJni(JNIEnv * env, jobject arg, jint retStatus, jstring retMessage)
{
    LOGD("Java_com_gameworks_sdkkit_sdknative_GWSDKKitPlateformCallBackImplWrapper_exitGameCallBack");
    std::string s_retMessage = sdkkit::JniHelper::jstring2string(retMessage);
    LOGD("Java_com_gameworks_sdkkit_sdknative_GWSDKKitPlateformCallBackImplWrapper_exitGameCallBack %s", s_retMessage.c_str());
    SDKKitPlateformCallBackImplWrapper_exitGameCallBack(retStatus, s_retMessage);
}

JNIEXPORT void JNICALL Java_com_gameworks_sdkkit_sdknative_GWPlatformJniHelper_nativeSetContextJni(JNIEnv * env, jobject thiz, jobject context)
 {
    static JavaVM *jvm;

    LOGD("Java_com_gameworks_sdkkit_sdknative_GWPlatformJniHelper_nativeSetContextJni");

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

