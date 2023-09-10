// entities.h

typedef struct {
    int x, y;                       // Position
    int health;                     // Health points
    const char *inventory[10];      // Max 10 items in inventory for now
    int inventoryCount;             // Number of items in the inventory
} Player;

typedef struct {
    int x, y;                       // Position
    int damage;                     // Damage points
} Enemy;

typedef struct {
    int x, y;                       // Position
    char *name;                     // Name of the item
} Item;

typedef struct {
    int x, y;                       // Position
    const char *name;               // Name of the quest
    bool isCompleted;               // Completed or not
} Quest;