#include <bsp.h>
#include <sysctl.h>

int core1_function(void *ctx)
{
    uint64_t core = current_coreid();
    printf("Core %ld Hello world\n", core);
    while(1);
}

int main(void)
{
    sysctl_pll_set_freq(SYSCTL_PLL0, 800000000);
    uint64_t core = current_coreid();
    int data;
    printf("Core %ld Hello world\n", core);
    register_core1(core1_function, NULL);

    /* Clear stdin buffer before scanf */
    sys_stdin_flush();

    scanf("%d", &data);
    printf("\nData is %d\n", data);
    
    while(1);
    return 0;
}
