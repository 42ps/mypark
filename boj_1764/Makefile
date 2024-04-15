NAME=boj_1764

TARGET=target/$(NAME)

$(TARGET): src/*.cpp
	c++ -o $@ $^

.PHONY: test
test: $(TARGET)
	./$(TARGET) <input/1 >output/1