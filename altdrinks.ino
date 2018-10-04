
#define MAX_NAME_LENGTH 17

#define ALT_WHISKEY &ingredients[0]
#define ALT_RUM &ingredients[1]
#define ALT_SYRUP &ingredients[2]
#define ALT_COKE &ingredients[3]
#define ALT_SODA &ingredients[4]
#define ALT_LIME_JUICE &ingredients[5]

typedef struct {
  char name[MAX_NAME_LENGTH];
  uint8_t relay;
} Ingredient;

typedef struct {
  Ingredient* ingredient;
  uint8_t percent;
} Portion;

typedef struct {
  char name[MAX_NAME_LENGTH];
  Portion *portions;
  uint8_t num_portions;
} Drink;

//void drinkPour() {
//  Drink drink = drinks[0];
//  for (int i = 0; i < drink.num_portions; i++) {
//    Portion portion = drink.portions[i];
//    
//    lcdClear();
//    lcdPrintCentered(drink.name, 0);
//    
//    char bottomString[17] = {0};
//    snprintf(bottomString, MAX_NAME_LENGTH, "%d%% %s", portion.percent, portion.ingredient->name);
//    lcdPrintCentered(bottomString, 1);
//
//    // relayTurnOn()
//    delay(1000);
//  }
//}

Ingredient ingredients[6] = {
  (Ingredient){"Whiskey", 1},
  (Ingredient){"Rum", 2},
  (Ingredient){"Syrup", 3},
  (Ingredient){"Coke", 4},
  (Ingredient){"Soda", 5},
  (Ingredient){"Lime Juice", 6},
};

const Drink drinks2[] = {
  (Drink){"Whiskey", (Portion[1]){
    {ALT_WHISKEY, 100}}, 1},
    
  (Drink){"Rum", (Portion[1]){
    {ALT_RUM, 100}}, 1},
    
  (Drink){"Coke", (Portion[1]){
    {ALT_COKE, 100}}, 1},

  (Drink){"Rum and Coke", (Portion[2]){
    {ALT_RUM, 20}, {ALT_COKE, 80}}, 1},
};






