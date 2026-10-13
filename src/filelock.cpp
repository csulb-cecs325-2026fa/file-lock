#include "filelock.h"

FileLock::FileLock(LockableFile& file) : m_file {file} {
    // TODO: Try to lock m_file and remember whether this FileLock succeeded.
}

FileLock::~FileLock() {
    // TODO: Release the lock only if this FileLock acquired it.
}

bool FileLock::ownsLock() const {
    // TODO: Report whether this FileLock acquired the lock.
    return false;
}
