#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

// start variables
int rounds = 0;
bool data_ready = false;
const int widh = 71;
const int height = 29;
vector<pair<int, int>> last_investment;
bool first = true;
int women = 1;
double chance_woman = 0;
double chance_man = 20;
double increase = 10;
int men = 2;
int percent;
int money = 30;
int rent = 5;
int space;
int e = 3;
bool finish_game = false;
bool result;
int decrease = 0;
int commands = -1;
string first_new = "Atualmente, no Brasil, os estudantes de áreas tecnológicas são, em sua maioria, homens, como apresentado na pesquisa do IBGE,\napenas 13,3%% dos estudantes de Computação e TIC(Tecnologia da Informação e Comunicações) são mulheres.\nEssa situação estã gerando indiginação na população e afetando negativamente a economia.\nA grande questão é:sera que o governo vai fazer algo para mudar isso?";

// start gen random numbers
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(1, 100);

// start matrixs

pair<int, int> options[7][3] = {
    {{1, 40}, {2, 30}, {3, 30}},
    {{0, 80}, {0, 70}, {0, 120}},
    {{0, 90}, {0, 120}, {0, 60}},
    {{0, 240}, {0, 300}, {0, 90}},
    {{0, 70}, {0, 130}, {0, 150}},
    {{0, 50}, {0, 180}, {0, 30}},
    {{0, 120}, {0, 500}, {0, 50}}};

pair<int, int> alt[7][3] = {
    {{3, 5}, {3, 2}, {-2, 5}},
    {{-2, 7}, {3, 1}, {2, 6}},
    {{-7, -20}, {2, 4}, {-4, 0}},
    {{2, 4}, {2, 8}, {-4, -5}},
    {{-5, -8}, {3, 4}, {-13, -20}},
    {{-4, -8}, {2, 8}, {-10, 2}},
    {{10, 6}, {9, 20}, {-8, 20}}};

string texts[7][3] = {
    {"Investir em projetos de incentivo e na educação de mulheres nas áreas científicas,visando aumentar a diversidade de gênero nessas áreas.", "Criar jogos educativos nas áreas de exatas que atraiam o público feminino, estimulando a participação das mulheres nestas áreas.", "Investir no petróleo para aproveitar esta riqueza natural e no pré-sal para aumentar os lucros do Brasil."}, //  Texto 1
    {"Investir na agropecuária nacional, fortalecendo a economia local.", "Criar grupos de apoio para mulheres das áreas de exatas para que possam se sentir apoiadas.", "Criar campanhas e palestras demonstrando que, independente do gênero, todos têm a mesma capacidade."},                                                                                                                   //  Texto 2
    {"Incentivar o tradicionalismo, pois os homens devem trabalhar e as mulheres devem ficar em casa cuidando dos filhos.", "Criar leis que garantam a participação de mulheres na política, evitando que esta área permaneça predominada por homens.", "Investir em um exército só de homens, pois eles são mais fortes e assim, melhorar a força do Brasil em guerras."},                        // Texto 3
    {"Criar grupos de maratona de programação feminina para as incentivar a participar de eventos de programação.", "Divulgar na internet e na televisão todos os grandes feitos das mulheres nas áreas de exatas, inspirando, assim, outras mulheres.", "Criar leis para fortalecer o patriarcado."},                                                                                             // Texto4
    {"Unificar os esportes masculinos e femininos, pois, como homens e mulheres são iguais, não faz sentido ter times separados.", "Criar leis que garantam ambiêntes agradáveis para mulheres, pois muitos deles são hostis para elas, afastando-as do ambiente de trabalho.", "Incentivar a criação de empresas só para homens, pois, se não houver mulheres na empresa, não haverá machismo."}, // Texto5
    {"Incentivar a homogeneidade de gênero nas diversas áreas da sociedade, para que haja uma divisão sexual de trabalho.", "Criar leis que garantam a segurança das mulheres em todas áreas.", "Proibir a licença maternidade, pois isso é prejudicial para a economia."},                                                                                                                        // Texto 6
    {"Garantir às mulheres segurança de renda e trabalho no período após a gravidez, incentivando-as a retornar ao ambiente de trabalho.", "Garantir a igualdade salarial para homens e mulheres.", "Investir nas indústrias visando a melhorar a economia e independência econômica do Brasil."},                                                                                                 // Texto7
};

string news[7][3] = {
    {"O maior investimento do governo para que mulheres participem de áreas científicas incentivou"
     "milhares de jovens a seguir carreiras em STEM. A iniciativa da Corporação TecNova, em parcer"
     "ia com universidades renomadas, resultou em um aumento de 30% na participação feminina nesse"
     "s cursos. Economistas apontam que a inclusão de mais mulheres na ciência pode gerar um impac"
     "to positivo no PIB, com projeções de crescimento de 2% nos próximos cinco anos. Além disso, "
     "a iniciativa também está promovendo a criação de programas de mentoria para mulheres cientis"
     "tas, visando apoiar o desenvolvimento de suas carreiras e aumentar a representatividade femi"
     "nina nas áreas científicas.",

     "Desenvolvedores de jogos, como a startup GameHer, estão criando títulos que atendem aos"
     "interesses das mulheres, aumentando a participação feminina no mercado de jogos. A CEO da"
     "GameHer, Julia Lopes, afirmou que essa mudança está promovendo um ambiente mais inclusivo e"
     "diversificado. A empresa relatou um aumento de 50% em suas vendas, demonstrando o impacto"
     "positivo dessa estratégia. Além disso, a GameHer também está investindo em programas de"
     "capacitação para mulheres interessadas em desenvolver jogos, visando incentivar a participação"
     "feminina na indústria de games.",

     "A descoberta de novos campos de petróleo pela PetroNacional está fortalecendo a economia."
     "Especialistas alertam, porém, para os impactos ambientais. A ONG VerdeLimpo destacou que é"
     "essencial balancear o desenvolvimento econômico com a sustentabilidade. No cenário global, a"
     "descoberta coloca o país entre os principais exportadores de petróleo, mas também aumenta as"
     "responsabilidades ambientais e revela um lado sombrio: o aumento do machismo na indústria do "
     "petróleo. Relatos de discriminação e assédio têm surgido, evidenciando a necessidade de combater essa questão."},

    {"A agropecuária nacional está se expandindo graças às inovações tecnológicas implementadas pela"
     "AgroTech Brasil. A empresa, em colaboração com o Ministério da Agricultura, promove práticas"
     "sustentáveis que estão revolucionando o setor. A produção aumentou em 20%, e o impacto positivo"
     "já é visível na balança comercial do país. No entanto, desafios ambientais ainda persistem. Além"
     "disso, a AgroTech Brasil está investindo em programas de capacitação para mulheres agricultoras,"
     "visando promover a participação feminina no setor agropecuário e garantir a igualdade de"
     "oportunidades.",

     "Grupos de apoio feminino, como o RedeMulher, estão ajudando mulheres a superarem desafios e"
     "alcançarem seus objetivos. O projeto MulheresEmpreendedoras, da Fundação Aurora, oferece"
     "mentorias e financiamento para startups lideradas por mulheres, resultando na criação de"
     "milhares de novos negócios. Esse movimento está criando uma rede de suporte vital e empoderando"
     "mulheres em todo o país. Além disso, o RedeMulher também está promovendo a realização de"
     "workshops e cursos de capacitação para mulheres empreendedoras, visando fortalecer suas"
     "habilidades e promover o crescimento de seus negócios.",

     "Campanhas nacionais contra o preconceito, lideradas pelo Instituto IgualdadeJá, estão"
     "promovendo uma sociedade mais justa. A campanha 'Respeito por Todos', lançada pelo governo,"
     "resultou em um aumento significativo na conscientização e no respeito aos direitos das mulheres."
     "Pesquisas mostram que essas iniciativas estão reduzindo incidentes de discriminação e promovendo"
     "maior igualdade. Além disso, o Instituto IgualdadeJá está desenvolvendo programas de educação"
     "e conscientização sobre igualdade de gênero, visando combater o preconceito e promover a"
     "tolerância na sociedade."},

    {"Movimentos tradicionalistas, como o BrasilTradição, estão promovendo valores conservadores e"
     "modos de vida tradicionais. Enquanto ganham apoio em algumas regiões, críticos alertam para o"
     "potencial retrocesso na igualdade de gênero. Organizações de direitos humanos, como a NovoTempo,"
     "sublinhando a importância de balancear tradições com progresso social e inclusão de gênero. Além"
     "disso, a NovoTempo está promovendo debates e diálogos entre diferentes grupos sociais, visando"
     "fomentar a compreensão mútua e encontrar soluções que respeitem os direitos de todos.",

     "Mais mulheres estão sendo eleitas para cargos políticos, trazendo perspectivas diversas e"
     "importantes para a legislação. A iniciativa Mulheres no Poder, apoiada pela ONG Política para"
     "Todos, está treinando futuras líderes. Esse aumento na representação feminina está contribuindo"
     "para políticas públicas mais inclusivas e equitativas, sendo um modelo para outros países da"
     "região. Além disso, a ONG Política para Todos está promovendo a realização de workshops e"
     "cursos de capacitação política para mulheres interessadas em ingressar na vida pública, visando"
     "fortalecer sua participação e influência.",

     "O governo está aumentando o investimento nas forças armadas com o projeto Defesa Forte,"
     "fortalecendo a defesa nacional. No entanto, críticos apontam que esses recursos poderiam ser"
     "melhor empregados em áreas sociais. A organização Paz e Progresso sugere um balanço entre"
     "investimento militar e desenvolvimento social para garantir um crescimento sustentável. Além"
     "disso, a Paz e Progresso está promovendo debates e discussões sobre a destinação dos recursos"
     "públicos, visando encontrar um equilíbrio entre as necessidades de defesa e as demandas sociais."},

    {"Grupos de maratona femininos de programação, como o CodeGirls, estão incentivando a participação de mulheres"
     "em eventos de programação. Essas iniciativas promovem o desenvolvimento de habilidades técnicas e"
     "aumentam a visibilidade feminina na área de programação. Eventos como a Maratona da Igualdade de Programação estão atraindo"
     "milhares de participantes e destacando a importância da inclusão das mulheres na indústria de tecnologia. Além disso, o"
     "CodeGirls está promovendo a realização de treinamentos e workshops para mulheres interessadas"
     "em participar de maratonas de programação, visando prepará-las e encorajá-las a superar desafios.",

     "Campanhas estão destacando as conquistas de mulheres em áreas de ciências exatas, inspirando"
     "futuras gerações. O projeto Mulheres de Ciência, da Fundação Futuro, divulgou histórias de"
     "sucesso que estão ajudando a quebrar estereótipos de gênero. Essas iniciativas estão encorajando"
     "mais meninas a seguir carreiras científicas e promovendo um ambiente mais inclusivo nas"
     "universidades e empresas. Além disso, a Fundação Futuro está promovendo a realização de"
     "palestras e workshops sobre carreiras científicas para estudantes do ensino médio, visando"
     "despertar o interesse das jovens pela ciência.",

     "Sistemas patriarcais ainda prevalecem em muitas áreas, dificultando o progresso para a igualdade"
     "de gênero. Ativistas da Aliança por Igualdade estão trabalhando para desmantelar essas"
     "estruturas e promover uma sociedade mais justa. Campanhas como 'Igualdade Agora' estão ganhando"
     "apoio e destacando a necessidade de mudanças sistêmicas para alcançar a verdadeira equidade de"
     "gênero. Além disso, a Aliança por Igualdade está promovendo a realização de debates e"
     "conferências sobre igualdade de gênero, visando conscientizar a sociedade e impulsionar a"
     "mudança."},

    {"Iniciativas para esportes sem distinção de gênero, como o Esporte para Todos, estão ganhando"
     "apoio, promovendo igualdade e inclusão. A Confederação Esportiva Nacional lançou uma campanha"
     "para garantir que todos, independentemente de gênero, tenham acesso igualitário a recursos"
     "esportivos. Essas mudanças estão criando um ambiente esportivo mais justo e acessível para"
     "todos. Além disso, o Esporte para Todos está promovendo a realização de eventos esportivos"
     "inclusivos, nos quais homens e mulheres competem juntos, visando promover a igualdade de"
     "oportunidades.",

     "Empresas estão se esforçando para criar ambientes de trabalho mais agradáveis, aumentando a"
     "satisfação e produtividade dos funcionários. A Corporação Ambience lidera o movimento com"
     "iniciativas que incluem horários flexíveis e espaços de trabalho colaborativos. No entanto, é"
     "crucial garantir que essas melhorias beneficiem igualmente todos os gêneros para promover uma"
     "verdadeira inclusão. Além disso, a Corporação Ambience está implementando programas de"
     "diversidade e inclusão, visando garantir a igualdade de oportunidades para todos os funcionários.",

     "Empresas exclusivamente masculinas estão sendo criticadas por falta de diversidade e inclusão."
     "Estudos conduzidos pela Universidade Global mostram que a diversidade de gênero nas empresas"
     "leva a melhores resultados e maior inovação. A campanha Diversidade Já, liderada pelo Instituto"
     "Progresso, está pressionando por mudanças significativas no setor empresarial. Além disso, o"
     "Instituto Progresso está promovendo a realização de pesquisas e estudos sobre diversidade de"
     "gênero nas empresas, visando conscientizar o mercado sobre os benefícios da inclusão."},

    {"Políticas que evitam a diversidade de gênero estão enfrentando forte oposição por limitar o"
     "progresso e a inclusão. Organizações como a Diversidade Global estão destacando a importância da"
     "diversidade para a inovação e o sucesso sustentável. Empresas que promovem a inclusão, como a"
     "Tech4All, estão se tornando modelos de sucesso no mercado internacional. Além disso, a"
     "Diversidade Global está promovendo a realização de conferências e eventos sobre diversidade de"
     "gênero, visando disseminar boas práticas e inspirar outras empresas a adotarem políticas de"
     "inclusão.",

     "Medidas de segurança reforçadas para mulheres estão sendo implementadas em áreas urbanas e"
     "rurais. O programa Cidade Segura, uma colaboração entre o governo e a ONG Proteção para Todos,"
     "visa reduzir a violência e o assédio. Essas ações estão criando ambientes mais seguros e"
     "confiáveis para as mulheres em espaços públicos e no trabalho. Além disso, o programa Cidade"
     "Segura está promovendo a realização de campanhas de conscientização e treinamentos de autodefesa"
     "para mulheres, visando empoderá-las e garantir sua segurança.",

     "Propostas para reduzir a licença maternidade estão sendo debatidas, gerando preocupação entre"
     "grupos de direitos das mulheres. O Instituto Maternidade Justa argumenta que uma licença"
     "adequada é essencial para o bem-estar das mães e filhos. A discussão está atraindo atenção"
     "internacional e destaca a importância de políticas de apoio às famílias. Além disso, o Instituto"
     "Maternidade Justa está promovendo a realização de debates e fóruns de discussão sobre a"
     "licença maternidade, visando conscientizar a sociedade sobre a importância desse direito."},

    {"Palestras em escolas sobre igualdade de gênero, como parte do programa Educação para Todos,"
     "estão ajudando a educar jovens sobre respeito e direitos das mulheres. Essas iniciativas, lideradas"
     "pela ONG Educação Igualitária, estão promovendo uma cultura de igualdade e inclusão desde cedo,"
     "preparando as futuras gerações para um mundo mais justo. Além disso, a ONG Educação Igualitária"
     "está desenvolvendo materiais educativos e programas de conscientização sobre igualdade de gênero,"
     "visando disseminar conhecimento e promover a mudança.",

     "Esforços para alcançar a igualdade salarial estão ganhando momentum, com mais empresas adotando"
     "práticas justas de remuneração. A campanha Salário Justo, apoiada pela Federação Nacional de"
     "Trabalhadores, está promovendo transparência salarial e práticas equitativas. Essas mudanças"
     "estão ajudando a reduzir a disparidade de gênero e promover uma economia mais equitativa. Além"
     "disso, a Federação Nacional de Trabalhadores está promovendo a realização de pesquisas e"
     "estudos sobre a igualdade salarial, visando conscientizar a sociedade e pressionar por mudanças.",

     "O setor industrial está se expandindo, trazendo oportunidades de emprego e crescimento"
     "econômico. A iniciativa Indústria para Todos, liderada pela Associação Industrial Brasileira,"
     "visa garantir que essas oportunidades sejam acessíveis igualmente a homens e mulheres. Essa"
     "abordagem inclusiva está sendo vista como um modelo para o desenvolvimento sustentável no"
     "mercado global. Além disso, a Associação Industrial Brasileira está promovendo a realização de"
     "programas de capacitação e treinamento para mulheres interessadas em ingressar na indústria,"
     "visando promover a igualdade de oportunidades e fortalecer o setor industrial."}};

string choices[7][3] = {
    {"Mulheres na ciencia", "Jogos atrativos para mulheres", "Petroleo nacional"},
    {"Agropecuaria nacional", "Grupos de apoio femininos", "Combate ao preconceito contra mulheres"},
    {"Tradicionalismo", "Mulheres na politica", "Investir no exercito"},
    {"Grupos de programacao femininos", "Divulgar feitos das mulheres em exatas", "Patriarcado"},
    {"Esportes sem distincao de genero", "Ambientes inclusivos", "Empresas exclusivamente de homens"},
    {"Evitar a diversidade de genero", "Garantia de segurança para mulheres", "Tirar licensa maternidade"},
    {"Palestras em escolas", "Igualdade salarial", "Industrias"}};

int mapp[height][widh] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

void write_map();
void investments();
bool change_options();

// function to get input without pause the game
void get_input()
{
    while (!finish_game)
    {
        this_thread::sleep_for(chrono::milliseconds(500));
        while (!data_ready)
        {
            cin >> commands;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // igore invalid inputs
                cout << "Entrada inválida. Por favor, digite um número." << endl;
            }
            else
                data_ready = true;
        }
    }
}

int main()
{
    // show the game goal
    cout << "\033[H\033[J\033[30m\033[47mSeu objetivo nesse jogo é conseguir a mesma quantidade(ou aproximada) de homens e mulheres nas áreas de exatas.\nVocê, como presidente do Brasil, deve fazer os melhores investimentos para que isso ocorra. Boa sorte!\n\n\033[0;0m\033[30m\033[47mDigite 0 para continuar: \033[0;0m";
    while (commands != 0)
    {
        cin >> commands;
        if (cin.fail())
        {
            cin.clear();                                              // Limpa o estado de erro de cin
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); // Ignora a entrada inválida
            cout << "Entrada inválida. Por favor, digite um número." << endl;
            commands = -1;
        }
    }
    // start threads
    thread input_thread(get_input);
    thread temp(write_map);

    // main loop to get inputs and show the investment screen;
    while (!finish_game)
    {
        this_thread::sleep_for(chrono::milliseconds(500));
        if (data_ready)
        {
            if (commands == 1)
            {
                investments();
            }
            else
            {
                data_ready = false;
                cout << "Comando invalido!" << endl;
            }
        }
    }

    // show if win or lose
    if (result)
    {
        cout << "\033[H\033[J\033[42;97mParabéns!\nVocê conseguiu atingir a igualdade de genêro nas áreas de exatas e contribuiu para um Brasil mais diverso e justo." << endl;
        this_thread::sleep_for(chrono::seconds(5));
    }
    else
    {
        cout << "\033[H\033[J\033[31;1;4mGAME OVER\nVocê tomou decisões que não colaboraram com a diversidade de gênero e, por isso, o Brasil virou um país dominado por homens. Péssimo da sua parte!\033[0;0m" << endl;
        this_thread::sleep_for(chrono::seconds(5));
    }
    return 0;
}

// write the map of brasil and your stats
void write_map()
{
    while (!finish_game)
    {
        this_thread::sleep_for(chrono::milliseconds(500));
        while (!data_ready)
        {
            if (women >= men)
            {
                result = true;
                finish_game = true;
                data_ready = true;
            }
            else
            {
                if (women == 0)
                {
                    result = false;
                    finish_game = true;
                    data_ready = true;
                }
                else
                {
                    cout << "\033[H\033[J";
                    women = 0;
                    men = 0;
                    cout << "\033[30m\033[47mMapa do Brasil referente a quantidade de homens e mulheres nas áreas de exatas:\033[0;0m" << endl
                         << endl;
                    // print man or woman and apply the probability
                    for (int i = 0; i < height; i++)
                    {
                        for (int j = 0; j < widh; j++)
                        {
                            if (mapp[i][j] == 0)
                            {
                                cout << '.';
                            }
                            else if (mapp[i][j] == 1)
                            {
                                if (dis(gen) <= decrease)
                                    mapp[i][j] = 2;
                                men++;
                                cout << "\033[44m" << "♂" << "\033[0m";
                            }
                            else if (mapp[i][j] == 2)
                            {
                                if (dis(gen) <= chance_man)
                                    mapp[i][j] = 1;
                                women++;
                                cout << "\033[48;5;55m" << "♀" << "\033[0m";
                            }
                        }
                        cout << endl;
                    }
                    cout << endl;
                    percent = women * 100 / (women + men);
                    cout << "Mulheres nas áreas de exatas: " << percent << "%" << endl;
                    cout << "Dinheiro disponível: " << money << "MI" << endl;
                    cout << "Renda: " << rent << "MI" << endl
                         << endl;

                    cout << "\033[30m\033[47mÚLTIMA NOTÍCIA:\033[0;0m" << endl
                         << endl;
                    if (first)
                    {
                        cout << "\033[30m\033[47m" << first_new << "\033[0;0m" << endl
                             << endl;
                    }
                    else
                    {
                        cout << "\033[30m\033[47m";
                        space = 0;
                        for (int c = 0; c < news[last_investment.back().first][last_investment.back().second].size(); c++)
                        {
                            if (c % 100 == 0)
                                cout << endl;
                            cout << news[last_investment.back().first][last_investment.back().second][c];
                        }

                        cout
                            << "\033[0;0m" << endl
                            << endl;
                        // show another new
                        if (rounds == 3)
                        {
                            if (last_investment.size() != 1)
                                last_investment.pop_back();
                            rounds = 0;
                        }
                        rounds++;
                    }
                    cout << "Digite 1 para ver a tela de investimento" << endl;
                    // wait 5 seconds
                    this_thread::sleep_for(chrono::seconds(5));
                    money += rent;
                    chance_man += increase;
                    if (decrease == chance_woman)
                    {
                        decrease -= 0.1;
                    }
                    else
                        decrease -= 3;
                    increase = increase * 7 / 8;
                }
            }
        }
    }
}

// show tabular screen with investments options
void investments()
{
    while (commands != 0)
    {
        cout << "\033[H\033[J";
        cout << "\033[42;97m" << "Dinheiro disponível: " << money << "MI" << endl
             << endl
             << "\033[0;0m";
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                space = 49;
                if (options[i][j].first == -1)
                {
                    cout << "\033[0;37m" << choices[i][j] << "\033[0;0m";
                    space -= choices[i][j].length();
                }
                else if (options[i][j].first > 0)
                {
                    cout << "\033[47;30m" << options[i][j].first << "." << choices[i][j] << "[" << setfill('0') << setw(3) << options[i][j].second << "MI" << "]" << "\033[0;0m";
                    space -= (choices[i][j].length() + 9);
                }
                while (space--)
                    cout << " ";
            }
            cout << endl
                 << endl;
        }
        cout << endl;

        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (options[i][j].first > 0)
                {
                    cout << options[i][j].first << "." << texts[i][j] << endl
                         << endl;
                }
            }
        }

        cout << endl
             << endl
             << "\033[47;30m(Digite 0 para sair)";
        cout << "No que deseja investir? \033[0;0m";
        cin >> commands;
        if (commands != 0)
            if (!change_options())
            {
                cout << "\033[31;1;4mComando inválido ou dinheiro insuficiente\033[0m" << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
    }
    data_ready = false;
}

bool change_options()
{
    bool f = true;
    bool s = true;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (commands == options[i][j].first)
            {
                if (options[i][j].second > money)
                {
                    return false;
                }
                else
                {
                    money -= options[i][j].second;
                    rent += alt[i][j].second;
                    chance_woman += alt[i][j].first;
                    first = false;
                    last_investment.push_back({i, j});
                    rounds = 0;
                    if (alt[i][j].first > 0)
                    {
                        decrease = chance_woman;
                        chance_man = 20;
                    }
                }
                if (i != 0 && options[i - 1][j].first == 0)
                {
                    options[i - 1][j].first = options[i][j].first;
                    f = false;
                }
                if (i != 6 && options[i + 1][j].first == 0)
                {
                    if (f)
                    {
                        options[i + 1][j].first = options[i][j].first;
                        f = false;
                    }
                    else
                    {
                        e++;
                        options[i + 1][j].first = e;
                        s = false;
                    }
                }
                if (j != 0 && options[i][j - 1].first == 0)
                {
                    if (f)
                    {
                        options[i][j - 1].first = options[i][j].first;
                        f = false;
                    }
                    else if (s)
                    {
                        e++;
                        options[i][j - 1].first = e;
                        s = false;
                    }
                    else
                    {
                        e++;
                        options[i][j - 1].first = e;
                    }
                }
                if (j != 2 && options[i][j + 1].first == 0)
                {
                    if (f)
                    {
                        options[i][j + 1].first = options[i][j].first;
                    }
                    else if (s)
                    {
                        e++;
                        options[i][j + 1].first = e;
                    }
                    else
                    {
                        e++;
                        options[i][j + 1].first = e;
                    }
                }
                options[i][j].first = -1;
                return true;
            }
        }
    }
    return false;
}
