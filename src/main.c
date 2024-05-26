#include <raylib.h>
//#define RAYGUI_DEBUG_RECS_BOUNDS
//#define RAYGUI_DEBUG_TEXT_BOUNDS
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>
#undef RAYGUI_IMPLEMENTATION

#define GUI_WINDOW_FILE_DIALOG_IMPLEMENTATION
#include "gui_window_file_dialog.h"

GuiWindowFileDialogState p2_a_file_dialog;
GuiWindowFileDialogState p2_b_file_dialog;

#include "draw.h"
#include "p1.h"
#include "p2.h"

void (*views[])() = { draw_p1, draw_p2, 0 };

int main(void) {
    InitWindow(500, 800, "Things");
    SetTargetFPS(30);

    p2_a_file_dialog = InitGuiWindowFileDialog(GetWorkingDirectory());
    p2_b_file_dialog = InitGuiWindowFileDialog(GetWorkingDirectory());

    Font font = LoadFontEx("resources/default.ttf", 16, 0, 250);
    GuiSetFont(font);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 16);

    long view = 0;
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
