//
// Created by Elad on 02/05/2022.
//

#include "Card.h"

Card::Card(std::string cardName) :
    m_cardName(cardName)
{}
void Card::getInfoStream(std::ostream& outStream) const{
    printCardDetails(outStream, m_cardName);
    this->getCardDetails(outStream);
    printEndOfCardDetails(outStream);
}
std::ostream& operator<<(std::ostream& outStream, const Card &card){
    card.getInfoStream(outStream);
    return outStream;
}