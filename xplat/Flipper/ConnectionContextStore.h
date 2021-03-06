/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the LICENSE
 * file in the root directory of this source tree.
 */
#pragma once

#include <string>
#include <folly/io/async/SSLContext.h>
#include <folly/dynamic.h>
#include "FlipperInitConfig.h"

using namespace folly;

namespace facebook {
namespace flipper {

class ConnectionContextStore {

public:
  ConnectionContextStore(DeviceData deviceData);
  bool hasRequiredFiles();
  std::string createCertificateSigningRequest();
  std::shared_ptr<SSLContext> getSSLContext();
  std::string getCertificateDirectoryPath();
  std::string getDeviceId();
  void storeConnectionConfig(folly::dynamic& config);

 private:
  DeviceData deviceData_;

  std::string absoluteFilePath(const char* filename);
  bool resetFlipperDir();
};

} // namespace flipper
} // namespace facebook
