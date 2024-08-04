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
string first_new = "Atualmente, no Brasil, os estudantes de areas tecnologicas sao, em sua maioria, homens,\n como apresentado na pesquisa do IBGE, apenas 13,3%% dos estudantes de Computacao e TIC\n(Tecnologia da Informacao e Comunicacoes) sao mulheres.Essa situacao esta gerando indig\ninacao na populacao e afetando negativamente a economia.\n\nA grande questao eh:sera que o governo vai fazer algo para mudar isso?";

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
    {{0, 300}, {0, 500}, {0, 50}}};

pair<int, int> alt[7][3] = {
    {{3, 5}, {3, 2}, {-3, 2}},
    {{-4, 3}, {3, 2}, {2, 6}},
    {{-7, -20}, {2, 4}, {-4, 0}},
    {{2, 4}, {2, 8}, {-6, -5}},
    {{-7, -8}, {3, 4}, {-13, -20}},
    {{-4, -8}, {2, 8}, {-10, 2}},
    {{5, 6}, {7, 20}, {-8, 20}}};

string texts[7][3] = {
    {"Investir em projetos de incentivo e na educacao de mulheres nas areas cientificas,visando aumentar a diversidade de genero nessas areas.", "Criar jogos educativos nas areas de exatas que atraiam o publico feminino, estimulando a participacao das mulheres nestas areas.", "Investir no petroleo para aproveitar esta riqueza natural e no preh-sal para aumentar os lucros do Brasil."}, //  Texto 1
    {"Investir na agropecuaria nacional, fortalecendo a economia local.", "Criar grupos de apoio para mulheres das areas de exatas para que possam se sentir apoiadas.", "Criar campanhas e palestras demonstrando que, independente do genero, todos tem a mesma capacidade."},                                                                                                                    //  Texto 2
    {"Incentivar o tradicionalismo, pois os homens devem trabalhar e as mulheres devem ficar em casa cuidando dos filhos.", "Criar leis que garantam a participacao de mulheres na politica, evitando que esta area permaneca predominada por homens.", "Investir em um exehrcito so de homens, pois eles sao mais fortes e assim, melhorar a forca do Brasil em guerras."},                        // Texto 3
    {"Criar grupos de maratona de programacao feminina para as incentivar a participar de eventos de programacao.", "Divulgar na internet e na televisao todos os grandes feitos das mulheres nas areas de exatas, inspirando, assim, outras mulheres.", "Criar leis para fortalecer o patriarcado."},                                                                                              // Texto4
    {"Unificar os esportes masculinos e femininos, pois, como homens e mulheres sao iguais, nao faz sentido ter times separados.", "Criar leis que garantam ambientes agradaveis para mulheres, pois muitos deles sao hostis para elas, afastando-as do ambiente de trabalho.", "Incentivar a criacao de empresas so para homens, pois, se nao houver mulheres na empresa, nao havera machismo."},  // Texto5
    {"Incentivar a homogeneidade de genero nas diversas areas da sociedade, para que haja uma divisao sexual de trabalho.", "Criar leis que garantam a seguranca das mulheres em todas areas.", "Proibir a licenca maternidade, pois isso eh prejudicial para a economia."},                                                                                                                        // Texto 6
    {"Garantir as mulheres seguranca de renda e trabalho no periodo apos a gravidez, incentivando-as a retornar ao ambiente de trabalho.", "Garantir a igualdade salarial para homens e mulheres.", "Investir nas industrias visando a melhorar a economia e independencia economica do Brasil."},                                                                                                  // Texto7
};

string news[7][3] = {
    {"O maior investimento do governo para que mulheres participem de areas cientificas incentivou "
     "milhares de jovens a seguir carreiras em STEM. A iniciativa da Corporacao TecNova, em parcer"
     "ia com universidades renomadas, resultou em um aumento de 30% na participacao feminina nesse "
     "curso. Economistas apontam que a inclusao de mais mulheres na ciencia pode gerar um impacto "
     "positivo no PIB, com projecoes de crescimento de 2% nos proximos cinco anos. Alem disso, "
     "a iniciativa tambem esta promovendo a criacao de programas de mentoria para mulheres cientis"
     "tas, visando apoiar o desenvolvimento de suas carreiras e aumentar a representatividade femi"
     "nina nas areas cientificas.",

     "Desenvolvedores de jogos, como a startup GameHer, estao criando titulos que atendem aos "
     "interesses das mulheres, aumentando a participacao feminina no mercado de jogos. A CEO da "
     "GameHer, Julia Lopes, afirmou que essa mudanca esta promovendo um ambiente mais inclusivo e "
     "diversificado. A empresa relatou um aumento de 50% em suas vendas, demonstrando o impacto "
     "positivo dessa estrategia. Alem disso, a GameHer tambem esta investindo em programas de "
     "capacitacao para mulheres interessadas em desenvolver jogos, visando incentivar a participacao "
     "feminina na industria de games.",

     "A descoberta de novos campos de petroleo pela PetroNacional esta fortalecendo a economia. "
     "Especialistas alertam, porem, para os impactos ambientais. A ONG VerdeLimpo destacou que e "
     "essencial balancear o desenvolvimento economico com a sustentabilidade. No cenario global, a "
     "descoberta coloca o pais entre os principais exportadores de petroleo, mas tambem aumenta as "
     "responsabilidades ambientais e revela um lado sombrio: o aumento do machismo na industria do "
     "petroleo. Relatos de discriminacao e assedio tem surgido, evidenciando a necessidade de combater essa questao."},

    {"A agropecuaria nacional esta se expandindo gracas as inovacoes tecnologicas implementadas pela "
     "AgroTech Brasil. A empresa, em colaboracao com o Ministerio da Agricultura, promove praticas "
     "sustentaveis que estao revolucionando o setor. A producao aumentou em 20%, e o impacto positivo "
     "ja e visivel na balanca comercial do pais. No entanto, desafios ambientais ainda persistem. Alem "
     "disso, a AgroTech Brasil esta investindo em programas de capacitacao para mulheres agricultoras, "
     "visando promover a participacao feminina no setor agropecuario e garantir a igualdade de "
     "oportunidades.",

     "Grupos de apoio feminino, como o RedeMulher, estao ajudando mulheres a superarem desafios e "
     "alcancarem seus objetivos. O projeto MulheresEmpreendedoras, da Fundacao Aurora, oferece "
     "mentorias e financiamento para startups lideradas por mulheres, resultando na criacao de "
     "milhares de novos negocios. Esse movimento esta criando uma rede de suporte vital e empoderando "
     "mulheres em todo o pais. Alem disso, o RedeMulher tambem esta promovendo a realizacao de "
     "workshops e cursos de capacitacao para mulheres empreendedoras, visando fortalecer suas "
     "habilidades e promover o crescimento de seus negocios.",

     "Campanhas nacionais contra o preconceito, lideradas pelo Instituto IgualdadeJa, estao "
     "promovendo uma sociedade mais justa. A campanha 'Respeito por Todos', lancada pelo governo, "
     "resultou em um aumento significativo na conscientizacao e no respeito aos direitos das mulheres. "
     "Pesquisas mostram que essas iniciativas estao reduzindo incidentes de discriminacao e promovendo "
     "maior igualdade. Alem disso, o Instituto IgualdadeJa esta desenvolvendo programas de educacao "
     "e conscientizacao sobre igualdade de genero, visando combater o preconceito e promover a "
     "tolerancia na sociedade."},

    {"Movimentos tradicionalistas, como o BrasilTradicao, estao promovendo valores conservadores e "
     "modos de vida tradicionais. Enquanto ganham apoio em algumas regioes, criticos alertam para o "
     "potencial retrocesso na igualdade de genero. Organizacoes de direitos humanos, como a NovoTempo, "
     "sublinhando a importancia de balancear tradicoes com progresso social e inclusao de genero. Alem "
     "disso, a NovoTempo esta promovendo debates e dialogos entre diferentes grupos sociais, visando "
     "fomentar",

     "Mais mulheres estao sendo eleitas para cargos politicos, trazendo perspectivas diversas e "
     "importantes para a legislacao. A iniciativa Mulheres no Poder, apoiada pela ONG Politica para "
     "Todos, esta treinando futuras lideres. Esse aumento na representacao feminina esta contribuindo "
     "para politicas publicas mais inclusivas e equitativas, sendo um modelo para outros paises da "
     "regiao. Alem disso, a ONG Politica para Todos esta promovendo a realizacao de workshops e "
     "cursos de capacitacao politica para mulheres interessadas em ingressar na vida publica, visando "
     "fortalecer sua participacao e influencia.",

     "O governo esta aumentando o investimento nas forcas armadas com o projeto Defesa Forte, "
     "fortalecendo a defesa nacional. No entanto, criticos apontam que esses recursos poderiam ser "
     "melhor empregados em areas sociais. A organizacao Paz e Progresso sugere um balanco entre "
     "investimento militar e desenvolvimento social para garantir um crescimento sustentavel. Alem "
     "disso, a Paz e Progresso esta promovendo debates e discussoes sobre a destinacao dos recursos "
     "publicos, visando encontrar um equilibrio entre as necessidades de defesa e as demandas sociais."},

    {"Grupos de maratona femininos de programacao, como o CodeGirls, estao incentivando a participacao de mulheres "
     "em eventos de programacao. Essas iniciativas promovem o desenvolvimento de habilidades tehcnicas e "
     "aumentam a visibilidade feminina na area de programacao. Eventos como a Maratona da Igualdade de Programacao estao atraindo "
     "milhares de participantes e destacando a importancia da inclusao das mulheres na industria de tecnologia. Alem disso, o "
     "CodeGirls esta promovendo a realizacao de treinamentos e workshops para mulheres interessadas "
     "em participar de maratonas de programacao, visando prepara-las e encoraja-las a superar desafios.",

     "Campanhas estao destacando as conquistas de mulheres em areas de ciencias exatas, inspirando "
     "futuras geracoes. O projeto Mulheres de Ciencia, da Fundacao Futuro, divulgou historias de "
     "sucesso que estao ajudando a quebrar estereotipos de genero. Essas iniciativas estao encorajando "
     "mais meninas a seguir carreiras cientificas e promovendo um ambiente mais inclusivo nas "
     "universidades e empresas. Alem disso, a Fundacao Futuro esta promovendo a realizacao de "
     "palestras e workshops sobre carreiras cientificas para estudantes do ensino mehdio, visando "
     "despertar o interesse das jovens pela ciencia. ",

     "Sistemas patriarcais ainda prevalecem em muitas areas, dificultando o progresso para a igualdade "
     "de genero. Ativistas da Alianca por Igualdade estao trabalhando para desmantelar essas "
     "estruturas e promover uma sociedade mais justa. Campanhas como 'Igualdade Agora' estao ganhando "
     "apoio e destacando a necessidade de mudancas sistemicas para alcancar a verdadeira equidade de "
     "genero. Alem disso, a Alianca por Igualdade esta promovendo a realizacao de debates e "
     "conferencias sobre igualdade de genero, visando conscientizar a sociedade e impulsionar a "
     "mudanca."},

    {"Iniciativas para esportes sem distincao de genero, como o Esporte para Todos, estao ganhando "
     "apoio, promovendo igualdade e inclusao. A Confederacao Esportiva Nacional lancou uma campanha "
     "para garantir que todos, independentemente de genero, tenham acesso igualitario a recursos "
     "esportivos. Essas mudancas estao criando um ambiente esportivo mais justo e acessivel para "
     "todos. Alem disso, o Esporte para Todos esta promovendo a realizacao de eventos esportivos "
     "inclusivos, nos quais homens e mulheres competem juntos, visando promover a igualdade de "
     "oportunidades.",

     "Empresas estao se esforcando para criar ambientes de trabalho mais agradaveis, aumentando a "
     "satisfacao e produtividade dos funcionarios. A Corporacao Ambience lidera o movimento com "
     "iniciativas que incluem horarios flexiveis e espacos de trabalho colaborativos. No entanto, eh "
     "crucial garantir que essas melhorias beneficiem igualmente todos os generos para promover uma "
     "verdadeira inclusao. Alem disso, a Corporacao Ambience esta implementando programas de "
     "diversidade e inclusao, visando garantir a igualdade de oportunidades para todos os funcionarios. ",

     "Empresas exclusivamente masculinas estao sendo criticadas por falta de diversidade e inclusao. "
     "Estudos conduzidos pela Universidade Global mostram que a diversidade de genero nas empresas "
     "leva a melhores resultados e maior inovacao. A campanha Diversidade Ja, liderada pelo Instituto "
     "Progresso, esta pressionando por mudancas significativas no setor empresarial. Alem disso, o "
     "Instituto Progresso esta promovendo a realizacao de pesquisas e estudos sobre diversidade de "
     "genero nas empresas, visando conscientizar o mercado sobre os beneficios da inclusao."},

    {"Politicas que evitam a diversidade de genero estao enfrentando forte oposicao por limitar o "
     "progresso e a inclusao. Organizacoes como a Diversidade Global estao destacando a importancia da "
     "diversidade para a inovacao e o sucesso sustentavel. Empresas que promovem a inclusao, como a "
     "Tech4All, estao se tornando modelos de sucesso no mercado internacional. Alem disso, a "
     "Diversidade Global esta promovendo a realizacao de conferencias e eventos sobre diversidade de "
     "genero, visando disseminar boas praticas e inspirar outras empresas a adotarem politicas de "
     "inclusao.",

     "Medidas de seguranca reforcadas para mulheres estao sendo implementadas em areas urbanas e "
     "rurais. O programa Cidade Segura, uma colaboracao entre o governo e a ONG Protecao para Todos,"
     "visa reduzir a violencia e o assehdio. Essas acoes estao criando ambientes mais seguros e "
     "confiaveis para as mulheres em espacos publicos e no trabalho. Alem disso, o programa Cidade "
     "Segura esta promovendo a realizacao de campanhas de conscientizacao e treinamentos de autodefesa "
     "para mulheres, visando empodera-las e garantir sua seguranca.",

     "Propostas para reduzir a licenca maternidade estao sendo debatidas, gerando preocupacao entre "
     "grupos de direitos das mulheres. O Instituto Maternidade Justa argumenta que uma licenca "
     "adequada eh essencial para o bem-estar das maes e filhos. A discussao esta atraindo atencao"
     "internacional e destaca a importancia de politicas de apoio as familias. Alem disso, o Instituto"
     "Maternidade Justa esta promovendo a realizacao de debates e foruns de discussao sobre a"
     "licenca maternidade, visando conscientizar a sociedade sobre a importancia desse direito."},

    {"Palestras em escolas sobre igualdade de genero, como parte do programa Educacao para Todos,"
     "estao ajudando a educar jovens sobre respeito e direitos das mulheres. Essas iniciativas, lideradas "
     "pela ONG Educacao Igualitaria, estao promovendo uma cultura de igualdade e inclusao desde cedo, "
     "preparando as futuras geracoes para um mundo mais justo. Alem disso, a ONG Educacao Igualitaria "
     "esta desenvolvendo materiais educativos e programas de conscientizacao sobre igualdade de genero,"
     "visando disseminar conhecimento e promover a mudanca.",

     "Esforcos para alcancar a igualdade salarial estao ganhando momentum, com mais empresas adotando "
     "praticas justas de remuneracao. A campanha Salario Justo, apoiada pela Federacao Nacional de"
     "Trabalhadores, esta promovendo transparencia salarial e praticas equitativas. Essas mudancas"
     "estao ajudando a reduzir a disparidade de genero e promover uma economia mais equitativa. Alem "
     "disso, a Federacao Nacional de Trabalhadores esta promovendo a realizacao de pesquisas e"
     "estudos sobre a igualdade salarial, visando conscientizar a sociedade e pressionar por mudancas.",

     "O setor industrial esta se expandindo, trazendo oportunidades de emprego e crescimento "
     "economico. A iniciativa Industria para Todos, liderada pela Associacao Industrial Brasileira,"
     "visa garantir que essas oportunidades sejam acessiveis igualmente a homens e mulheres. Essa "
     "abordagem inclusiva esta sendo vista como um modelo para o desenvolvimento sustentavel no"
     "mercado global. Alem disso, a Associacao Industrial Brasileira esta promovendo a realizacao de "
     "programas de capacitacao e treinamento para mulheres interessadas em ingressar na industria,"
     "visando promover a igualdade de oportunidades e fortalecer o setor industrial."}};

string choices[7][3] = {
    {"Mulheres na ciencia", "Jogos atrativos para mulheres", "Petroleo nacional"},
    {"Agropecuaria nacional", "Grupos de apoio femininos", "Combate ao preconceito contra mulheres"},
    {"Tradicionalismo", "Mulheres na politica", "Investir no exercito"},
    {"Grupos de programacao femininos", "Divulgar feitos das mulheres em exatas", "Patriarcado"},
    {"Esportes sem distincao de genero", "Ambientes inclusivos", "Empresas exclusivamente de homens"},
    {"Evitar a diversidade de genero", "Garantia de seguranca para mulheres", "Tirar licensa maternidade"},
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
void show_news();

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
    cout << "\033[H\033[J\033[30m\033[47mSeu objetivo nesse jogo eh conseguir a mesma quantidade(ou aproximada) de homens e mulheres nas areas de exatas.\nVoce, como presidente do Brasil, deve fazer os melhores investimentos para que isso ocorra. Boa sorte!\n\nAlterne entre o mapa e a tela de investimentos para vizualizar o mapa referente á quantidade\nde mulheres nas áreas de exatas. A cada 4 segundos o seu dinheiro aumenta o equivalente a sua renda.\nInvista o seu dinheiro visando a diversidade de genero e igualdade social/economica\n\n*Não há acentos em muitas partes do jogo por causa do erro deles em certas funções*\n*Faça boas escolhas que são inclusivas para ganhar o jogo*\n*Leia as notícias atentamente, elas são muito importantes e demonstram como sua escolha impactou o país*\n\n\033[0;0m\033[30m\033[47mDigite 0 para continuar: \033[0;0m";
    while (commands != 0)
    {
        cin >> commands;
        if (cin.fail())
        {
            cin.clear();                                              // Limpa o estado de erro de cin
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); // Ignora a entrada invalida
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
        cout << "\033[H\033[J\033[42;97mParabehns!\nVoce conseguiu atingir a igualdade de genero nas areas de exatas e contribuiu para um Brasil mais diverso e justo." << endl;
        this_thread::sleep_for(chrono::seconds(5));
    }
    else
    {
        cout << "\033[H\033[J\033[31;1;4mGAME OVER\nVoce tomou decisoes que nao colaboraram com a diversidade de genero e, por isso, o Brasil virou um pais dominado por homens. Pehssimo da sua parte!\033[0;0m" << endl;
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
                    cout << "\033[30m\033[47mMapa do Brasil referente a quantidade de homens e mulheres nas areas de exatas:\033[0;0m" << endl
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
                    cout << "Mulheres nas areas de exatas: " << percent << "%" << endl;
                    cout << "Dinheiro disponivel: " << money << "MI" << endl;
                    cout << "Renda: " << rent << "MI" << endl
                         << endl;

                    if (first)
                    {
                        cout << "\033[30m\033[47MNOTÍCIA:\033[0;0m" << endl
                             << endl;
                        cout << "\033[30m\033[47m" << first_new << "\033[0;0m" << endl
                             << endl;
                    }
                    cout << "Digite 1 para ver a tela de investimento" << endl;
                    // wait 5 seconds
                    this_thread::sleep_for(chrono::seconds(4));
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
        cout << "\033[42;97m" << "Dinheiro disponivel: " << money << "MI" << endl
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
        cout << "\033[47mEXPLICAÇÕES:\033[0;0m" << endl
             << endl;

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
             << "\033[47;30m(Digite 0 para voltar" << endl;
        cout << "No que deseja investir? \033[0;0m";
        cin >> commands;
        if (commands != 0)
            if (!change_options())
            {
                cout << "\033[31;1;4mComando inválido ou dinheiro insuficiente\033[0m" << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
    }
    if (!first)
        show_news();
}

// function to change the matrix of options
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

// function to show the news
void show_news()
{
    while (last_investment.size() != 0)
    {
        cout << "\033[H\033[J";
        cout << "\033[30m\033[43mLEIA A ÚLTIMA NOTÍCIA DO MOMENTO:\033[0;0m" << endl
             << endl;
        cout << "\033[30m\033[47m";
        for (int c = 0; c < news[last_investment.back().first][last_investment.back().second].size(); c++)
        {
            if (c % 100 == 0)
                cout << endl;
            cout << news[last_investment.back().first][last_investment.back().second][c];
        }

        cout
            << "\033[0;0m" << endl
            << endl
            << "Leia a notícia e espere um pouco" << endl;
        // show another new

        this_thread::sleep_for(chrono::seconds(10));
        cout << endl
             << endl
             << "Aperte 0 para continuar: " << endl;
        commands = 1;
        while (commands != 0)
        {
            cin >> commands;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada invalida. Por favor, digite um numero." << endl;
                commands = -1;
            }
        }
        last_investment.pop_back();
    }
    data_ready = false;
}
