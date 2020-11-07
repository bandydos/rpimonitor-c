#include "PJ_RPI.h"
#include <stdio.h>
#include <stdlib.h>
#include <mariadb/mysql.h>

static char *host = "localhost";
static char *user = "bopib";
static char *pwd = "adminroot";
static char *dbname = "rpimonitor";

unsigned int port = 3306;
static char *unix_socket = NULL;
unsigned int flag = 0;

int main()
{
	/*if (map_peripheral(&gpio) == -1)
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return -1;
	}*/

	MYSQL *conn = mysql_init(NULL);
	MYSQL_STMT *stmt;
	MYSQL_BIND param[3];

	if (!(mysql_real_connect(conn, host, user, pwd, dbname, port, unix_socket, flag)))
	{
		fprintf(stderr, "\nError: %s [%d]\n", mysql_error(conn), mysql_errno(conn));
		exit(1);
	}

	printf("Connection succesfull.");

	// Define gpio 17 as output
	/*INP_GPIO(17);
	OUT_GPIO(17);

	while (1)
	{
		// Toggle 17 (blink a led!)
		GPIO_SET = 1 << 17;
		printf("SET\n");
		sleep(1);

		GPIO_CLR = 1 << 17;
		printf("CLR\n");
		sleep(1);
	}*/

	return EXIT_SUCCESS;
}
