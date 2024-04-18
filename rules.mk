# required variables:
#  NAME

TARGET=target/$(NAME)

$(TARGET): src/main.cpp
	c++ $(CXXFLAGS) -std=c++17 -o $@ $^

.PHONY: test pwd
test: $(TARGET)
	./test.sh "./$(TARGET)"
