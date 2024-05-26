static char p1_a_data[5][255] = { 0 };
static int p1_a_active_table[4] = { 0 };

static char p1_b_data[4][255] = { 0 };
static int p1_b_active_table[3] = { 0 };

static char p1_c_data[4][255] = { 0 };
static int p1_c_active_table[3] = { 0 };

long draw_p1_a(long offset_y) {
    long row = 0;
    long column = 0;
    long width = 48;
    long padding = 16;

    char *vars[][2] = { { p1_a_data[0], "A" }, { p1_a_data[1], "B" }, { p1_a_data[2], "C" }, { p1_a_data[3], "D" } };

    for (int i = 0; i < 4; i++) {
        GuiLabel((Rectangle){ padding + (padding * row) + (width * row), offset_y + padding, 72, 12 }, vars[i][1]);
        if (GuiTextBox((Rectangle){ padding + (padding * row) + (width * row), offset_y + padding * 2, width, 32 }, vars[i][0], 12, p1_a_active_table[i])) p1_a_active_table[i] = !p1_a_active_table[i];
        row++;
    }

    if (GuiButton((Rectangle){ padding + (padding * row) + (width * row), offset_y + 32, 72, 32 }, "Run")) {
        int a = atoi(p1_a_data[0]), b = atoi(p1_a_data[1]), c = atoi(p1_a_data[2]), d = atoi(p1_a_data[3]);
        sprintf(
            p1_a_data[4],
            "sum = %d\nsquare sum = %d\naverage = %d\npair sum = %d",
            a + b + c + d,
            (a * 3) + (b * 3) + (c * 3) + (d * 3),
            (a + b + c + d) / 4,
            (a * b) + (c * d)
        );
    }

    offset_y += padding * 5;

    Rectangle output_bounds = { padding, offset_y, 200, 60 };
    GuiSetStyle(DEFAULT, TEXT_ALIGNMENT_VERTICAL, TEXT_ALIGN_TOP);
    GuiLabel(output_bounds, p1_a_data[4]);
    GuiSetStyle(DEFAULT, TEXT_ALIGNMENT_VERTICAL, TEXT_ALIGN_CENTER);
    column++;

    offset_y += output_bounds.height + padding;

    return offset_y;
}

long draw_p1_b(long offset_y) {
    long width = 48;
    long padding = 16;

    // a
    draw_labeled_box((Rectangle){ padding, offset_y + padding + 72 / 2, width, 32 }, "a", p1_b_data[0], p1_b_active_table, 0);

    // b
    draw_labeled_box((Rectangle){ padding + (72 + 240) / 2, offset_y + padding + 120 + padding + 8, width, 32 }, "b", p1_b_data[1], p1_b_active_table, 1);

    // A
    draw_labeled_box((Rectangle){ padding + 72 + padding, offset_y + 60, width, 32 }, "A", p1_b_data[2], p1_b_active_table, 2);

    // c
    GuiLabel((Rectangle){ padding + 72 + 240 - 64, offset_y + 60, 120, 32 }, p1_b_data[3]);

    DrawLine(
        padding + 72,
        padding + offset_y,
        padding + 72,
        padding + offset_y + 120,
        GetColor(GuiGetStyle(LABEL, TEXT))
    );
    DrawLine(
        padding + 72,
        padding + offset_y,
        padding + 72 + 240,
        padding + offset_y + 120,
        GetColor(GuiGetStyle(LABEL, TEXT))
    );
    DrawLine(
        padding + 72,
        padding + offset_y + 120,
        padding + 72 + 240,
        padding + offset_y + 120,
        GetColor(GuiGetStyle(LABEL, TEXT))
    );
    DrawCircleSectorLines(
        (Vector2){ padding + 72, padding + offset_y + 120 },
        40,
        -90,
        0,
        10,
        GetColor(GuiGetStyle(LABEL, TEXT))
    );

    offset_y += 120 + 32 + padding + padding;

    if (GuiButton((Rectangle){ padding, offset_y + padding, 72, 32 }, "Run")) {
        float a, b, A;
        sscanf(p1_b_data[0], "%f", &a);
        sscanf(p1_b_data[1], "%f", &b);
        sscanf(p1_b_data[2], "%f", &A);
        sprintf(p1_b_data[3], "c = %f", sqrtf((a * a) + (b * b) - (2 * a * b * cosf(A * (PI / 180)))));
    }

    offset_y += padding + padding + 32;

    return offset_y;
}

long draw_p1_c(long offset_y) {
    long width = 48;
    long padding = 16;

    // a
    draw_labeled_box((Rectangle){ padding, offset_y + padding + 72 / 2, width, 32 }, "a", p1_c_data[0], p1_c_active_table, 0);

    // b
    draw_labeled_box((Rectangle){ padding + (72 + 240) / 2, offset_y + padding + 120 + padding + 8, width, 32 }, "b", p1_c_data[1], p1_c_active_table, 1);

    // c
    draw_labeled_box((Rectangle){ padding + 72 + 240 - 64, offset_y + 60, width, 32 }, "c", p1_c_data[2], p1_c_active_table, 2);

    DrawLine(
        padding + 72,
        padding + offset_y,
        padding + 72,
        padding + offset_y + 120,
        GetColor(GuiGetStyle(LABEL, TEXT))
    );
    DrawLine(
        padding + 72,
        padding + offset_y,
        padding + 72 + 240,
        padding + offset_y + 120,
        GetColor(GuiGetStyle(LABEL, TEXT))
    );
    DrawLine(
        padding + 72,
        padding + offset_y + 120,
        padding + 72 + 240,
        padding + offset_y + 120,
        GetColor(GuiGetStyle(LABEL, TEXT))
    );

    offset_y += 120 + 32 + padding + padding;

    if (GuiButton((Rectangle){ padding, offset_y + padding, 72, 32 }, "Run")) {
        float a, b, c, p;
        sscanf(p1_c_data[0], "%f", &a);
        sscanf(p1_c_data[1], "%f", &b);
        sscanf(p1_c_data[2], "%f", &c);
        p = (a + b + c) / 2;
        sprintf(p1_c_data[3], "S = %f", sqrtf(p * (p - a) * (p - b) * (p - c)));
    }

    GuiLabel((Rectangle){ padding + 72 + padding, offset_y + 16, 120, 32 }, p1_c_data[3]);

    offset_y += padding + padding + 32;

    return offset_y;
}

void draw_p1(void) {
    long offset_y = 0;

    offset_y = draw_p1_a(offset_y);
    DrawLine(0, offset_y, 500, offset_y, GetColor(GuiGetStyle(LABEL, TEXT)));

    offset_y = draw_p1_b(offset_y);
    DrawLine(0, offset_y, 500, offset_y, GetColor(GuiGetStyle(LABEL, TEXT)));

    offset_y = draw_p1_c(offset_y);
    DrawLine(0, offset_y, 500, offset_y, GetColor(GuiGetStyle(LABEL, TEXT)));
}
