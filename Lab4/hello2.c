#include <hello1.h>

MODULE_AUTHOR("IO-14 Mir Sanzhari Mir Ali");
MODULE_DESCRIPTION("lab4");
MODULE_LICENSE("Dual BSD/GPL");

static uint amount = 1;

module_param(amount, uint, 0);
MODULE_PARM_DESC(amount, " amount lab4\n");

static int __init init_hello(void)
{
	pr_info("Success! hello2 has been initiated\n");
	print_hello(amount);
	return 0;
}

static void __exit exit_hello(void)
{
	pr_info("Success! hello2 has been unloaded\n");
}

module_init(init_hello);
module_exit(exit_hello);

