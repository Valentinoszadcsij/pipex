#include "pipex.h"
//check_cmd() first isolates PATH from **envp with ft_strnstr
//then we need to split that string by ':' and check if cmd1
//and cmd2 exist in any given path
//if commands dont exist return false, else true
char    *check_cmd(char *cmd, char **envp)
{
    int     i;
    char    *env_path;
    char    **split_path;
    char    *full_path;
    char    **split_cmd;

    i = 0;
    while (envp[i] != "\0")
    {
        env_path = ft_strnstr(envp[i], "PATH=", 5);
        if (env_path)
            break;
        else
            i++;
    }
    i = 0;
    split_path = ft_split(env_path+5, ':');
    split_cmd = ft_split(cmd, ' ');
    while (split_path[i] != NULL)
    {    
        full_path = ft_strjoin(split_path[i], split_cmd[0]);
        printf("%s\n", full_path);
        if (access(full_path, F_OK) == 0)
            return (full_path);
        free(full_path);
        i++;
    }
    perror("Error: ");
    return (NULL);
}

//3rd arg to main is environment variable, which is a 2d array containing PATH variable
//PATH holds pathes where bash commands might be located, seperated by ':'
//As for pipex without bonus we only pass 5 arguments to program hence checking it
int main(int argc, char **argv, char **envp)
{
    int     fd_in;
    int     fd_out;
    char    *cmd1_path;
    char    *cmd2_path;

    if (argc != 5)
    {
        printf("Error: wrong number of argument\n");
        return (EXIT_FAILURE);
    }
    fd_in = open(argv[1], O_RDONLY);
    if (fd_in == -1)
    {
        perror(argv[1]);
        return (EXIT_FAILURE);
    }
    fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd_out == -1) 
    {
        perror(argv[4]);
        return (EXIT_FAILURE);
    }
    cmd1_path = check_cmd(argv[2], envp);
    cmd2_path = check_cmd(argv[3], envp);
    printf("Found: %s\n", cmd1_path);
    printf("Found: %s\n", cmd2_path);
    return (0);
}
