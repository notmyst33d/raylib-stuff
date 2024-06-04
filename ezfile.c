//usr/bin/cc -x c -O2 -Wall -lpthread -o .buildbin "$0" && ./.buildbin; exit

#define CC "clang"
#define USE_LD
#define LD "lld"
#include "ez.h"

char *compile_flags[] = { "-Wall", "-Iraylib/src", "-Iraygui/src", "-DPLATFORM_DESKTOP", 0 };
char *binary[] = { "-lm", "-lglfw", 0 };

#define cc(in, out) global_queue_cc(in, out, compile_flags)
#define ld global_queue_ld

void build_raylib(void) {
    cc("raylib/src/rcore.c", "out/raylib/rcore.o");
    cc("raylib/src/rshapes.c", "out/raylib/rshapes.o");
    cc("raylib/src/rtext.c", "out/raylib/rtext.o");
    cc("raylib/src/rtextures.c", "out/raylib/rtextures.o");
    cc("raylib/src/utils.c", "out/raylib/utils.o");
}

void build_main(void) {
    cc("src/main.c", "out/main.o");
}

void link_main(void) {
    ld("out/main", (char*[]){
        "out/main.o",
        "out/raylib/rcore.o",
        "out/raylib/rshapes.o",
        "out/raylib/rtext.o",
        "out/raylib/rtextures.o",
        "out/raylib/utils.o", 0
    }, binary);
}

int main(void) {
    ez_mkdir("out");
    ez_mkdir("out/raylib");

    global_queue_start();

    build_raylib();
    build_main();
    assert(global_queue_wait());

    link_main();
    assert(global_queue_wait());

    global_queue_shutdown();

    INFO("Done");
    return 0;
}
