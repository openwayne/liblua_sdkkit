------------------------------------------------------------------------------------------------------------------------
function SDKKitPlateformCallBackImplWrapper_loginCallBack(retStatus, retMessage, loginUserId, loginAuthToken, cpId)
    print(retStatus, retMessage, loginUserId, loginAuthToken)
    return true
end

function SDKKitPlateformCallBackImplWrapper_logoutCallBack(retStatus, s_retMessage)
    print(retStatus, s_retMessage)
    return true
end

function SDKKitPlateformCallBackImplWrapper_payCallBack(retStatus, retMessage, loginUserId, loginAuthToken, loginServerId, payKitOrderId)
    print(retMessage, loginUserId, loginAuthToken, loginServerId, payKitOrderId)
    return true
end

function SDKKitPlateformCallBackImplWrapper_exitGameCallBack(retStatus, s_retMessage)
    print(retStatus, s_retMessage)
    return true
end

function SDKKitPlateformCallBackImplWrapper_getOrderResultCallBack(retStatus, s_retMessage)
    print(retStatus, s_retMessage)
    return true
end
------------------------------------------------------------------------------------------------------------------------
