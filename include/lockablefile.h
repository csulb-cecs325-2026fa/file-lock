#ifndef LOCKABLEFILE_H
#define LOCKABLEFILE_H

// A small simulation for the FileLock homework. This class does not open
// a real file or synchronize threads.
class LockableFile {
private:
    bool m_locked {false};

public:
    LockableFile() = default;
    LockableFile(const LockableFile&) = delete;
    LockableFile& operator=(const LockableFile&) = delete;

    // Acquires the lock and returns true if the file was unlocked.
    // Returns false, without changing the state, if it was already locked.
    bool tryLock();

    // Releases the lock. Has no effect if the file was already unlocked.
    void unlock();

    bool isLocked() const;
};

#endif  // LOCKABLEFILE_H
