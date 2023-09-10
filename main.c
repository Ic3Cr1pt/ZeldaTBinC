#include <ncurses.h>
#include <stdlib.h>
#include "entities.h"

void handlePlayerMovement(int ch, Player *player) {
    switch (ch) {
        case KEY_UP:
            player->y--;
            break;
        case KEY_DOWN:
            player->y++;
            break;
        case KEY_LEFT:
            player->x--;
            break;
        case KEY_RIGHT:
            player->x++;
            break;
        default:
            break;
    }
}

void handleCombatMechanics(Player *player, Enemy *enemy) {
    if (player -> x == enemy -> x && player -> y == enemy -> y) {
        player -> health -= enemy -> damage;
        
        printw("Engaged in combat! Lost %d health!", enemy -> damage);
        
        enemy -> x = -1; // Remove enemy from board
        enemy -> y = -1;
    }
}

int main() {
    // Initialize ncurses
    initscr(); // Initialize the window
    noecho(); // Don't echo keypresses
    keypad(stdscr, TRUE); // Enable function keys

    // Initialize player
    Player player = {10, 10, 100};
    // Initialize an enemy for demonstration
    Enemy enemy = {20, 20, 10};
    // Initialize an item for demonstration
    Item item = {5, 5, "Sword"};
    // Initialize a quest
    Quest relicQuest = {15, 15, "Find the Relic", false};
    // Initialize a new item for the Relic
    Item relic = {relicQuest.x, relicQuest.y, "Relic"};

    // Game loop
    int ch;
    while ((ch = getch()) != 'q') { // Quit the game when 'q' is pressed
        // Game logic here
        clear(); // Clear the screen;

        // Handle movement
        handlePlayerMovement(ch, &player);

        // Collision Detection
        // Keep player inside screen boundaries
        if (player.x < 0) player.x = 0;
        if (player.y < 0) player.y = 0;
        if (player.x >= COLS) player.x = COLS - 1;
        if (player.y >= LINES) player.y = LINES - 1;

        // Combat mechanics
        handleCombatMechanics(&player, &enemy);
        
        // Item Interaction
        // Check for item pickup
        if (player.x == item.x && player.y == item.y) {
            // Implement item logic here
            player.inventory[player.inventoryCount++] = item.name;
            printw("Picked up a %s!\n", item.name);
        }

        if (player.x == relic.x && player.y == relic.y) {
            player.inventory[player.inventoryCount++] = relic.name;
            mvprintw(1, 0, "You have found the Relic! Quest complete!");
            relicQuest.isCompleted = true;
        }

        // Draw player, enemy, and item
        mvprintw(player.y, player.x, "@");

        if (enemy.x >= 0 && enemy.y >= 0) { // Only draw enemy if it's on the board
            mvprintw(enemy.y, enemy.x, "E");
        }
        mvprintw(item.y, item.x, "I");
        mvprintw(relic.y, relic.x, "R");

        // Draw UI
        mvprintw(0, 0, "Health: %d", player.health);
        mvprintw(1, 0, "Quest: %s %s", relicQuest.name, relicQuest.isCompleted ? "(Completed)" : "(Not Completed)");

        // Game Over
        if (player.health <= 0) {
            mvprintw(LINES / 2, (COLS - 9) / 2, "Game Over");
            getch();    // Wait for a key press
            break;      // Exit the game loop
        }

        int enemyMove = rand() % 4;
        switch (enemyMove) {
            case 0:
                enemy.y--;
                break;
            case 1:
                enemy.y++;
                break;
            case 2:
                enemy.x--;
                break;
            case 3:
                enemy.x++;
                break;
        }


        refresh(); // Update the screen
    }

    endwin();
    return 0;
}