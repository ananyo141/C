// Test signals //
#include <stdio.h>
#include <signal.h>

void handler(int sig);
void raise_sig(void);

int main() {
    void 