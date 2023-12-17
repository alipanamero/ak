#include <linux/list.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/moduleparam.h>
#include <linux/ktime.h>
#include <linux/slab.h>

MODULE_AUTHOR("IO-14 Mir Ali Mir Sanzhari");
MODULE_DESCRIPTION("Lab3");
MODULE_LICENSE("Dual BSD/GPL");

static uint amount = 1;

module_param(amount, uin
	struct list_head tlist;
	ktime_t time;
};

static LIST_HEAD(my_list_head);

static int __init hello_init(void)
{
	if (amount == 0) {
		pr_warn("Parameter = 0\n");
	} else if (amount >= 5 && amount <= 10) {
		pr_warn("5 >= Parameter <= 10\n");
	} else if (amount > 10) {
		pr_warn("Parameter > 10(fail)\n");
		return -EINVAL;
	}

	int i=0;

	for (i = 0; i < amount; i++) {
		struct my_struct *ms;

		ms = kmalloc(sizeof(struct my_struct), GFP_KERNEL);
		ms->time = ktime_get();
		list_add_tail(&ms->tlist, &my_list_head);

		pr_info("Hello, world!\n");
	}

	return 0;
}

static void __exit hello_exit(void)
{
	int count = 0;
	struct my_struct *t, *tmp;

	list_for_each_entry_safe(t, tmp, &my_list_head, tlist) {
		pr_info("i: %d; ktime = %lld\n", count++, ktime_to_ns(t->time));
		list_del(&t->tlist);
		kfree(t);
	}
	pr_info("Module is undeployed\n");
}

module_init(hello_init);
module_exit(hello_exit);
