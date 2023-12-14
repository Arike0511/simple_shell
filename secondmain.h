#ifndef SECONDMAIN_H
#define SECONDMAIN_H

#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

/* aux_lists.c */

/**initially "sep_list *add_sep_node(sep_list **head, char divide);"*/
sep_list *add_sep_node(sep_list **head, char split);

/**initially "void free_sep(sep_list **head);"*/
void free_sep(sep_list **head);

/**initially "line_list *add_line_node(line_list **head, char *straight_line);"*/
line_list *add_line_node(line_list **head, char *strght_ln);

/**initially "void free_line_list(line_list **head);"*/
void free_line_list(line_list **head);

/**End of aux_lists.c*/


/* aux_lists2.c */

/**"r_var *add_rvar(r_var **head, int Ivap, char *var, int ival);"*/
r_var *add_rvar(r_var **head, int plavin, char *var, int vald);

/**initially "void free_rvar_list(r_var **head);"*/
void free_rvar(r_var **head);

/**End of aux_lists2.c*/


/* aux_str functions */
char *_strngcat(char *new_src, const char *src);
char *_strngcopy(char *new_src, char *src);
int _strngcompare(char *strng1, char *strng2);
char *_strngchr(char *strng, char cha);
int _strngspn(char *strng, char *granted);
/**End of aux_str functions*/


/* aux_mem.c */

/**"void _memorycpy(void *newpointer, const void *pointer, unsigned int size);"*/
void _memorycopy(void *nwpoint, const void *point, unsigned int all);

/**"void *_reallocate(void *point, unsigned int prevs_size, unsigned int nw_size)"*/
void *_reallocated(void *point, unsigned int previous_size, unsigned int new_size);

/**"char **_realocdp(char **point, unsigned int prevs_size, unsigned int nw_size);"*/
char **_reallocatedp(char **point, unsigned int previous_size, unsigned int new_size);

/**End of aux_mem.c*/


/* aux_str2.c */

/**"char *_stringdup(const char *string);"*/
char *_strngduplicate(const char *strng);

/**"int _stringlen(const char *string);"*/
int _strnglength(const char *strng);

/**"int compare_chars(char string[], const char *delim);"*/
int cmpre_chars(char strng[], const char *delim);

/**"*_stringtok(char string[], const char *delim);"*/
char *_strngtoken(char strng[], const char *delim);

/**"int _isdigit(const char *string);"*/
int _isdgt(const char *strng);

/**End of aux_str2.c*/

/* aux_str3.c */

/**"void reverse_string(char *string);"*/
void rever_strng(char *strng);

/**End of aux_str3.c*/


/* check_syntax_error.c */

/**"int rpted_char(char *ipt, int a);"*/
int reapted_charac(char *tip, int a);

/**"int err_div_op(char *ipt, int a, char last);"*/
int error_sep_op(char *tip, int a, char end);

/**"int fest_char(char *ipt, int *a);"*/
int festive_charac(char *tip, int *a);

/**"void pint_syn_err(data_shell *datash, char *inputs, int a, int bool);"*/
void prnt_syntax_error(data_shell *datash, char *take_in, int a, int bool);

/**"int check_syn_err(data_shell *datash, char *input);"*/
int chck_syn_err(data_shell *datash, char *take_in);
/**End check syntax error.c*/


/* shell_loop.c */

/**"char *without_comment(char *in);"*/
char *wthot_com(char *in);

/**"void shell_loop(data_shell *datash);"*/
void shell_loop(data_shell *datash);
/**End of shell_loop.c**/


/* read_line.c */
/**"*rd_ln(int *i_eof);"*/
char *rd_line(int *i_eof);
/**End read_line.c*/


/* split.c */

/**"char *swp_cha(char *ipt, int bool);"*/
char *swp_character(char *tip, int bool);

/**"void add_node(sep_list **head_s, line_list **head_l, char *inputs);"*/
void plus_node(sep_list **head_s, line_list **head_l, char *take_in);

/**"void pull_nxt(sep_list **list_s, line_list **list_l, data_shell *datash);"*/
void brng_nxt(sep_list **list_s, line_list **list_l, data_shell *datash);

/**"int divide_cmds(data_shell *datash, char *input);"*/
int split_cmds(data_shell *datash, char *take_in);

/**"char **line_split(char *inputs);"*/
char **ln_splitter(char *take_in);
/**End of split.c*/

/* rep_var.c */
/**"void chck_environ(r_var **h, char *in, data_shell *data);"*/
void chck_envir(r_var **h, char *in, data_shell *data);

/**"int chck_variable(r_var **h, char *in, char *st, data_shell *data);"*/
int chck_var(r_var **h, char *in, char *st, data_shell *data);

/**"char *rpced_inputs(r_var **head, char *input, char *new_input, int nlen);"*/
char *replace_take_in(r_var **head, char *take_in, char *new_take_in, int nlen);

/**"char *rep_variable(char *inputs, data_shell *datash);"*/
char *rep_varble(char *take_in, data_shell *datash);

/**End rep_var.c*/


/* get_line.c */

/**"void gt_line(char **lnptr, size_t *n, char *buffer, size_t a);"*/
void get_lne(char **lineptr, size_t *n, char *buffering, size_t a);

/**"ssize_t get_line(char **lnptr, size_t *n, FILE *streaming);"*/
ssize_t get_liner(char **lineptr, size_t *n, FILE *streamed);

/* exec_line */

/**"int execute_ln(data_shell *datash);"*/
int exe_ln(data_shell *datash);

/* cmd_exec.c */

/**"int is_cdirectory(char *pat, int *i);"*/
int is_cdirec(char *tap, int *i);

/**"char *_whch(char *cmd, char **_environment);"*/
char *_wich(char *cmd, char **_environment);

/**"int is_execute(data_shell *datash);"*/
int is_exe(data_shell *datash);

/**"int chck_err_cmd(char *dir, data_shell *datash);"*/
int chck_error_cmnd(char *dir, data_shell *datash);

/**"int cmd_execute(data_shell *datash);"*/
int cmd_exe(data_shell *datash);

/* env1.c */

/**"char *_gtenv(const char *name, char **_environment);"*/
char *_gtenv(const char *name, char **_evirnment);

/**"int _env(data_shell *datash);"*/
int _env(data_shell *datash);

/* env2.c */

/**"char *copy_info(char *name, char *val);"*/
char *cpy_info(char *name, char *value);

/**"void st_env(char *name, char *val, data_shell *datash);"*/
void set_envirn(char *name, char *value, data_shell *datash);

/**"int _setenv(data_shell *datash);"*/
int _stenviron(data_shell *datash);

/**"int _unsetenv(data_shell *datash);"*/
int _unstenviron(data_shell *datash);

/* cd.c */

/**"void cd_dot(data_shell *datash);"*/
void cd_dt(data_shell *datash);

/**"void cd_to(data_shell *datash);"*/
void cd_to(data_shell *datash);

/**"void cd_previous(data_shell *datash);"*/
void cd_fro(data_shell *datash);

/**"void cd_to_origin(data_shell *datash);"*/
void cd_to_org(data_shell *datash);

/* cd_shell.c */

/**"int cd_shell(data_shell *datash);"*/
int cd_shell(data_shell *datash);

/* get_builtin */

/**"int (*get_builtOOBin(char *cmd))(data_shell *datash);"*/
int (*get_builtOOBin(char *cmd))(data_shell *datash);

/* _exit.c */

/**"int exit_theshell(data_shell *datash);"*/
int quit_theshell(data_shell *datash);

/* aux_stdlib.c */

/**"int get_length(int n);"*/
int get_len(int n);

/**"char *aux_fromitoa(int n);"*/
char *aux_frmitoa(int a);

/**"int _atoi(char *s);"*/
int _atoi(char *s);

/* aux_error1.c */

/**"char *strconcat_cd(data_shell *, char *, char *, char *);"*/
char *strcncat_cdirec(data_shell *, char *, char *, char *);

/**"char *err_gt_cd(data_shell *datash);*/
char *err_get_cdirec(data_shell *datash);

/**"char *err_absent(data_shell *datash);" */
char *err_abs(data_shell *datash);
/**"char *err_depart_shell(data_shell *datash);"*/
char *error_dprt_shell(data_shell *datash);

/* aux_error2.c */
/**"char *err_gt_alter(char **args);*/
char *error_get_alt(char **args);
/**"char *err_environ(data_shell *datash);*/
char *err_env(data_shell *datash);
/**"char *err_syn(char **args);"*/
char *err_syntax(char **args);
/**"char *err_permit(char **args);"*/
char *err_pmt(char **args);
/**"char *error_path_126(data_shell *datash);"*/
char *error_pt_126(data_shell *datash);


/* get_error.c */
/**"int gt_err(data_shell *datash, int evaluate);"*/
int get_err(data_shell *datash, int eval);

/* get_sigint.c */
/**"void gt_signedinnt(int sigma);"*/
void gt_signdint(int sgma);

/* aux_help.c */
/**"void ax_assist_envir(void);;"*/
void aux_asst_env(void);
/**"void ax_assist_setenver(void);"*/
void aux_asst_setenv(void);
/**"void ax_assist_unsetenver(void);"*/
void aux_asst_unseten(void);
/**"void ax_assist_gen(void);*/
void ax_asst_gen(void);
/**"void ax_assist_depart(void);"*/
void ax_asst_dprt(void);

/* aux_help2.c */
/**"void ax_assist(void);"*/
void aux_asst(void);
/**"void ax_assist_alias(void);"*/
void aux_asst_als(void);
/**"void ax_assist_cdir(void);"*/
void aux_asst_cd(void);

/* get_help.c */
/**"int gt_assist(data_shell *datash);"*/
int gt_asst(data_shell *datash);
#endif
