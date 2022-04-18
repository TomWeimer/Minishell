#include <unistd.h>
int ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (i);
	while(str[i])
		i++;
	return (i);
}

char *new_var(char *str, char c)
{
	char *rtn;
	int i;

	i = 0;
	rtn = malloc(sizeof(char) * (ft_strlen(str) + 1 + 1));
	while (str[i])
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i + 1] = c;
	rtn[i + 2] = '\0';
	free(str);
	str = NULL;
	return (rtn);
}

char *get_var(char *var, char c)
{
	char *rtn;
	
	if (var == NULL)
	{
		rtn = malloc(sizeof(char) * 2);
		rtn[0] = c;
		rtn[1] = '\0';
	}
	else
	{
		rtn = new_var(var, c);
	}
	return (rtn);
}

int is_delimiter(char c)
{
	if (c == '_')
		return (0);
	if (c >= '0' && c <= '9')
		return (0);
	else if ((c >= 'A' && c <= 'Z') ||(c >= 'a' && c >= 'z'))
		return (0);
	return (1);
	
}
void echo(char *str, char *cmd[])
{
	int i;
	char *var;

	i = 0;
	var = NULL;
	while(str[i])
	{
		if (str[i] != '$')
			write(1, str[i], 1);
		else
		{
			//while (is_delimiter(str[i]))
			//{
			//	var = get_var(var, str[i]);
			//	i++;
			//}
			//printf("%s", ENV_VAR[var]);
			//free(var);
			//var = NULL;
		}
		i++;
	}
	//if (cmd[1] == 'n')
		write(1, "\n", 1);
}