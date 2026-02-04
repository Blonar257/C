int main() {
    extern int a; // defined elsewhere
    static int b; // hold value between invocations
    register int c; // store in CPU register for fast access
    auto int d; // automatic duration - scope lifetime. Implicit if not specified
    //_Thread_local int e; // thread storage duration
    return 0;
}
