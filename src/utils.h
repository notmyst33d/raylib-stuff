void clear_memory(char *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }
}

void print_array(int input[], int input_size, char output[]) {
    int position = 0;
    for (int i = 0; i < input_size; i++)
        position += sprintf(output + position, position == 0 ? "%d" : "\n%d", input[i]);
}
