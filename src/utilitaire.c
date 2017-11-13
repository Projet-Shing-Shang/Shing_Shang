#include <utilitaire.h>

void clear_console()  // Vide la console
{
    #ifdef linux  // Si on est sur linux
        system("clear");
    #elif _WIN32  // Si on est sur windows
        system("cls");
    #endif
}

void vider_buffer() // Vide le buffer pour le scanf
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
