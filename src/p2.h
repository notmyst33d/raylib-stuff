static int p2_a_message_frames = 0;
static int p2_a_message_show = 0;

static char p2_b_output[512] = { 0 };

int draw_p2_a(int offset_y) {
    int padding = 16;

    if (p2_fd_a.SelectFilePressed) {
        int nums[5] = { 0 };
        char file_path[512];
        strcpy(file_path, TextFormat("%s" PATH_SEPERATOR "%s", p2_fd_a.dirPathText, p2_fd_a.fileNameText));
        char *data = LoadFileText(file_path);
        sscanf(data, "%d\n%d\n%d\n%d", nums, nums + 1, nums + 2, nums + 3);
        FILE *ef = fopen("even.txt", "w");
        FILE *of = fopen("odd.txt", "w");
        for (int i = 0; nums[i] != 0; i++) {
            char buffer[32];
            int length = sprintf(buffer, "%d", nums[i]);
            if (nums[i] % 2 == 0) {
                fwrite(buffer, length, 1, ef);
                fwrite("\n", 1, 1, ef);
            } else {
                fwrite(buffer, length, 1, of);
                fwrite("\n", 1, 1, of);
            }
        }
        fclose(ef);
        fclose(of);

        p2_fd_a.SelectFilePressed = 0;
        p2_a_message_show = 1;
    }

    if (p2_a_message_show) {
        GuiLabel((Rectangle){ padding + 120 + padding, offset_y + padding, 340, 32 }, "Files written to even.txt and odd.txt");
        p2_a_message_frames += 1;
        if (p2_a_message_frames >= 60) {
            p2_a_message_frames = 0;
            p2_a_message_show = 0;
        }
    }

    if (GuiButton((Rectangle){ padding, offset_y + padding, 120, 32 }, GuiIconText(ICON_FILE_OPEN, "Open File"))) {
        p2_fd_a.windowActive = 1;
    }

    DrawLine(0, offset_y + padding + 32 + padding, 500, offset_y + padding + 32 + padding, GetColor(GuiGetStyle(LABEL, TEXT)));

    return offset_y + padding + 32 + padding;
}

int draw_p2_b(int offset_y) {
    int padding = 16;

    if (p2_fd_b.SelectFilePressed) {
        int a, b, c, is_triangle, is_equal;
        char file_path[512];
        strcpy(file_path, TextFormat("%s" PATH_SEPERATOR "%s", p2_fd_b.dirPathText, p2_fd_b.fileNameText));
        char *data = LoadFileText(file_path);
        sscanf(data, "%d\n%d\n%d", &a, &b, &c);

        if (a + b > c && b + c > a && a + c > b) {
            is_triangle = 1;
            if ((a * a) + (b * b) == (c * c)) {
                is_equal = 1;
            } else {
                is_equal = 0;
            }
        } else {
            is_triangle = 0;
            is_equal = 0;
        }

        sprintf(p2_b_output, "Triangle: %s\nEqual: %s", is_triangle ? "yes" : "no", is_equal ? "yes" : "no");

        p2_fd_b.SelectFilePressed = 0;
    }

    GuiLabel((Rectangle){ padding + 120 + padding, offset_y + padding, 240, 32 }, p2_b_output);

    if (GuiButton((Rectangle){ padding, offset_y + padding, 120, 32 }, GuiIconText(ICON_FILE_OPEN, "Open File"))) {
        p2_fd_b.windowActive = 1;
    }

    DrawLine(0, offset_y + padding + 32 + padding, 500, offset_y + padding + 32 + padding, GetColor(GuiGetStyle(LABEL, TEXT)));

    return offset_y + padding + 32 + padding;
}

void draw_p2(void) {
    int offset_y = 0;
    if (p2_fd_a.windowActive || p2_fd_b.windowActive) {
        GuiLock();
    }
    offset_y = draw_p2_a(offset_y);
    offset_y = draw_p2_b(offset_y);
    GuiUnlock();
    GuiWindowFileDialog(&p2_fd_a);
    GuiWindowFileDialog(&p2_fd_b);
}
