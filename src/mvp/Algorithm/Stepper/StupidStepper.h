/// \file StupidStepper.h
///
/// Defines a stupid stepper
///
/// TODO: Write something here
///

#ifndef __MVP_ALGORITHM_STUPIDSTEPPER_H__
#define __MVP_ALGORITHM_STUPIDSTEPPER_H__

#include <mvp/Algorithm/Stepper.h>

namespace mvp {
namespace algorithm {

struct StupidStepper : public Stepper {
  int m_memvar;

  StupidStepper(int memvar) : m_memvar(memvar) {}

  virtual void zing(int a, int b) {
    std::cout << "StupidSteper::zing(" << a << ", " << b << std::endl;
    std::cout << "memvar: " << m_memvar << std::endl;
  }

  virtual int zap(int a) {
    std::cout << "StupidStepper::zap(" << a << std::endl;
    std::cout << "memvar: " << m_memvar << std::endl;
    return 5;
  }
}; 

}}

#endif