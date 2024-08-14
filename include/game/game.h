
/// @brief Initialise function for the game
/// @return An initial game state
void* initialise();

/// @brief Update the game state
/// @param dt Time delta
/// @param state Game state
void update(double dt, void* state);

/// @brief Render the game state
/// @param dt Time delta
/// @param state Game state
void render(double dt, const void* state);

/// @brief Cleanup the game state
/// @param state Game state
void cleanup(void* state);