#include "secondmain.h"

/**
 * chck_envir - checks if the typed variable is an env variable
 *
 * @h: head of linked list
 * @in: input string
 * @data: data structure
 * Return: no return
 */
void chck_envir(r_var **h, char *in, data_shell *data)
{
	int str_row, chr_ome, a, str_lval;
	char **_evian;

	_evian = data->_evirnment;
	for (str_row = 0; _evian[str_row]; str_row++)
	{
		for (a = 1, chr_ome = 0; _evian[str_row][chr_ome]; chr_ome++)
		{
			if (_evian[str_row][chr_ome] == '=')
			{
				str_lval = _strnglength(_evian[str_row] + chr_ome + 1);
				add_rvar(h, a, _evian[str_row] + chr_ome + 1, str_lval);
				return;
			}

			if (in[a] == _evian[str_row][chr_ome])
				a++;
			else
			{
                break;
            }
		}
	}

	for (a = 0; in[a]; a++)
	{
		if (in[a] == ' ' || in[a] == '\t' || in[a] == ';' || in[a] == '\n')
		{
            break;
        }
	}

	add_rvar(h, a, NULL, 0);
}

/**
 * chck_var - check if the typed variable is $$ or $?
 *
 * @h: head of the linked list
 * @in: input string
 * @st: last status of the Shell
 * @data: data structure
 * 
 * Return: no return
 */
int chck_var(r_var **h, char *in, char *st, data_shell *data)
{
	int k, sa_lst, pa_lpd;

	sa_lst = _strnglength(st);
	pa_lpd = _strnglength(data->pid);

	for (k = 0; in[k]; k++)
	{
		if (in[k] == '$')
		{
			if (in[k + 1] == '?')
				add_rvar(h, 2, st, sa_lst), k++;
			else if (in[k + 1] == '$')
				add_rvar(h, 2, data->pid, pa_lpd), k++;
			else if (in[k + 1] == '\n')
				add_rvar(h, 0, NULL, 0);
			else if (in[k + 1] == '\0')
				add_rvar(h, 0, NULL, 0);
			else if (in[k + 1] == ' ')
				add_rvar(h, 0, NULL, 0);
			else if (in[k + 1] == '\t')
				add_rvar(h, 0, NULL, 0);
			else if (in[k + 1] == ';')
				add_rvar(h, 0, NULL, 0);
			else
				chck_envir(h, in + k, data);
		}
	}

	return (k);
}

/**
 * replace_take_in - replaces string into variables
 *
 * @head: head of the linked list
 * @input: input string
 * @new_input: new input string (replaced)
 * @nlen: new length
 * Return: replaced string
 */
char *replace_take_in(r_var **head, char *input, char *new_input, int nlen)
{
	r_var *indices;
	int a, b, c;

	indices = *head;
	for (b = a = 0; a < nlen; a++)
	{
		if (input[b] == '$')
		{
			if (!(indices->var_len) && !(indices->val_len))
			{
				new_input[a] = input[b];
				b++;
			}
			else if (indices->var_len && !(indices->val_len))
			{
				for (c = 0; c < indices->var_len; c++)
					b++;
				a--;
			}
			else
			{
				for (c = 0; c < indices->val_len; c++)
				{
					new_input[a] = indices->worth[c];
					a++;
				}
				b += (indices->var_len);
				a--;
			}
			indices = indices->next;
		}
		else
		{
			new_input[a] = input[b];
			b++;
		}
	}

	return (new_input);
}

/**
 * rep_varble - calls functions to replace string into vars
 *
 * @input: input string
 * @datash: data structure
 * 
 * Return: replaced string
 */
char *rep_varble(char *input, data_shell *datash)
{
	r_var *head, *indices;
	char *position, *new_input;
	int length1, length2;

	position = aux_frmitoa(datash->posture);
	head = NULL;

	length1 = chck_var(&head, input, position, datash);

	if (head == NULL)
	{
		free(position);
		return (input);
	}

	indices = head;
	length2 = 0;

	while (indices != NULL)
	{
		length2 += (indices->val_len - indices->var_len);
		indices = indices->next;
	}

	length2 += length1;

	new_input = malloc(sizeof(char) * (length2 + 1));
	new_input[length2] = '\0';

	new_input = replace_take_in(&head, input, new_input, length2);

	free(input);
	free(position);
	free_rvar(&head);

	return (new_input);
}
