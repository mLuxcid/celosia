#include <lib/spinlock.h>
#include <sys/types.h>

void init_lock(spinlock *lock, const char *name) {
    lock->name = (char *)name;
    lock->locked = 0;
}

/* TODO: Disable Interrupts to avoid deadlocks */
void acquire_lock(spinlock *lock) {
    while (__sync_lock_test_and_set(&lock->locked, 1)) {
    }
}

void release_lock(spinlock *lock) { __sync_lock_release(&lock->locked); }
