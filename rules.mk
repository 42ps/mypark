# required variables:
#  NAME

TARGET=target/$(NAME)

$(TARGET): src/*.cpp
	c++ -std=c++17 -o $@ $^

.PHONY: test pwd
test: $(TARGET)
	./test.sh "./$(TARGET)"
