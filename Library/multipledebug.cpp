void mprint() {}
template <typename T, typename... Args>
void mprint(const std::string& name, const T& value, const Args&... args) {
    std::cout << name << " : " << value << ", ";
    mprint(args...);
}