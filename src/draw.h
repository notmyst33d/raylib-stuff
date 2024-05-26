void draw_labeled_box(Rectangle bounds, const char *label, char *data, int active_table[], int active_table_index) {
    Rectangle label_bounds = { bounds.x, bounds.y - bounds.height / 2, 120, 12 };
    GuiLabel(label_bounds, label);
    if (GuiTextBox(bounds, data, 12, active_table[active_table_index])) active_table[active_table_index] = !active_table[active_table_index];
}
