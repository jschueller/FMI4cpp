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

#ifndef FMI4CPP_FMUVARIABLEACCESSOR_HPP
#define FMI4CPP_FMUVARIABLEACCESSOR_HPP

#include <vector>
#include <string>

#include "../fmi2Functions.h"

namespace fmi4cpp::fmi2 {

    class FmuReader {

    public:

        virtual fmi2Status readInteger(fmi2ValueReference vr, fmi2Integer &ref) const = 0;
        virtual fmi2Status readInteger(const std::vector<fmi2ValueReference> &vr, std::vector<fmi2Integer> &ref) const = 0;

        virtual fmi2Status readReal(fmi2ValueReference vr, fmi2Real &ref) const = 0;
        virtual fmi2Status readReal(const std::vector<fmi2ValueReference> &vr, std::vector<fmi2Real> &ref) const = 0;

        virtual fmi2Status readString(fmi2ValueReference vr, fmi2String &ref) const = 0;
        virtual fmi2Status readString(const std::vector<fmi2ValueReference> &vr, std::vector<fmi2String> &ref) const = 0;

        virtual fmi2Status readBoolean(fmi2ValueReference vr, fmi2Boolean &ref) const = 0;
        virtual fmi2Status readBoolean(const std::vector<fmi2ValueReference> &vr, std::vector<fmi2Boolean > &ref) const = 0;

    };

    class FmuWriter {

    public:

        virtual fmi2Status writeInteger(fmi2ValueReference vr, fmi2Integer value) = 0;
        virtual fmi2Status writeInteger(const std::vector<fmi2ValueReference> &vr, const std::vector<fmi2Integer > &values) = 0;

        virtual fmi2Status writeReal(fmi2ValueReference vr, fmi2Real value) = 0;
        virtual fmi2Status writeReal(const std::vector<fmi2ValueReference> &vr, const std::vector<fmi2Real > &values) = 0;

        virtual fmi2Status writeString(fmi2ValueReference vr, fmi2String value) = 0;
        virtual fmi2Status writeString(const std::vector<fmi2ValueReference> &vr, const std::vector<fmi2String > &values) = 0;

        virtual fmi2Status writeBoolean(fmi2ValueReference vr, fmi2Boolean value) = 0;
        virtual fmi2Status writeBoolean(const std::vector<fmi2ValueReference> &vr, const std::vector<fmi2Boolean > &values) = 0;
    };
    
    class FmuVariableAccessor: public FmuReader, public FmuWriter {};
    
}

#endif //FMI4CPP_FMUVARIABLEACCESSOR_HPP
