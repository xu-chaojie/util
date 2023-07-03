#include <iomanip>
#include <string>

std::string format_str(const char* buf, size_t size) {
    std::ostringstream oss;
    oss << std::hex << std::setfill('0');
    const size_t line = 16;  // 每行打印16个字符
    const size_t sector = 512;  // 每512字节打印一次offset
    for (size_t i = 0; i < size; ++i) {
        if (i % sector == 0) {
            oss << "\noffset: 0x" << std::hex << i;
        }
        if (i % line == 0) {
            oss << "\n";
        }
        oss << std::setw(2) << (static_cast<unsigned>(buf[i]) & 0xFF) << " ";
    }
    return oss.str();
}
