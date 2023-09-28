#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>
#include <strings.h>
#include <ctype.h>

typedef struct{
    char nombre[20];
    char tp[10];
    char ts[15];
}pokemon;

void cargar(pokemon *);
void jugar(pokemon *, int, int);
void gens(char *, char *, int *, int *);
void info();
int adivinar(pokemon *, char *, int, int, int, char, char *, char *, char *);

int main(){
    pokemon p[1011];
    char res, x, y;
    int gen1=1, gen2=1010;

    system("cls");

    cargar(p);

    printf("-------- WORDLE POKEMON --------\n\n\n");
    do{
        printf("Selecciona una opcion:\n\n");
        printf("1. Jugar\n");
        printf("2. Elegir generaciones\n");
        printf("3. Informacion y Reglas\n");
        printf("4. Salir\n");

        fflush(stdin);
        scanf("%c", &res);

        system("cls");

        switch(res){
            case '1':
                jugar(p,gen1,gen2);
                break;
            case '2':
                gens(&x,&y,&gen1,&gen2);
                break;
            case '3':
                info();
                break;
            case '4':
                printf("Programa creado por: @jeesuux_fdez\n");
                printf("Gracias por jugar.\n\n");
                sleep(2);
                return 0;
            default:
                printf("Opcion incorrecta\n\n");
                break;
        }
    }while(res!='4');
}

void cargar(pokemon *p){
    int i;

    char *nombres[] = {" ","Bulbasaur", "Ivysaur", "Venusaur", "Charmander", "Charmeleon", "Charizard", "Squirtle", "Wartortle", "Blastoise", "Caterpie", "Metapod", "Butterfree", "Weedle", "Kakuna", "Beedrill", "Pidgey", "Pidgeotto", "Pidgeot", "Rattata", "Raticate", "Spearow", "Fearow", "Ekans", "Arbok", "Pikachu", "Raichu", "Sandshrew", "Sandlash", "Nidoran", "Nidorina", "Nidoqueen", "Nidoran", "Nidorino", "Nidoking", "Clefairy", "Clebafle", "Vulpix", "Ninetales", "Jigglypuff", "Wigglytuff", "Zubat", "Golbat", "Oddish", "Gloom", "Vileplume", "Paras", "Parasect", "Venonat", "Venomoth", "Diglett", "Dugtrio", "Meowth", "Persian", "Psyduck", "Golduck", "Mankey", "Primeape", "Growlithe", "Arcanine", "Poliwag", "Poliwhirl", "Poliwrath", "Abra", "Kadabra", "Alakazam", "Machop", "Machoke", "Machamp", "Bellsprout", "Weepinbell", "Victreebel", "Tentacool", "Tentacruel", "Geodude", "Graveler", "Golem", "Ponyta", "Rapidash", "Slowpoke", "Slowbro", "Magnemite", "Magneton", "Farfetchd", "Doduo", "Dodrio", "Seel", "Dewgong", "Grimer", "Muk", "Shellder", "Cloyster", "Gastly", "Haunter", "Gengar", "Onix", "Drowzee", "Hypno", "Krabby", "Kingler", "Voltorb", "Electrode", "Exeggcute", "Exeggutor", "Cubone", "Marowak", "Hitmonlee", "Hitmonchan", "Lickitung", "Koffing", "Weezing", "Rhyhorn", "Rhydon", "Chansey", "Tangela", "Kangaskhan", "Horsea", "Seadra", "Goldeen", "Seaking", "Staryu", "Starmie", "MrMime", "Scyther", "Jynx", "Electabuzz", "Magmar", "Pinsir", "Tauros", "Magikarp", "Gyarados", "Lapras", "Ditto", "Eevee", "Vaporeon", "Jolteon", "Flareon", "Porygon", "Omanyte", "Omastar", "Kabuto", "Kabutops", "Aerodactyl", "Snorlax", "Articuno", "Zapdos", "Moltres", "Dratini", "Dragonair", "Dragonite", "Mewtwo", "Mew", "Chikorita", "Bayleef", "Meganium", "Cyndaquil", "Quilava", "Typhlosion", "Totodile", "Croconaw", "Feraligatr", "Sentret", "Furret", "Hoothoot", "Noctowl", "Ledyba", "Ledian", "Spinarak", "Ariados", "Crobat", "Chinchou", "Lanturn", "Pichu", "Cleffa", "Igglybuff", "Togepi", "Togetic", "Natu", "Xatu", "Mareep", "Flaaffy", "Ampharos", "Bellossom", "Marill", "Azumarill", "Sudowoodo", "Politoed", "Hoppip", "Skiploom", "Jumpluff", "Aipom", "Sunkern", "Sunflora", "Yanma", "Wooper", "Quagsire", "Espeon", "Umbreon", "Murkrow", "Slowking", "Misdreavous", "Unown", "Wobbuffet", "Girafarig", "Pineco", "Forretress", "Dunsparce", "Gligar", "Steelix", "Snubbull", "Granbull", "Qwilfish", "Scizor", "Shuckle", "Heracross", "Sneasel", "Teddiursa", "Ursaring", "Slugma", "Magcargo", "Swinub", "Piloswine", "Corsola", "Remoraid", "Octillery", "Delibird", "Mantine", "Skarmory", "Houndour", "Houndoom", "Kingdra", "Phanpy", "Donphan", "Porygon2", "Stantler", "Smeargle", "Tyrogue", "Hitmontop", "Smoochum", "Elekid", "Magby", "Miltank", "Blissey", "Raikou", "Entei", "Suicune", "Larvitar", "Pupitar", "Tyranitar", "Lugia", "HoOh", "Celebi", "Treecko", "Grovyle", "Sceptile", "Torchic", "Combusken", "Blaziken", "Mudkip", "Marshtomp", "Swampert", "Poochyena", "Mightyena", "Zigzagoon", "Linoone", "Wurmple", "Silcoon", "Beautifly", "Cascoon", "Dustox", "Lotad", "Lombre", "Ludicolo", "Seedot", "Nuzleaf", "Shiftry", "Taillow", "Swellow", "Wingull", "Pelipper", "Ralts", "Kirlia", "Gardevoir", "Surskit", "Masquerain", "Shroomish", "Breloom", "Slakoth", "Vigoroth", "Slaking", "Nincada", "Ninjask", "Shedinja", "Whismur", "Loudred", "Exploud", "Makuhita", "Hariyama", "Azurill", "Nosepass", "Skitty", "Delcatty", "Sableye", "Mawile", "Aron", "Lairon", "Aggron", "Meditite", "Medicham", "Electrike", "Manectric", "Plusle", "Minun", "Volbeat", "Illumise", "Roselia", "Gulpin", "Swalot", "Carvanha", "Sharpedo", "Wailmer", "Wailord", "Numel", "Camerupt", "Torkoal", "Spoink", "Grumpig", "Spinda", "Trapinch", "Vibrava", "Flygon", "Cacnea", "Cacturne", "Swablu", "Altaria", "Zangoose", "Seviper", "Lunatone", "Solrock", "Barboach", "Whiscash", "Corphish", "Crawdaunt", "Baltoy", "Claydol", "Lileep", "Cradily", "Anorith", "Armaldo", "Feebas", "Milotic", "Castform", "Kecleon", "Shuppet", "Banette", "Duskull", "Dusclops", "Tropius", "Chimecho", "Absol", "Wynaut", "Snorunt", "Glalie", "Spheal", "Sealeo", "Walrein", "Clamperl", "Huntail", "Gorebyss", "Relicanth", "Luvdisc", "Bagon", "Shelgon", "Salamence", "Beldum", "Metang", "Metagross", "Regirock", "Regice", "Registeel", "Latias", "Latios", "Kyogre", "Groudon", "Rayquaza", "Jirachi", "Deoxys", "Turtwig", "Grotle", "Torterra", "Chimchar", "Monferno", "Infernape", "Piplup", "Prinplup", "Empoleon", "Starly", "Staravia", "Staraptor", "Bidoof", "Bibarel", "Kricketot", "Kricketune", "Shinx", "Luxio", "Luxray", "Budew", "Roserade", "Cranidos", "Rampardos", "Shieldon", "Bastiodon", "Burmy", "Wormadam", "Mothim", "Combee", "Vespiquen", "Pachirisu", "Buizel", "Floatzel", "Cherubi", "Cherrim", "Shellos", "Gastrodon", "Ambipom", "Drifloon", "Drifblim", "Buneary", "Lopunny", "Mismagius", "Honchkrow", "Glameow", "Purugly", "Chingling", "Stunky", "Skuntank", "Bronzor", "Bronzong", "Bonsly", "MimeJr", "Happiny", "Chatot", "Spiritomb", "Gible", "Gabite", "Garchomp", "Munchlax", "Riolu", "Lucario", "Hippopotas", "Hippowdon", "Skorupi", "Drapion", "Croagunk", "Toxicroak", "Carnivine", "Finneon", "Lumineon", "Mantyke", "Snover", "Abomasnow", "Weavile", "Magnezone", "Lickilicky", "Rhyperior", "Tangrowth", "Electivire", "Magmortar", "Togekiss", "Yanmega", "Leafeon", "Glaceon", "Gliscor", "Mamoswine", "PorygonZ", "Gallade", "Probopass", "Dusknoir", "Froslass", "Rotom", "Uxie", "Mesprit", "Azelf", "Dialga", "Palkia", "Heatran", "Regigigas", "Giratina", "Cresselia", "Phione", "Manaphy", "Darkrai", "Shaymin", "Arceus", "Victini", "Snivy", "Servine", "Serperior", "Tepig", "Pignite", "Emboar", "Oshawott", "Dewott", "Samurott", "Patrat", "Watchog", "Lillipup", "Herdier", "Stoutland", "Purrloin", "Liepard", "Pansage", "Simisage", "Pansear", "Simisear", "Panpour", "Simipour", "Munna", "Musharna", "Pidove", "Tranquill", "Unfezant", "Blitzle", "Zebstrika", "Roggenrola", "Boldore", "Gigalith", "Woobat", "Swoobat", "Drilbur", "Excadrill", "Audino", "Timburr", "Gurdurr", "Conkeldurr", "Tympole", "Palpitoad", "Seismitoad", "Throh", "Sawk", "Sewaddle", "Swadloon", "Leavanny", "Venipede", "Whirlipede", "Scolipede", "Cottonee", "Whimsicott", "Petilil", "Lilligant", "Basculin", "Sandile", "Krokorok", "Krookodile", "Darumaka", "Darmanitan", "Maractus", "Dwebble", "Crustle", "Scraggy", "Scrafty", "Sigilyph", "Yamask", "Cofagrigus", "Tirtouga", "Carracosta", "Archen", "Archeops", "Trubbish", "Garbodor", "Zorua", "Zoroark", "Minccino", "Cinccino", "Gothita", "Gothorita", "Gothitelle", "Solosis", "Duosion", "Reuniclus", "Ducklett", "Swanna", "Vanillite", "Vanillish", "Vanilluxe", "Deerling", "Sawsbuck", "Emolga", "Karrablast", "Escavalier", "Foongus", "Amoonguss", "Frillish", "Jellicent", "Alomomola", "Joltik", "Galvantula", "Ferroseed", "Ferrothorn", "Klink", "Klang", "Klinklang", "Tynamo", "Eelektrik", "Eelektross", "Elgyem", "Beheeyem", "Litwick", "Lampent", "Chandelure", "Axew", "Fraxure", "Haxorus", "Cubchoo", "Beartic", "Cryogonal", "Shelmet", "Accelgor", "Stunfisk", "Mienfoo", "Mienshao", "Druddigon", "Golett", "Golurk", "Pawniard", "Bisharp", "Bouffalant", "Rufflet", "Braviary", "Vullaby", "Mandibuzz", "Heatmor", "Durant", "Deino", "Zweilous", "Hydreigon", "Larvesta", "Volcarona", "Cobalion", "Terrakion", "Virizion", "Tornadus", "Thundurus", "Reshiram", "Zekrom", "Landorus", "Kyurem", "Keldeo", "Meloetta", "Genesect", "Chespin", "Quilladin", "Chesnaught", "Fennekin", "Braixen", "Delphox", "Froakie", "Frogadier", "Greninja", "Bunnelby", "Diggersby", "Fletchling", "Fletchinder", "Talonflame", "Scatterbug", "Spewpa", "Vivillon", "Litleo", "Pyroar", "Flabebe", "Floette", "Florges", "Skiddo", "Gogoat", "Pancham", "Pangoro", "Furfrou", "Espurr", "Meowstic", "Honedge", "Doublade", "Aegislash", "Spritzee", "Aromatisse", "Swirlix", "Slurpuff", "Inkay", "Malamar", "Binacle", "Barbaracle", "Skrelp", "Dragalge", "Clauncher", "Clawitzer", "Helioptile", "Heliolisk", "Tyrunt", "Tyrantrum", "Amaura", "Aurorus", "Sylveon", "Hawlucha", "Dedenne", "Carbink", "Goomy", "Sliggoo", "Goodra", "Klefki", "Phantump", "Trevenant", "Pumpkaboo", "Gourgeist", "Bergmite", "Avalugg", "Noibat", "Noivern", "Xerneas", "Yveltal", "Zygarde", "Diancie", "Hoopa", "Volcanion", "Rowlet", "Dartrix", "Decidueye", "Litten", "Torracat", "Incineroar", "Popplio", "Brionne", "Primarina", "Pikipek", "Trumbeak", "Toucannon", "Yungoos", "Gumshoos", "Grubbin", "Charjabug", "Vikavolt", "Crabrawler", "Crabominable", "Oricorio", "Cutiefly", "Ribombee", "Rockruff", "Lycanroc", "Wishiwashi", "Mareanie", "Toxapex", "Mudbray", "Mudsdale", "Dewpider", "Araquanid", "Fomantis", "Lurantis", "Morelull", "Shiinotic", "Salandit", "Salazzle", "Stufful", "Bewear", "Bounsweet", "Steenee", "Tsareena", "Comfey", "Oranguru", "Passimian", "Wimpod", "Golisopod", "Sandygast", "Palossand", "Pyukumuku", "CodigoCero", "Silvally", "Minior", "Komala", "Turtonator", "Togedemaru", "Mimikyu", "Bruxish", "Drampa", "Dhelmise", "Jangmoo", "Hakamoo", "Kommoo", "TapuKoko", "TapuLele", "TapuBulu", "TapuFini", "Cosmog", "Cosmoem", "Solgaleo", "Lunala", "Nihilego", "Buzzwole", "Pheromosa", "Xurkitree", "Celesteela", "Kartana", "Guzzlord", "Necrozma", "Magearna", "Marshadow", "Poipole", "Naganadel", "Stakataka", "Blacephalon", "Zeraora", "Meltan", "Melmetal", "Grookey", "Thwackey", "Rillaboom", "Scorbunny", "Raboot", "Cinderace", "Sobble", "Drizzile", "Inteleon", "Skwovet", "Greedent", "Rookidee", "Corvisquire", "Corviknight", "Blipbug", "Dottler", "Orbeetle", "Nickit", "Thievul", "Gossifleur", "Eldegoss", "Wooloo", "Dubwool", "Chewtle", "Drednaw", "Yamper", "Boltund", "Rolycoly", "Carkol", "Coalossal", "Applin", "Flapple", "Appletun", "Silicobra", "Sandaconda", "Cramorant", "Arrokuda", "Barraskewda", "Toxel", "Toxtricity", "Sizzlipede", "Centiskorch", "Clobbopus", "Grapploct", "Sinistea", "Polteageist", "Hatenna", "Hattrem", "Hatterene", "Impidimp", "Morgrem", "Grimmsnarl", "Obstagoon", "Perrserker", "Cursola", "Sirfetchd", "MrRime", "Runerigus", "Milcery", "Alcremie", "Falinks", "Pincurchin", "Snom", "Frosmoth", "Stonjourner", "Eiscue", "Indeedee", "Morpeko", "Cufant", "Copperajah", "Dracozolt", "Arctozolt", "Dracovish", "Arctovish", "Duraludon", "Dreepy", "Drakloak", "Dragapult", "Zacian", "Zamazenta", "Eternatus", "Kubfu", "Urshifu", "Zarude", "Regieleki", "Regidrago", "Glastrier", "Spectrier", "Calyrex", "Wyrdeer", "Kleavor", "Ursaluna", "Basculegion", "Sneasler", "Overqwil", "Enamorus", "Sprigatito", "Floragato", "Meowscarada", "Fuecoco", "Crocalor", "Skeledirge", "Quaxly", "Quaxwell", "Quaquaval", "Lechonk", "Oinkologne", "Tarountula", "Spidops", "Nymble", "Lokix", "Pawmi", "Pawmo", "Pawmot", "Tandemaus", "Maushold", "Fidough", "Dachsbun", "Smoliv", "Dolliv", "Arboliva", "Squawkabilly", "Nacli", "Naclstack", "Garganacl", "Charcadet", "Armarouge", "Ceruledge", "Tadbulb", "Bellibolt", "Wattrel", "Kilowattrel", "Maschiff", "Mabosstiff", "Shroodle", "Grafaiai", "Bramblin", "Brambleghast", "Toedscool", "Toedscruel", "Klawf", "Capsakid", "Scovillain", "Rellor", "Rabsca", "Flittle", "Espathra", "Tinkatink", "Tinkatuff", "Tinkaton", "Wiglett", "Wugtrio", "Bombirdier", "Finizen", "Palafin", "Varoom", "Revavroom", "Cyclizar", "Orthworm", "Glimmet", "Glimmora", "Greavard", "Houndstone", "Flamigo", "Cetoddle", "Cetitan", "Veluza", "Dondozo", "Tatsugiri", "Annihilape", "Clodsire", "Farigiraf", "Dudunsparce", "Kingambit", "Colmilargo", "Colagrito", "Furioseta", "Melenaleteo", "Reptalada", "Pelarena", "Ferrodada", "Ferrosaco", "Ferropalmas", "Ferrocuello", "Ferropolilla", "Ferropuas", "Frigibax", "Arctibax", "Baxcalibur", "Gimmighoul", "Gholdengo", "WoChien", "ChienPao", "TingLu", "ChiYu", "Bramaluna", "Ferropaladin", "Koraidon", "Miraidon", "Ondulagua", "Ferroverdor"};

    char *tip[]={"", "Planta", "Planta", "Planta", "Fuego", "Fuego", "Fuego", "Agua", "Agua", "Agua", "Bicho", "Bicho", "Bicho", "Bicho", "Bicho", "Bicho", "Normal", "Normal", "Normal", "Normal", "Normal", "Normal", "Normal", "Veneno", "Veneno", "Electrico", "Electrico", "Tierra", "Tierra", "Veneno", "Veneno", "Veneno", "Veneno", "Veneno", "Veneno", "Hada", "Hada", "Fuego", "Fuego", "Normal", "Normal", "Veneno", "Veneno", "Planta", "Planta", "Planta", "Bicho", "Bicho", "Bicho", "Bicho", "Tierra", "Tierra", "Normal", "Normal", "Agua", "Agua", "Lucha", "Lucha", "Fuego", "Fuego", "Agua", "Agua", "Agua", "Psiquico", "Psiquico", "Psiquico", "Lucha", "Lucha", "Lucha", "Planta", "Planta", "Planta", "Agua", "Agua", "Roca", "Roca", "Roca", "Fuego", "Fuego", "Agua", "Agua", "Electrico", "Electrico", "Normal", "Normal", "Normal", "Agua", "Agua", "Veneno", "Veneno", "Agua", "Agua", "Fantasma", "Fantasma", "Fantasma", "Roca", "Psiquico", "Psiquico", "Agua", "Agua", "Electrico", "Electrico", "Planta", "Planta", "Tierra", "Tierra", "Lucha", "Lucha", "Normal", "Veneno", "Veneno", "Tierra", "Tierra", "Normal", "Planta", "Normal", "Agua", "Agua", "Agua", "Agua", "Agua", "Agua", "Psiquico", "Bicho", "Hielo", "Electrico", "Fuego", "Bicho", "Normal", "Agua", "Agua", "Agua", "Normal", "Normal", "Agua", "Electrico", "Fuego", "Normal", "Roca", "Roca", "Roca", "Roca", "Roca", "Normal", "Hielo", "Electrico", "Fuego", "Dragon", "Dragon", "Dragon", "Psiquico", "Psiquico", "Planta", "Planta", "Planta", "Fuego", "Fuego", "Fuego", "Agua", "Agua", "Agua", "Normal", "Normal", "Normal", "Normal", "Bicho", "Bicho", "Bicho", "Bicho", "Veneno", "Agua", "Agua", "Electrico", "Hada", "Normal", "Hada", "Hada", "Psiquico", "Psiquico", "Electrico", "Electrico", "Electrico", "Planta", "Agua", "Agua", "Roca", "Agua", "Planta", "Planta", "Planta", "Normal", "Planta", "Planta", "Bicho", "Agua", "Agua", "Psiquico", "Siniestro", "Siniestro", "Agua", "Fantasma", "Psiquico", "Psiquico", "Normal", "Bicho", "Bicho", "Normal", "Tierra", "Acero", "Hada", "Hada", "Agua", "Bicho", "Bicho", "Bicho", "Siniestro", "Normal", "Normal", "Fuego", "Fuego", "Hielo", "Hielo", "Agua", "Agua", "Agua", "Hielo", "Agua", "Acero", "Siniestro", "Siniestro", "Agua", "Tierra", "Tierra", "Normal", "Normal", "Normal", "Lucha", "Lucha", "Hielo", "Electrico", "Fuego", "Normal", "Normal", "Electrico", "Fuego", "Agua", "Roca", "Roca", "Roca", "Psiquico", "Fuego", "Psiquico", "Planta", "Planta", "Planta", "Fuego", "Fuego", "Fuego", "Agua", "Agua", "Agua", "Siniestro", "Siniestro", "Normal", "Normal", "Bicho", "Bicho", "Bicho", "Bicho", "Bicho", "Agua", "Agua", "Agua", "Planta", "Planta", "Planta", "Normal", "Normal", "Agua", "Agua", "Psiquico", "Psiquico", "Psiquico", "Bicho", "Bicho", "Planta", "Planta", "Normal", "Normal", "Normal", "Bicho", "Bicho", "Bicho", "Normal", "Normal", "Normal", "Lucha", "Lucha", "Normal", "Roca", "Normal", "Normal", "Siniestro", "Acero", "Acero", "Acero", "Acero", "Lucha", "Lucha", "Electrico", "Electrico", "Electrico", "Electrico", "Bicho", "Bicho", "Planta", "Veneno", "Veneno", "Agua", "Agua", "Agua", "Agua", "Fuego", "Fuego", "Fuego", "Psiquico", "Psiquico", "Normal", "Tierra", "Tierra", "Tierra", "Planta", "Planta", "Normal", "Dragon", "Normal", "Veneno", "Roca", "Roca", "Agua", "Agua", "Agua", "Agua", "Tierra", "Tierra", "Roca", "Roca", "Roca", "Roca", "Agua", "Agua", "Normal", "Normal", "Fantasma", "Fantasma", "Fantasma", "Fantasma", "Planta", "Psiquico", "Siniestro", "Psiquico", "Hielo", "Hielo", "Hielo", "Hielo", "Hielo", "Agua", "Agua", "Agua", "Agua", "Agua", "Dragon", "Dragon", "Dragon", "Acero", "Acero", "Acero", "Roca", "Hielo", "Acero", "Dragon", "Dragon", "Agua", "Tierra", "Dragon", "Acero", "Psiquico", "Planta", "Planta", "Planta", "Fuego", "Fuego", "Fuego", "Agua", "Agua", "Agua", "Normal", "Normal", "Normal", "Normal", "Normal", "Bicho", "Bicho", "Electrico", "Electrico", "Electrico", "Planta", "Planta", "Roca", "Roca", "Roca", "Roca", "Bicho", "Bicho", "Bicho", "Bicho", "Bicho", "Electrico", "Agua", "Agua", "Planta", "Planta", "Agua", "Agua", "Normal", "Fantasma", "Fantasma", "Normal", "Normal", "Fantasma", "Siniestro", "Normal", "Normal", "Psiquico", "Veneno", "Veneno", "Acero", "Acero", "Roca", "Psiquico", "Normal", "Normal", "Fantasma", "Dragon", "Dragon", "Dragon", "Normal", "Lucha", "Lucha", "Tierra", "Tierra", "Veneno", "Veneno", "Veneno", "Veneno", "Planta", "Agua", "Agua", "Agua", "Planta", "Planta", "Siniestro", "Electrico", "Normal", "Tierra", "Planta", "Electrico", "Fuego", "Hada", "Bicho", "Planta", "Hielo", "Tierra", "Hielo", "Normal", "Psiquico", "Roca", "Fantasma", "Hielo", "Electrico", "Psiquico", "Psiquico", "Psiquico", "Acero", "Agua", "Fuego", "Normal", "Fantasma", "Psiquico", "Agua", "Agua", "Siniestro", "Planta", "Normal", "Psiquico", "Planta", "Planta", "Planta", "Fuego", "Fuego", "Fuego", "Agua", "Agua", "Agua", "Normal", "Normal", "Normal", "Normal", "Normal", "Siniestro", "Siniestro", "Planta", "Planta", "Fuego", "Fuego", "Agua", "Agua", "Psiquico", "Psiquico", "Normal", "Normal", "Normal", "Electrico", "Electrico", "Roca", "Roca", "Roca", "Psiquico", "Psiquico", "Tierra", "Tierra", "Normal", "Lucha", "Lucha", "Lucha", "Agua", "Agua", "Agua", "Lucha", "Lucha", "Bicho", "Bicho", "Bicho", "Bicho", "Bicho", "Bicho", "Planta", "Planta", "Planta", "Planta", "Agua", "Tierra", "Tierra", "Tierra", "Fuego", "Fuego", "Planta", "Bicho", "Bicho", "Siniestro", "Siniestro", "Psiquico", "Fantasma", "Fantasma", "Agua", "Agua", "Roca", "Roca", "Veneno", "Veneno", "Siniestro", "Siniestro", "Normal", "Normal", "Psiquico", "Psiquico", "Psiquico", "Psiquico", "Psiquico", "Psiquico", "Agua", "Agua", "Hielo", "Hielo", "Hielo", "Normal", "Normal", "Electrico", "Bicho", "Bicho", "Planta", "Planta", "Agua", "Agua", "Agua", "Bicho", "Bicho", "Planta", "Planta", "Acero", "Acero", "Acero", "Electrico", "Electrico", "Electrico", "Psiquico", "Psiquico", "Fantasma", "Fantasma", "Fantasma", "Dragon", "Dragon", "Dragon", "Hielo", "Hielo", "Hielo", "Bicho", "Bicho", "Tierra", "Lucha", "Lucha", "Dragon", "Tierra", "Tierra", "Siniestro", "Siniestro", "Normal", "Normal", "Normal", "Siniestro", "Siniestro", "Fuego", "Bicho", "Siniestro", "Siniestro", "Siniestro", "Bicho", "Bicho", "Acero", "Roca", "Planta", "Volador", "Electrico", "Dragon", "Dragon", "Tierra", "Dragon", "Agua", "Normal", "Bicho", "Planta", "Planta", "Planta", "Fuego", "Fuego", "Fuego", "Agua", "Agua", "Agua", "Normal", "Normal", "Normal", "Fuego", "Fuego", "Bicho", "Bicho", "Bicho", "Fuego", "Fuego", "Hada", "Hada", "Hada", "Planta", "Planta", "Lucha", "Lucha", "Normal", "Psiquico", "Psiquico", "Acero", "Acero", "Acero", "Hada", "Hada", "Hada", "Hada", "Siniestro", "Siniestro", "Roca", "Roca", "Veneno", "Veneno", "Agua", "Agua", "Electrico", "Electrico", "Roca", "Roca", "Roca", "Roca", "Hada", "Lucha", "Electrico", "Roca", "Dragon", "Dragon", "Dragon", "Acero", "Fantasma", "Fantasma", "Fantasma", "Fantasma", "Hielo", "Hielo", "Volador", "Volador", "Hada", "Siniestro", "Dragon", "Roca", "Psiquico", "Fuego", "Planta", "Planta", "Planta", "Fuego", "Fuego", "Fuego", "Agua", "Agua", "Agua", "Normal", "Normal", "Normal", "Normal", "Normal", "Bicho", "Bicho", "Bicho", "Lucha", "Lucha", "Fuego", "Bicho", "Bicho", "Roca", "Roca", "Agua", "Veneno", "Veneno", "Tierra", "Tierra", "Agua", "Agua", "Planta", "Planta", "Planta", "Planta", "Veneno", "Veneno", "Normal", "Normal", "Planta", "Planta", "Planta", "Hada", "Normal", "Lucha", "Bicho", "Bicho", "Fantasma", "Fantasma", "Agua", "Normal", "Normal", "Roca", "Normal", "Fuego", "Electrico", "Fantasma", "Agua", "Normal", "Fantasma", "Dragon", "Dragon", "Dragon", "Electrico", "Psiquico", "Planta", "Agua", "Psiquico", "Psiquico", "Psiquico", "Psiquico", "Roca", "Bicho", "Bicho", "Electrico", "Acero", "Planta", "Siniestro", "Psiquico", "Acero", "Lucha", "Veneno", "Veneno", "Roca", "Fuego", "Electrico", "Acero", "Acero", "Planta", "Planta", "Planta", "Fuego", "Fuego", "Fuego", "Agua", "Agua", "Agua", "Normal", "Normal", "Volador", "Volador", "Volador", "Bicho", "Bicho", "Bicho", "Siniestro", "Siniestro", "Planta", "Planta", "Normal", "Normal", "Agua", "Agua", "Electrico", "Electrico", "Roca", "Roca", "Roca", "Planta", "Planta", "Planta", "Tierra", "Tierra", "Volador", "Agua", "Agua", "Electrico", "Electrico", "Fuego", "Fuego", "Lucha", "Lucha", "Fantasma", "Fantasma", "Psiquico", "Psiquico", "Psiquico", "Siniestro", "Siniestro", "Siniestro", "Siniestro", "Acero", "Fantasma", "Lucha", "Hielo", "Tierra", "Hada", "Hada", "Lucha", "Electrico", "Hielo", "Hielo", "Roca", "Hielo", "Psiquico", "Electrico", "Acero", "Acero", "Electrico", "Electrico", "Agua", "Agua", "Acero", "Dragon", "Dragon", "Dragon", "Hada", "Lucha", "Veneno", "Lucha", "Lucha", "Siniestro", "Electrico", "Dragon", "Hielo", "Fantasma", "Psiquico", "Normal", "Bicho", "Tierra", "Agua", "Lucha", "Siniestro", "Hada", "Planta", "Planta", "Planta", "Fuego", "Fuego", "Fuego", "Agua", "Agua", "Agua", "Normal", "Normal", "Bicho", "Bicho", "Bicho", "Bicho", "Electrico", "Electrico", "Electrico", "Normal", "Normal", "Hada", "Hada", "Planta", "Planta", "Planta", "Normal", "Roca", "Roca", "Roca", "Fuego", "Fuego", "Fuego", "Electrico", "Electrico", "Electrico", "Electrico", "Siniestro", "Siniestro", "Veneno", "Veneno", "Planta", "Planta", "Tierra", "Tierra", "Roca", "Planta", "Planta", "Bicho", "Bicho", "Psiquico", "Psiquico", "Hada", "Hada", "Hada", "Agua", "Agua", "Volador", "Agua", "Agua", "Acero", "Acero", "Dragon", "Acero", "Roca", "Roca", "Fantasma", "Fantasma", "Volador", "Hielo", "Hielo", "Agua", "Agua", "Dragon", "Lucha", "Veneno", "Normal", "Normal", "Siniestro", "Tierra", "Hada", "Planta", "Fantasma", "Bicho", "Electrico", "Tierra", "Hielo", "Lucha", "Siniestro", "Fuego", "Roca", "Dragon", "Dragon", "Dragon", "Fantasma", "Acero", "Siniestro", "Siniestro", "Siniestro", "Siniestro", "Dragon", "Hada", "Lucha", "Electrico", "Agua", "Planta"};

    char *tis[]={"","Veneno", "Veneno", "Veneno", "Sin Secundario", "Sin Secundario", "Volador", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Volador", "Veneno", "Veneno", "Veneno", "Volador", "Volador", "Volador", "Sin Secundario", "Sin Secundario", "Volador", "Volador", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Tierra", "Sin Secundario", "Sin Secundario", "Tierra", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Hada", "Hada", "Volador", "Volador", "Veneno", "Veneno", "Veneno", "Planta", "Planta", "Veneno", "Veneno", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Lucha", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Veneno", "Veneno", "Veneno", "Veneno", "Veneno", "Tierra", "Tierra", "Tierra", "Sin Secundario", "Sin Secundario", "Psiquico", "Psiquico", "Acero", "Acero", "Volador", "Volador", "Volador", "Sin Secundario", "Hielo", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Hielo", "Veneno", "Veneno", "Veneno", "Tierra", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Psiquico", "Psiquico", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Roca", "Roca", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Psiquico", "Hada", "Volador", "Psiquico", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Volador", "Hielo", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Agua", "Agua", "Agua", "Agua", "Volador", "Sin Secundario", "Volador", "Volador", "Volador", "Sin Secundario", "Sin Secundario", "Volador", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Volador", "Volador", "Volador", "Volador", "Veneno", "Veneno", "Volador", "Electrico", "Electrico", "Sin Secundario", "Sin Secundario", "Hada", "Sin Secundario", "Volador", "Volador", "Volador", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Hada", "Hada", "Sin Secundario", "Sin Secundario", "Volador", "Volador", "Volador", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Volador", "Tierra", "Tierra", "Sin Secundario", "Sin Secundario", "Volador", "Psiquico", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Psiquico", "Sin Secundario", "Acero", "Sin Secundario", "Volador", "Tierra", "Sin Secundario", "Sin Secundario", "Veneno", "Acero", "Roca", "Lucha", "Hielo", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Roca", "Tierra", "Tierra", "Roca", "Sin Secundario", "Sin Secundario", "Volador", "Volador", "Volador", "Fuego", "Fuego", "Dragon", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Psiquico", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Tierra", "Tierra", "Siniestro", "Volador", "Volador", "Planta", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Lucha", "Lucha", "Sin Secundario", "Tierra", "Tierra", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Volador", "Sin Secundario", "Veneno", "Planta", "Planta", "Planta", "Sin Secundario", "Siniestro", "Siniestro", "Volador", "Volador", "Volador", "Volador", "Hada", "Hada", "Hada", "Agua", "Volador", "Sin Secundario", "Lucha", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Tierra", "Volador", "Fantasma", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Hada", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Fantasma", "Hada", "Roca", "Roca", "Roca", "Psiquico", "Psiquico", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Veneno", "Sin Secundario", "Sin Secundario", "Siniestro", "Siniestro", "Sin Secundario", "Sin Secundario", "Tierra", "Tierra", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Dragon", "Dragon", "Sin Secundario", "Siniestro", "Volador", "Volador", "Sin Secundario", "Sin Secundario", "Psiquico", "Psiquico", "Tierra", "Tierra", "Sin Secundario", "Siniestro", "Psiquico", "Psiquico", "Planta", "Planta", "Bicho", "Bicho", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Volador", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Agua", "Agua", "Agua", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Roca", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Volador", "Psiquico", "Psiquico", "Psiquico", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Psiquico", "Psiquico", "Sin Secundario", "Sin Secundario", "Volador", "Psiquico", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Tierra", "Sin Secundario", "Lucha", "Lucha", "Sin Secundario", "Sin Secundario", "Acero", "Volador", "Volador", "Volador", "Sin Secundario", "Agua", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Veneno", "Veneno", "Sin Secundario", "Sin Secundario", "Acero", "Acero", "Sin Secundario", "Planta", "Volador", "Volador", "Volador", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Tierra", "Sin Secundario", "Volador", "Volador", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Volador", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Siniestro", "Siniestro", "Psiquico", "Psiquico", "Sin Secundario", "Hada", "Sin Secundario", "Volador", "Siniestro", "Tierra", "Tierra", "Tierra", "Sin Secundario", "Sin Secundario", "Acero", "Sin Secundario", "Sin Secundario", "Bicho", "Siniestro", "Lucha", "Lucha", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Volador", "Hielo", "Hielo", "Hielo", "Acero", "Sin Secundario", "Roca", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Volador", "Volador", "Sin Secundario", "Sin Secundario", "Volador", "Tierra", "Sin Secundario", "Lucha", "Acero", "Sin Secundario", "Fantasma", "Fantasma", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Dragon", "Dragon", "Acero", "Sin Secundario", "Dragon", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Fuego", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Lucha", "Lucha", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Volador", "Volador", "Volador", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Volador", "Volador", "Sin Secundario", "Acero", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Tierra", "Tierra", "Sin Secundario", "Sin Secundario", "Planta", "Planta", "Planta", "Veneno", "Veneno", "Veneno", "Hada", "Hada", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Siniestro", "Siniestro", "Siniestro", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Roca", "Roca", "Lucha", "Lucha", "Volador", "Sin Secundario", "Sin Secundario", "Roca", "Roca", "Volador", "Volador", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Volador", "Volador", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Planta", "Planta", "Volador", "Sin Secundario", "Acero", "Veneno", "Veneno", "Fantasma", "Fantasma", "Sin Secundario", "Electrico", "Electrico", "Acero", "Acero", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Fuego", "Fuego", "Fuego", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Electrico", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Fantasma", "Fantasma", "Acero", "Acero", "Sin Secundario", "Volador", "Volador", "Volador", "Volador", "Sin Secundario", "Acero", "Dragon", "Dragon", "Dragon", "Fuego", "Fuego", "Lucha", "Lucha", "Lucha", "Sin Secundario", "Volador", "Fuego", "Electrico", "Volador", "Hielo", "Lucha", "Psiquico", "Acero", "Sin Secundario", "Sin Secundario", "Lucha", "Sin Secundario", "Sin Secundario", "Psiquico", "Sin Secundario", "Sin Secundario", "Siniestro", "Sin Secundario", "Tierra", "Volador", "Volador", "Volador", "Sin Secundario", "Sin Secundario", "Volador", "Normal", "Normal", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Siniestro", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Fantasma", "Fantasma", "Fantasma", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Psiquico", "Psiquico", "Agua", "Agua", "Agua", "Dragon", "Sin Secundario", "Sin Secundario", "Normal", "Normal", "Dragon", "Dragon", "Hielo", "Hielo", "Sin Secundario", "Volador", "Hada", "Hada", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Hada", "Planta", "Planta", "Planta", "Planta", "Sin Secundario", "Sin Secundario", "Dragon", "Dragon", "Sin Secundario", "Volador", "Tierra", "Hada", "Fantasma", "Agua", "Volador", "Volador", "Fantasma", "Sin Secundario", "Sin Secundario", "Siniestro", "Sin Secundario", "Sin Secundario", "Hada", "Volador", "Volador", "Volador", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Electrico", "Electrico", "Sin Secundario", "Hielo", "Volador", "Hada", "Hada", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Agua", "Agua", "Sin Secundario", "Sin Secundario", "Bicho", "Bicho", "Sin Secundario", "Sin Secundario", "Hada", "Hada", "Fuego", "Fuego", "Lucha", "Lucha", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Psiquico", "Sin Secundario", "Agua", "Agua", "Tierra", "Tierra", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Volador", "Sin Secundario", "Dragon", "Acero", "Hada", "Psiquico", "Dragon", "Planta", "Sin Secundario", "Lucha", "Lucha", "Hada", "Hada", "Hada", "Hada", "Sin Secundario", "Sin Secundario", "Acero", "Fantasma", "Veneno", "Lucha", "Lucha", "Sin Secundario", "Volador", "Acero", "Dragon", "Sin Secundario", "Hada", "Fantasma", "Sin Secundario", "Dragon", "Acero", "Fantasma", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Acero", "Sin Secundario", "Psiquico", "Psiquico", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Roca", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Fuego", "Fuego", "Dragon", "Dragon", "Dragon", "Sin Secundario", "Sin Secundario", "Agua", "Sin Secundario", "Sin Secundario", "Veneno", "Veneno", "Bicho", "Bicho", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Hada", "Hada", "Hada", "Hada", "Normal", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Psiquico", "Fantasma", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Bicho", "Bicho", "Sin Secundario", "Sin Secundario", "Normal", "Siniestro", "Sin Secundario", "Sin Secundario", "Dragon", "Hielo", "Dragon", "Hielo", "Dragon", "Fantasma", "Fantasma", "Fantasma", "Sin Secundario", "Sin Secundario", "Dragon", "Sin Secundario", "Siniestro", "Planta", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Planta", "Psiquico", "Roca", "Normal", "Fantasma", "Veneno", "Veneno", "Volador", "Sin Secundario", "Sin Secundario", "Siniestro", "Sin Secundario", "Sin Secundario", "Fantasma", "Sin Secundario", "Sin Secundario", "Lucha", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Siniestro", "Sin Secundario", "Lucha", "Lucha", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Normal", "Normal", "Normal", "Volador", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Sin Secundario", "Psiquico", "Fantasma", "Sin Secundario", "Sin Secundario", "Volador", "Volador", "Sin Secundario", "Sin Secundario", "Normal", "Normal", "Fantasma", "Fantasma", "Planta", "Planta", "Sin Secundario", "Sin Secundario", "Fuego", "Sin Secundario", "Psiquico", "Sin Secundario", "Sin Secundario", "Acero", "Acero", "Acero", "Sin Secundario", "Sin Secundario", "Siniestro", "Sin Secundario", "Sin Secundario", "Veneno", "Veneno", "Normal", "Sin Secundario", "Veneno", "Veneno", "Sin Secundario", "Sin Secundario", "Lucha", "Sin Secundario", "Sin Secundario", "Psiquico", "Sin Secundario", "Agua", "Fantasma", "Tierra", "Psiquico", "Sin Secundario", "Acero", "Lucha", "Psiquico", "Siniestro", "Hada", "Lucha", "Tierra", "Acero", "Agua", "Electrico", "Volador", "Veneno", "Electrico", "Hielo", "Hielo", "Hielo", "Sin Secundario", "Fantasma", "Planta", "Hielo", "Tierra", "Fuego", "Siniestro", "Lucha", "Dragon", "Dragon", "Dragon", "Psiquico"};

    for(i=0;i<1011;i++){
        strcpy(p[i].nombre, nombres[i]);
        strcpy(p[i].tp, tip[i]);
        strcpy(p[i].ts, tis[i]);
    }
}

void jugar(pokemon *p, int gen1, int gen2){
    char res, prim[10], sec[15];
    int elegido, nletras=0, i, intentos=5, acierto=0;
    char letras[27]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    do{
        printf("En que modo vas a jugar?\n\n");
        printf("1. Modo normal\n");
        printf("2. Modo asistido\n");
        printf("3. Modo desafio\n");

        fflush(stdin);
        scanf("%c", &res);

        system("cls");

        if(res!='1' && res!='2'){
            printf("Opcion incorrecta\n\n");
        }
    }while(res!='1' && res!='2' && res!='3');

    if(res=='3'){
        intentos=3;
    }

    srand(time(NULL));

    elegido=(rand()%gen2)+gen1;

    while(p[elegido].nombre[nletras]!='\0'){
        nletras++;
    }

    nletras++;

    char *pokemon=(char *)malloc(nletras*sizeof(char));

    for(i=0;i<nletras-1;i++){
        pokemon[i]='_';
    }

    pokemon[nletras]='\0';
    strcpy(prim,"???");
    strcpy(sec, "???");
    
    printf("El pokemon que tienes que adivinar tiene %i letras, como se muestra abajo:\n\n", nletras-1);

    while(intentos>0 && acierto==0){
        acierto=adivinar(p, pokemon, elegido, nletras, intentos, res, prim, sec, letras);
        intentos--;
    }

    system("cls");

    if(acierto==1){
        printf("Felicidades, has adivinado el pokemon!\n\n");
    }else{
        printf("Se acabaron los intentos! El pokemon era %s\n\n", p[elegido].nombre);
    }

    printf("                                  ,'\\\n");
    printf("    _.----.        ____         ,'  _\\   ___    ___     ____\n");
    printf("_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.\n");
    printf("\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |\n");
    printf(" \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |\n");
    printf("   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |\n");
    printf("    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |\n");
    printf("     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |\n");
    printf("      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |\n");
    printf("       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |\n");
    printf("        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |\n");
    printf("                                `'                            '-._|\n");

    sleep(2);
}

int adivinar(pokemon *p, char *pokemon, int elegido, int nletras, int intentos, char res, char *prim, char *sec, char *letras){
    int i,j,respuesta=0,longitud;
    char nombre[20];
    
    do{
        printf("Te quedan %i intentos.\n\n",intentos);

        for(i=0;i<nletras-1;i++){
            printf("%c ", pokemon[i]);
        }

        if(res=='2'){
            printf("\n\nTipo primario:   %s", prim);
            printf("\nTipo secundario: %s", sec);
        }

        i=0;

        printf("\n\n(Letras por utilizar:");

        while(i<27){
            if(letras[i]!='0'){
                printf(" %c",letras[i]);
            }
            i++;
        }
    
        printf(")");

        printf("\n\nTu respuesta: ");
        scanf("%s",nombre);
        system("cls");

        i=0;

        while(i<1010 && respuesta==0){
            if(strcasecmp(p[i].nombre,nombre)!=0){ //Esta funcion compara dos cadenas de caracteres obviando mayusculas y minusculas
                i++;
            }else{
                respuesta=i;
            }
        }

        if(i==1010){
            printf("Ese pokemon no existe! Intentalo de nuevo.\n\n");
        }
    }while(i==1010);

    longitud=strlen(nombre);

    for(i=0;i<longitud;i++){
        j=0;
        do{
            if(letras[j]==toupper(nombre[i])){
                letras[j]='0';
                j=26;
            }
            j++;
        }while(letras[j]!='\0');
    }

    if(strcasecmp(p[elegido].nombre,nombre)==0){
        return 1;
    }else{
        i=0;
        while(p[elegido].nombre[i]!='\0'){
            j=0;
            while(p[respuesta].nombre[j]!='\0'){
                if(tolower(p[elegido].nombre[i])==tolower(p[respuesta].nombre[j])){ //Pone las dos letras en minuscula y las compara para ver si son iguales
                    pokemon[i]=(toupper(p[elegido].nombre[i]));
                }
                j++;
            }
            i++;
        }
    }

    if(res=='2'){
        if((strcmp(p[elegido].tp,p[respuesta].tp)==0) || strcmp(p[elegido].tp,p[respuesta].ts)==0){
            strcpy(prim,p[elegido].tp);
        }
        if((strcmp(p[elegido].ts,p[respuesta].tp)==0) || strcmp(p[elegido].ts,p[respuesta].ts)==0){
            strcpy(sec,p[elegido].ts);
        }
    }

    return 0;
}

void gens(char *x, char *y, int *gen1, int *gen2){
    char aux;
    do{
        printf("Introduce las generaciones en las que quieres jugar (Rango permitido 1-9):\n");
        printf("Desde la generacion ");
        fflush(stdin);
        scanf("%c", x);
        if(*x!='1' && *x!='2' && *x!='3' && *x!='4' && *x!='5' && *x!='6' && *x!='7' && *x!='8' && *x!='9'){
            system("cls");
            printf("Opcion incorrecta\n\n");
        }
    }while(*x!='1' && *x!='2' && *x!='3' && *x!='4' && *x!='5' && *x!='6' && *x!='7' && *x!='8' && *x!='9');
    system("cls");
    do{
        printf("Introduce las generaciones en las que quieres jugar (Rango permitido 1-9):\n");
        printf("Desde la generacion %c",*x);
        printf(" hasta la generacion ");
        fflush(stdin);
        scanf("%c", y);
        if(*y!='1' && *y!='2' && *y!='3' && *y!='4' && *y!='5' && *y!='6' && *y!='7' && *y!='8' && *y!='9'){
            system("cls");
            printf("Opcion incorrecta\n\n");
        }
    }while(*y!='1' && *y!='2' && *y!='3' && *y!='4' && *y!='5' && *y!='6' && *y!='7' && *y!='8' && *y!='9');
    if(*x>*y){
        aux=*y;
        *y=*x;
        *x=aux;
    }
    switch(*x){
        case '1':
            *gen1=1;
            break;
        case '2':
            *gen1=152;
            break;
        case '3':
            *gen1=252;
            break;
        case '4':
            *gen1=387;
            break;
        case '5':
            *gen1=495;
            break;
        case '6':
            *gen1=650;
            break;
        case '7':
            *gen1=722;
            break;
        case '8':
            *gen1=810;
            break;
        case '9':
            *gen1=906;
            break;
    }
    switch(*y){
        case '1':
            *gen2=151;
            break;
        case '2':
            *gen2=251;
            break;
        case '3':
            *gen2=386;
            break;
        case '4':
            *gen2=494;
            break;
        case '5':
            *gen2=649;
            break;
        case '6':
            *gen2=721;
            break;
        case '7':
            *gen2=809;
            break;
        case '8':
            *gen2=905;
            break;
        case '9':
            *gen2=1011;
            break;
    }
}

void info(){
    char tecla;

    do{
        printf("Este programa es un Wordle pokemon.\n\n");

        printf("Al empezar a jugar, se escogera un pokemon random que este dentro del rango de generaciones elegido y el objetivo del juego es intentar adivinar cual es ese pokemon, con un maximo de 5 intentos.\n\n");

        printf("Para jugar, deberas introducir correctamente el nombre de un pokemon de cualquier generacion y las letras comunes entre ambos se revelaran para seguir avanzando en el juego.\n\n");

        printf("DATO IMPORTANTE: Los pokemon que contengan caracteres que no pertenezcan al abecedario, como: puntos(.), espacios( ), guiones(-) o apostrofes (') no contaran como caracteres, por lo que se borran.\n");

        printf("Ejemplo: (Mr. Mime -> MrMime) o (Farfetch'd --> Farfetchd)\n\n");

        printf("Tambien, existen 3 niveles de dificultad:\n");

        printf("    1. Normal: En este nivel de dificultad solo se muestran las letras comunes entre el pokemon a adivinar y el que introduces\n");

        printf("    2. Asistido: En este nivel de dificultad, que es mas facil, ademas de mostrar las letras comunes entre los 2 pokemon, tambien se muestran los tipos comunes entre ambos.\n");

        printf("    3. Desafio: Mismas condiciones que en el Modo Normal pero con 3 intentos en vez de 5\n\n");

        printf("Presiona Enter para continuar... ");

        fflush(stdin);
        tecla = getchar();
        system("cls");
    }while(tecla!='\n');
    
}