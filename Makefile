SRCS	=	main.cpp \

LIBSRCS =	ft.cpp

OBJS	=	${SRCS:%.cpp=./.build/%.o}
LIBOBJS	=	${LIBSRCS:%.cpp=./.build/%.o}

NAME	=	container

LIBNAME =	${NAME}.a

CPPFLAGS	=	-Wall -Wextra -Werror -I. -std=c++98

RM		=	rm -rf

CCP		=	/usr/bin/c++

# COLORS
NONE			= \033[0m
CL_LINE			= \033[2K
B_RED			= \033[1;31m
B_GREEN			= \033[1;32m
B_MAGENTA 		= \033[1;35m
B_CYAN 			= \033[1;36m

RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)

./.build/%.o : %.cpp
		@/usr/bin/mkdir -p .build
		@$(CCP) ${CPPFLAGS} -I. -o $@ -c $?
		@/usr/bin/printf "${B_MAGENTA}Compilling $? ...\n${NONE}"


all:	
		@/usr/bin/mkdir -p .build
		@/usr/bin/make ${NAME} --no-print-directory

test:
		/usr/bin/make lib --no-print-directory
		cd tester && ./test.sh $(RUN_ARGS)

#always relink
relib:	
		/usr/bin/make lib

lib:	${LIBOBJS}
		@/usr/bin/ar rc $(LIBNAME) $(LIBOBJS)

${NAME}:	${OBJS}
		@${CCP} ${CPPFLAGS} ${OBJS} -o ${NAME}
		@printf "${B_GREEN}==>{${NAME}} LINKED SUCCESFULLY<==${NONE}\n"

clean:
		@${RM}
		@${RM} ./.build
		@printf "${B_RED}XX clean XX\n${NONE}"

fclean:	clean
		@${RM} ${NAME} $(LIBNAME)
		@printf "${B_RED}XX fclean XX\n${NONE}"

re:		fclean all

.PHONY:	all clean fclean re --no=valgrind