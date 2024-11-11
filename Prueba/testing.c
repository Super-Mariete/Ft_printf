#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define PINK "\033[35m"
#define TITLE "\033[4m\033[33m"

#define TEST(n, format, ...)do                                      \
	{                                                               \
		printf(TITLE "Test %d:" RESET "\n", n);                     \
		freopen("txt1.txt", "w", stdout);                           \
		int len1 = printf(format, ##__VA_ARGS__);                   \
		freopen("txt2.txt", "w", stdout);                           \
		int len2 = ft_printf(format, ##__VA_ARGS__);                \
		freopen("/dev/tty", "w", stdout);                           \
		if (system("diff txt1.txt txt2.txt") != 0 || len1 != len2)  \
			    printf(RED ".KO" RESET "\n");                       \
        else                                                        \
                printf(GREEN ".OK" RESET "\n");                     \
        printf("len printf = %d, len ft_printf = %d\n", len1, len2);\
		printf("your result:\n");                                   \
        ft_printf(format, ##__VA_ARGS__);                           \
        printf("\nExpected:\n");                                    \
        printf(format, ##__VA_ARGS__);                              \
        printf("\n");                                               \
        remove("txt1.txt");                                         \
        remove("txt2.txt");                                         \
    } while (0)                                                     \

	void s_test()
{
    char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus. Quem num gosta di mé, boa gentis num é. Quem manda na minha terra sou euzis!";
    TEST(1, " %s", "");
    TEST(2, "%s ", "");
    TEST(3, " %s ", "");
    TEST(4, " %s ", "-");
    TEST(5, " %s %s ", "", "-");
    TEST(6, " %s %s ", " - ", "");
    TEST(7, " %s %s %s %s %s", " - ", "", "4", "", "2 ");
    TEST(8, " %s %s %s %s %s ", " - ", "", "4", "", s2);
    TEST(9, " NULL %s NULL ", NULL);
    TEST(10, "%s", "abc");
    TEST(11, "111%s333", "222");
    TEST(12, "%s333", "222");
    TEST(13, "111%s", "222");
    TEST(14, "{%s}", 0);
    TEST(15, "{%s}", "");
    TEST(16, "111%s333%s555", "222", "444");
    TEST(17, "111%s333%s555%saaa%sccc", "222", "444", "666", "bbb");
    TEST(18, "%s%s%s%s%s", "1", "2", "3", "4", "5");
    TEST(19, "%s", "las cosas");
    
}

void c_test() {
    TEST(1, "%c", '0');
    TEST(2, " %c ", '0');
    TEST(3, " %c", '0' - 256);
    TEST(4, "%c ", '0' + 256);
    TEST(5, " %c %c %c ", '0', 0, '1');
    TEST(6, " %c %c %c ", ' ', ' ', ' ');
    TEST(7, " %c %c %c ", '1', '2', '3');
    TEST(8, " %c %c %c ", '2', '1', 0);
    TEST(9, " %c %c %c ", 0, '1', '2');
    TEST(10, " NULL %c %c ",  0, '2');
    TEST(11, "%c", 'a');
    TEST(12, "111%c  %c333", '2','a');
}

void	u_test(void)
{
	TEST(1, " %u ", 0);
	TEST(2, " %u ", -1);
	TEST(3, " %u ", 1);
	TEST(4, " %u ", 9);
	TEST(5, " %u ", 10);
	TEST(6, " %u ", 11);
	TEST(7, " %u ", 15);
	TEST(8, " %u ", 16);
	TEST(9, " %u ", 17);
	TEST(10, " %u ", 99);
	TEST(11, " %u ", 100);
	TEST(12, " %u ", 101);
	TEST(13, " %u ", -9);
	TEST(14, " %u ", -10);
	TEST(15, " %u ", -11);
	TEST(16, " %u ", -14);
	TEST(17, " %u ", -15);
	TEST(18, " %u ", -16);
	TEST(19, " %u ", -99);
	TEST(20, " %u ", -100);
	TEST(21, " %u ", -101);
	TEST(22, " %u ", INT_MAX);
	TEST(23, " %u ", INT_MIN);
	TEST(24, " %u ", LONG_MAX);
	TEST(25, " %u ", LONG_MIN);
	TEST(26, " %u ", UINT_MAX);
	TEST(27, " %u ", ULONG_MAX);
	TEST(28, " %u ", 9223372036854775807LL);
	TEST(29, " %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN,
		ULONG_MAX, 0, -42);
	TEST(30, " %u", 0);
	TEST(31, "%u ", 0);
	TEST(32, " %u ", 0);
	TEST(33, " %u ", 0);
	TEST(34, " %u %u ", 0, 1);
	TEST(35, " %u %u ", 0, 1);
	TEST(36, " %u %u %u %u %u", 0, 1, 2, 3, 4);
	TEST(37, " %u %u %u %u %u ", 0, 1, 2, 3, 4);
	TEST(38, " NULL %u NULL ", 0);
    TEST(39, "%u", 0);
    TEST(40, "%u", -1);

}
void x_test(void)
{
    TEST(1, " %x ", 0);
    TEST(2, "%x ", 0);
    TEST(3, " %x ", 0);
    TEST(4, " %x ", 0);
    TEST(5, " %x %x ", 0, 1);
    TEST(6, " %x %x ", 0, 1);
    TEST(7, " %x %x %x %x %x", 0, 1, 2, 3, 4);
    TEST(8, " %x %x %x %x %x ", 0, 1, 2, 3, 4);
    TEST(9, " NULL %x NULL ", 0);
    TEST(10, " %x ", -1);
    TEST(11, " %x ", 1);
    TEST(12, " %x ", 9);
    TEST(13, " %x ", 10);
    TEST(14, " %x ", 11);
    TEST(15, " %x ", 15);
    TEST(16, " %x ", 16);
    TEST(17, " %x ", 17);
    TEST(18, " %x ", 99);
    TEST(19, " %x ", 100);
    TEST(20, " %x ", 101);
    TEST(21, " %x ", -9);
    TEST(22, " %x ", -10);
    TEST(23, " %x ", -11);
    TEST(24, " %x ", -14);
    TEST(25, " %x ", -15);
    TEST(26, " %x ", -16);
    TEST(27, " %x ", -99);
    TEST(28, " %x ", -100);
    TEST(29, " %x ", -101);
    TEST(30, " %x ", INT_MAX);
    TEST(31, " %x ", INT_MIN);
    TEST(32, " %x ", LONG_MAX);
    TEST(33, " %x ", LONG_MIN);
    TEST(34, " %x ", UINT_MAX);
    TEST(35, " %x ", ULONG_MAX);
    TEST(36, " %x ", 9223372036854775807LL);
    TEST(37, " %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    TEST(38, " %x ", 42);
    TEST(39, " %x ", -42);
    TEST(40, "%x", -10);
    TEST(41, "%x", -200000);
    TEST(42, "%x", -6000023);
    TEST(43, "%x", 0xabcdef);
    TEST(44, "%x", 0x7fedcba1);
    TEST(45, "dgs%xxx", 10);
    TEST(46, "%x%xx%x", 1, 2, -3);

}

void upperX_test(void)
{
    TEST(1, " %X ", 0);
    TEST(2, "%X ", 0);
    TEST(3, " %X ", 0);
    TEST(4, " %X ", 0);
    TEST(5, " %X %X ", 0, 1);
    TEST(6, " %X %X ", 0, 1);
    TEST(7, " %X %X %X %X %X", 0, 1, 2, 3, 4);
    TEST(8, " %X %X %X %X %X ", 0, 1, 2, 3, 4);
    TEST(9, " NULL %X NULL ", 0);
    TEST(10, " %X ", -1);
    TEST(11, " %X ", 1);
    TEST(12, " %X ", 9);
    TEST(13, " %X ", 10);
    TEST(14, " %X ", 11);
    TEST(15, " %X ", 15);
    TEST(16, " %X ", 16);
    TEST(17, " %X ", 17);
    TEST(18, " %X ", 99);
    TEST(19, " %X ", 100);
    TEST(20, " %X ", 101);
    TEST(21, " %X ", -9);
    TEST(22, " %X ", -10);
    TEST(23, " %X ", -11);
    TEST(24, " %X ", -14);
    TEST(25, " %X ", -15);
    TEST(26, " %X ", -16);
    TEST(27, " %X ", -99);
    TEST(28, " %X ", -100);
    TEST(29, " %X ", -101);
    TEST(30, " %X ", INT_MAX);
    TEST(31, " %X ", INT_MIN);
    TEST(32, " %X ", LONG_MAX);
    TEST(33, " %X ", LONG_MIN);
    TEST(34, " %X ", UINT_MAX);
    TEST(35, " %X ", ULONG_MAX);
    TEST(36, " %X ", 9223372036854775807LL);
    TEST(37, " %X %X %X %X %X %X %X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    TEST(38, " %X ", 42);
    TEST(39, " %X ", -42);
    TEST(40, "%X", 0xabcdef);
    TEST(41, "%X", 0x7fedcba1);
    TEST(42, "dgs%Xxx", 10);
    TEST(43, "%X%Xx%X", 1, 2, -3);

}
void percent_test(void)
{
    TEST(1, " %%", 0);
    TEST(2, "%% ", 0);
    TEST(3, " %% ", 0);
    TEST(4, " %% ", 0);
    TEST(5, " %% %% ", 0, 1);
    TEST(6, " %% %% ", 0, 1);
    TEST(7, " %% %% %% %% %%", 0, 1, 2, 3, 4);
    TEST(8, " %% %% %% %% %% ", 0, 1, 2, 3, 4);
    TEST(9, " NULL %% NULL ", 0);
    TEST(10, " %% ");
    TEST(11, " %%%% ");
    TEST(12, " %% %% %% ");
    TEST(13, " %%  %%  %% ");
    TEST(14, " %%   %%   %% ");
    TEST(15, "%%");
    TEST(16, "%% %%");
}
void d_test(void)
{
    TEST(1, " %d ", 0);
    TEST(2, "%d ", 0);
    TEST(3, " %d ", 0);
    TEST(4, " %d ", 0);
    TEST(5, " %d %d ", 0, 1);
    TEST(6, " %d %d ", 0, 1);
    TEST(7, " %d %d %d %d %d", 0, 1, 2, 3, 4);
    TEST(8, " %d %d %d %d %d ", 0, 1, 2, 3, 4);
    TEST(9, " NULL %d NULL ", 0);
    TEST(10, " %d ", -1);
    TEST(11, " %d ", 1);
    TEST(12, " %d ", 9);
    TEST(13, " %d ", 10);
    TEST(14, " %d ", 11);
    TEST(15, " %d ", 15);
    TEST(16, " %d ", 16);
    TEST(17, " %d ", 17);
    TEST(18, " %d ", 99);
    TEST(19, " %d ", 100);
    TEST(20, " %d ", 101);
    TEST(21, " %d ", -9);
    TEST(22, " %d ", -10);
    TEST(23, " %d ", -11);
    TEST(24, " %d ", -14);
    TEST(25, " %d ", -15);
    TEST(26, " %d ", -16);
    TEST(27, " %d ", -99);
    TEST(28, " %d ", -100);
    TEST(29, " %d ", -101);
    TEST(30, " %d ", INT_MAX);
    TEST(31, " %d ", INT_MIN);
    TEST(32, " %d ", LONG_MAX);
    TEST(33, " %d ", LONG_MIN);
    TEST(34, " %d ", UINT_MAX);
    TEST(35, " %d ", ULONG_MAX);
    TEST(36, " %d ", 9223372036854775807LL);
    TEST(37, " %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    TEST(38, "%d", INT_MIN);
}
void i_test(void)
{
    TEST(1, " %i ", 0);
    TEST(2, "%i ", 0);
    TEST(3, " %i ", 0);
    TEST(4, " %i ", 0);
    TEST(5, " %i %i ", 0, 1);
    TEST(6, " %i %i ", 0, 1);
    TEST(7, " %i %i %i %i %i", 0, 1, 2, 3, 4);
    TEST(8, " %i %i %i %i %i ", 0, 1, 2, 3, 4);
    TEST(9, " NULL %i NULL ", 0);
    TEST(10, " %i ", -1);
    TEST(11, " %i ", 1);
    TEST(12, " %i ", 9);
    TEST(13, " %i ", 10);
    TEST(14, " %i ", 11);
    TEST(15, " %i ", 15);
    TEST(16, " %i ", 16);
    TEST(17, " %i ", 17);
    TEST(18, " %i ", 99);
    TEST(19, " %i ", 100);
    TEST(20, " %i ", 101);
    TEST(21, " %i ", -9);
    TEST(22, " %i ", -10);
    TEST(23, " %i ", -11);
    TEST(24, " %i ", -14);
    TEST(25, " %i ", -15);
    TEST(26, " %i ", -16);
    TEST(27, " %i ", -99);
    TEST(28, " %i ", -100);
    TEST(29, " %i ", -101);
    TEST(30, " %i ", INT_MAX);
    TEST(31, " %i ", INT_MIN);
    TEST(32, " %i ", LONG_MAX);
    TEST(33, " %i ", LONG_MIN);
    TEST(34, " %i ", UINT_MAX);
    TEST(35, " %i ", ULONG_MAX);
    TEST(36, " %i ", 9223372036854775807LL);
    TEST(37, " %i %i %i %i %i %i %i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    TEST(38, "%i", 42);
    TEST(39, "%i%i", 42, -1);
    TEST(40, "%i %i", -1, 42);
}

void p_test() {
    TEST(1, " %p ", -1);
    TEST(2, " %p ", 1);
    TEST(3, " %p ", 15);
    TEST(4, " %p ", 16);
    TEST(5, " %p ", 17);
    TEST(6, " %p %p ", LONG_MIN, LONG_MAX);
    TEST(7, " %p %p ", INT_MIN, INT_MAX);
    TEST(8, " %p %p ", ULONG_MAX, -ULONG_MAX);
    TEST(9, " %p %p ", 0, 0);
    TEST(10, "%p", 1);
    TEST(11, "%p", -1);
    TEST(12, "%p", 105);
    TEST(13, "%p", 0);
    TEST(14, "%p", "h");
    TEST(15, "%p", 'a');
    TEST(16, "%p", 0x12345678);
    TEST(17,"%p", NULL);
    TEST(18, "%p", (void *)-14523);
    TEST(19,"0x%p-", (void *)ULONG_MAX);
    TEST(20, "%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
    TEST(21, "%p", (void *)LONG_MAX + 423856);
    TEST(22,"%p",  (void *)0);
    TEST(23, "%p", NULL);
    TEST(24, "%pp%p%p", (void *)LONG_MAX + 423856, (void *)0,(void *)INT_MAX);
    TEST(25, " %p %p ", 0, 0);
    

}

void plus_test(void)
{
    TEST(1, " %+d ", 0);
    TEST(2, "%+d ", -1);
    TEST(3, " %+d ", 9);
    TEST(4, " %+d ", 10);
    TEST(5, " %+d ", 11);
    TEST(6, " %+d ", 15);
    TEST(7, " %+d ", 16);
    TEST(8, " %+d ", 17);
    TEST(9, " %+d ", 99);
    TEST(10, " %+d ", 100);
    TEST(11, " %+d ", 101);
    TEST(12, " %+d ", -9);
    TEST(13, " %+d ", -10);
    TEST(14, " %+d ", -11);
    TEST(15, " %+d ", -14);
    TEST(16, " %+d ", -15);
    TEST(17, " %+d ", -16);
    TEST(18, " %+d ", -99);
    TEST(19, " %+d ", -100);
    TEST(20, " %+d ", -101);
    TEST(21, " %+d ", INT_MAX);
    TEST(22, " %+d ", INT_MIN);
    TEST(23, " %+d ", LONG_MAX);
    TEST(24, " %+d ", LONG_MIN);
    TEST(25, " %+d ", UINT_MAX);
    TEST(26, " %+d ", ULONG_MAX);
    TEST(27, " %+d ", 9223372036854775807LL);
    TEST(28, " %+d %+d %+d %+d %+d %+d %+d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    TEST(29, " %+i ", 0);
    TEST(30, " %+i ", -1);
    TEST(31, " %+i ", 1);
    TEST(32, " %+i ", 9);
    TEST(33, " %+i ", 10);
    TEST(34, " %+i ", 11);
    TEST(35, " %+i ", 15);
    TEST(36, " %+i ", 16);
    TEST(37, " %+i ", 17);
    TEST(38, " %+i ", 99);
    TEST(39, " %+i ", 100);
    TEST(40, " %+i ", 101);
    TEST(41, " %+i ", -9);
    TEST(42, " %+i ", -10);
    TEST(43, " %+i ", -11);
    TEST(44, " %+i ", -14);
    TEST(45, " %+i ", -15);
    TEST(46, " %+i ", -16);
    TEST(47, " %+i ", -99);
    TEST(48, " %+i ", -100);
    TEST(49, " %+i ", -101);
    TEST(50, " %+i ", INT_MAX);
    TEST(51, " %+i ", INT_MIN);
    TEST(52, " %+i ", LONG_MAX);
    TEST(53, " %+i ", LONG_MIN);
    TEST(54, " %+i ", UINT_MAX);
    TEST(55, " %+i ", ULONG_MAX);
    TEST(56, " %+i ", 9223372036854775807LL);
    TEST(57, " %+i %+i %+i %+i %+i %+i %+i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
}

void zero_test(){
    TEST(1, " %01d ", 0);
    TEST(2, (" %02d ", -1));
    TEST(3, (" %04d ", 9));
    TEST(4, (" %01d ", 10));
    TEST(5, (" %02d ", 11));
    TEST(6, (" %03d ", 15));
    TEST(7, (" %04d ", 16));
    TEST(8, (" %05d ", 17));
    TEST(9, (" %01d ", 99));
    TEST(10, (" %02d ", 100));
    TEST(11, (" %03d ", 101));
    TEST(12, (" %01d ", -9));
    TEST(13, (" %02d ", -10));
    TEST(14, (" %03d ", -11));
    TEST(15, (" %04d ", -14));
    TEST(16, (" %05d ", -15));
    TEST(17, (" %06d ", -16));
    TEST(18, (" %01d ", -99));
    TEST(19, (" %02d ", -100));
    TEST(20, (" %03d ", -101));
    TEST(21, (" %09d ", INT_MAX));
    TEST(22, (" %010d ", INT_MIN));
    TEST(23, (" %011d ", LONG_MAX));
    TEST(24, (" %012d ", LONG_MIN));
    TEST(25, (" %013d ", UINT_MAX));
    TEST(26, (" %014d ", ULONG_MAX));
    TEST(27, (" %015d ", 9223372036854775807LL));
    TEST(28, (" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
    TEST(29, (" %01i ", 0));
    TEST(30, (" %02i ", -1));
    TEST(31, (" %03i ", 1));
    TEST(32, (" %04i ", 9));
    TEST(33, (" %01i ", 10));
    TEST(34, (" %02i ", 11));
    TEST(35, (" %03i ", 15));
    TEST(36, (" %04i ", 16));
    TEST(37, (" %05i ", 17));
    TEST(38, (" %01i ", 99));
    TEST(39, (" %02i ", 100));
    TEST(40, (" %03i ", 101));
    TEST(41, (" %01i ", -9));
    TEST(42, (" %02i ", -10));
    TEST(43, (" %03i ", -11));
    TEST(44, (" %04i ", -14));
    TEST(45, (" %05i ", -15));
    TEST(46, (" %06i ", -16));
    TEST(47, (" %01i ", -99));
    TEST(48, (" %02i ", -100));
    TEST(49, (" %03i ", -101));
    TEST(50, (" %09i ", INT_MAX));
    TEST(51, (" %010i ", INT_MIN));
    TEST(52, (" %011i ", LONG_MAX));
    TEST(53, (" %012i ", LONG_MIN));
    TEST(54, (" %013i ", UINT_MAX));
    TEST(55, (" %014i ", ULONG_MAX));
    TEST(56, (" %015i ", 9223372036854775807LL));
    TEST(57, (" %09i %010i %011i %012i %013i %014i %015i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
    TEST(58, (" %01u ", 0));
    TEST(59, (" %02u ", -1));
    TEST(60, (" %03u ", 1));
    TEST(61, (" %04u ", 9));
    TEST(62, (" %01u ", 10));
    TEST(63, (" %02u ", 11));
    TEST(64, (" %03u ", 15));
    TEST(65, (" %04u ", 16));
    TEST(66, (" %05u ", 17));
    TEST(67, (" %01u ", 99));
    TEST(68, (" %02u ", 100));
    TEST(69, (" %03u ", 101));
    TEST(70, (" %01u ", -9));
    TEST(71, (" %02u ", -10));
    TEST(72, (" %03u ", -11));
    TEST(73, (" %04u ", -14));
    TEST(74, (" %05u ", -15));
    TEST(75, (" %06u ", -16));
    TEST(76, (" %01u ", -99));
    TEST(77, (" %02u ", -100));
    TEST(78, (" %03u ", -101));
    TEST(79, (" %09u ", INT_MAX));
    TEST(80, (" %010u ", INT_MIN));
    TEST(81, (" %011u ", LONG_MAX));
    TEST(82, (" %012u ", LONG_MIN));
    TEST(83, (" %013u ", UINT_MAX));
    TEST(84, (" %014u ", ULONG_MAX));
    TEST(85, (" %015u ", 9223372036854775807LL));
    TEST(86, (" %09u %010u %011u %012u %013u %014u %015u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
    TEST(87, (" %01x ", 0));
    TEST(88, (" %02x ", -1));
    TEST(89, (" %03x ", 1));
    TEST(90, (" %04x ", 9));
    TEST(91, (" %01x ", 10));
    TEST(92, (" %02x ", 11));
    TEST(93, (" %03x ", 15));
    TEST(94, (" %04x ", 16));
    TEST(95, (" %05x ", 17));
    TEST(96, (" %01x ", 99));
    TEST(97, (" %02x ", 100));
    TEST(98, (" %03x ", 101));
    TEST(99, (" %01x ", -9));
    TEST(100, (" %02x ", -10));
    TEST(101, (" %03x ", -11));
    TEST(102, (" %04x ", -14));
    TEST(103, (" %05x ", -15));
    TEST(104, (" %06x ", -16));
    TEST(105, (" %01x ", -99));
    TEST(106, (" %02x ", -100));
    TEST(107, (" %03x ", -101));
    TEST(108, (" %09x ", INT_MAX));
    TEST(109, (" %010x ", INT_MIN));
    TEST(110, (" %011x ", LONG_MAX));
    TEST(111, (" %012x ", LONG_MIN));
    TEST(112, (" %013x ", UINT_MAX));
    TEST(113, (" %014x ", ULONG_MAX));
    TEST(114, (" %015x ", 9223372036854775807LL));
    TEST(115, (" %09x %010x %011x %012x %013x %014x %015x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
    TEST(116, (" %01X ", 0));
    TEST(117, (" %02X ", -1));
    TEST(118, (" %03X ", 1));
    TEST(119, (" %04X ", 9));
    TEST(120, (" %01X ", 10));
    TEST(121, (" %02X ", 11));
    TEST(122, (" %03X ", 15));
    TEST(123, (" %04X ", 16));
    TEST(124, (" %05X ", 17));
    TEST(125, (" %01X ", 99));
    TEST(126, (" %02X ", 100));
    TEST(127, (" %03X ", 101));
    TEST(128, (" %01X ", -9));
    TEST(129, (" %02X ", -10));
    TEST(130, (" %03X ", -11));
    TEST(131, (" %04X ", -14));
    TEST(132, (" %05X ", -15));
    TEST(133, (" %06X ", -16));
    TEST(134, (" %01X ", -99));
    TEST(135, (" %02X ", -100));
    TEST(136, (" %03X ", -101));
    TEST(137, (" %09X ", INT_MAX));
    TEST(138, (" %010X ", INT_MIN));
    TEST(139, (" %011X ", LONG_MAX));
    TEST(140, (" %012X ", LONG_MIN));
    TEST(141, (" %013X ", UINT_MAX));
    TEST(142, (" %014X ", ULONG_MAX));
    TEST(143, (" %015X ", 9223372036854775807LL));
    TEST(144, (" %09X %010X %011X %012X %013X %014X %015X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
}

void simple_test()
{
    TEST(1, " hola mundo");
    TEST(2, " estamos escribiendo un test \n");
    TEST(3, "\n\v\t\r\f\b\a");
    TEST(4, " %s %c %d %i %u %x %X %p %%", "hola", 'c', 42, 42, 42, 42, 42, 42);
    TEST(5, "%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
    TEST(6, " %%%s ", "42");
    TEST(7, " %%%c ", 'A');
    TEST(8, " %%%d ", 42);
    TEST(9, " %%%c%%%s ", 'a', "27");
    TEST(10, " %%%c%%%s%%%d ", 'a', "27", 42);
    TEST(11, " %%c ", 'a');
    TEST(12, "&g*N |D7Yf%iy\tDAx3AqS%u>KL(I%p*\fK5B\nh]%u-y%X %p%dJ}'ZVV\t%xTWr's't", 2128754483, -354672185, (void *)-1392844369646924149, 64476362, -991208294, (void *)-3333247611148773223, 241563957, -215998421);
    //TEST(13, "g[#[,f@\vaM%cF-.6Z%X`WE@Em`%i9&aF%iRaaJ|%pu*<]%d*=M-.\s1%dc", 2111875731, -1698834862, 1157537571, 1252752773, (void *)2586644020698456485, 1956149085, -1074773975);
    //TEST(14, ">LHRB%d\rQ+:%d*Q|v%X\t" j@^R%dPl->*%dFb\n_, -1988000032, 1166352773, 1599722101, 1407589056, 499735280);
    TEST(15,"\f{""w%p=dF,w%xXH", (void *)-1943992436323341412, -120246203);
    //TEST(16, ""H+NR%%bVb6:EF0\r%x%su%u<}\nnG%d$>!~"", 1981762668, "#G1|Jq)/(l=6mka'1`j29zs\tr5=EI`F<l&H^H%X3$\tbnoC%=GiZDd0f#s~9Km 3\rvAE~9", -546229617, -930805903);
    //TEST(17, ""P+8V)_#\n%u/W"%ds'@}_ C%p%su>", 245461684, -1196885550, (void *)1235583772827579250, ".R}K?4)");
    //TEST(18, ""%XPXNPSR&%XLF\n|?\"", -1430580808, -1992646744");
    TEST(20, "\001\002\007\v\010\f\r\n");

}  

void run_test(char *specifier) {
    if (strcmp(specifier, "s") == 0) {
        s_test();
    } else if (strcmp(specifier, "c") == 0) {
        c_test();
    } else if (strcmp(specifier, "u") == 0) {
        u_test();
    } else if (strcmp(specifier, "x") == 0) {
        x_test();
    } else if (strcmp(specifier, "X") == 0) {
        upperX_test();
    } else if (strcmp(specifier, "%") == 0) {
        percent_test();
    } else if (strcmp(specifier, "d") == 0) {
        d_test();
    } else if (strcmp(specifier, "i") == 0) {
        i_test();
    } else if (strcmp(specifier, "simple") == 0) {
        simple_test();
    } else if (strcmp(specifier, "p") == 0) {
        p_test();
    } else if (strcmp(specifier, "+") == 0) {
        plus_test();
    } else if (strcmp(specifier, "0") == 0) {
        zero_test();
    } else if (strcmp(specifier, "all") == 0) {
        s_test();
        c_test();
        u_test();
        x_test();
        upperX_test();
        percent_test();
        d_test();
        i_test();
        simple_test();
        p_test();
        plus_test();
        zero_test();
    } else {
        printf("Especificador no reconocido: %s\n", specifier);
    }
}
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Por favor, proporciona un especificador como argumento.\n");
        return 1;
    }

    char *specifier = argv[1];
    run_test(specifier);

    return 0;
}
