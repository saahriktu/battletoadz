/*
 * Battletoadz v0.3
 * nonvisual arcade game
 * License: GNU GPLv3
 * Author: Artem Kurashov
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main()
{
    srand(time(0));
    int             tty_in,
                    x[2],
                    y[2],
                    z,
                    l = 3,
		    zz = 0;
    printf(" --= Battle ToadZ =--\n");
    for (;;) {
	z = (int) (10.0 * rand() / (RAND_MAX + 1.0));
	x[1] = (int) (3.0 * rand() / (RAND_MAX + 1.0));
	y[1] = (int) (3.0 * rand() / (RAND_MAX + 1.0));
	printf("choose your yz-projection sector:");
	scanf("%1d", &tty_in);
	getchar();
	x[0] = (tty_in - 1) % 3;
	y[0] = (tty_in - 1) / 3;
	switch (z) {
	case 0:
	    printf("Abyss\n");
	    if (y[0] < 1) {
		printf("Game over\n");
		return 0;
	    } else
	    printf("GO->\n");
	    break;
	case 1:
	    printf("Pig\n");
	    if (x[0] == x[1] && y[0] == y[1]) {
		printf("Ouch! -1 life point\n");
		l--;
	    } else
	    printf("GO->\n");
	    break;
	case 2:
	    printf("Sceleton\n");
	    if (x[0] == x[1] && y[0] == y[1]) {
		printf("Ouch! -1 life point\n");
		l--;
	    } else
	    printf("GO->\n");
	    break;
	case 3:
	    printf("Rat\n");
	    if (x[0] == x[1] && y[0] == y[1]) {
		printf("Ouch! -1 life point\n");
		l--;
	    } else
	    printf("GO->\n");
	    break;
	case 4:
	    printf("Frog UFO\n");
	    if (x[0] == x[1]) {
		printf("Ouch! -1 life point\n");
		l--;
	    } else
	    printf("GO->\n");
	    break;
	case 5:
	    printf("Rocket launching to sky\n");
	    if (x[0] == x[1]) {
		printf("Ouch! -1 life point\n");
		l--;
	    } else
	    printf("GO->\n");
	    break;
	case 6:
	    printf("Wall from sky to ground\n");
	    if (y[0] != 0) {
		printf("Game over\n");
		return 0;
	    } else
	    printf("GO->\n");
	    break;
	case 7:
	    printf("Wall\n");
	    if (y[0] == y[1]) {
		printf("Game over\n");
		return 0;
	    } else
	    printf("GO->\n");
	    break;
	default:
	    printf("Fly\n");
	    if (x[0] == x[1] && y[0] == y[1]) {
		printf("Yeah! +1 life point\n");
		l++;
	    } else
	    printf("GO->\n");
	}
	if (l < 1) {
	    printf("Game over\n");
	    return 0;
	}
	if (++zz == 1024) {
	    printf("U won! The end\n");
	    return 0;
	}
    }
}
