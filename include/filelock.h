#ifndef FILELOCK_H
#define FILELOCK_H

#include "lockablefile.h"

// Holds a lock on a LockableFile for this object's lifetime, if acquired.
// The LockableFile must outlive the FileLock.
class FileLock {
private:
    LockableFile& m_file;

public:
    explicit FileLock(LockableFile& file);
    ~FileLock();

    FileLock(const FileLock&) = delete;
    FileLock& operator=(const FileLock&) = delete;
    FileLock(FileLock&&) = delete;
    FileLock& operator=(FileLock&&) = delete;

    bool ownsLock() const;
};

#endif  // FILELOCK_H
