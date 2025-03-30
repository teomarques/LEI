import turtle as t
import functools
import random
import math as m
import csv
import os
from math import isclose, sqrt, atan2, cos, sin, pi

LARGURA_JANELA = 1024
ALTURA_JANELA = 600
DEFAULT_TURTLE_SIZE = 40
DEFAULT_TURTLE_SCALE = 3
RAIO_JOGADOR = DEFAULT_TURTLE_SIZE / DEFAULT_TURTLE_SCALE
RAIO_BOLA = DEFAULT_TURTLE_SIZE / 2
PIXEIS_MOVIMENTO = 30
LADO_MAIOR_AREA = ALTURA_JANELA / 3
LADO_MENOR_AREA = 50
RAIO_MEIO_CAMPO = LADO_MAIOR_AREA / 2
START_POS_BALIZAS = ALTURA_JANELA / 4
BOLA_START_POS = (5,5)


# Funções responsáveis pelo movimento dos jogadores no ambiente. 
# O número de unidades que o jogador se pode movimentar é definida pela constante 
# PIXEIS_MOVIMENTO. As funções recebem um dicionário que contém o estado 
# do jogo e o jogador que se está a movimentar. 

def jogador_cima(estado_jogo, jogador):
    estado_jogo[jogador].sety(estado_jogo[jogador].ycor() + PIXEIS_MOVIMENTO)
    if estado_jogo[jogador].ycor() > ALTURA_JANELA/2:
        estado_jogo[jogador].sety(estado_jogo[jogador].ycor() - PIXEIS_MOVIMENTO)
    guarda_posicoes_para_var(estado_jogo)

def jogador_baixo(estado_jogo, jogador):
    estado_jogo[jogador].sety(estado_jogo[jogador].ycor() - PIXEIS_MOVIMENTO)
    if estado_jogo[jogador].ycor() < - ALTURA_JANELA/2:
        estado_jogo[jogador].sety(estado_jogo[jogador].ycor() + PIXEIS_MOVIMENTO)
    guarda_posicoes_para_var(estado_jogo)
    
def jogador_direita(estado_jogo, jogador):
    estado_jogo[jogador].setx(estado_jogo[jogador].xcor() + PIXEIS_MOVIMENTO)
    if estado_jogo[jogador].xcor() > LARGURA_JANELA/2:
        estado_jogo[jogador].setx(estado_jogo[jogador].xcor() - PIXEIS_MOVIMENTO)
    guarda_posicoes_para_var(estado_jogo)

def jogador_esquerda(estado_jogo, jogador):
    estado_jogo[jogador].setx(estado_jogo[jogador].xcor() - PIXEIS_MOVIMENTO)
    if estado_jogo[jogador].xcor() < - LARGURA_JANELA/2:
        estado_jogo[jogador].setx(estado_jogo[jogador].xcor() + PIXEIS_MOVIMENTO)
    guarda_posicoes_para_var(estado_jogo)

def desenha_linhas_campo():
    # Cria o círculo central
    t.pensize(5)
    t.pu()
    t.goto(0, -RAIO_MEIO_CAMPO)
    t.pd()
    t.pencolor('white')
    t.begin_fill()
    t.circle(RAIO_MEIO_CAMPO)
    # Cria a linha meio-campo
    t.pu()
    t.goto(0, ALTURA_JANELA / 2)
    t.pd()
    t.seth(-90)
    t.fd(ALTURA_JANELA)
    # Cria as linhas das balizas
    t.seth(0)
    for i in range(-1, 2, 2):
        t.pu()
        t.goto((LARGURA_JANELA / 2)*i, (LADO_MAIOR_AREA / 2))
        t.pd()
        t.fd(LADO_MENOR_AREA)
        t.seth(-90)
        t.fd(LADO_MAIOR_AREA)
        if i == -1:
            t.right(90)
        else:
            t.left(90)
        t.fd(LADO_MENOR_AREA)
    
    ''' Função responsável por desenhar as linhas do campo, 
    nomeadamente a linha de meio campo, o círculo central, e as balizas. '''


def criar_bola():
    bola = t.Turtle()
    bola.pu()
    bola.goto(BOLA_START_POS[0], BOLA_START_POS[1])
    bola.pd()
    bola.color('black')
    bola.begin_fill()
    bola.shape('circle')
    bola.shapesize(1)
    bola.end_fill()
    bola.pu()
    '''
    Função responsável pela criação da bola. 
    Deverá considerar que esta tem uma forma redonda, é de cor preta, 
    começa na posição BOLA_START_POS com uma direção aleatória. 
    Deverá ter em conta que a velocidade da bola deverá ser superior à dos jogadores. 
    A função deverá devolver um dicionário contendo 4 elementos: o objeto bola, 
    a sua direção no eixo dos xx, a sua direção no eixo dos yy, 
    e um elemento inicialmente a None que corresponde à posição anterior da mesma.
    '''
    dirrandom = random.uniform(-1, 1)
    return {
        'objecto': bola,
        'direction_x': dirrandom,
        'direction_y': dirrandom,
        'lastx': BOLA_START_POS[0],
        'lasty': BOLA_START_POS[1],
        'posicao_anterior': None
    }


def cria_jogador(x_pos_inicial, y_pos_inicial, cor):
    jogador = t.Turtle()
    jogador.shape('circle')
    jogador.shapesize(stretch_wid=DEFAULT_TURTLE_SCALE, stretch_len=DEFAULT_TURTLE_SCALE)
    jogador.color(cor)
    jogador.pu()
    jogador.goto(x_pos_inicial, y_pos_inicial)
    
    ''' Função responsável por criar e devolver o objeto que corresponde a um jogador (um objecto Turtle). 
    A função recebe 3 argumentos que correspondem às coordenadas da posição inicial 
    em xx e yy, e a cor do jogador. A forma dos jogadores deverá ser um círculo, 
    cujo seu tamanho deverá ser definido através da função shapesize
    do módulo \texttt{turtle}, usando os seguintes parâmetros: 
    stretch_wid=DEFAULT_TURTLE_SCALE, stretch_len=DEFAULT_TURTLE_SCALE. '''
    return jogador


def init_state():
    estado_jogo = {}
    estado_jogo['bola'] = None
    estado_jogo['jogador_vermelho'] = None
    estado_jogo['jogador_azul'] = None
    estado_jogo['var'] = {
        'bola' : [],
        'jogador_vermelho' : [],
        'jogador_azul' : [],
    }
    estado_jogo['pontuacao_jogador_vermelho'] = 0
    estado_jogo['pontuacao_jogador_azul'] = 0
    return estado_jogo

def cria_janela():
    #create a window and declare a variable called window and call the screen()
    window=t.Screen()
    window.title("Foosball Game")
    window.bgcolor("green")
    window.setup(width = LARGURA_JANELA,height = ALTURA_JANELA)
    window.tracer(0)
    return window

def cria_quadro_resultados():
    #Code for creating pen for scorecard update
    quadro=t.Turtle()
    quadro.speed(0)
    quadro.color("Blue")
    quadro.penup()
    quadro.hideturtle()
    quadro.goto(0,260)
    quadro.write("FLU: 0\t\tCOR: 0 ", align="center", font=('Monaco',24,"normal"))
    return quadro


def terminar_jogo(estado_jogo):
    '''# Nome do arquivo para armazenar o histórico de resultados
    historico_filename = 'historico_resultados.csv'
    # Cabeçalho do arquivo CSV
    cabecalho = ['NJogo', 'JogadorVermelho', 'JogadorAzul']

    # Cria ou atualiza o arquivo CSV
    if not os.path.exists(historico_filename):
        estado_jogo['n_jogo'] = 1
        with open(historico_filename, 'w', newline='') as file:
            writer = csv.writer(file)
            writer.writerow(cabecalho)
            writer.writerow([estado_jogo['n_jogo'],
                             estado_jogo['pontuacao_jogador_vermelho'],
                             estado_jogo['pontuacao_jogador_azul']])
    # Adiciona uma nova linha ao arquivo CSV com os resultados do jogo atual
    with open(historico_filename, 'a', newline='') as file:
        estado_jogo['n_jogo'] += 1
        writer = csv.writer(file)
        writer.writerow([estado_jogo['n_jogo'],
                         estado_jogo['pontuacao_jogador_vermelho'],
                         estado_jogo['pontuacao_jogador_azul']])
        file.close()'''
    
    # Nome do arquivo para armazenar o histórico de resultados
    historico_filename = 'historico_resultados.csv'
    # Cabeçalho do arquivo
    cabecalho = ['NJogo', 'JogadorVermelho', 'JogadorAzul']
    
    # Se o arquivo não existir, inicializa n_jogo
    if not os.path.exists(historico_filename):
        estado_jogo['n_jogo'] = 1
        with open(historico_filename, 'w', newline='') as file:
            file.writerow(cabecalho)
            file.writerow([estado_jogo['n_jogo'],
                             estado_jogo['pontuacao_jogador_vermelho'],
                             estado_jogo['pontuacao_jogador_azul']])
    else:
        # Recupera o valor atual de n_jogo do arquivo
        with open(historico_filename, 'r') as file:
            next(file)  # Pula o cabeçalho
            ultimo_jogo = list(file)[-1]
            estado_jogo['n_jogo'] = int(ultimo_jogo[0]) + 1
            
            # Adiciona uma nova linha ao arquivo CSV com os resultados do jogo atual
            with open(historico_filename, 'a', newline='') as file:
                file.writerow([estado_jogo['n_jogo'],
                                 estado_jogo['pontuacao_jogador_vermelho'],
                                 estado_jogo['pontuacao_jogador_azul']])
                
                
    # Reinicia o estado do jogo
    estado_jogo['pontuacao_jogador_vermelho'] = 0
    estado_jogo['pontuacao_jogador_azul'] = 0

    '''
     Função responsável por terminar o jogo. Nesta função, deverá atualizar o ficheiro 
     ''historico_resultados.csv'' com o número total de jogos até ao momento, 
     e o resultado final do jogo. Caso o ficheiro não exista, 
     ele deverá ser criado com o seguinte cabeçalho: 
     NJogo,JogadorVermelho,JogadorAzul.
    '''
    print("Adeus")
    estado_jogo['janela'].bye()

def setup(estado_jogo, jogar):
    janela = cria_janela()
    #Assign keys to play
    janela.listen()
    if jogar:
        janela.onkeypress(functools.partial(jogador_cima, estado_jogo, 'jogador_vermelho') ,'w')
        janela.onkeypress(functools.partial(jogador_baixo, estado_jogo, 'jogador_vermelho') ,'s')
        janela.onkeypress(functools.partial(jogador_esquerda, estado_jogo, 'jogador_vermelho') ,'a')
        janela.onkeypress(functools.partial(jogador_direita, estado_jogo, 'jogador_vermelho') ,'d')
        janela.onkeypress(functools.partial(jogador_cima, estado_jogo, 'jogador_azul') ,'Up')
        janela.onkeypress(functools.partial(jogador_baixo, estado_jogo, 'jogador_azul') ,'Down')
        janela.onkeypress(functools.partial(jogador_esquerda, estado_jogo, 'jogador_azul') ,'Left')
        janela.onkeypress(functools.partial(jogador_direita, estado_jogo, 'jogador_azul') ,'Right')
        janela.onkeypress(functools.partial(terminar_jogo, estado_jogo) ,'Escape')
        quadro = cria_quadro_resultados()
        estado_jogo['quadro'] = quadro
    desenha_linhas_campo()
    bola = criar_bola()
    jogador_vermelho = cria_jogador(-((ALTURA_JANELA / 2) + LADO_MENOR_AREA), 0, "red")
    jogador_azul = cria_jogador(((ALTURA_JANELA / 2) + LADO_MENOR_AREA), 0, "black")
    estado_jogo['janela'] = janela
    estado_jogo['bola'] = bola
    estado_jogo['jogador_vermelho'] = jogador_vermelho
    estado_jogo['jogador_azul'] = jogador_azul


def update_board(estado_jogo):
    estado_jogo['quadro'].clear()
    estado_jogo['quadro'].write("FLU: {}\t\tCOR: {} ".format(estado_jogo['pontuacao_jogador_vermelho'], estado_jogo['pontuacao_jogador_azul']),align="center",font=('Monaco',24,"normal"))

def movimenta_bola(estado_jogo):
    bola = estado_jogo['bola']
    
    # Se a bola não foi inicializada, inicialize-a com uma direção aleatória.
    if bola is None:
        estado_jogo['bola'] = criar_bola()
        estado_jogo['bola']['direction_x'] = random.uniform(5, 10)
        estado_jogo['bola']['direction_y'] = random.uniform(5, 10)
        estado_jogo['bola']['lastx'] = BOLA_START_POS[0]
        estado_jogo['bola']['lasty'] = BOLA_START_POS[1]
        return

    # Mova a bola em incrementos de pixels
    estado_jogo['bola']['objecto'].goto(estado_jogo['bola']['objecto'].xcor() + estado_jogo['bola']['direction_x'], estado_jogo['bola']['objecto'].ycor() + estado_jogo['bola']['direction_y'])

    # Atualize as posições anteriores da bola
    estado_jogo['bola']['lastx'] = estado_jogo['bola']['objecto'].xcor()
    estado_jogo['bola']['lasty'] = estado_jogo['bola']['objecto'].ycor()

    # Atualize o estado para o VAR
    guarda_posicoes_para_var(estado_jogo)

    # Atualize a tela
    estado_jogo['janela'].update()
    
    
    '''
    Função responsável pelo movimento da bola que deverá ser feito tendo em conta a
    posição atual da bola e a direção em xx e yy.
    '''

def verifica_colisoes_ambiente(estado_jogo):
    bola = estado_jogo['bola']['objecto']
    
    # Verifica colisão com os limites em x
    if bola.xcor() > LARGURA_JANELA / 2 - RAIO_BOLA or bola.xcor() < -LARGURA_JANELA / 2 + RAIO_BOLA:
        estado_jogo['bola']['direction_x'] = - estado_jogo['bola']['direction_x']
    
    # Verifica colisão com os limites em y
    if bola.ycor() > ALTURA_JANELA / 2 - RAIO_BOLA or bola.ycor() < -ALTURA_JANELA / 2 + RAIO_BOLA:
        estado_jogo['bola']['direction_y'] = - estado_jogo['bola']['direction_y']
    
    '''
    Função responsável por verificar se há colisões com os limites do ambiente, 
    atualizando a direção da bola. Não se esqueça de considerar que nas laterais, 
    fora da zona das balizas, a bola deverá inverter a direção onde atingiu o limite.
    '''


def verifica_golo_jogador_vermelho(estado_jogo):
    bola = estado_jogo['bola']['objecto']

    if bola.xcor() >= LARGURA_JANELA / 2 - LADO_MENOR_AREA and -LADO_MAIOR_AREA / 2 < bola.ycor() < LADO_MAIOR_AREA / 2:
        # Cria arquivo de replay
        linhas = []

        for key in ['bola', 'jogador_vermelho', 'jogador_azul']:
            linha = ';'.join(["{:.3f},{:.3f}".format(coord[0], coord[1]) for coord in estado_jogo['var'][key][-50:]])  # Limita a 50 últimas posições
            linhas.append(linha)

        replay_filename = 'replay_golojv{}ja{}.txt'.format(estado_jogo['pontuacao_jogador_vermelho'], estado_jogo['pontuacao_jogador_azul'])
        
        with open(replay_filename, 'a') as file:
            file.write('\n'.join(linhas) + '\n')

        # Atualiza o estado do jogo para o inicial
        estado_jogo['pontuacao_jogador_vermelho'] += 1
        update_board(estado_jogo)

        # Volta a bola ao centro
        estado_jogo['bola']['objecto'].goto(BOLA_START_POS[0], BOLA_START_POS[1])
        estado_jogo['bola']['direction_x'] = random.uniform(-1, 1)
        estado_jogo['bola']['direction_y'] = random.uniform(-1, 1)
        
    
    '''
    Função responsável por verificar se um determinado jogador marcou golo. 
    Para fazer esta verificação poderá fazer uso das constantes: 
    LADO_MAIOR_AREA e 
    START_POS_BALIZAS. 
    Note que sempre que há um golo, deverá atualizar a pontuação do jogador, 
    criar um ficheiro que permita fazer a análise da jogada pelo VAR, 
    e reiniciar o jogo com a bola ao centro. 
    O ficheiro para o VAR deverá conter todas as informações necessárias 
    para repetir a jogada, usando as informações disponíveis no objeto 
    estado_jogo['var']. O ficheiro deverá ter o nome 
    
    replay_golo_jv_[TotalGolosJogadorVermelho]ja[TotalGolosJogadorAzul].txt 
    
    onde [TotalGolosJogadorVermelho], [TotalGolosJogadorAzul] 
    deverão ser substituídos pelo número de golos marcados pelo jogador vermelho 
    e azul, respectivamente. Este ficheiro deverá conter 3 linhas, estruturadas 
    da seguinte forma:
    Linha 1 - coordenadas da bola;
    Linha 2 - coordenadas do jogador vermelho;
    Linha 3 - coordenadas do jogador azul;
    
    Em cada linha, os valores de xx e yy das coordenadas são separados por uma 
    ',', e cada coordenada é separada por um ';'.
    '''

def verifica_golo_jogador_azul(estado_jogo):
    
    bola = estado_jogo['bola']['objecto']

    if bola.xcor() <= -LARGURA_JANELA / 2 + LADO_MENOR_AREA and -LADO_MAIOR_AREA/2 < bola.ycor() < LADO_MAIOR_AREA/2:
        # Cria arquivo de replay
        linhas = []

        for key in ['bola', 'jogador_vermelho', 'jogador_azul']:
            linha = ';'.join(["{:.3f},{:.3f}".format(coord[0], coord[1]) for coord in estado_jogo['var'][key][-50:]])  # Limita a 50 últimas posições
            linhas.append(linha)

        replay_filename = 'replay_golojv{}ja{}.txt'.format(estado_jogo['pontuacao_jogador_vermelho'], estado_jogo['pontuacao_jogador_azul'])
        
        with open(replay_filename, 'w') as file:
            file.write('\n'.join(linhas) + '\n')

        # Atualiza o estado do jogo para o inicial
        estado_jogo['pontuacao_jogador_azul'] += 1
        update_board(estado_jogo)

        # Volta a bola ao centro
        estado_jogo['bola']['objecto'].goto(BOLA_START_POS[0], BOLA_START_POS[1])
        estado_jogo['bola']['direction_x'] = random.uniform(-1, 1)
        estado_jogo['bola']['direction_y'] = random.uniform(-1, 1)
        
def formatar(nome):
    count = 1
    string = ""
    for i in str(nome):
        if i == "[" or i == "]" or i :
            string += ""
        elif i == ",":
            if count % 2 != 0:
                string.replace(i, ";")
            count += 1
        else:
            string += i
            
    '''
    Função responsável por verificar se um determinado jogador marcou golo. 
    Para fazer esta verificação poderá fazer uso das constantes: 
    LADO_MAIOR_AREA e 
    START_POS_BALIZAS. 
    Note que sempre que há um golo, deverá atualizar a pontuação do jogador, 
    criar um ficheiro que permita fazer a análise da jogada pelo VAR, 
    e reiniciar o jogo com a bola ao centro. 
    O ficheiro para o VAR deverá conter todas as informações necessárias 
    para repetir a jogada, usando as informações disponíveis no objeto 
    estado_jogo['var']. O ficheiro deverá ter o nome 
    
    replay_golo_jv_[TotalGolosJogadorVermelho]ja[TotalGolosJogadorAzul].txt 
    
    onde [TotalGolosJogadorVermelho], [TotalGolosJogadorAzul] 
    deverão ser substituídos pelo número de golos marcados pelo jogador vermelho 
    e azul, respectivamente. Este ficheiro deverá conter 3 linhas, estruturadas 
    da seguinte forma:
    Linha 1 - coordenadas da bola;
    Linha 2 - coordenadas do jogador vermelho;
    Linha 3 - coordenadas do jogador azul;
    
    Em cada linha, os valores de xx e yy das coordenadas são separados por uma 
    ',', e cada coordenada é separada por um ';'.
    '''

def verifica_golos(estado_jogo):
    verifica_golo_jogador_vermelho(estado_jogo)
    verifica_golo_jogador_azul(estado_jogo)

def verifica_toque_jogador_azul(estado_jogo):
    bola = estado_jogo['bola']['objecto']
    jogador_azul = estado_jogo['jogador_azul']
    
    # Verifica a colisão através da distância entre a bola e o jogador (módulo)
    distancia = sqrt((jogador_azul.xcor() - bola.xcor())**2 + (jogador_azul.ycor() - bola.ycor())**2)
    if distancia <= (RAIO_BOLA + RAIO_JOGADOR):
        # Calcula o vetor normal à superfície do jogador no ponto de colisão
        normal_x = bola.xcor() - jogador_azul.xcor()
        normal_y = bola.ycor() - jogador_azul.ycor()
    
        # Normaliza o vetor normal
        normal_len = sqrt(normal_x**2 + normal_y**2)
        normal_x /= normal_len
        normal_y /= normal_len
    
        # Calcula o vetor de reflexão usando a fórmula da reflexão vetorial
        incidente_x = estado_jogo['bola']['direction_x']
        incidente_y = estado_jogo['bola']['direction_y']
        produto_vetorial = incidente_x * normal_x + incidente_y * normal_y
        refletido_x = incidente_x - 2 * produto_vetorial * normal_x
        refletido_y = incidente_y - 2 * produto_vetorial * normal_y
    
        # Atualiza a direção da bola com o vetor de reflexão
        estado_jogo['bola']['direction_x'] = refletido_x
        estado_jogo['bola']['direction_y'] = refletido_y 
    
    '''
    Função responsável por verificar se o jogador tocou na bola. 
    Sempre que um jogador toca na bola, deverá mudar a direção desta.
    '''

def verifica_toque_jogador_vermelho(estado_jogo):
    bola = estado_jogo['bola']['objecto']
    jogador_vermelho = estado_jogo['jogador_vermelho']
    # Verifica a colisão através da distância entre a bola e o jogador (módulo)
    '''distancia = sqrt((jogador_vermelho.xcor() - bola.xcor())**2 + (jogador_vermelho.ycor() - bola.ycor())**2)
    ang = atan2(jogador_vermelho.ycor()-bola.ycor(), jogador_vermelho.xcor()-bola.xcor())
    if distancia <= (RAIO_BOLA + RAIO_JOGADOR):
        v = 0
        while v < 4:
            if abs(estado_jogo['bola']['direction_x']) < abs(estado_jogo['bola']['direction_y']):
                n = -1
            else:
                n = 1
            X_de_incidencia = bola.xcor() 
            Y_de_incidencia = bola.ycor()
            cos_vetor_refletido = m.sin(ang)
            sin_vetor_refletido = m.cos(ang)
            estado_jogo['bola']['direction_x'] = n * cos_vetor_refletido
            estado_jogo['bola']['direction_y'] = -n * sin_vetor_refletido
            v += 1'''      
    
    # Verifica a colisão através da distância entre a bola e o jogador (módulo)
    distancia = sqrt((jogador_vermelho.xcor() - bola.xcor())**2 + (jogador_vermelho.ycor() - bola.ycor())**2)
    if distancia <= (RAIO_BOLA + RAIO_JOGADOR):
        # Calcula o vetor normal à superfície do jogador no ponto de colisão
        normal_x = bola.xcor() - jogador_vermelho.xcor()
        normal_y = bola.ycor() - jogador_vermelho.ycor()

        # Normaliza o vetor normal
        normal_len = sqrt(normal_x**2 + normal_y**2)
        normal_x /= normal_len
        normal_y /= normal_len

        # Calcula o vetor de reflexão usando a fórmula da reflexão vetorial
        incidente_x = estado_jogo['bola']['direction_x']
        incidente_y = estado_jogo['bola']['direction_y']
        produto_vetorial = incidente_x * normal_x + incidente_y * normal_y
        refletido_x = incidente_x - 2 * produto_vetorial * normal_x
        refletido_y = incidente_y - 2 * produto_vetorial * normal_y

        # Atualiza a direção da bola com o vetor de reflexão
        estado_jogo['bola']['direction_x'] = refletido_x
        estado_jogo['bola']['direction_y'] = refletido_y
    
    '''
    Função responsável por verificar se o jogador tocou na bola. 
    Sempre que um jogador toca na bola, deverá mudar a direção desta.
    '''

def guarda_posicoes_para_var(estado_jogo):
    estado_jogo['var']['bola'].append(estado_jogo['bola']['objecto'].pos())
    estado_jogo['var']['jogador_vermelho'].append(estado_jogo['jogador_vermelho'].pos())
    estado_jogo['var']['jogador_azul'].append(estado_jogo['jogador_azul'].pos())


def main():
    estado_jogo = init_state()
    setup(estado_jogo, True)
    estado_jogo['TotalGolosJogadorVermelho'] = 0
    estado_jogo['TotalGolosJogadorAzul'] = 0
    print(estado_jogo)
    while True:
        estado_jogo['janela'].update()
        if estado_jogo['bola'] is not None:
            movimenta_bola(estado_jogo)
        verifica_colisoes_ambiente(estado_jogo)
        verifica_golos(estado_jogo)
        if estado_jogo['jogador_vermelho'] is not None:
            verifica_toque_jogador_azul(estado_jogo)
        if estado_jogo['jogador_azul'] is not None:
            verifica_toque_jogador_vermelho(estado_jogo)
        guarda_posicoes_para_var(estado_jogo)

if __name__ == '__main__':
    main()