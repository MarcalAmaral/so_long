/* Teste 3 (Verificando o que ocorre na função ft_appendnext, caso receba parâmetros nulos) (Ok)*/

/*Objeto do teste*/
/*
void	ft_appendnext(t_map **head, t_map *node)
{
	t_map	*temp;

	if (!node)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}

	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
} */

/* Quando passado valor nulo no parãmetro (t_map *node) ocorreu segmentation fault (core dumped) (Solucionado, ocorre segfault pois o ft_printf tenta acessar valores 
inacessíveis, pois a função manipula endereços e se passado diretamente NULL como parâmetro de (t_map **head), quando a função termina não sabe como acessar os valores)*/ 
/* int	main(void)
{
	t_map	*node;

	node = ft_newnode_map('l');
	ft_appendnext(NULL, '\0');
	ft_printf("%c \n", node->content);
	ft_printf("%c \n", node->dup_content);
	ft_printf("%p \n", node->next);
	ft_printf("%p \n", node->prev);
	ft_printf("%p \n", node->up);
	ft_printf("%p \n", node->down);
	ft_printf("%c \n", node->next->content);
	ft_printf("%c \n", node->next->dup_content);
	ft_printf("%p \n", node->next->next);
	ft_printf("%p \n", node->next->prev);
	ft_printf("%p \n", node->next->up);
	ft_printf("%p \n", node->next->down);
	free(node->next);
	free(node);
	return (0);
}*/

/* Solução do segfault (Corrigir main)
{
	int	main(void)
{
	t_map	*node;
	t_map	*a;

	a = NULL; #Consegue manter a referência após a função ser executada e consegue acessar os valores no ft_printf.
	node = ft_newnode_map('l');
	ft_appendnext(&a, ft_newnode_map('\0'));
	ft_printf("%c \n", node->content);
	ft_printf("%c \n", node->dup_content);
	ft_printf("%p \n", node->next);
	ft_printf("%p \n", node->prev);
	ft_printf("%p \n", node->up);
	ft_printf("%p \n", node->down);
	ft_printf("%c \n", a->content);
	ft_printf("%c \n", a->dup_content);
	ft_printf("%p \n", a->next);
	ft_printf("%p \n", a->prev);
	ft_printf("%p \n", a->up);
	ft_printf("%p \n", a->down);
	free(node->next);
	free(node);
	return (0);
}
 */
/*Se comportou da forma esperada retornando apenas valores nulos em content, quando passado o caracter nulo como parâmetro.*/
/* int	main(void)
{
	t_map	*node;

	node = ft_newnode_map('l');
	ft_appendnext(node, '\0');
	ft_printf("%c \n", node->content);
	ft_printf("%c \n", node->dup_content);
	ft_printf("%p \n", node->next);
	ft_printf("%p \n", node->prev);
	ft_printf("%p \n", node->up);
	ft_printf("%p \n", node->down);
	ft_printf("%c \n", node->next->content);
	ft_printf("%c \n", node->next->dup_content);
	ft_printf("%p \n", node->next->next);
	ft_printf("%p \n", node->next->prev);
	ft_printf("%p \n", node->next->up);
	ft_printf("%p \n", node->next->down);
	free(node->next);
	free(node);
	return (0);
}*/

/* Teste 2 (Verificando se está sendo adicionado novo nodo no next do nodo anterior) (OK)*/
/* int	main(void)
{
	t_map	*node;

	node = ft_newnode_map('l');
	ft_appendnext(node, 'a');
	ft_printf("%c \n", node->content);
	ft_printf("%c \n", node->dup_content);
	ft_printf("%p \n", node->next);
	ft_printf("%p \n", node->prev);
	ft_printf("%p \n", node->up);
	ft_printf("%p \n", node->down);
	ft_printf("%c \n", node->next->content);
	ft_printf("%c \n", node->next->dup_content);
	ft_printf("%p \n", node->next->next);
	ft_printf("%p \n", node->next->prev);
	ft_printf("%p \n", node->next->up);
	ft_printf("%p \n", node->next->down);
	free(node->next);
	free(node);
	return (0);
} */

/* Teste 1 (validando criação de nodo e verificando valores) (Ok)*/

/* Objeto de teste (Função ft_newnode_map)*/
/*
t_map	*ft_newnode_map(char content)
{
	t_map	*new_node;

	new_node = (t_map *) ft_calloc (1, sizeof(t_map));
	new_node->content = content;
	new_node->dup_content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->up = NULL;
	new_node->down = NULL;
	return (new_node);
}*/

/* int	main(void)
{
	t_map	*node;

	node = ft_newnode_map('l');
	ft_printf("%c \n", node->content);
	ft_printf("%c \n", node->dup_content);
	ft_printf("%p \n", node->next);
	ft_printf("%p \n", node->prev);
	ft_printf("%p \n", node->up);
	ft_printf("%p \n", node->down);
	free(node);
	return (0);
}
 */