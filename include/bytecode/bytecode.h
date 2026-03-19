#ifndef BYTECODE_H
#define BYTECODE_H

#include <cstdint>

namespace bytecode {

    enum class Opcodes : uint16_t {
        EDMW_IPv4   = 0x0000,
        EDMW_IPv6   = 0x0001,
        EDM         = 0x0002,
        HLT         = 0x0003,
    };

}

#endif
