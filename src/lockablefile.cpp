#include "lockablefile.h"

bool LockableFile::tryLock() {
    if (m_locked) {
        return false;
    }

    m_locked = true;
    return true;
}

void LockableFile::unlock() {
    m_locked = false;
}

bool LockableFile::isLocked() const {
    return m_locked;
}
