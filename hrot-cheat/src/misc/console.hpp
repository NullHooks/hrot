#pragma once

namespace console {
    inline FILE *in, *out, *err;

    void initialize(const char* title);
    void release();
    void welcome();
}
