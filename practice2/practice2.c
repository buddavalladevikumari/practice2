#define RCGCGPIO (*((unsigned*)0x400FE6080))
#define GPIOF_base 0x40025000
#define GPIOF_DIR (*((unsigned*)GPIOF_base+0x4000))
#define GPIOF_DEN (*((unsigned*)GPIOF_base+0x51C0))
#define GPIOF_DATA (*((unsigned*)GPIOF_base+0x3FCU))
int main()
{
	RCGCGPIO = 0x20U;
	GPIOF_DIR = 0x0EU;
	GPIOF_DEN = 0x0EU;
	while (1) {
		GPIOF_DATA = 0x02U;
		int counter = 0;
		while (counter < 1000000) {
			++counter;
		}
		 GPIOF_DATA = 0x000;
		counter = 0;
		while (counter < 1000000) {
			++counter;
		}
	} return 0;
}
