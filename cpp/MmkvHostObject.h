//
//  MmkvHostObject.h
//  Mmkv
//
//  Created by Marc Rousavy on 03.09.21.
//  Copyright © 2021 Facebook. All rights reserved.
//

#pragma once

#include "NativeMmkvModule.h"
#include <jsi/jsi.h>

#if __has_include("MMKV.h")
#include "MMKV.h"
#else
#include <MMKVCore/MMKV.h>
#endif

using namespace facebook;
using namespace mmkv;

class MmkvHostObject : public jsi::HostObject {
public:
  MmkvHostObject(const facebook::react::MMKVConfig& config);
  ~MmkvHostObject();

public:
  jsi::Value get(jsi::Runtime&, const jsi::PropNameID& name) override;
  std::vector<jsi::PropNameID> getPropertyNames(jsi::Runtime& rt) override;

private:
  static MMKVMode getMMKVMode(const facebook::react::MMKVConfig& config);

private:
  MMKV* instance;
};
