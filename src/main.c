#include <raylib.h>
//#define RAYGUI_DEBUG_RECS_BOUNDS
//#define RAYGUI_DEBUG_TEXT_BOUNDS
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>
#undef RAYGUI_IMPLEMENTATION

#define GUI_WINDOW_FILE_DIALOG_IMPLEMENTATION
#include "gui_window_file_dialog.h"

#define FILE_DIALOG_COUNT 6
GuiWindowFileDialogState file_dialog_table[FILE_DIALOG_COUNT] = { 0 };
#define p2_fd_a file_dialog_table[0]
#define p2_fd_b file_dialog_table[1]
#define p3_fd file_dialog_table[2]
#define p4_a_fd file_dialog_table[3]
#define p4_b_fd file_dialog_table[4]
#define p4_c_fd file_dialog_table[5]

#include "utils.h"
#include "draw.h"
#include "p1.h"
#include "p2.h"
#include "p3.h"
#include "p4.h"
#include "p6.h"
#include "p7.h"

void (*views[])() = { draw_p1, draw_p2, draw_p3, draw_p4, draw_p6, draw_p7, 0 };

int main(void) {
    InitWindow(500, 800, "Things");
    SetTargetFPS(30);

    for (int i = 0; i < FILE_DIALOG_COUNT; i++) {
        file_dialog_table[i] = InitGuiWindowFileDialog(GetWorkingDirectory());
    }

    Font font = LoadFontEx("resources/default.ttf", 16, 0, 0);
    GuiSetFont(font);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 16);

    int view = 0;
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        if (IsKeyPressed(KEY_LEFT) && view - 1 >= 0) {
            view -= 1;
        }
        if (IsKeyPressed(KEY_RIGHT) && views[view + 1] != 0) {
            view += 1;
        }

        views[view]();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
