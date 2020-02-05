/*
 * Copyright (C) 2007 The Android Open Source Project
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
#pragma once

#include <sys/types.h>

#include <cstdint>

#include "Layer.h"

namespace android {

class ColorLayer : public Layer {
public:
    explicit ColorLayer(const LayerCreationArgs&);
    ~ColorLayer() override;

    sp<compositionengine::LayerFE> getCompositionEngineLayerFE() const override;
    compositionengine::LayerFECompositionState* editCompositionState() override;

    const char* getType() const override { return "ColorLayer"; }
    bool isVisible() const override;

    bool setColor(const half3& color) override;

    bool setDataspace(ui::Dataspace dataspace) override;

    ui::Dataspace getDataSpace() const override;

    bool isOpaque(const Layer::State& s) const override;

protected:
    /*
     * compositionengine::LayerFE overrides
     */
    const compositionengine::LayerFECompositionState* getCompositionState() const override;
    void preparePerFrameCompositionState() override;
    std::optional<compositionengine::LayerFE::LayerSettings> prepareClientComposition(
            compositionengine::LayerFE::ClientCompositionTargetSettings&) override;

    std::unique_ptr<compositionengine::LayerFECompositionState> mCompositionState;

    sp<Layer> createClone() override;
};

} // namespace android
