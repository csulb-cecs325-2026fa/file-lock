#include "filelock.h"

#include <iostream>

int main() {
    LockableFile file{};
    std::cout << "Initially locked: " << file.isLocked() << '\n';

    {
        FileLock lock{file};
        std::cout << "FileLock owns the lock: " << lock.ownsLock() << '\n';
        std::cout << "Locked inside scope: " << file.isLocked() << '\n';
    }

    std::cout << "Locked after scope: " << file.isLocked() << '\n';
}
