/*
 * Copyright 2023 Google LLC
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

#include "scheme_rainbow.h"

#include "hct.h"
#include "dynamic_scheme.h"
#include "variant.h"
#include "tones.h"

namespace material_color_utilities {

SchemeRainbow::SchemeRainbow(Hct set_source_color_hct, bool set_is_dark,
                             double set_contrast_level)
    : DynamicScheme(
          /*set_source_color_hct:*/ set_source_color_hct,
          /*variant:*/ Variant::kRainbow,
          /*contrast_level:*/ set_contrast_level,
          /*is_dark:*/ set_is_dark,
          /*primary_palette:*/
          TonalPalette(set_source_color_hct.get_hue(), 48.0),
          /*secondary_palette:*/
          TonalPalette(set_source_color_hct.get_hue(), 16.0),
          /*tertiary_palette:*/
          TonalPalette(
              SanitizeDegreesDouble(set_source_color_hct.get_hue() + 60.0),
              24.0),
          /*neutral_palette:*/
          TonalPalette(set_source_color_hct.get_hue(), 0.0),
          /*neutral_variant_palette:*/
          TonalPalette(set_source_color_hct.get_hue(), 0.0)) {}

SchemeRainbow::SchemeRainbow(Hct set_source_color_hct, bool set_is_dark)
    : SchemeRainbow::SchemeRainbow(set_source_color_hct, set_is_dark, 0.0) {}

}  // namespace material_color_utilities
