#ifndef PRINTF_COLORS_H
# define PRINTF_COLORS_H

# define MSG_INVALID_COLOR "Minishell: invalid color name. \
Available options are as below:\n"

//Regular text
# define BLACK   "\e[0;30m"
# define RED     "\e[0;31m"
# define GREEN   "\e[0;32m"
# define YELLOW  "\e[0;33m"
# define BLUE    "\e[0;34m"
# define MAGENTA "\e[0;35m"
# define CYAN    "\e[0;36m"
# define WHITE   "\e[0;37m"

//Regular underline text
# define UBLACK   "\e[4;30m"
# define URED     "\e[4;31m"
# define UGREEN   "\e[4;32m"
# define UYELLOW  "\e[4;33m"
# define UBLUE    "\e[4;34m"
# define UMAGENTA "\e[4;35m"
# define UCYAN    "\e[4;36m"
# define UWHITE   "\e[4;37m"

//Regular background
# define BLACKB   "\e[40m"
# define REDB     "\e[41m"
# define GREENB   "\e[42m"
# define YELLOWB  "\e[43m"
# define BLUEB    "\e[44m"
# define MAGENTAB "\e[45m"
# define CYANB    "\e[46m"
# define WHITEB   "\e[47m"

//High intensty background 
# define BLACKHB   "\e[0;100m"
# define REDHB     "\e[0;101m"
# define GREENHB   "\e[0;102m"
# define YELLOWHB  "\e[0;103m"
# define BLUEHB    "\e[0;104m"
# define MAGENTAHB "\e[0;105m"
# define CYANHB    "\e[0;106m"
# define WHITEHB   "\e[0;107m"

//High intensty text
# define HBLACK   "\e[0;90m"
# define HRED     "\e[0;91m"
# define HGREEN   "\e[0;92m"
# define HYELLOW  "\e[0;93m"
# define HBLUE    "\e[0;94m"
# define HMAGENTA "\e[0;95m"
# define HCYAN    "\e[0;96m"
# define HWHITE   "\e[0;97m"

//Bold high intensity text
# define BHBLACK   "\e[1;90m"
# define BHRED     "\e[1;91m"
# define BHGREEN   "\e[1;92m"
# define BHYELLOW  "\e[1;93m"
# define BHBLUE    "\e[1;94m"
# define BHMAGENTA "\e[1;95m"
# define BHCYAN    "\e[1;96m"
# define BHWHITE   "\e[1;97m"

//Reset
# define RESET       "\e[0m"
# define CRESET      "\e[0m"
# define COLOR_RESET "\e[0m"

#endif