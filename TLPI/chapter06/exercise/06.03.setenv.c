/*==================================================================================================
 * 练习3：使用 getenv() 函数、putenv() 函数，必要时可直接修改 environ，来实现 setenv() 函数和 unsetenv() 函数。
此处的 unsetenv() 函数应检查是否对环境变量进行了多次定义，如果是多次定义则将移除对该变量的所有定义（glibc 版本的 unsetenv() 函数实现了这一功能）。
================================================================================================== */