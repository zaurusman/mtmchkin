//
// Created by Elad on 02/05/2022.
//

#include "Card.h"

Card::Card(std::string cardName) :
    m_cardName(cardName)
{}
void Card::getInfoStream(std::ostream& outStream) const{
    printCardDetails(outStream, m_cardName);
    printEndOfCardDetails(outStream);
}
std::string Card::getName() const{
    return m_cardName;
}
std::ostream& operator<<(std::ostream& outStream, const Card &card){
    card.getInfoStream(outStream);
    return outStream;
}