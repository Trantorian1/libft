#ifndef FT_LSTMAP_H
# define FT_LSTMAP_H

t_list	*ft_lst_map(t_list *head, t_any (*f_map)(t_any), void (*f_free)(t_any));

#endif
