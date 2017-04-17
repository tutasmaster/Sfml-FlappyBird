#include "GameMaster.h"

namespace GameMaster{
    std::vector<bool*> failSettings;
    int score = 0;
    bool fail = false;
    void setFail(bool setting){
        for(int i = 0; i < failSettings.size(); i++){
            fail = setting;
            *failSettings[i] = setting;
        }
    }
    void addScore(){
        score += 1;
        std::cout<<score<<std::endl;
    }
}
