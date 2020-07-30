#pragma once

#include <stdint.h>
#include <math.h>
#include <vector>

#include "liboculus/SimplePingResult.h"
#include "draw_sonar/DataStructures.h"

namespace serdp_common {

using namespace liboculus;

struct SimplePingResultInterface : public draw_sonar::AbstractSonarInterface {

  SimplePingResultInterface( const SimplePingResult &ping )
    : _ping(ping) {;}

  virtual int nBearings() const { return _ping.bearings().size(); }
  virtual float bearing( int n ) const { return _ping.bearings().at(n) * M_PI/180; }

  virtual int nRanges() const { return _ping.oculusPing()->nRanges; }
  virtual float range( int n ) const { return _ping.oculusPing()->rangeResolution * n; }

  virtual uint8_t intensity( int i ) const { return _ping.image().at( i % nBearings(), floor(i/nBearings()) ); }

  const SimplePingResult &_ping;
};


} // namespace serdp_common
