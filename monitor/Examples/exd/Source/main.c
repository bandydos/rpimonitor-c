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

// Function to avoid unnecessary repitition.
void finish_with_error(MYSQL *con)
{
	fprintf(stderr, "/s\n", mysql_error(con));
	mysql_close(con);
	exit(1);
}

int main()
{
	if (map_peripheral(&gpio) == -1)
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return -1;
	}

	// Create a MYSQL connection.
	MYSQL *connection = mysql_init(NULL);

	// Connect.
	if (mysql_real_connect(connection, host, user, pwd, dbname, port, unix_socket, flag) == NULL)
	{
		finish_with_error(connection);
	}

	// Select by query.
	if (mysql_query(connection, "SELECT * FROM rpimon"))
	{
		finish_with_error(connection);
	}

	MYSQL_RES *res = mysql_store_result(connection); // Store results.
	MYSQL_ROW row;									 // MySQL row.

	int num_fields = mysql_num_fields(res); // Get number of columns in table.

	while (row = mysql_fetch_row(res))
	{
		for (int i = 0; i < num_fields; i++) // Loop columns.
		{
			printf("%s\t ", row[i] ? row[i] : "NULL"); // If something => print.
		}
		printf("\n");
	}

	// Free the resources.
	mysql_free_result(res);
	mysql_close(connection);

	// Define gpio 17 as input
	//INP_GPIO(17);

	char status = 0;
	//char operation[50];

	while (1)
	{
		status = GPIO_READ(17);
		if (status)
		{
			return "on";
		}
		else
		{
			return "off";
		}
		//status ? "on" : "off";
		// Insert by query.

		// nog fixen dat status kan meegegeven worden in query
		if (mysql_query(connection, "INSERT INTO `rpimon` (`id`, `status`, `logtime`) VALUES (NULL, %s, CURRENT_TIME())", status))
		{
			finish_with_error(connection);
		}

		sleep(10);
	}

	return EXIT_SUCCESS;
}
