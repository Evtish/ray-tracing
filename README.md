# Build and run

### Compile the program, render the image and open it
```make open```

Or open the rendered file manually from the [`images`](./images/) directory (it will be created after running `make render`).

### Compile the program and render the image
```make render```

Or run the executable file manually from the [`build`](./build/) directory (it will be created after running `make`).

### Compile the program
```make```

### Remove build and the image
```make clean```

# Settings
You can modify the following parameters in the source code:
- `IMAGE_H` － in [`inc/image.h`](./inc/image.h)
- `BENCHMARK` － in [`src/main.c`](./src/main.c)
- `ANTI_ALIASING_MODE`, `SAMPLES_PER_PIXEL` － in [`src/anti_aliasing.c`](./src/anti_aliasing.c)
- `scene[]` － in [`src/scene.c`](./src/scene.c)
- `AMOUNT_OF_HITTABLES` － in [`inc/scene.h`](./inc/scene.h)
