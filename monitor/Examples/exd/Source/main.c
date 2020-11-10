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
	fprintf(stderr, "%s\n", mysql_error(con));
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

	int pin = 21;  // Pin.
	INP_GPIO(pin); // Define pin as input.

	char stat[11];
	char query[501];

	while (1)
	{
		if (GPIO_READ(pin))
		{
			strcpy(stat, "on"); // Set stat "on".
		}
		else
		{
			strcpy(stat, "off"); // Set stat "off".
		}

		// Insert status into query using sprintf.
		sprintf(query, "INSERT INTO `rpimon` (`id`, `status`, `logtime`) VALUES (NULL, '%s', CURRENT_TIME())", stat);

		// Print out some data.
		printf("Status: %s (%d)\nQuery to send: %s\n", stat, GPIO_READ(pin), query);

		// Send query string to db.
		/*if (mysql_query(connection, query))
		{
			finish_with_error(connection);
		}*/

		sleep(5); // Wait for 5s.
	}

	// Free the resources.
	mysql_free_result(res);
	mysql_close(connection);

	// Exit.
	exit(0);
}
