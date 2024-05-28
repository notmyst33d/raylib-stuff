static int p7_scroll_index = 0;
static int p7_array[512] = { 0 };
static int p7_array_size = 0;
static char p7_array_string[4096] = { 0 };
static char p7_output[3][512] = { 0 };

void clear_array(void) {
    for (int i = 0; i < 512; i++) {
        p7_array[i] = 0;
    }
}

void generate_array(void) {
    clear_array();
    p7_array_size = GetRandomValue(4, 16);

    int string_position = 0;
    for (int i = 0; i < p7_array_size; i++) {
        p7_array[i] = GetRandomValue(-10000, 10000);
        string_position += sprintf(p7_array_string + string_position, "%d\n", p7_array[i]);
    }
    p7_array_string[string_position - 1] = 0;
}

int array_minmax(int array[], int array_size, int max) {
    int value = 0;
    if (!max) {
        value = array_minmax(array, array_size, 1);
    }

    for (int i = 0; i < array_size; i++) {
        if (!max && array[i] < value) {
            value = array[i];
        } else if (max && array[i] > value) {
            value = array[i];
        }
    }
    return value;
}

int array_average(int array[], int array_size) {
    int value = 0;
    for (int i = 0; i < array_size; i++) {
        value += array[i];
    }
    return value / array_size;
}

void draw_p7(void) {
    int row = 0;
    int padding = 16;

    GuiListView((Rectangle){ padding, padding, 120, 300 }, p7_array_string, &p7_scroll_index, 0);

    if (GuiButton((Rectangle){ padding + 120 + padding, padding + (32 * row) + (padding * row), 72, 32 }, "Generate")) {
        generate_array();
    }
    row++;

    if (GuiButton((Rectangle){ padding + 120 + padding, padding + (32 * row) + (padding * row), 72, 32 }, "Min")) {
        sprintf(p7_output[0], "%d", array_minmax(p7_array, p7_array_size, 0));
    }
    GuiLabel((Rectangle){ padding + 120 + padding + 72 + padding, padding + (32 * row) + (padding * row), 120, 32 }, p7_output[0]);
    row++;

    if (GuiButton((Rectangle){ padding + 120 + padding, padding + (32 * row) + (padding * row), 72, 32 }, "Max")) {
        sprintf(p7_output[1], "%d", array_minmax(p7_array, p7_array_size, 1));
    }
    GuiLabel((Rectangle){ padding + 120 + padding + 72 + padding, padding + (32 * row) + (padding * row), 120, 32 }, p7_output[1]);
    row++;

    if (GuiButton((Rectangle){ padding + 120 + padding, padding + (32 * row) + (padding * row), 72, 32 }, "Average")) {
        sprintf(p7_output[2], "%d", array_average(p7_array, p7_array_size));
    }
    GuiLabel((Rectangle){ padding + 120 + padding + 72 + padding, padding + (32 * row) + (padding * row), 120, 32 }, p7_output[2]);
    row++;

    DrawLine(0, padding + 300 + padding, GetScreenWidth(), padding + 300 + padding, GetColor(GuiGetStyle(LABEL, TEXT)));
}
