NAME			:=	fixed

SRCS			:=	Fixed.cpp \
					main.cpp

SRCS_DIR		:=	./srcs/
HEADERS_DIR		:=	./headers/
OBJS_DIR		:=	./objs/
DEP_DIR			:=	./dependencies/

#################################################################

vpath				%.cpp $(SRCS_DIR)
vpath				%.hpp $(HEADERS_DIR)
vpath				%.o $(OBJS_DIR)
vpath				%.d $(DEP_DIR)

OBJS			:=	$(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))
DEP				:=	$(addprefix $(DEP_DIR), $(SRCS:.cpp=.d))

CC				:=	clang++
CFLAGS			:=	-Wall -Wextra -Werror -I$(HEADERS_DIR)
DEPFLAGS		=	-MT $@ -MMD -MP -MF $(DEP_DIR)$*.d

all				:	$(NAME)

$(NAME)			:	$(OBJS) $(OBJS_DIR) $(DEP_DIR)
					$(CC) $(CFLAGS) $(DEPFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o	:	%.cpp $(DEP_DIR)%.d $(OBJS_DIR) $(DEP_DIR)
					$(CC) ${CFLAGS} $(DEPFLAGS) -o $@ -c $<

$(DEP_DIR)		:
					mkdir -p $(DEP_DIR)

$(OBJS_DIR)		:
					mkdir -p $(OBJS_DIR)

clean			:
					rm -rf $(OBJS_DIR)

fclean			:	clean
					rm -rf $(DEP_DIR)
					rm -rf $(NAME)

re				:	fclean	all

.PHONY			:	all clean fclean re

$(DEP)			:
include $(wildcard $(DEP))
