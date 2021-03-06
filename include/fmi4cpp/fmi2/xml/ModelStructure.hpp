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

#ifndef FMI4CPP_MODELSTRUCTURE_HPP
#define FMI4CPP_MODELSTRUCTURE_HPP

#include <string>
#include <vector>
#include <optional>

#include "../fmi2TypesPlatform.h"

namespace fmi4cpp::fmi2 {

    class Unknown {

    private:

        unsigned int index_;
        std::optional<std::string> dependenciesKind_;
        std::optional<std::vector<unsigned int >> dependencies_;

    public:

        Unknown(unsigned int index, const std::optional<std::string> &dependenciesKind,
                const std::optional<std::vector<unsigned int>> &dependencies);

        const size_t index();
        const std::optional<std::string> dependenciesKind();
        const std::optional<std::vector<unsigned int >> &dependencies() const;

    };

    class ModelStructure {

    private:

        std::vector<Unknown> outputs_;
        std::vector<Unknown> derivatives_;
        std::vector<Unknown> initialUnknowns_;
        
    public:

        ModelStructure() = default;

        ModelStructure(const std::vector<Unknown> &outputs_, const std::vector<Unknown> &derivatives_,
                       const std::vector<Unknown> &initialUnknowns_);

        const std::vector<Unknown> &outputs() const;

        const std::vector<Unknown> &derivatives() const;

        const std::vector<Unknown> &initialUnknowns() const;

    };

}

#endif //FMI4CPP_MODELSTRUCTURE_HPP
