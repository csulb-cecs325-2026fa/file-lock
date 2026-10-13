#include <gtest/gtest.h>

#include "filelock.h"

TEST(FileLock, AcquiresAndReleasesAnAvailableLock) {
    LockableFile file{};
    EXPECT_FALSE(file.isLocked());

    {
        FileLock lock{file};
        EXPECT_TRUE(lock.ownsLock());
        EXPECT_TRUE(file.isLocked());
    }

    EXPECT_FALSE(file.isLocked());
}

TEST(FileLock, FailedAcquisitionDoesNotReleaseSomeoneElsesLock) {
    LockableFile file{};
    ASSERT_TRUE(file.tryLock());

    {
        FileLock lock{file};
        EXPECT_FALSE(lock.ownsLock());
        EXPECT_TRUE(file.isLocked());
    }

    EXPECT_TRUE(file.isLocked());
    file.unlock();
}

namespace {

bool useFileAndReturnEarly(LockableFile& file) {
    FileLock lock{file};
    if (lock.ownsLock()) {
        return true;
    }
    return false;
}

}  // namespace

TEST(FileLock, ReleasesLockWhenFunctionReturns) {
    LockableFile file{};
    EXPECT_TRUE(useFileAndReturnEarly(file));
    EXPECT_FALSE(file.isLocked());
}
