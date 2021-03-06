/*
 * @APPLE_APACHE_LICENSE_HEADER_START@
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @APPLE_APACHE_LICENSE_HEADER_END@
 */


/*
 * This file contains stubbed out functions we are using during
 * the initial linux port.  When the port is complete, this file
 * should be empty (and thus removed).
 */

#include <stdint.h>

#include <config/config.h>

#include "pthread.h"

#define program_invocation_short_name "hi"

#include "os/linux_base.h"
#include "internal.h"


#undef LINUX_PORT_ERROR
#define LINUX_PORT_ERROR()  do { printf("LINUX_PORT_ERROR_CALLED %s:%d: %s\n",__FILE__,__LINE__,__FUNCTION__); abort(); } while (0)

void _dispatch_mach_msg_dispose() { LINUX_PORT_ERROR();  }

unsigned long _dispatch_mach_probe(dispatch_mach_t dm) {
  LINUX_PORT_ERROR();
}

dispatch_block_t _dispatch_block_create(dispatch_block_flags_t flags,
					voucher_t voucher, pthread_priority_t priority,
					dispatch_block_t block) {
  LINUX_PORT_ERROR();
}

void _dispatch_mach_invoke() { LINUX_PORT_ERROR();  }

size_t _dispatch_mach_msg_debug(dispatch_mach_msg_t dmsg, char* buf, size_t bufsiz) {
  LINUX_PORT_ERROR();
}
void _dispatch_mach_dispose() { LINUX_PORT_ERROR();  }
void _dispatch_mach_msg_invoke() { LINUX_PORT_ERROR();  }

unsigned long _dispatch_runloop_queue_probe(dispatch_queue_t dq) {
  LINUX_PORT_ERROR();
}
void _dispatch_runloop_queue_xref_dispose() { LINUX_PORT_ERROR();  }

void strlcpy() { LINUX_PORT_ERROR();  }
void _dispatch_runloop_queue_dispose() { LINUX_PORT_ERROR();  }
char* mach_error_string(mach_msg_return_t x) {
  LINUX_PORT_ERROR();
}

void mach_vm_deallocate() { LINUX_PORT_ERROR();  }

mach_port_t pthread_mach_thread_np() {
  return (mach_port_t)pthread_self();
}

mach_port_t mach_task_self() {
  return (mach_port_t)pthread_self();
}

int sysctlbyname(const char *name, void *oldp, size_t *oldlenp,
		 void *newp, size_t newlen) {
  LINUX_PORT_ERROR();
}

int kevent64(int kq, const struct kevent *changelist, int nchanges, struct kevent *eventlist, int nevents,unsigned int flags, const struct timespec *timeout)
{
     return kevent(kq,changelist,nchanges,eventlist,nevents,timeout);
}

/*
 * Stubbed out static data
 */

pthread_key_t dispatch_voucher_key;
pthread_key_t dispatch_pthread_root_queue_observer_hooks_key;

unsigned short dispatch_timer__program_semaphore;
unsigned short dispatch_timer__wake_semaphore;
unsigned short dispatch_timer__fire_semaphore;
unsigned short dispatch_timer__configure_semaphore;
void (*_dispatch_block_special_invoke)(void*);
struct dispatch_queue_attr_s _dispatch_queue_attr_concurrent;
