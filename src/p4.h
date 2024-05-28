int draw_p4_a(int offset_y) {
    int padding = 16;

    DrawLine(0, offset_y + padding, GetScreenWidth(), offset_y + padding, GetColor(GuiGetStyle(LABEL, TEXT)));
    return offset_y + padding;
}

void draw_p4(void) {
    int offset_y = 0;
    offset_y = draw_p4_a(offset_y);
}
