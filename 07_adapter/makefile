ROOT_DIR := $(abspath $(CURDIR)/..)
include $(ROOT_DIR)/common.mk

# TARGET = pattern          # 기본값 사용
# SRCS   = pattern.cpp      # 기본값: 디렉토리 내 모든 .cpp 자동 수집

RUST_LIB_DIR = $(abspath $(CURDIR)/rust_vector/target/release)
LDFLAGS += -L$(RUST_LIB_DIR) -lrust_vector -lpthread -ldl