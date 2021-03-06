/*
 * The MIT License
 *
 * Copyright 2017-2018 Norwegian University of Technology
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <fmi4cpp/fmi2/import/CoSimulationSlave.hpp>

using namespace std;
using namespace fmi4cpp::fmi2;

CoSimulationSlave::CoSimulationSlave(const fmi2Component c,
                                     const shared_ptr<CoSimulationLibrary> &library,
                                     const shared_ptr<CoSimulationModelDescription> &modelDescription)
        : AbstractFmuInstance<CoSimulationLibrary, CoSimulationModelDescription>(c, library, modelDescription) {}

fmi2Status CoSimulationSlave::doStep(const double stepSize) {
    fmi2Status status = library_->doStep(c_, simulationTime_, stepSize, false);
    if (status == fmi2OK) {
        simulationTime_ += stepSize;
    }
    return status;
}

fmi2Status CoSimulationSlave::cancelStep() {
    return library_->cancelStep(c_);
}

shared_ptr<CoSimulationModelDescription> CoSimulationSlave::getModelDescription() const {
    return AbstractFmuInstance::getModelDescription();
}

void CoSimulationSlave::init(const double start, const double stop) {
    AbstractFmuInstance::init(start, stop);
}

fmi2Status CoSimulationSlave::reset() {
    return AbstractFmuInstance::reset();
}

fmi2Status CoSimulationSlave::terminate() {
    return AbstractFmuInstance::terminate();
}

fmi2Status CoSimulationSlave::getFMUstate(fmi2FMUstate &state) {
    return AbstractFmuInstance::getFMUstate(state);
}

fmi2Status CoSimulationSlave::setFMUstate(fmi2FMUstate state) {
    return AbstractFmuInstance::setFMUstate(state);
}

fmi2Status CoSimulationSlave::freeFMUstate(fmi2FMUstate &state) {
    return AbstractFmuInstance::freeFMUstate(state);
}

fmi2Status CoSimulationSlave::serializeFMUstate(const fmi2FMUstate &state, vector<fmi2Byte> &serializedState) {
    return AbstractFmuInstance::serializeFMUstate(state, serializedState);
}

fmi2Status CoSimulationSlave::deSerializeFMUstate(fmi2FMUstate &state, const vector<fmi2Byte> &serializedState) {
    return AbstractFmuInstance::deSerializeFMUstate(state, serializedState);
}

fmi2Status CoSimulationSlave::getDirectionalDerivative(const vector<fmi2ValueReference> &vUnkownRef,
                                                       const vector<fmi2ValueReference> &vKnownRef,
                                                       const vector<fmi2Real> &dvKnownRef,
                                                       vector<fmi2Real> &dvUnknownRef) const {
    return AbstractFmuInstance::getDirectionalDerivative(vUnkownRef, vKnownRef, dvKnownRef, dvUnknownRef);
}

fmi2Status CoSimulationSlave::readInteger(const fmi2ValueReference vr, fmi2Integer &ref) const {
    return AbstractFmuInstance::readInteger(vr, ref);
}

fmi2Status CoSimulationSlave::readInteger(const vector<fmi2ValueReference> &vr, vector<fmi2Integer> &ref) const {
    return AbstractFmuInstance::readInteger(vr, ref);
}

fmi2Status CoSimulationSlave::readReal(const fmi2ValueReference vr, fmi2Real &ref) const {
    return AbstractFmuInstance::readReal(vr, ref);
}

fmi2Status CoSimulationSlave::readReal(const vector<fmi2ValueReference> &vr, vector<fmi2Real> &ref) const {
    return AbstractFmuInstance::readReal(vr, ref);
}

fmi2Status CoSimulationSlave::readString(const fmi2ValueReference vr, fmi2String &ref) const {
    return AbstractFmuInstance::readString(vr, ref);
}

fmi2Status CoSimulationSlave::readString(const vector<fmi2ValueReference> &vr, vector<fmi2String> &ref) const {
    return AbstractFmuInstance::readString(vr, ref);
}

fmi2Status CoSimulationSlave::readBoolean(const fmi2ValueReference vr, fmi2Boolean &ref) const {
    return AbstractFmuInstance::readBoolean(vr, ref);
}

fmi2Status CoSimulationSlave::readBoolean(const vector<fmi2ValueReference> &vr, vector<fmi2Boolean> &ref) const {
    return AbstractFmuInstance::readBoolean(vr, ref);
}

fmi2Status CoSimulationSlave::writeInteger(const fmi2ValueReference vr, const fmi2Integer value) {
    return AbstractFmuInstance::writeInteger(vr, value);
}

fmi2Status
CoSimulationSlave::writeInteger(const vector<fmi2ValueReference> &vr, const vector<fmi2Integer> &values) {
    return AbstractFmuInstance::writeInteger(vr, values);
}

fmi2Status CoSimulationSlave::writeReal(const fmi2ValueReference vr, const fmi2Real value) {
    return AbstractFmuInstance::writeReal(vr, value);
}

fmi2Status CoSimulationSlave::writeReal(const vector<fmi2ValueReference> &vr, const vector<fmi2Real> &values) {
    return AbstractFmuInstance::writeReal(vr, values);
}

fmi2Status CoSimulationSlave::writeString(const fmi2ValueReference vr, fmi2String value) {
    return AbstractFmuInstance::writeString(vr, value);
}

fmi2Status
CoSimulationSlave::writeString(const vector<fmi2ValueReference> &vr, const vector<fmi2String> &values) {
    return AbstractFmuInstance::writeString(vr, values);
}

fmi2Status CoSimulationSlave::writeBoolean(const fmi2ValueReference vr, const fmi2Boolean value) {
    return AbstractFmuInstance::writeBoolean(vr, value);
}

fmi2Status CoSimulationSlave::writeBoolean(const vector<fmi2ValueReference> &vr, const vector<fmi2Boolean> &values) {
    return AbstractFmuInstance::writeBoolean(vr, values);
}
