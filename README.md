
# Cub3d 🕹️

Cub3d is a 3D game engine project developed as part of the 42 curriculum. This project is inspired by classic raycasting engines like those seen in early 3D games, including *Wolfenstein 3D*. The goal is to create a 3D rendering engine that can display simple 3D environments with walls, textures, and dynamic player movement.

This project includes the bonus tasks, which further extend the functionality and graphical capabilities of the engine.

## Key Features

- **Raycasting Engine**: A 3D engine that uses raycasting to render 2D textures in a 3D environment.
- **Textured Walls**: The ability to apply textures to walls in the 3D environment for a more immersive experience.
- **Player Movement**: Control the movement and orientation of the player within the 3D environment using the keyboard and mouse.
- **Map Rendering**: A simple 2D map layout with the ability to navigate through different levels.

## Bonus Features

- **Mini-map**: A small map displayed on the screen to help navigate the environment.
- **Sprite Rendering**: The ability to render sprites (2D objects) like items and enemies.
- **Dynamic Lighting**: Improved lighting effects, such as the ability to light walls based on player distance.

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/nfoughal/Cub3d.git
   ```

2. Navigate into the project directory:

   ```bash
   cd Cub3d
   ```

3. Compile the project:

   ```bash
   make
   ```

4. Run the game:

   ```bash
   ./cub3d maps/map.cub
   ```

## Controls 🎮

- **W/A/S/D**: Move around the environment
- **Mouse**: Look around the environment
- **ESC**: Quit the game

## References

- [42Cub3d](https://github.com/42cursus/cub3d)
- [Raycasting tutorial](https://www.youtube.com/watch?v=bs8x1B4tcDA)
- [Wolfenstein 3D Raycasting](https://www.gamasutra.com/blogs/JonathanWhiting/20171129/308792/Understanding_Raycasting_in_Wolfenstein_3D.php)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
