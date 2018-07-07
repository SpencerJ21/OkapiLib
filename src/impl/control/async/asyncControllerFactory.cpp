/**
 * @author Ryan Benasutti, WPI
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "okapi/impl/control/async/asyncControllerFactory.hpp"
#include "okapi/impl/control/util/settledUtilFactory.hpp"
#include "okapi/impl/filter/velMathFactory.hpp"

namespace okapi {
AsyncPosIntegratedController AsyncControllerFactory::posIntegrated(Motor imotor) {
  return AsyncPosIntegratedController(std::make_shared<Motor>(imotor),
                                      SettledUtilFactory::createPtr());
}

AsyncPosIntegratedController AsyncControllerFactory::posIntegrated(MotorGroup imotor) {
  return AsyncPosIntegratedController(std::make_shared<MotorGroup>(imotor),
                                      SettledUtilFactory::createPtr());
}

AsyncVelIntegratedController AsyncControllerFactory::velIntegrated(Motor imotor) {
  return AsyncVelIntegratedController(std::make_shared<Motor>(imotor),
                                      SettledUtilFactory::createPtr());
}

AsyncVelIntegratedController AsyncControllerFactory::velIntegrated(MotorGroup imotor) {
  return AsyncVelIntegratedController(std::make_shared<MotorGroup>(imotor),
                                      SettledUtilFactory::createPtr());
}

AsyncPosPIDController AsyncControllerFactory::posPID(Motor imotor, const double ikP,
                                                     const double ikI, const double ikD,
                                                     const double ikBias) {
  return AsyncPosPIDController(imotor.getEncoder(), std::make_shared<Motor>(imotor), ikP, ikI, ikD,
                               ikBias);
}

AsyncPosPIDController AsyncControllerFactory::posPID(MotorGroup imotor, const double ikP,
                                                     const double ikI, const double ikD,
                                                     const double ikBias) {
  return AsyncPosPIDController(imotor.getEncoder(), std::make_shared<MotorGroup>(imotor), ikP, ikI,
                               ikD, ikBias);
}

AsyncPosPIDController AsyncControllerFactory::posPID(std::shared_ptr<ControllerInput> iinput,
                                                     std::shared_ptr<ControllerOutput> ioutput,
                                                     const double ikP, const double ikI,
                                                     const double ikD, const double ikBias) {
  return AsyncPosPIDController(iinput, ioutput, ikP, ikI, ikD, ikBias);
}

AsyncVelPIDController AsyncControllerFactory::velPID(Motor imotor, const double ikP,
                                                     const double ikD, const double ikF,
                                                     const double iTPR) {
  return AsyncVelPIDController(imotor.getEncoder(), std::make_shared<Motor>(imotor), ikP, ikD, ikF,
                               VelMathFactory::createPtr(iTPR));
}

AsyncVelPIDController AsyncControllerFactory::velPID(MotorGroup imotor, const double ikP,
                                                     const double ikD, const double ikF,
                                                     const double iTPR) {
  return AsyncVelPIDController(imotor.getEncoder(), std::make_shared<MotorGroup>(imotor), ikP, ikD,
                               ikF, VelMathFactory::createPtr(iTPR));
}

AsyncVelPIDController AsyncControllerFactory::velPID(std::shared_ptr<ControllerInput> iinput,
                                                     std::shared_ptr<ControllerOutput> ioutput,
                                                     const double ikP, const double ikD,
                                                     const double ikF, const double iTPR) {
  return AsyncVelPIDController(iinput, ioutput, ikP, ikD, ikF, VelMathFactory::createPtr(iTPR));
}
} // namespace okapi
