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

#ifndef FMI4CPP_COSIMULATIONLIBRARY_HPP
#define FMI4CPP_COSIMULATIONLIBRARY_HPP

#include "FmiLibrary.hpp"

namespace fmi4cpp::fmi2 {

    class CoSimulationLibrary : public FmiLibrary {

    private:

        fmi2SetRealInputDerivativesTYPE *fmi2SetRealInputDerivatives_;
        fmi2GetRealOutputDerivativesTYPE *fmi2GetRealOutputDerivatives_;

        fmi2DoStepTYPE *fmi2DoStep_;
        fmi2CancelStepTYPE *fmi2CancelStep_;

        fmi2GetStatusTYPE *fmi2GetStatus_;
        fmi2GetRealStatusTYPE *fmi2GetRealStatus_;
        fmi2GetIntegerStatusTYPE *fmi2GetIntegerStatus_;
        fmi2GetBooleanStatusTYPE *fmi2GetBooleanStatus_;
        fmi2GetStringStatusTYPE *fmi2GetStringStatus_;

    public:

        explicit CoSimulationLibrary(const std::string &modelIdentifier, const std::shared_ptr<FmuResource> &resource);

        fmi2Status doStep(fmi2Component c, fmi2Real currentCommunicationPoint,
                          fmi2Real communicationStepSize, bool noSetFMUStatePriorToCurrentPoint) const;

        fmi2Status cancelStep(fmi2Component c) const;

        fmi2Status setRealInputDerivatives(fmi2Component c,
                                           const std::vector<fmi2ValueReference> &vr, const std::vector<fmi2Integer> &order,
                                           const std::vector<fmi2Real> &value) const;

        fmi2Status getRealOutputDerivatives(fmi2Component c,
                                            const std::vector<fmi2ValueReference> &vr, const std::vector<fmi2Integer> &order,
                                            std::vector<fmi2Real> &value) const;

        fmi2Status getStatus(fmi2Component c, fmi2StatusKind s, fmi2Status &value) const;

        fmi2Status getRealStatus(fmi2Component c, fmi2StatusKind s, fmi2Real &value) const;

        fmi2Status getIntegerStatus(fmi2Component c, fmi2StatusKind s, fmi2Integer &value) const;

        fmi2Status getBooleanStatus(fmi2Component c, fmi2StatusKind s, fmi2Boolean &value) const;

        fmi2Status getStringStatus(fmi2Component c, fmi2StatusKind s, fmi2String &value) const;

    };

}

#endif //FMI4CPP_COSIMULATIONLIBRARY_HPP
