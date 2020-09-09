#ifndef TRIE_H
# define TRIE_H

# include <stdbool.h>
# include <stdlib.h>

typedef struct	s_node
{
 	struct s_node	*next[26];
 	bool			finish;
}					t_node;

typedef t_node	*t_trie[26];

t_trie	*trie_init(void);
bool	trie_insert(t_trie *trie, char *str);
bool	trie_find(t_trie *trie, char *str);
void	free_trie(t_trie *trie);
t_node	*create_elem(void);

#endif
