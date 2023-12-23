#include "secondmain.h"

/**
 * swp_cha - A program swaps | and & for non-printed chars
 * @ipt: The input string
 * @bool: type of swap
 * Return: The prpgram retirns swapped string
 */

char *swp_character(char *ipt, int bool)
{
	int a;

	if (bool == 0)
	{
		for (a = 0; ipt[a]; a++)
		{
			if (ipt[a] == '|')
			{
				if (ipt[a + 1] != '|')
					ipt[a] = 16;
				else
					a++;
			}

			if (ipt[a] == '&')
			{
				if (ipt[a + 1] != '&')
					ipt[a] = 12;
				else
				{
					a++;
				}
			}
		}
	}
	else
	{
		for (a = 0; ipt[a]; a++)
		{
			ipt[a] = (ipt[a] == 16 ? '|' : ipt[a]);
			ipt[a] = (ipt[a] == 12 ? '&' : ipt[a]);
		}
	}
	return (ipt);
}

/**
 * plus_node - This program adds separators and command lines in the lists
 * @head_s: head of separator list
 * @head_l: head of command lines list
 * @inputs: input string
 * Return: no return
 */

void plus_node(sep_list **head_s, line_list **head_l, char *inputs)
{
	int a;
	char *nenil;

	inputs = swp_character(inputs, 0);

	for (a = 0; inputs[a]; a++)
	{
		if (inputs[a] == ';')
			add_sep_node(head_s, inputs[a]);

		if (inputs[a] == '|' || inputs[a] == '&')
		{
			add_sep_node(head_s, inputs[a]);
			a++;
		}
	}

	nenil = _strngtoken(inputs, ";|&");
	do {
		nenil = swp_character(nenil, 1);
		add_line_node(head_l, nenil);
		nenil = _strngtoken(NULL, ";|&");
	} while (nenil != NULL);

}

/**
 * pull_next - This program goes to the next command line stored
 * @list_s: separator list
 * @list_l: command line list
 * @datash: data structure
 * Return: no return
 */

void brng_nxt(sep_list **list_s, line_list **list_l, data_shell *datash)
{
	int pool_pes;
	sep_list *ls_s;
	line_list *ls_l;

	pool_pes = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && pool_pes)
	{
		if (datash->posture == 0)
		{
			if (ls_s->splitter == '&' || ls_s->splitter == ';')
				pool_pes = 0;
			if (ls_s->splitter == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->splitter == '|' || ls_s->splitter == ';')
				pool_pes = 0;
			if (ls_s->splitter == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !pool_pes)
		{
			ls_s = ls_s->next;
		}
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * split_cmds - This program splits command lines according to
 * the separators ;, | and &, and executes them
 * @datash: data structure
 * @take_in: input string
 * Return: 0 to exit, 1 to continue
 */

int split_cmds(data_shell *datash, char *take_in)
{

	sep_list *head_s, *list_s;
	line_list *head_l, *list_l;
	int loop;

	head_s = NULL;
	head_l = NULL;

	plus_node(&head_s, &head_l, take_in);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		datash->take_in = list_l->strght_ln;
		datash->arguments = ln_splitter(datash->take_in);
		loop = exe_ln(datash);
		free(datash->arguments);

		if (loop == 0)
			break;

		brng_nxt(&list_s, &list_l, datash);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	free_sep(&head_s);
	free_line_list(&head_l);

	if (loop == 0)
		return (0);
	return (1);
}

/**
 * line_split - The program tokenizes the input string
 * @input: input string.
 * Return: string splitted.
 */

char **ln_splitter(char *input)
{
	size_t lsdsize;
	size_t a;
	char **tokens;
	char *token;

	lsdsize = TOK_SIZE_IN_TOTAL;

	tokens = malloc(sizeof(char *) * (lsdsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strngtoken(input, TOK_MILDE);
	tokens[0] = token;

	for (a = 1; token != NULL; a++)
	{
		if (a == lsdsize)
		{
			lsdsize += TOK_SIZE_IN_TOTAL;

			tokens = _reallocatedp(tokens, a, sizeof(char *) * lsdsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strngtoken(NULL, TOK_MILDE);
		tokens[a] = token;
	}

	return (tokens);
}
