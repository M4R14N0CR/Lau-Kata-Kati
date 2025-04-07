<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
</head>
<body>
  <h1>Lau-Kata-Kati</h1>

  <h2>Overview</h2>
  <p>
    This project is an implementation of the traditional Indian game “Lau-Kata-Kati” using the C programming language. It allows two players to compete on a butterfly-shaped board where the objective is to capture or block the opponent's tokens. The game ends when one player captures all of the opponent’s pieces.
  </p>

  <h2>Implementation Details</h2>
  <p>
    The board is represented by a linked structure called <code>node</code> that defines each board position. Each node holds:
  </p>
  <ul>
    <li>An integer indicating the occupying player (0 for empty, 1 for player 1, 2 for player 2).</li>
    <li>A unique cell number for player reference.</li>
    <li>Pointers for directional moves (up, down, left, right) and additional connections for the central node.</li>
  </ul>
  <p>
    The key functions include:
  </p>
  <ul>
    <li><strong>Board Setup:</strong> <code>new_node</code>, <code>new_board</code>, and <code>new_game</code> (which calls <code>leftSide</code> and <code>rightSide</code>) build the board.</li>
    <li><strong>Display:</strong> A board-printing function displays cell numbers in different colors—white for empty, blue for player 1, and red for player 2.</li>
    <li><strong>Movement and Capture:</strong> Functions such as <code>find_node</code>, <code>isAdyacent</code>, <code>eat_token</code>, and <code>move_token</code> handle token movements and capturing mechanics.</li>
    <li><strong>Game Flow:</strong> The main function <code>start_game</code> manages the game menu, tracks tokens, validates moves, and determines the winner.</li>
  </ul>

  <h2>How to Play</h2>
  <p>
    When the program starts, the user is prompted to enter the board depth. Then, the starting player is decided, and the board is displayed. During each turn, the player inputs the cell number of the token they wish to move and the destination cell number.
  </p>
  <p>
    Valid moves update the board accordingly. If a token capture is made, the same player gets another turn; otherwise, the turn switches. The game continues until one player loses all tokens, and a winner is declared.
  </p>

  <h2>Conclusion</h2>
  <p>
    This implementation demonstrates the use of dynamic data structures and pointer manipulation in C to model a game board. It integrates game logic with interactive user input, offering a practical example of game development using classic programming techniques.
  </p>
</body>
</html>
