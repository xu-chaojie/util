int
bytes_to_human_readable_string(int64_t bytes, char *str, size_t size) {
    const char FILE_SIZE_UNITS[8][3]{
        "B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB"
    };
    int base = 0;
    float value = float(bytes);
    while ((bytes >> 10) != 0) {
        base ++;
        bytes = bytes >> 10;
    }
    value = value / (1ull << (base * 10));
    return snprintf(str, size, "%.1f%s", value, FILE_SIZE_UNITS[base]);
}
