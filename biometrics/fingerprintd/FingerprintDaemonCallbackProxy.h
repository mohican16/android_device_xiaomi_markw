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

#ifndef FINGERPRINT_DAEMON_CALLBACK_PROXY_H_
#define FINGERPRINT_DAEMON_CALLBACK_PROXY_H_

#include <hardware/fingerprint.h>
#include "IFingerprintDaemonCallback.h"

namespace android {

class FingerprintDaemonCallbackProxy: public BnFingerprintDaemonCallback {
public:
    FingerprintDaemonCallbackProxy();
    virtual ~FingerprintDaemonCallbackProxy();

    status_t setCallback(fingerprint_notify_t notify);

    status_t notifyCallback(const fingerprint_msg_t* msg);
private:
    static fingerprint_notify_t mNotify;
};

}

#endif // FINGERPRINT_DAEMON_CALLBACK_PROXY_H_
