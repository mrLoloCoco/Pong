# Pong
Pong Game assignment for CS 170

Controls: 
- Up Key, Down Key: Scroll Menu options
- Enter: Select Menu option
- W, S: Move Paddle
- Escape: Quit to Menu

Instructions:
- Player controls their paddle and plays Pong against the Computer
- ball collision with the paddle at various speeds and angles affects the velocity of the ball
- first player to 5 points wins, then game automatically restarts
- game has sounds for ball collision and leaving the arena

Some Notes:
  - After looking at the SFML example of Pong and reading up on some tutorials and forums, I decided to approach 
    making the Pong game through a longer process. After following a tutorial on youtube, I learned that
    rather than purely making the entire game in the 'main' file, it was better to understand how to 
    make the game through various game states, and files for various aspects of the game. By following the 
    tutorial, I learned to implement various files for the menu screen, game screen, the player paddle,
    the ai paddle, the ball (which included most of the conditions and logic for the game (collisions, win, lose,
    physics, etc.) and the game states, which is the fundamental base for the various states of the game, from
    Initialize, Update, Render, Draw, and Destroy, which all take part throughout the game. The main_game contains
    most of the logic using the game_states to initialize, render, update, destroy and draw elements to the screen, 
    while 'main' simply controls the window settings of the game. Many of the source files have corresponding
    header files that control the various public and private aspects. The hardest parts to implement were the physics
    for the game (reflection off the paddle, velocity, collision, etc.), the ai (responsiveness and difficulty to        beat), and the various conditions for scoring. All in all, I learned a lot more
    about C++ from developing this Pong game and have gained familiarity with the SFML library. 

