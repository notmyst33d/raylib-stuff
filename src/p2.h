char p2_a_file_path[255] = { 0 };
long p2_a_message_frames = 0;
int p2_a_message_show = 0;

char p2_b_file_path[255] = { 0 };
char p2_b_output[255] = { 0 };

long draw_p2_a(long offset_y) {
    long padding = 16;

    if (p2_a_file_dialog.SelectFilePressed) {
        int nums[5] = { 0 };
        strcpy(p2_a_file_path, TextFormat("%s" PATH_SEPERATOR "%s", p2_a_file_dialog.dirPathText, p2_a_file_dialog.fileNameText));
        char *data = LoadFileText(p2_a_file_path);
        sscanf(data, "%d\n%d\n%d\n%d", nums, nums + 1, nums + 2, nums + 3);
        FILE *ef = fopen("even.txt", "w");
        FILE *of = fopen("odd.txt", "w");
        for (int i = 0; nums[i] != 0; i++) {
            char buffer[32];
            long length = sprintf(buffer, "%d", nums[i]);
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

        p2_a_file_dialog.SelectFilePressed = false;
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

    if (p2_a_file_dialog.windowActive) {
        GuiLock();
    }

    if (GuiButton((Rectangle){ padding, offset_y + padding, 120, 32 }, GuiIconText(ICON_FILE_OPEN, "Open File"))) {
        p2_a_file_dialog.windowActive = true;
    }

    GuiUnlock();

    GuiWindowFileDialog(&p2_a_file_dialog);

    return offset_y + padding + 32 + padding;
}

long draw_p2_b(long offset_y) {
    long padding = 16;

    if (p2_b_file_dialog.SelectFilePressed) {
        int a, b, c, is_triangle, is_equal;
        strcpy(p2_b_file_path, TextFormat("%s" PATH_SEPERATOR "%s", p2_b_file_dialog.dirPathText, p2_b_file_dialog.fileNameText));
        char *data = LoadFileText(p2_b_file_path);
        sscanf(data, "%d\n%d\n%d", &a, &b, &c);

        is_triangle = a + b > c && b + c > a && a + c > b;
        is_equal = is_triangle && ((a * a) + (b * b) == (c * c));

        sprintf(p2_b_output, "Triangle: %s\nEqual: %s", is_triangle ? "yes" : "no", is_equal ? "yes" : "no");

        p2_b_file_dialog.SelectFilePressed = false;
    }

    GuiLabel((Rectangle){ padding + 120 + padding, offset_y + padding, 240, 32 }, p2_b_output);

    if (p2_b_file_dialog.windowActive) {
        GuiLock();
    }

    if (GuiButton((Rectangle){ padding, offset_y + padding, 120, 32 }, GuiIconText(ICON_FILE_OPEN, "Open File"))) {
        p2_b_file_dialog.windowActive = true;
    }

    GuiUnlock();

    GuiWindowFileDialog(&p2_b_file_dialog);

    return offset_y + padding + 32 + padding;
}

void draw_p2(void) {
    long offset_y = 0;

    offset_y = draw_p2_a(offset_y);
    DrawLine(0, offset_y, 500, offset_y, GetColor(GuiGetStyle(LABEL, TEXT)));

    offset_y = draw_p2_b(offset_y);
    DrawLine(0, offset_y, 500, offset_y, GetColor(GuiGetStyle(LABEL, TEXT)));
}
