#pragma once

namespace memory {
    DWORD ptr_from_offset(DWORD ptr, DWORD offset);
    DWORD ptr_from_offset(DWORD ptr, std::vector<DWORD> offsets);
}
