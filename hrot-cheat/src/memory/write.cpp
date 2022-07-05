#include "../main.hpp"
#include "write.hpp"

DWORD memory::ptr_from_offset(DWORD ptr, DWORD offset) {
    DWORD address = ptr;

    address = *(DWORD*)address;     // Cast as DWORD pointer and dereference to get the actual address
    address += offset;              // Add offset to address

    return address;
}

// Just overflow bro
DWORD memory::ptr_from_offset(DWORD ptr, std::vector<DWORD> offsets) {
    DWORD address = ptr;

    // We loop every offset and add it to the address
    for (int n = 0; n < offsets.size(); n++) {
        address = *(DWORD*)address;     // Cast as DWORD pointer and dereference to get the actual address
        address += offsets[n];          // Add offset to address
    }

    return address;
}