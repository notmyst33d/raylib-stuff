static int p6_array[512] = { 0 },
           p6_array_size = 0,
           p6_scroll_index = 0,
           p6_active = 0;

static char p6_array_string[4096] = { 0 },
            p6_input[512] = { 0 },
            p6_output[3][512] = { 0 };

// strcmp-like comparison function for qsort
int compare_ints(const void *a, const void *b) {
    const int *da = a;
    const int *db = b;
    return (*da > *db) - (*da < *db);
}

// shitsort (TM) is the best sorting algorithm
// in the world (PATENT PENDING)
void shitsort(int array[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j + 1 < size; j += 1) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void draw_p6(void) {
    int row = 0;
    int padding = 16;

    GuiListView((Rectangle){ padding, padding, 120, 300 }, p6_array_string, &p6_scroll_index, 0);

    if (GuiTextBox((Rectangle){ padding + 120 + padding, padding + (32 * row) + (padding * row), 72, 32 }, p6_input, 12, p6_active)) {
        p6_active = !p6_active;
    }
    if (GuiButton((Rectangle){ padding + 120 + padding + 72 + padding, padding + (32 * row) + (padding * row), 72, 32 }, "Add")) {
        p6_array[p6_array_size] = atoi(p6_input);
        p6_array_size += 1;
        print_array(p6_array, p6_array_size, p6_array_string);
        p6_input[0] = 0;
    }
    GuiLabel((Rectangle){ padding + 120 + padding + 72 + padding, padding + (32 * row) + (padding * row), 120, 32 }, p6_output[0]);
    row++;

    if (GuiButton((Rectangle){ padding + 120 + padding, padding + (32 * row) + (padding * row), 120, 32 }, "Clear")) {
        clear_memory((char*)p6_array, 512 * sizeof(int));
        clear_memory(p6_array_string, 4096);
        p6_array_size = 0;
    }
    GuiLabel((Rectangle){ padding + 120 + padding + 72 + padding, padding + (32 * row) + (padding * row), 120, 32 }, p6_output[2]);
    row++;

    if (GuiButton((Rectangle){ padding + 120 + padding, padding + (32 * row) + (padding * row), 120, 32 }, "libc qsort")) {
        qsort(p6_array, p6_array_size, sizeof(int), compare_ints);
        print_array(p6_array, p6_array_size, p6_array_string);
    }
    GuiLabel((Rectangle){ padding + 120 + padding + 72 + padding, padding + (32 * row) + (padding * row), 120, 32 }, p6_output[1]);
    row++;

    if (GuiButton((Rectangle){ padding + 120 + padding, padding + (32 * row) + (padding * row), 120, 32 }, "shitsort (TM)")) {
        shitsort(p6_array, p6_array_size);
        print_array(p6_array, p6_array_size, p6_array_string);
    }
    GuiLabel((Rectangle){ padding + 120 + padding + 72 + padding, padding + (32 * row) + (padding * row), 120, 32 }, p6_output[2]);
    row++;

    DrawLine(0, padding + 300 + padding, GetScreenWidth(), padding + 300 + padding, GetColor(GuiGetStyle(LABEL, TEXT)));
}
