#include <stdio.h>
#include "microshell.h"
#include "msconf.h"
 
static void utx(char c)
{
    putchar(c);
}
 
static char urx(void)
{
    return getchar();
}
 
static void action_hook(MSCORE_ACTION action)
{
}
 
int main(void)
{
    char buf[MSCONF_MAX_INPUT_LENGTH];
    MICROSHELL ms;
 
    printf(
            "\r\n\r\n"
            "======================================\r\n"
            " MicroShell Simple Example for LPC824 \r\n"
            "======================================\r\n"
            );
    printf(" Type 'help' for a list of commands.\r\n");
 
    microshell_init(&ms, utx, urx, action_hook);
 
    while (1) {
        printf("MicroShell>");
        microshell_getline(&ms, buf, sizeof(buf));
    }
 
    return 0;
}