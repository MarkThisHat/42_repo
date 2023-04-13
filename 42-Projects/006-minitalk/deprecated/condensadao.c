//client

volatile sig_atomic_t g_andalf = 0;

static void send_bit(int bit, int pid)
{
    g_andalf = 0;
    while (!g_andalf)
    {
        if (!bit)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);

        usleep(50000); // Adjust usleep time as needed
    }
}

static void send_char(unsigned char c, int pid)
{
	int	i;

	i = 7;
	while (i + 1)
	{
		send_bit((c >> i) & 1, pid);
		i--;
	}
}

static void	send_message(char *str, int pid)
{
	while (*str)
	{
		send_char(*str, pid);
		str++;
	}
	send_char(0, pid);
}

static void sig_c_handler(int sig, siginfo_t *info, void *context)
{
    if (sig == SIGUSR1)
        g_andalf = 1;

    (void)context;
}

int	main(int argc, char **argv)
{
	int	pid;
	struct sigaction s_action;
	sigset_t ice;

	if (argc != 3)
		leave_program("Usage ./client [server PID] [message]\n", 1);
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		leave_program("Server PID has to be numeric and positive\n", 1);
	sigemptyset(&ice);
	s_action.sa_handler = NULL;
	s_action.sa_mask = ice;
	s_action.sa_flags = SA_SIGINFO;
	s_action.sa_sigaction = &sig_c_handler;
	sigaction(SIGUSR1, &s_action, NULL);
	send_message(argv[2], pid);
}

//server

volatile sig_atomic_t g_andalf = 0;

void binary_signal(int sig, int sender_pid)
{
	static unsigned char	c;
	static int	pid;
	static int	bit;

	if (pid && pid != sender_pid)
		return ;
	if (!c && !pid && !bit)
	{
		pid = sender_pid;
		bit = 7;
	}
	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit--;
	    if (bit < 0 && c)
    {
        write(1, &c, 1);
        bit = 7;
        c = 0;
    }
    else if (bit < 0 && !c)
    {
        pid = 0;
        bit = 0;
    }

    g_andalf = 1;
    kill(sender_pid, SIGUSR1);
}

static void sig_handler(int sig, siginfo_t *info, void *context)
{
    if (sig == SIGUSR1 || sig == SIGUSR2)
    {
        g_andalf = 0;
        binary_signal(sig, info->si_pid);
    }

    if (sig == SIGINT)
        exit(0);

    (void)context;
}

int	main(void)
{
	struct sigaction s_action;
	sigset_t	ice;

	sigemptyset(&ice);
	s_action.sa_handler = NULL;
	s_action.sa_mask = ice;
	s_action.sa_flags = SA_SIGINFO;
	s_action.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
	sigaction(SIGINT, &s_action, NULL);
	ft_printf("Server ID is %i\n", getpid());
	while (42)
		sleep(1);
}



/////


// Function to handle bit manipulation based on the received signal
static void update_character(int sig, int *bit, unsigned char *c)
{
    if (sig == SIGUSR1)
        *c |= (1 << *bit);
    (*bit)--;
}

// Function to write character, update variables, and reset bit counter
static void process_character(int *bit, int *pid, unsigned char *c)
{
    if (*bit >= 0)
        return;

    if (*c)
    {
        write(1, c, 1);
        *c = 0;
    }
    else
    {
        write(1, "\n", 1);
        *pid = 0;
    }
    *bit = 7;
}

// Main function to process the received signal
static void process_signal(int sig, int sender_pid)
{
    static unsigned char c;
    static int pid;
    static int bit;

    if (pid && pid != sender_pid)
        return;
    if (!c && !pid && !bit)
    {
        pid = sender_pid;
        bit = 7;
    }

    update_character(sig, &bit, &c);
    process_character(&bit, &pid, &c);
}
