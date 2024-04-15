# required variables:
#  NAME

TARGET=target/$(NAME)

$(TARGET): src/*.cpp
	c++ -o $@ $^

.PHONY: test pwd
test: $(TARGET)
	./test.sh "./$(TARGET)"
