# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

# first lib, which will be built statically
#
include $(CLEAR_VARS)

LOCAL_MODULE    := libtowlib-first
LOCAL_SRC_FILES := first.c

include $(BUILD_STATIC_LIBRARY)

# second lib, which will depend on and include the first one
#
include $(CLEAR_VARS)

LOCAL_MODULE    := testc
LOCAL_SRC_FILES := testc.c 

LOCAL_STATIC_LIBRARIES := libtowlib-first

include $(BUILD_SHARED_LIBRARY)


# third lib, --->>>HelloNDK.so
#
include $(CLEAR_VARS)

LOCAL_MODULE    := HelloNDK
LOCAL_SRC_FILES := HelloNDK.c 

include $(BUILD_SHARED_LIBRARY)

# fourth lib, --->>>NativeJniAdder.so
#
include $(CLEAR_VARS)

LOCAL_MODULE    := NativeJniAdder
LOCAL_SRC_FILES := NativeJniAdder.c Adder.c

include $(BUILD_SHARED_LIBRARY)

# fifth lib, --->>>CounterNative.so
#
include $(CLEAR_VARS)

LOCAL_MODULE    := CounterNative
LOCAL_SRC_FILES := CounterNative.c

include $(BUILD_SHARED_LIBRARY)

# sixth lib,  --->>>NativeGetFieldFromJava.so
#
include $(CLEAR_VARS)

LOCAL_MODULE    := NativeGetFieldFromJava
LOCAL_SRC_FILES := NativeGetFieldFromJava.c

include $(BUILD_SHARED_LIBRARY)

# seventh lib,  --->>>NativeGetFieldFromJava.so
#
include $(CLEAR_VARS)

LOCAL_MODULE    := encode
LOCAL_SRC_FILES := encode.c

include $(BUILD_SHARED_LIBRARY)
