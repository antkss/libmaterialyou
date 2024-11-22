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

#ifndef CPP_DYNAMICCOLOR_CONTRAST_CURVE_H_
#define CPP_DYNAMICCOLOR_CONTRAST_CURVE_H_

#include "utils.h"

namespace material_color_utilities {

/**
 * A class containing a value that changes with the contrast level.
 *
 * Usually represents the contrast requirements for a dynamic color on its
 * background. The four values correspond to values for contrast levels -1.0,
 * 0.0, 0.5, and 1.0, respectively.
 */
struct ContrastCurve {
  double low;
  double normal;
  double medium;
  double high;

  /**
   * Creates a `ContrastCurve` object.
   *
   * @param low Value for contrast level -1.0
   * @param normal Value for contrast level 0.0
   * @param medium Value for contrast level 0.5
   * @param high Value for contrast level 1.0
   */
  ContrastCurve(double low, double normal, double medium, double high)
      : low(low), normal(normal), medium(medium), high(high) {}

  /**
   * Returns the value at a given contrast level.
   *
   * @param contrastLevel The contrast level. 0.0 is the default (normal); -1.0
   *     is the lowest; 1.0 is the highest.
   * @return The value. For contrast ratios, a number between 1.0 and 21.0.
   */
  double get(double contrastLevel) {
    if (contrastLevel <= -1.0) {
      return low;
    } else if (contrastLevel < 0.0) {
      return Lerp(low, normal, (contrastLevel - (-1)) / 1);
    } else if (contrastLevel < 0.5) {
      return Lerp(normal, medium, (contrastLevel - 0) / 0.5);
    } else if (contrastLevel < 1.0) {
      return Lerp(medium, high, (contrastLevel - 0.5) / 0.5);
    } else {
      return high;
    }
  }
};

}  // namespace material_color_utilities

#endif  // CPP_DYNAMICCOLOR_CONTRAST_CURVE_H_
