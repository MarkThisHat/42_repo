/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:23:27 by maalexan          #+#    #+#             */
/*   Updated: 2023/03/18 16:41:14 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "../libs/libft/incl/libft.h"
/*
typedef struct s_msg {
	char	c;
	char	*msg;
	char	msg_size[7];
	int		pid;
	int		bit;
	int		len;
}	t_msg;
*/

typedef struct s_msg {
	char	c;
	int		pid;
	int		bit;
}			t_msg;

void	leave_program(char *str, int return_code);
//void	binary_signal(int sig, int sender_pid);
void	print_binary(char c);

/*
struct sigaction {
	void		(*sa_handler)(int);	//Pointer to function that should handle the signal by default
	sigset_t	sa_mask;			//Handles signals that should be ignored by the program
	int			sa_flags;			//When you want to alter behavior of a signal
	void		(*sa_sigaction)(int, siginfo_t *, void *);//Pointer to function that should handle the signal when you choose to
};

union sigval {
	int sival_int;
	void *sival_ptr;
};

typedef struct {
	int si_signo;
	int si_code;
	union sigval si_value;
	int si_errno;
	pid_t si_pid;
	uid_t si_uid;
	void *si_addr;
	int si_status;
	int si_band;
} siginfo_t;
*/
