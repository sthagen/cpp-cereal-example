#define CATCH_CONFIG_MAIN

#include <cereal/cereal.hpp>
#include <cereal/archives/json.hpp>

#include <string>
#include <sstream>

struct player_data {
    int id{-1};
    std::string name{};
};

template<typename Archive>
void serialize(Archive& archive, player_data const &data) {
    archive(
        cereal::make_nvp("id", data.id), 
        cereal::make_nvp("name", data.name)
    );
}

int main() {
    player_data player{3, "Gamer One"};
    std::ostringstream oss;
    cereal::JSONOutputArchive output(oss);
    output(cereal::make_nvp("player_data", player));

    std::cout << oss.str() << std::endl;
}
