/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
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

#ifndef OHOS_ABILITY_SLITE_DUMMY_JS_ABILITY_H
#define OHOS_ABILITY_SLITE_DUMMY_JS_ABILITY_H

#include "slite_ability.h"
#include "js_ability.h"

namespace OHOS {
namespace AbilitySlite {
class DummyJsAbility : public SliteAbility {
public:
    DummyJsAbility() = default;

    ~DummyJsAbility() override = default;

    void OnCreate(const Want &want) override;

    void OnForeground(const Want &want) override;

    void OnBackground() override;

    void OnDestroy() override;

    void HandleExtraMessage(const AbilityInnerMsg &innerMsg) override;

private:
    bool isBackground_ = false;
    ACELite::JSAbility jsAbility_;
};
} // namespace AbilitySlite
} // namespace OHOS





#endif // OHOS_ABILITY_SLITE_DUMMY_JS_ABILITY_H
