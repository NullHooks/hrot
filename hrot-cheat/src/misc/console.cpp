#include "../main.hpp"
#include "console.hpp"

void console::initialize(const char* title) {
    AllocConsole();

    freopen_s(&in, "CONIN$", "r", stdin);
    freopen_s(&out, "CONOUT$", "w", stdout);
    freopen_s(&err, "CONOUT$", "w", stderr);

    SetConsoleTitleA(title);
}

void console::release() {
    fclose(in);
    fclose(out);
    fclose(err);

    FreeConsole();
}

void console::welcome() {
    // Fuck all that cout shit
    printf("Welcome to HROT cheats! Check my code at:\n");
    printf("\thttps://github.com/NullHooks/hrot\n");
}