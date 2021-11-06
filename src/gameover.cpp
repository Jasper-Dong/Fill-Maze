#include "gameover.h"
#include "main.h"

// game over
void gameOver(){
    // if all empty are filled
    int count = 0;
    for (int i=0; i<colormap.size(); i++){
        for (int j=0; j<colormap.at(i).size(); j++){
            if (colormap.at(i).at(j) == 0) {
                count += 1;
            }
        }
    }
	if (count == 0){
		over = true;
	}
}