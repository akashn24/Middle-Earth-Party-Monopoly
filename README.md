# Middle Earth Party Monopoly 
An implementation of the classic board game, ***Monopoly***, in C++. I've made it ***Middle Earth*** themed based on the works of ***J.R.R. Tolkien***, and have added some modifications to the rules of the base game. Some of the modifications are based off the video game ***Mario Party***.

## Modifications 
* Dice: Similar to *Mario Party* the characters do not have a standard fair six-sided dice, instead they have *customised dice*, with varying values. 
* Currency: Instead of money the currency used will be stars like in the Mario Party video game.
* Squares on board:
    * The *In Jail/Just Visiting square* is replaced by the *In Dungeon/Just Visiting square* and the *Go To Jail square* is replaced *Go To The Dungeon square*.
    * *Free Parking square* will hold the same function as it does in monopoly but will be renamed as the *Free Stars square*.
    * *Income Tax* and *Luxury Tax square* will be changed to *Minus 200 Stars squares*, where stars will be put into a separate pile.
    * *Community Chest* and *Chance* will be changed to *Plus 100 star squares*.
    * Both *Utility Squares* will be changed to *Re-Roll squares*, where when players land on it, they have a chance to re-roll their characters dice.
    * *Train Station Squares* will be changed to *Teleporters Stations*, called *Eagles Eyrie*, where when players land on it, they will be randomly transported to another square on the board.
    * Properties will be renamed but will keep the same use and can be bought by players, as in the original game, and when players land on a owned property square they will have to pay rent to the owner.

## Gameplay 
1. At the start all players receive **1500 stars**.
2. All players start from the GO square.
3. The order to start the game will be decided by which character they choose, as *Frodo* is Player 1, *Sam* is Player 2 and so on.
4. Players roll their dice and move the number of spaces indicated.
5. If they land on a property they are allowed to buy it, where each property has its own selling price and rent.
6. If they land on a *Teleporter Station* they will automatically be sent to a random square on the board.
7. If they land on a *Re-Roll Square* they can re-roll their dice and move again.
8. If they land on *Minus 200 star squares*, **200 stars** will be subtracted from their total.
9. If they land on *Plus 100 star squares*, **100 stars** will be added to their total.
10. If they land on the *Free Stars square*, they can claim the stars from the minus stars pile.
11. If they land on the *Go To The Dungeon Square* they will be sent to the *In Dungeon Square*, where they will either forfeit a dice roll or pay **150 stars**.
12. Every time players pass the *GO square* they will receive **200 stars**.
13. One round is completed when each player has rolled one time each, not counting the re-roll squares..
14. At the end of the tenth round, players will play a *Pick A Card Minigame* against each other to win stars.
15. At the end of the 20th round, which is the final round, players will play a *Rock-Paper-Scissors Boss Battle* against the Boss, *Sauron*, to win stars.
16. After the Boss Battle, the number of stars of the players are totalled up and the winner will be the one with the highest number of stars.

## How To Run The Game
By having all the `.h` and `.cpp` files in the same folder, all you would need to do is to run the `main.cpp` file and the game should start immediately.

## Built With 
* [Xcode 2019](https://developer.apple.com/xcode/)

## Author 
* **Akash Nair** - [akashn24](https://github.com/akashn24)

## Pull Requests Welcome 
This is just a simple prototype which is far from perfect, so if you would like to fork it and build on it, feel free to do so. Also if there are any bugs or inconsitencies, please send a pull request!