CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
LDFLAGS =
LIBRARIES = -lncurses
TEST_FLAGS := -lcheck -lm -lpthread $(LIBRARIES) -I/opt/homebrew/include -L/opt/homebrew/lib
GCOV_FLAGS := -fprofile-arcs -ftest-coverage

DIST_DIR := archive

BACKEND := brick_game/tetris/backend/collisions/collisions.c \
			brick_game/tetris/backend/colors/color_handler.c \
			brick_game/tetris/backend/colors/colors.c \
			brick_game/tetris/backend/game/block/block.c \
			brick_game/tetris/backend/game/board/board.c \
			brick_game/tetris/backend/game/player/player.c \
			brick_game/tetris/backend/game_status/game_status.c \
			brick_game/tetris/backend/highscores/highscores.c \
			brick_game/tetris/backend/parameters/parameters.c \
			brick_game/tetris/backend/backend.c

TETRIS := brick_game/tetris/fsm/fsm_matrix.c \
 			brick_game/tetris/tetris/tetris.c \
 			brick_game/tetris/time/time.c

FRONTEND := gui/cli/frontend.c

OPEN_COMMAND = open
ifeq ($(OS), Linux)
	OPEN_COMMAND = xdg-open
else
	OPEN_COMMAND = open
endif

all: install run

install: ${BACKEND} ${TETRIS} ${FRONTEND}
	$(CC) ${CFLAGS} $(LIBRARIES) $^ -o tetris.out

run:
	./tetris.out

dvi:
	${OPEN_COMMAND} ../dvi/README.html

dist: clean_dist
	cd ../ && mkdir -p ${DIST_DIR}
	cd ../ && cp -rf src/brick_game ${DIST_DIR}/brick_game
	cd ../ && cp -rf src/gui ${DIST_DIR}/gui
	cd ../ && cp -rf src/Makefile ${DIST_DIR}/
	cd ../ && tar -czvf archive.tar.gz ${DIST_DIR}
	cd ../ && rm -rf ${DIST_DIR}

dist_unpack:
	cd ../ && tar -xzvf archive.tar.gz

test:
	@mkdir -p ../tests/build
	$(CC) ../tests/main_test.c ${CFLAGS} $(BACKEND) $(TEST_FLAGS) -o ./test.out
	./test.out

gcov_report:
	@mkdir -p report
	$(CC) ../tests/main_test.c $(BACKEND) $(TEST_FLAGS) $(GCOV_FLAGS) -o ./gcov_report.out
	./gcov_report.out
	lcov -t "test" -o test.info -c -d .
	genhtml -o report/ test.info
	${OPEN_COMMAND} ./report/index.html
	make clean_gcov

style_check:
	@find .. -type f -name "*.c" -exec clang-format -n -style=Google {} \;
	@find .. -type f -name "*.h" -exec clang-format -n -style=Google {} \;
	@echo "Clang format style check is finished"

style:
	@find .. -type f -name "*.c" -exec clang-format -i -style=Google {} \;
	@find .. -type f -name "*.h" -exec clang-format -i -style=Google {} \;
	@echo "Clang format style apply is finished"

style_test:
	@cd ../tests
	@find .. -type f -name "*.c" -exec clang-format -i -style=Google {} \;
	@find .. -type f -name "*.h" -exec clang-format -i -style=Google {} \;
	@echo "Clang format style apply is finished"

clean: clean_project clean_static_lib clean_log clean_exec clean_obj clean_gcov clean_lcov clean_lcov_report clean_dist
	@echo "Clean finished"

clean_project:
	@find .. -type f -name "*.highscores" -exec rm {} \;

clean_dist:
	@cd ../ && rm -rf archive
	@cd ../ && rm -rf archive.tar.gz

clean_after_building:
	@rm -rf ${OBJ_DIR}

clean_static_lib:
	@find .. -type f -name "*.a" -exec rm {} \;

clean_log:
	@find .. -type f -name "*.log" -exec rm {} \;

clean_exec:
	@find .. -type f -name "*.out" -exec rm {} \;

clean_obj:
	@find .. -type f -name "*.o" -exec rm {} \;

clean_gcov:
	@find .. -type f -name "*.gcda" -exec rm {} \;
	@find .. -type f -name "*.gcno" -exec rm {} \;

clean_lcov:
	@find .. -type f -name "*.info" -exec rm {} \;

clean_lcov_report:
	@rm -rf report
