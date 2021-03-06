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

#ifndef FMI4CPP_FMUINSTANCE_HPP
#define FMI4CPP_FMUINSTANCE_HPP

#include <vector>
#include <memory>

#include "FmuVariableAccessor.hpp"

namespace fmi4cpp::fmi2 {
    
    template <typename T>
    class FmuInstance: public FmuVariableAccessor {

    protected:

        double simulationTime_ = 0.0;

        bool instantiated_ = false;
        bool terminated_ = false;

    public:

        const double getSimulationTime() const {
            return simulationTime_;
        }

        const bool isInstantiated() const {
            return instantiated_;
        }

        const bool isTerminated() const {
            return terminated_;
        }

        virtual std::shared_ptr<T> getModelDescription() const = 0;

        virtual void init(double start = 0, double stop = 0) = 0;

        virtual fmi2Status reset() = 0;

        virtual fmi2Status terminate() = 0;

        virtual fmi2Status getFMUstate(fmi2FMUstate &state) = 0;
        virtual fmi2Status setFMUstate(fmi2FMUstate state) = 0;
        virtual fmi2Status freeFMUstate(fmi2FMUstate &state) = 0;

        virtual fmi2Status serializeFMUstate(const fmi2FMUstate &state, std::vector<fmi2Byte> &serializedState) = 0;
        virtual fmi2Status deSerializeFMUstate(fmi2FMUstate &state, const std::vector<fmi2Byte> &serializedState) = 0;

        virtual fmi2Status getDirectionalDerivative(
                const std::vector<fmi2ValueReference> &vUnkownRef,
                const std::vector<fmi2ValueReference> &vKnownRef,
                const std::vector<fmi2Real> &dvKnownRef,
                std::vector<fmi2Real> &dvUnknownRef) const = 0;

        virtual ~FmuInstance() = default;

    };

}

#endif //FMI4CPP_FMUINSTANCE_HPP
