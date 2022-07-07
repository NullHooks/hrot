#include "main.hpp"

DWORD WINAPI MainThread(LPVOID hModule) {
    console::initialize("HROT cheat console");
    console::welcome();

    DWORD module_base = (DWORD)GetModuleHandle(NULL);
    
    int* base_ammo = (int*)(module_base + (DWORD)offsets::base_ammo);
    int* rifle_ammo = (int*)memory::ptr_from_offset((DWORD)base_ammo, (DWORD)4);

    printf("Base ammo: %p\n", base_ammo);

    // TODO: WndProc for key
    while (!GetAsyncKeyState(keys::unload_key)) {       // Continue until we press unload key
        // Show ammo
        if (GetAsyncKeyState(keys::show_ammo) & 1) {
            printf("\r                                                                                                \r|");  // Clear line
            for (int n = 0; n < 16; n++) {
                int* cur_ammo = (int*)memory::ptr_from_offset((DWORD)base_ammo, (DWORD)n);      // +4 is rifle ammo
                printf(" %d |", *cur_ammo);
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    console::release();
    FreeLibraryAndExitThread(static_cast<HMODULE>(hModule), 0);
    return 0;
}

bool WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved) {
    switch (dwReason) {
        case DLL_PROCESS_ATTACH:
            //MessageBoxA(NULL, "DLL injected to hrot successfully.", "Success!", MB_OK);
            CreateThread(nullptr, 0, MainThread, hModule, 0, nullptr);        // MainThread is the function
            break;
        default: break;
    }

    return true;
}
