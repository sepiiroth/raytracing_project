#include "Plan.h"

Plan::Plan() {
    this->mat = Material(Color(0.5, 0.1, 0.1), Color(0.75, 0.5, 0.5), Color(0.75, 0.75, 0.75), 0.0f);
    this->textureMode = TextureMode::Damier;
}

Plan::Plan(TextureMode textureMode, Material m) {
     this->textureMode = textureMode;
     this->mat = m;
}
