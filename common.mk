# =============================================================================
# 디자인 패턴 학습 프로젝트 - 공통 빌드 설정
# 각 패턴 디렉토리의 makefile에서 include 해서 사용합니다.
#
# 각 패턴 makefile에서 include 전에 아래 변수를 재정의할 수 있습니다:
#   TARGET : 생성할 실행 파일 이름 (기본값: pattern)
#   SRCS   : 컴파일할 소스 파일 목록 (기본값: 디렉토리 내 모든 .cpp)
# =============================================================================

CXX       = g++
CXXFLAGS  = -std=c++17 -Wall -Wextra -O2 -I$(ROOT_DIR) -I. -MMD -MP
LDFLAGS   =

BUILD_DIR = build
TARGET   ?= pattern
SRCS     ?= $(wildcard *.cpp)
OBJS      = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS      = $(OBJS:.o=.d)

# =============================================================================

.PHONY: all clean

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)
