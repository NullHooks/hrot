#include "main.hpp"

DWORD WINAPI MainThread(LPVOID hModule) {
    console::initialize("HROT cheat console");
    console::welcome();

    DWORD module_base = (DWORD)GetModuleHandle(reinterpret_cast<LPCWSTR>("hrot.exe"));
    
    int* ammo = (int*)module_base + offsets::pistol_ammo;

    // TODO: WndProc for key
    while (!GetAsyncKeyState(keys::unload_key)) {       // Continue until we press unload key
        if (GetAsyncKeyState(keys::show_ammo) & 1)
            printf("%d", *ammo);
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
