#include <linux/pid_namespace.h>
#include <linux/refcount.h>

struct pid init_struct_pid = {
	.count = REFCOUNT_INIT(1),
	.tasks = {
		{ .first = NULL },
		{ .first = NULL },
		{ .first = NULL },
	},
	.level = 0,
	.numbers = { {
		.nr = 0,
		.ns = &init_pid_ns,
	}, }
};


struct task_struct *find_task_by_pid_ns(pid_t nr, struct pid_namespace *ns)
{
	return lx_emul_task_get(nr);
}
