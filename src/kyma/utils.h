#ifndef KYMA_UTILS_H
    #define KYMA_UTILS_H
    #include "uart.h"

    // Colors for terminal output
    #define C "\x1b[36m"   // Cyan
    #define R "\x1b[0m"    // Reset
    #define S "\x1b[32m"   // Green
    #define M "\x1b[35m"   // Magenta


   const char *icon[] = {
        C "    ╱▔▔▔▔▔▔╲   " R,
        C "  ╱  ▔▔▔▔╲   ╲  " R,
        C " ▏   ╱    ╲   ▕ " R,
        C " ▏  ╱  ╱╲  ╲  ▕ " R,
        C " ▏ ╱  ╱  ╲  ╲ ▕ " R,
        C "  ╲  ╱____╲  ╱  " R,
        C "    ╲______╱   " R,
    };

    const char *wordmark[] = {
        "",
        "  " C "██╗  ██╗██╗   ██╗███╗   ███╗ █████╗ " R,
        "  " C "██║ ██╔╝╚██╗ ██╔╝████╗ ████║██╔══██╗" R,
        "  " C "█████╔╝  ╚████╔╝ ██╔████╔██║███████║" R,
        "  " C "██╔═██╗   ╚██╔╝  ██║╚██╔╝██║██╔══██║" R,
        "  " C "██║  ██╗   ██║   ██║ ╚═╝ ██║██║  ██║" R,
        "  " C "╚═╝  ╚═╝   ╚═╝   ╚═╝     ╚═╝╚═╝  ╚═╝" R,
        "  " S "Obsidian Note Generator  " M "*  v1.0.0-beta" R,
    };

    int icon_lines = sizeof(icon) / sizeof(icon[0]);
    int wordmark_lines = sizeof(wordmark) / sizeof(wordmark[0]);

    void show_logo(){
        for (int i = 0; i < icon_lines; i++) {
                printf("%s", icon[i]);
                if (i < wordmark_lines) {
                    printf("   %s", wordmark[i]);
                }
                printf("\n");
            }
    }


#endif // KYMA_UTILS_H