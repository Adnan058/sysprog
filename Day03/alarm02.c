#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

volatile sig_atomic_t print_flag = false;

void handle_alarm( int sig ) {
    print_flag = true;
}

int main() {
    signal( SIGALRM, handle_alarm ); // Install handler first,
    alarm( 1 ); // before scheduling it to be called.

    for (;;) {
        if ( print_flag ) {
            printf( "Hello\n" );
            print_flag = false;
            alarm( 1 );
        }
    }
}
