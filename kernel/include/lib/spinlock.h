#ifndef KERNEL_LIB_SPINLOCK_H_
#define KERNEL_LIB_SPINLOCK_H_

#include <sys/types.h>

namespace lib {

struct spinlock {
    uint locked;
    char *name;
};

void init_lock(struct spinlock *, const char *);
void acquire_lock(struct spinlock *);
void release_lock(struct spinlock *);

}  // namespace lib

#endif /* KERNEL_LIB_SPINLOCK_H_ */
