# 定义编译器：指定为实验要求的GCC
CC = gcc
# 编译选项：启用所有警告（-Wall）、使用C99标准（-std=c99），确保代码规范性检查
CFLAGS = -Wall -std=c99
# 定义目标可执行文件名：严格按照实验要求设为"aes"
TARGET = aes
# 定义所有需要编译的.c文件：覆盖实验要求的常规实现、查表实现、测试文件，若存在share.c（共同代码）则加入
SRCS = conventional.c t_tables.c test.c share.c
# 自动推导.c文件对应的编译中间文件（.o文件）：将SRCS中所有.c替换为.o
OBJS = $(SRCS:.c=.o)
# 定义头文件依赖：确保修改头文件时能触发重新编译
HDRS = conventional.h t_tables.h share.h

# 核心目标：生成可执行文件aes（默认执行此目标，输入make即可触发）
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)  # 链接所有.o文件生成aes

# 编译规则：将单个.c文件编译为.o文件（$<表示当前.c文件，$@表示生成的.o文件）
%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@  # 仅编译未修改或依赖文件变化的.c文件

# 清理目标：删除编译生成的中间文件（.o）和可执行文件（aes），输入make clean触发
clean:
	rm -f $(OBJS) $(TARGET)