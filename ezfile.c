//usr/bin/cc -x c -O2 -Wall -lpthread -o .buildbin "$0" && ./.buildbin; exit

#include "ez.h"

#define CC "clang"
#define LD "lld"

void cc(char *in, char *out) {
    Command *cmd = cmd_new();
    char message[512];

    sprintf(message, CC " %s", in);
    cmd_message(cmd, message);

    cmd_push(cmd, CC);
    cmd_push(cmd, "-Wall");
    cmd_push(cmd, "-Iraylib/src");
    cmd_push(cmd, "-Iraygui/src");
    cmd_push(cmd, "-DPLATFORM_DESKTOP");
    cmd_push(cmd, "-c");
    cmd_push(cmd, "-o");
    cmd_push(cmd, out);
    cmd_push(cmd, in);

    queue_push(&global_queue, cmd);
}

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

int link_main(void) {
    Command *cmd = cmd_new();
    cmd_push(cmd, CC);
    cmd_push(cmd, "-fuse-ld=" LD);
    cmd_push(cmd, "-lm");
    cmd_push(cmd, "-lglfw");
    cmd_push(cmd, "-o");
    cmd_push(cmd, "out/main");
    cmd_push(cmd, "out/main.o");
    cmd_push(cmd, "out/raylib/rcore.o");
    cmd_push(cmd, "out/raylib/rshapes.o");
    cmd_push(cmd, "out/raylib/rtext.o");
    cmd_push(cmd, "out/raylib/rtextures.o");
    cmd_push(cmd, "out/raylib/utils.o");
    assert(cmd_execute(cmd));
    cmd_free(cmd);
    return 0;
}

int main(void) {
    ez_mkdir("out");
    ez_mkdir("out/raylib");

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&thread_pool[i], 0, queue_worker, 0);
    }

    //build_raylib();
    build_main();

    while (global_queue.size > 0 && !fail) {
        usleep(1000);
    }
    queue_shutdown();
    if (fail) {
        ERROR("Compilation aborted");
        return -1;
    }

    assert(link_main());

    INFO("Done");
    return 0;
}
