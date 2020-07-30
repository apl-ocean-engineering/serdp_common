#pragma once

#include <memory>

#include <opencv2/core/core.hpp>

#include "serdp_common/DataStructures.h"
#include "draw_sonar/DrawSonar.h"

namespace serdp_common {

using namespace draw_sonar;

// Helper wrappers which convert liboculus::SimplePingResult to AbstractSonarInterface
inline cv::Size calculateImageSize( const liboculus::SimplePingResult &ping, cv::Size hint, int pixPerRangeBin = 2) {
  return draw_sonar::calculateImageSize( SimplePingResultInterface(ping), hint, pixPerRangeBin );
}

inline void drawSonar(const std::shared_ptr<liboculus::SimplePingResult> &ping, cv::Mat &mat, const SonarColorMap &colorMap=InfernoColorMap()) {
  draw_sonar::drawSonar( SimplePingResultInterface(*ping), mat, colorMap );
}

inline void drawSonar(const liboculus::SimplePingResult &ping, cv::Mat &mat, const SonarColorMap &colorMap = InfernoColorMap()) {
  draw_sonar::drawSonar( SimplePingResultInterface(ping), mat, colorMap);
}


} // namespace serdp_common
