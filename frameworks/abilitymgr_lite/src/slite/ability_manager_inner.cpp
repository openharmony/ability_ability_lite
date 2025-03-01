/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ability_manager_inner.h"
#include "abilityms_slite_client.h"

StartCheckFunc CALLBACKFUNC = nullptr;
bool cleanAbilityDataFlag = false;

extern "C" {
int RegAbilityCallback(StartCheckFunc startCheckCallback)
{
    CALLBACKFUNC = startCheckCallback;
    return 0;
}

int SchedulerLifecycleDone(uint64_t token, int state)
{
    return OHOS::AbilitySlite::AbilityMsClient::GetInstance().SchedulerLifecycleDone(token, state);
}

int ForceStopBundle(uint64_t token)
{
    return OHOS::AbilitySlite::AbilityMsClient::GetInstance().ForceStopBundle(token);
}

int ForceStop(char *bundleName)
{
    return OHOS::AbilitySlite::AbilityMsClient::GetInstance().ForceStop(bundleName);
}

StartCheckFunc GetAbilityCallback()
{
    return CALLBACKFUNC;
}

void SetCleanAbilityDataFlag(bool cleanFlag)
{
    cleanAbilityDataFlag = cleanFlag;
}

bool GetCleanAbilityDataFlag()
{
    return cleanAbilityDataFlag;
}
}
