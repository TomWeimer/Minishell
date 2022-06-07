# 42 School - Libft

## Description
This project is the first project available in the curriculum of School 42.	The goal of this assignment is to create a simple library, that can be used in some of the future project.


Working on this project, you will learn the basics of a C library.
Among the functions of the libft, we find some of the most used in C, such as strlen, strcopy, calloc...<br>
Click [here](https://github.com/TomWeimer/Libft/blob/main/fr.subject.pdf) to see the complete subject of this project. 

## Installation
```zsh
git clone https://github.com/TomWeimer/Libft libft
```
## Usage
To use a library in C you need to add, in the source file using the library, the following code:
```C
#include  "libft.h"
```
You also need to link the library:
```C
gcc  foo.c -lft
```
Or if the library is not in the standard path:
```C
gcc  foo.c -L<path_to_the_libft> -lft
```
## Content of the library
### Mandatory functions:
The functions bellow are reproductions of others library functions:
| Standard C functions                      	|                     |                         |                         |                         |
|:------------------------| :-------------------|:------------------------|:------------------------|:------------------------|
| ft_isalpha	        	  |	ft_toupper	        | ft_strlen				      	| ft_bzero					      | ft_calloc	              |				  
|	ft_isdigit	          	|	ft_tolower      		|	ft_strlcpy				      | ft_strdup					      |	ft_atoi			            |
|	ft_isalnum	         	  |	ft_strchr						|	ft_strlcat				      | ft_isprint			      	| ft_memcpy		        	  |	  
|	ft_isascii			    	  | ft_strrchr					| ft_strncmp					    | ft_memmove				      |	ft_memchr			          |
|	ft_memset					      |	ft_memcmp						| 

The functions bellow are a choice of School 42:		
| Additional 42 functions: |											|											|											|								|
|:----------------------|:--------------------|:--------------------|:--------------------|:--------------|
|	ft_substr							|	ft_strjoin					|	ft_putnbr_fd				|	ft_striteri					| ft_putstr_fd	|
|	ft_strtrim						| ft_split						|	ft_putendl					|	ft_putchar_fd				|	ft_strmapi		|
|	ft_itoa																
### Bonus functions:
The functions below aren't needed for validated the project:
| Additional 42 functions: 			|											|											|											|											|
|:----------------------|:--------------------|:--------------------|:--------------------|:--------------------|
|	ft_lstnew							|	ft_lstdelone				|ft_lstclear					|	ft_lstiter					|ft_lstmap							|	
|	ft_lstadd_front				| ft_lstadd_back			|ft_lstsize						|	ft_lstlast					|

