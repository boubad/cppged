
/////////////////////////
#include "stringconstants.h"
///////////////////////////
namespace infoged {

//////////////////////////////
const int stringconstants::MAX_LEVEL_VALUE(99);
const size_t stringconstants::LINE_MAX_LENGTH(255);
const size_t stringconstants::ID_MAX_LENGTH(22);
const size_t stringconstants::VALUE_LENGTH_THRESHOLD(220);
const size_t stringconstants::TAG_MAX_LENGTH(31);
///////////////////
const char_type stringconstants::AROBAS('@');
const char_type stringconstants::ZERO('0');
const char_type stringconstants::ONE('1');
const char_type stringconstants::NINE('9');
const char_type stringconstants::CR('\r');
const char_type stringconstants::CHAR_SPACE(' ');
const char_type stringconstants::LF('\n');
const char_type stringconstants::UNDERSCORE('_');
//
const string stringconstants::NUMBER_PATTERN("\\d+(\\.\\d+)?");
//
const string stringconstants::EMPTY("");
const string stringconstants::SPACE(" ");
const string stringconstants::TAB("\t");
const string stringconstants::COLON(":");
const string stringconstants::WHITECHARS(" \t\r\n");
const string stringconstants::ALPHA("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
const string stringconstants::ELIPSIS("...");
const string stringconstants::SLASH("/");
const string stringconstants::NEWLINE("\n");
//
const string stringconstants::STR_QINC("(INC)");
const string stringconstants::STR_QQUESTION("??");
//
const string stringconstants::STR_INC("INC");
const string stringconstants::STR_UNKNOWN("UNKNOWN");
const string stringconstants::STR_QUESTION("?");
const string stringconstants::STR_UNKN("UNKN");
//
const string stringconstants::STR_LINE_DUMP(" Line: ");
const string stringconstants::STR_LINE_COLON(": ");
const string stringconstants::STR_LINE_ERRORS(" Errors: ");
const string stringconstants::STR_LINE_NONCOMPLIANTS(" Non(compliants: ");
const string
    stringconstants::STR_MISSING_ENTITY("Définition entité manquante: ");
const string
    stringconstants::STR_NOTREFERENCED_ENTITY("Entité nom referencée: ");
//

const string stringconstants::ERR_EMPTY_LINE("Ligne vide");
const string stringconstants::ERR_LINE_TOO_LONG(
    "Longueur de ligne supérieurz à la limite de 255 caractères");
const string stringconstants::ERR_CANNOT_DECODE("Erreur de décodage");
const string stringconstants::ERR_INVALID_LEVEL("Niveau ligne incorrect");
const string stringconstants::ERR_INVALID_ID("Format ID incorrect");
const string stringconstants::ERR_INVALID_TAG("Format de tag incorrect");
const string stringconstants::ERR_NONSTANDART_TAG("Tag non standart");
const string
    stringconstants::ERR_INVALID_LINESEQUENCE("Séquence de niveaux incorrecte");
const string
    stringconstants::ERR_INVALID_VALUELENGTH("longueur de valeur incorrecte");
////////////////////////////////
} // namespace infoged