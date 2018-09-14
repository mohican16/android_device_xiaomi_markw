/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_NDEBUG 0
#define LOG_TAG "FingerprintDaemonCallbackProxy"

#include <stdlib.h>
#include <utils/String16.h>
#include <utils/Log.h>
#include <hardware/hardware.h>
#include <hardware/hw_auth_token.h>
#include <hardware/fingerprint.h>
#include "FingerprintDaemonCallbackProxy.h"

using namespace android;

FingerprintDaemonCallbackProxy::FingerprintDaemonCallbackProxy()
        : mNotify(NULL) {
}

FingerprintDaemonCallbackProxy::~FingerprintDaemonCallbackProxy() {
}

status_t FingerprintDaemonCallbackProxy::setCallback(fingerprint_notify_t notify) {
    mNotify = notify;
    return OK;
}

status_t FingerprintDaemonCallbackProxy::notifyCallback(const fingerprint_msg_t* msg) {
    if (mNotify == NULL || msg == NULL) {
        ALOGE("notifyDevice mNotify or msg is NULL");
        return UNKNOWN_ERROR;
    }

    mNotify(msg);
    return OK;
}
