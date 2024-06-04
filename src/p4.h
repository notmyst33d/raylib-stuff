static int p4_a_message_frames = 0, p4_a_message_show = 0,
           p4_b_message_frames = 0, p4_b_message_show = 0,
           p4_c_message_frames = 0, p4_c_message_show = 0;

int draw_p4_a(int offset_y) {
    int padding = 16;

    if (p4_a_fd.SelectFilePressed) {
        int a = 0, b = 0, c = 0;
        char file_path[512];
        strcpy(file_path, TextFormat("%s" PATH_SEPERATOR "%s", p4_a_fd.dirPathText, p4_a_fd.fileNameText));
        char *data = LoadFileText(file_path);
        sscanf(data, "%d\n%d\n%d", &a, &b, &c);
        UnloadFileText(data);
        FILE *f = fopen("p4_a_result.txt", "w");
        for (int i = a; i < b; i++) {
            if (i % c == 0) {
                fprintf(f, "%d\n", i);
            }
        }
        fclose(f);
        p4_a_fd.SelectFilePressed = 0;
        p4_a_message_show = 1;
    }

    if (p4_a_message_show) {
        GuiLabel((Rectangle){ padding + 120 + padding, offset_y + padding, 340, 32 }, "File written to p4_a_result.txt");
        p4_a_message_frames += 1;
        if (p4_a_message_frames >= 60) {
            p4_a_message_frames = 0;
            p4_a_message_show = 0;
        }
    }

    if (GuiButton((Rectangle){ padding, offset_y + padding, 120, 32 }, GuiIconText(ICON_FILE_OPEN, "Open File"))) {
        p4_a_fd.windowActive = 1;
    }

    DrawLine(0, offset_y + padding + 32 + padding, 500, offset_y + padding + 32 + padding, GetColor(GuiGetStyle(LABEL, TEXT)));

    return offset_y + padding + 32 + padding;
}

int draw_p4_b(int offset_y) {
    int padding = 16;

    if (p4_b_fd.SelectFilePressed) {
        int s = 0, sum = 0, count = 0;
        char file_path[512];
        strcpy(file_path, TextFormat("%s" PATH_SEPERATOR "%s", p4_b_fd.dirPathText, p4_b_fd.fileNameText));
        char *data = LoadFileText(file_path);
        sscanf(data, "%d", &s);
        UnloadFileText(data);
        FILE *f = fopen("p4_b_result.txt", "w");
        while (sum < s) {
            int v = GetRandomValue(1, 9);
            sum += v;
            if (sum >= s) {
                fprintf(f, "%d", v);
            } else {
                fprintf(f, "%d ", v);
            }
            count++;
        }
        fprintf(f, "\n%d %d", sum, count);
        fclose(f);
        p4_b_fd.SelectFilePressed = 0;
        p4_b_message_show = 1;
    }

    if (p4_b_message_show) {
        GuiLabel((Rectangle){ padding + 120 + padding, offset_y + padding, 340, 32 }, "File written to p4_b_result.txt");
        p4_b_message_frames += 1;
        if (p4_b_message_frames >= 60) {
            p4_b_message_frames = 0;
            p4_b_message_show = 0;
        }
    }

    if (GuiButton((Rectangle){ padding, offset_y + padding, 120, 32 }, GuiIconText(ICON_FILE_OPEN, "Open File"))) {
        p4_b_fd.windowActive = 1;
    }

    DrawLine(0, offset_y + padding + 32 + padding, 500, offset_y + padding + 32 + padding, GetColor(GuiGetStyle(LABEL, TEXT)));

    return offset_y + padding + 32 + padding;
}

int draw_p4_c(int offset_y) {
    int padding = 16;

    if (p4_c_fd.SelectFilePressed) {
        int num = 0;
        char file_path[512];
        strcpy(file_path, TextFormat("%s" PATH_SEPERATOR "%s", p4_c_fd.dirPathText, p4_c_fd.fileNameText));
        char *data = LoadFileText(file_path);
        sscanf(data, "%d", &num);
        UnloadFileText(data);
        FILE *f = fopen("p4_c_result.txt", "w");
        for (int i = num; i > 0; i--) {
            if (num % i == 0) {
                fprintf(f, "%d\n", i);
            }
        }
        fclose(f);
        p4_c_fd.SelectFilePressed = 0;
        p4_c_message_show = 1;
    }

    if (p4_c_message_show) {
        GuiLabel((Rectangle){ padding + 120 + padding, offset_y + padding, 340, 32 }, "File written to p4_c_result.txt");
        p4_c_message_frames += 1;
        if (p4_c_message_frames >= 60) {
            p4_c_message_frames = 0;
            p4_c_message_show = 0;
        }
    }

    if (GuiButton((Rectangle){ padding, offset_y + padding, 120, 32 }, GuiIconText(ICON_FILE_OPEN, "Open File"))) {
        p4_c_fd.windowActive = 1;
    }

    DrawLine(0, offset_y + padding + 32 + padding, 500, offset_y + padding + 32 + padding, GetColor(GuiGetStyle(LABEL, TEXT)));

    return offset_y + padding + 32 + padding;
}

void draw_p4(void) {
    int offset_y = 0;
    if (p4_a_fd.windowActive || p4_b_fd.windowActive || p4_c_fd.windowActive) {
        GuiLock();
    }
    offset_y = draw_p4_a(offset_y);
    offset_y = draw_p4_b(offset_y);
    offset_y = draw_p4_c(offset_y);
    GuiUnlock();
    GuiWindowFileDialog(&p4_a_fd);
    GuiWindowFileDialog(&p4_b_fd);
    GuiWindowFileDialog(&p4_c_fd);
}
