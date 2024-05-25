#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#define BUTTON_SIZE 64
#define INPUT_HEIGHT 40
#define ROWS 5
#define COLUMNS 3

int main(void) {
    InitWindow(BUTTON_SIZE * COLUMNS, BUTTON_SIZE * ROWS + INPUT_HEIGHT, "Calculator");
    SetTargetFPS(30);

    char text[64];
    long text_position = 0;
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
        GuiTextBox((Rectangle){ 0, 0, BUTTON_SIZE * COLUMNS, INPUT_HEIGHT }, text, 0, false);

        long row = 0;
        if (GuiButton((Rectangle){ 0, (BUTTON_SIZE * row) + INPUT_HEIGHT, BUTTON_SIZE, BUTTON_SIZE }, "1")) {
            text[text_position++] = '1';
            text[text_position] = 0;
        }
        if (GuiButton((Rectangle){ BUTTON_SIZE, (BUTTON_SIZE * row) + INPUT_HEIGHT, BUTTON_SIZE, BUTTON_SIZE }, "2")) {
            text[text_position++] = '2';
            text[text_position] = 0;
        }
        if (GuiButton((Rectangle){ BUTTON_SIZE * 2, (BUTTON_SIZE * row) + INPUT_HEIGHT, BUTTON_SIZE, BUTTON_SIZE }, "3")) {
            text[text_position++] = '3';
            text[text_position] = 0;
        }
        row++;

        if (GuiButton((Rectangle){ 0, (BUTTON_SIZE * row) + INPUT_HEIGHT, BUTTON_SIZE, BUTTON_SIZE }, "4")) {
            text[text_position++] = '4';
            text[text_position] = 0;
        }
        if (GuiButton((Rectangle){ BUTTON_SIZE, (BUTTON_SIZE * row) + INPUT_HEIGHT, BUTTON_SIZE, BUTTON_SIZE }, "5")) {
            text[text_position++] = '5';
            text[text_position] = 0;
        }
        if (GuiButton((Rectangle){ BUTTON_SIZE * 2, (BUTTON_SIZE * row) + INPUT_HEIGHT, BUTTON_SIZE, BUTTON_SIZE }, "6")) {
            text[text_position++] = '6';
            text[text_position] = 0;
        }
        row++;

        if (GuiButton((Rectangle){ 0, (BUTTON_SIZE * row) + INPUT_HEIGHT, BUTTON_SIZE, BUTTON_SIZE }, "7")) {
            text[text_position++] = '7';
            text[text_position] = 0;
        }
        if (GuiButton((Rectangle){ BUTTON_SIZE, (BUTTON_SIZE * row) + INPUT_HEIGHT, BUTTON_SIZE, BUTTON_SIZE }, "8")) {
            text[text_position++] = '8';
            text[text_position] = 0;
        }
        if (GuiButton((Rectangle){ BUTTON_SIZE * 2, (BUTTON_SIZE * row) + INPUT_HEIGHT, BUTTON_SIZE, BUTTON_SIZE }, "9")) {
            text[text_position++] = '9';
            text[text_position] = 0;
        }
        row++;

        if (GuiButton((Rectangle){ 0, (BUTTON_SIZE * row) + INPUT_HEIGHT, BUTTON_SIZE, BUTTON_SIZE }, "+")) {
            text[text_position++] = '+';
            text[text_position] = 0;
        }
        if (GuiButton((Rectangle){ BUTTON_SIZE, (BUTTON_SIZE * row) + INPUT_HEIGHT, BUTTON_SIZE, BUTTON_SIZE }, "-")) {
            text[text_position++] = '-';
            text[text_position] = 0;
        }
        if (GuiButton((Rectangle){ BUTTON_SIZE * 2, (BUTTON_SIZE * row) + INPUT_HEIGHT, BUTTON_SIZE, BUTTON_SIZE }, "*")) {
            text[text_position++] = '*';
            text[text_position] = 0;
        }
        row++;

        if (GuiButton((Rectangle){ 0, (BUTTON_SIZE * row) + INPUT_HEIGHT, BUTTON_SIZE, BUTTON_SIZE }, "/")) {
            text[text_position++] = '/';
            text[text_position] = 0;
        }
        if (GuiButton((Rectangle){ BUTTON_SIZE, (BUTTON_SIZE * row) + INPUT_HEIGHT, BUTTON_SIZE, BUTTON_SIZE }, "C")) {
            text[0] = 0;
            text_position = 0;
        }
        if (GuiButton((Rectangle){ BUTTON_SIZE * 2, (BUTTON_SIZE * row) + INPUT_HEIGHT, BUTTON_SIZE, BUTTON_SIZE }, "=")) {
        }
        row++;

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
