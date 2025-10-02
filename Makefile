PROGRAM_NAME := main
IMAGE_NAME := image.ppm

SRC_DIR := src
INC_DIR := inc
BUILD_DIR := build
IMAGE_DIR := images

SOURCE_EXTENSION := .c

SOURCE_FILES := $(wildcard $(SRC_DIR)/*$(SOURCE_EXTENSION))
OBJECT_FILES := $(patsubst $(SRC_DIR)/%$(SOURCE_EXTENSION),$(BUILD_DIR)/%.o,$(SOURCE_FILES))
DEPENDENCY_FILES := $(OBJECT_FILES:.o=.d)
EXEC_FILE := $(BUILD_DIR)/$(PROGRAM_NAME)
IMAGE_FILE := $(IMAGE_DIR)/$(IMAGE_NAME)

CC := cc
CFLAGS := -MMD -MP -std=c99 -pedantic -Wall -Wextra -O3 -I ./$(INC_DIR) -DIMAGE_NAME=\"$(IMAGE_FILE)\"
LDFLAGS := -lm

IMAGE_VIEWER := xdg-open

all: $(IMAGE_FILE)

$(BUILD_DIR) $(IMAGE_DIR):
	mkdir -pv $@

# check if the build directory exists
$(OBJECT_FILES): | $(BUILD_DIR)

# compile
$(BUILD_DIR)/%.o: $(SRC_DIR)/%$(SOURCE_EXTENSION)
	$(CC) -c $(CFLAGS) $< -o $@

-include $(DEPENDENCY_FILES)

# link
$(EXEC_FILE): $(OBJECT_FILES)
	$(CC) $^ $(LDFLAGS) -o $@

# render an image
$(IMAGE_FILE): $(EXEC_FILE) | $(IMAGE_DIR)
	./$(EXEC_FILE)

open: $(IMAGE_FILE)
	$(IMAGE_VIEWER) $(IMAGE_FILE)

# remove build files
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all open clean
