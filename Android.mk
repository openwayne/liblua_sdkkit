LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := lua_sdkkit

LOCAL_MODULE_FILENAME := liblua_sdkkit

LOCAL_SRC_FILES :=  SdkkitJniHelper.cpp \
					sdkkit.cpp 

LOCAL_C_INCLUDES := $(LOCAL_PATH) \
					$(LOCAL_PATH)/../../../../external/lua/lua \


LOCAL_CXXFLAGS += -fexceptions
                    
include $(BUILD_STATIC_LIBRARY)
