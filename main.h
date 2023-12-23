#ifndef MAIN_H
#define MAIN_H
/**#define TOTALSIZE 1024*/
#define SIZE_IN_TOTAL 1024

/**#define KOT_TOTALSIZE 128*/
#define TOK_SIZE_IN_TOTAL 128

/**#define KOT_MILED " \t\r\n\a"*/
#define TOK_MILDE " \t\r\n\a"


extern char **environ;

typedef struct data
{
	char **av;
	/**char *inputs;*/
	char *take_in;

	/**char **args;*/
	char **arguments;

	/**int position*/
	int posture;

	/**int measure;*/
	int meas_ure;

	/**char **_environment;*/
	char **_evirnment;
	char *pid;
} data_shell;

/**
 * struct sep_list_s - A program for struct
 * @divider: or| and&
 * @next: next node ->
 * Description: This shows single linked list to store separators
 */

typedef struct sep_list_s
{
	/**char divider*/
	char splitter;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - This program shows single linked list
 * @strght_ln: command line
 * @next: next node
 * Description: single linked list to store command lines
 */

typedef struct line_list_s
{
	/**char straight_line*/
	char *strght_ln;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - This program shows single linked list
 * @var_len: length of the variable
 * @worth: value of the variable
 * @val_len: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */

typedef struct r_var_list
{
	/**int variable_length*/
	int var_len;
	/**char *value*/
	char *worth;
	/**int value_length*/
	int val_len;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - This programs Builtin struct for command args.
 * @cmmnd_nme: command line name inputted by the user
 * @f: The data type pointer function.
 */

typedef struct builtin_s
{
	/**char cmd_name*/
	char *cmmnd_nme;
	int (*f)(data_shell *datash);
} builtin_t;

#endif
