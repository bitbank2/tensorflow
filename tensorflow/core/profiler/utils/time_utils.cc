/* Copyright 2020 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "tensorflow/core/profiler/utils/time_utils.h"

#include "absl/time/clock.h"

namespace tensorflow {
namespace profiler {

uint64 GetCurrentTimeNanos() {
  // absl::GetCurrentTimeNanos() is much faster than EnvTime::NowNanos().
  // It is wrapped under tensorflow::profiler::GetCurrentTimeNanos to avoid ODR
  // violation and to allow switching to yet another implementation if required.
  return absl::GetCurrentTimeNanos();
}

}  // namespace profiler
}  // namespace tensorflow
