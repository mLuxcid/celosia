#ifndef KERNEL_SPINLOCK_H_
#define KERNEL_SPINLOCK_H_

#include <sys/types.h>

struct spinlock {
    uint locked;
    char *name;
};

void init_lock(struct spinlock *, char *);
void acquire_lock(struct spinlock *);
void release_lock(struct spinlock *);

#endif /* KERNEL_SPINLOCK_H_ */
