// Copyright 2024 iLogtail Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "pipeline/compression/ZstdCompressor.h"
#include "unittest/Unittest.h"

using namespace std;

namespace logtail {

class ZstdCompressorUnittest : public ::testing::Test {
public:
    void TestCompress();
};

void ZstdCompressorUnittest::TestCompress() {
    ZstdCompressor compressor(CompressType::ZSTD);
    string input = "hello world";
    string output;
    string errorMsg;
    APSARA_TEST_TRUE(compressor.Compress(input, output, errorMsg));
    string decompressed;
    decompressed.resize(input.size());
    APSARA_TEST_TRUE(compressor.UnCompress(output, decompressed, errorMsg));
    APSARA_TEST_EQUAL(input, decompressed);
}

UNIT_TEST_CASE(ZstdCompressorUnittest, TestCompress)

} // namespace logtail

UNIT_TEST_MAIN