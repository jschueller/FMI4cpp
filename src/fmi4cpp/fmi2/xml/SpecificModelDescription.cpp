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

#include <fmi4cpp/fmi2/xml/ModelDescription.hpp>
#include <fmi4cpp/fmi2/xml/SpecificModelDescription.hpp>

using namespace fmi4cpp::fmi2::xml;

template<class T>
CoSimulationModelDescription SpecificModelDescription<T>::asCoSimulationModelDescription() {
    return modelDescription_.asCoSimulationModelDescription();
}

template<class T>
ModelExchangeModelDescription SpecificModelDescription<T>::asModelExchangeModelDescription() {
    return modelDescription_.asModelExchangeModelDescription();
}

CoSimulationModelDescription::CoSimulationModelDescription(ModelDescription &md, const CoSimulationAttributes &data)
        : SpecificModelDescription<CoSimulationAttributes>(md, data) {};

bool CoSimulationModelDescription::canInterpolateInputs() const {
    return data_.canInterpolateInputs;
}

bool CoSimulationModelDescription::canRunAsynchronuously() const {
    return data_.canRunAsynchronuously;
}

bool CoSimulationModelDescription::canHandleVariableCommunicationStepSize() const {
    return data_.canHandleVariableCommunicationStepSize;
}

const unsigned int CoSimulationModelDescription::maxOutputDerivativeOrder() const {
    return data_.maxOutputDerivativeOrder;
}

ModelExchangeModelDescription::ModelExchangeModelDescription(ModelDescription &md, const ModelExchangeAttributes &data)
        : SpecificModelDescription(md, data) {};

bool ModelExchangeModelDescription::completedIntegratorStepNotNeeded() const {
    return data_.completedIntegratorStepNotNeeded;
}
