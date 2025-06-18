#include "ASpell.hpp"
#include "ATarget.hpp"

void ASpell::launch(ATarget const & target) const{

	target.getHitBySpell(*this);
}
