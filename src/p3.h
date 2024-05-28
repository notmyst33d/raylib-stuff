static char p3_a_data[11][512] = { 0 };
static int p3_a_active_table[10] = { 0 };

static char p3_b_output[512] = { 0 };

int draw_p3_a(int offset_y) {
    int padding = 16;
    int column = 0;

    column = 0;
    draw_labeled_box((Rectangle){ padding + (120 * column + padding * column), offset_y + padding + 16, 120, 32 }, "2 + 2 =", p3_a_data[0], p3_a_active_table, 0);
    column++;
    draw_labeled_box((Rectangle){ padding + (120 * column + padding * column), offset_y + padding + 16, 120, 32 }, "10 + 10 =", p3_a_data[1], p3_a_active_table, 1);
    column++;
    offset_y += 48 + padding;

    column = 0;
    draw_labeled_box((Rectangle){ padding + (120 * column + padding * column), offset_y + padding + 16, 120, 32 }, "2 + 2 * 2 =", p3_a_data[2], p3_a_active_table, 2);
    column++;
    draw_labeled_box((Rectangle){ padding + (120 * column + padding * column), offset_y + padding + 16, 120, 32 }, "10 * 10 =", p3_a_data[3], p3_a_active_table, 3);
    column++;
    offset_y += 48 + padding;

    column = 0;
    draw_labeled_box((Rectangle){ padding + (120 * column + padding * column), offset_y + padding + 16, 120, 32 }, "4.5 + 4.5 =", p3_a_data[4], p3_a_active_table, 4);
    column++;
    draw_labeled_box((Rectangle){ padding + (120 * column + padding * column), offset_y + padding + 16, 120, 32 }, "77 + 33 =", p3_a_data[5], p3_a_active_table, 5);
    column++;
    offset_y += 48 + padding;

    column = 0;
    draw_labeled_box((Rectangle){ padding + (120 * column + padding * column), offset_y + padding + 16, 120, 32 }, "5 * x = 15, x =", p3_a_data[6], p3_a_active_table, 6);
    column++;
    draw_labeled_box((Rectangle){ padding + (120 * column + padding * column), offset_y + padding + 16, 120, 32 }, "sqrt(81) =", p3_a_data[7], p3_a_active_table, 7);
    column++;
    offset_y += 48 + padding;

    column = 0;
    draw_labeled_box((Rectangle){ padding + (120 * column + padding * column), offset_y + padding + 16, 120, 32 }, "50 / 2 =", p3_a_data[8], p3_a_active_table, 8);
    column++;
    draw_labeled_box((Rectangle){ padding + (120 * column + padding * column), offset_y + padding + 16, 120, 32 }, "15 + 15 =", p3_a_data[9], p3_a_active_table, 9);
    column++;
    offset_y += 48 + padding;

    if (GuiButton((Rectangle){ padding, offset_y + padding, 72, 32 }, "Run")) {
        int grade = 0;
        if (strcmp(p3_a_data[0], "4") == 0) grade += 1;
        if (strcmp(p3_a_data[1], "20") == 0) grade += 1;
        if (strcmp(p3_a_data[2], "6") == 0) grade += 1;
        if (strcmp(p3_a_data[3], "100") == 0) grade += 1;
        if (strcmp(p3_a_data[4], "9") == 0) grade += 1;
        if (strcmp(p3_a_data[5], "110") == 0) grade += 1;
        if (strcmp(p3_a_data[6], "3") == 0) grade += 1;
        if (strcmp(p3_a_data[7], "9") == 0) grade += 1;
        if (strcmp(p3_a_data[8], "25") == 0) grade += 1;
        if (strcmp(p3_a_data[9], "30") == 0) grade += 1;
        switch (grade) {
            case 10:
            case 9:
                sprintf(p3_a_data[10], "A");
                break;
            case 8:
            case 7:
                sprintf(p3_a_data[10], "B");
                break;
            case 6:
            case 5:
            case 4:
                sprintf(p3_a_data[10], "C");
                break;
            default:
                sprintf(p3_a_data[10], "F");
                break;
        }
    }
    GuiLabel((Rectangle){ padding + 72 + padding, offset_y + 16, 240, 32 }, p3_a_data[10]);
    offset_y += 32 + padding;

    DrawLine(0, offset_y + padding, 500, offset_y + padding, GetColor(GuiGetStyle(LABEL, TEXT)));

    return offset_y + padding;
}

int draw_p3_b(int offset_y) {
    int padding = 16;

    if (p3_fd.SelectFilePressed) {
        char file_path[512];
        strcpy(file_path, TextFormat("%s" PATH_SEPERATOR "%s", p3_fd.dirPathText, p3_fd.fileNameText));
        char *data = LoadFileText(file_path);

        // Clean code is my passion 👍
        switch (data[0]) {
            case 'q':
            case 'Q':
            case 'w':
            case 'W':
            case 'e':
            case 'E':
            case 'r':
            case 'R':
            case 't':
            case 'T':
            case 'y':
            case 'Y':
            case 'u':
            case 'U':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'p':
            case 'P':
                sprintf(p3_b_output, "First keyboard row");
                break;
            case 'a':
            case 'A':
            case 's':
            case 'S':
            case 'd':
            case 'D':
            case 'f':
            case 'F':
            case 'g':
            case 'G':
            case 'h':
            case 'H':
            case 'j':
            case 'J':
            case 'k':
            case 'K':
            case 'l':
            case 'L':
                sprintf(p3_b_output, "Second keyboard row");
                break;
            case 'z':
            case 'Z':
            case 'x':
            case 'X':
            case 'c':
            case 'C':
            case 'v':
            case 'V':
            case 'b':
            case 'B':
            case 'n':
            case 'N':
            case 'm':
            case 'M':
                sprintf(p3_b_output, "Third keyboard row");
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                sprintf(p3_b_output, "Numerical character");
                break;
            case '\0':
                sprintf(p3_b_output, "Null character (empty string)");
                break;
            default:
                sprintf(p3_b_output, "Unknown character");
                break;
        }

        p3_fd.SelectFilePressed = 0;
    }

    GuiLabel((Rectangle){ padding + 120 + padding, offset_y + padding, 340, 32 }, p3_b_output);

    if (GuiButton((Rectangle){ padding, offset_y + padding, 120, 32 }, GuiIconText(ICON_FILE_OPEN, "Open File"))) {
        p3_fd.windowActive = true;
    }

    DrawLine(0, offset_y + padding + 32 + padding, 500, offset_y + padding + 32 + padding, GetColor(GuiGetStyle(LABEL, TEXT)));

    return offset_y + padding + 32 + padding;
}

void draw_p3(void) {
    int offset_y = 0;
    if (p3_fd.windowActive) {
        GuiLock();
    }
    offset_y = draw_p3_a(offset_y);
    offset_y = draw_p3_b(offset_y);
    GuiUnlock();
    GuiWindowFileDialog(&p3_fd);
}
