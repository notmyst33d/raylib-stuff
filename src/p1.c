#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#define PADDING 16
#define WIDTH 48

int main(void) {
    InitWindow(500, 200, "P1");
    SetTargetFPS(30);

    char data[8][255] = { 0 };
    int active_table[5] = { 0 };
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        long row = 0;
        long column = 0;
        char *vars[][2] = { { data[0], "A1" }, { data[1], "B1" }, { data[2], "A2" }, { data[3], "B2" }, { data[4], "B3" } };
        for (int i = 0; i < 5; i++) {
            GuiLabel((Rectangle){ 16 + (PADDING * row) + (WIDTH * row), 16, 72, 12 }, vars[i][1]);
            if (GuiTextBox((Rectangle){ 16 + (PADDING * row) + (WIDTH * row), 32, WIDTH, 32 }, vars[i][0], 12, active_table[i])) active_table[i] = !active_table[i];
            row++;
        }

        GuiLabel((Rectangle){ 16, 72 + (PADDING * column), 72, 16 }, data[5]);
        column++;

        GuiLabel((Rectangle){ 16, 72 + (PADDING * column), 72, 16 }, data[6]);
        column++;

        GuiLabel((Rectangle){ 16, 72 + (PADDING * column), 72, 16 }, data[7]);
        column++;

        if (GuiButton((Rectangle){ 16 + (PADDING * row) + (WIDTH * row), 32, 72, 32 }, "Apply")) {
            int a1 = atoi(data[0]), b1 = atoi(data[1]), a2 = atoi(data[2]), b2 = atoi(data[3]), b3 = atoi(data[4]);
            int c1 = a1 + b2;
            int c2 = a2 * b2;
            int c3 = c2 * b3;
            sprintf(data[5], "C1 = %d", c1);
            sprintf(data[6], "C2 = %d", c2);
            sprintf(data[7], "C3 = %d", c3);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
