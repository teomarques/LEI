import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# 1 -------------------------------------------------------------------------------------------------------
# a)
path = '/home/teomarques/Desktop/UC/TI2/TP1/CarDataset.xlsx'
data = pd.read_excel(path)

# b)
matriz_valores = data.values

# c)
lista_variaveis = data.columns.values.tolist()


# 2
# Extrair a coluna MPG
mpg = data['MPG']

# Criar uma figura para os gráficos
plt.figure(figsize=(6, 5))

# Criar gráficos de dispersão de MPG em função das outras variáveis
for i, var in enumerate(lista_variaveis[:6], 1):  # Ignorar a última variável, que é MPG
    plt.subplot(3, 2, i)  # Organizar os gráficos em uma matriz 3x2
    plt.scatter(data[var], mpg, color = 'lightgreen', s=5) # Desenha cada bolinha
    plt.title(f'MPG vs {var}')
    plt.xlabel(var) 
    plt.ylabel('MPG')

# Mostrar todos os gráficos numa única janela
plt.tight_layout()
plt.show()


# 3

# a) 
# Converter os dados para o tipo uint16
dados_uint16 = data.astype('uint16')

# b) 
# Definir o alfabeto com base nos valores únicos de cada variável.
alfabeto = np.arange(0, 65535, dtype = np.uint16)


# 4
# Função para contar as ocorrências de cada símbolo em cada variável
def contar_ocorrencias(dados):
    ocorrencias = {col: dados[col].value_counts().to_dict() for col in lista_variaveis}
    return ocorrencias

ocorrencias_simbolos = contar_ocorrencias(data)


# 5
# Função para plotar o gráfico de barras das ocorrências
def plot_ocorrencias(ocorrencias, mostrar_graficos=True):
    if mostrar_graficos:
        for var, contagens in ocorrencias.items():
            simbolos, ocorrencias_filtradas = zip(*[(s, o) for s, o in contagens.items() if o > 0])
            plt.figure(figsize=(7, 5))
            plt.bar(simbolos, ocorrencias_filtradas, color='red')
            plt.xlabel(var)
            plt.ylabel('Count')
            plt.show()

# Plotar o número de ocorrências para todas as variáveis
plot_ocorrencias(ocorrencias_simbolos)


countMatrix = np.zeros((len(lista_variaveis), 65536), dtype=int)
for idx, var in enumerate(lista_variaveis):
    unique, counts = np.unique(data[var], return_counts=True)
    countMatrix[idx, unique] = counts

# 6
# Função para realizar o binning com correção para bins vazios
def binning(dados, countMatrix, variavel_idx, intervalo):
    limiteSuperior = dados.max()
    for i in range(0, limiteSuperior, intervalo):
        # Extrair elementos do countMatrix do índice i ao i + intervalo
        arrayFatiado = countMatrix[variavel_idx, i:i + intervalo]
        indiceMaxLocal = arrayFatiado.argmax()
        indiceMax = indiceMaxLocal + i
        
        # Substituir valores dentro do intervalo pelo índice do valor mais frequente
        condicao = np.logical_and(dados >= i, dados < i + intervalo)
        dados = np.where(condicao, indiceMax, dados)
    return dados

# Aplicar binning usando a nova função
data['Displacement_binned'] = binning(data['Displacement'], countMatrix, lista_variaveis.index('Displacement'), 5)
data['Horsepower_binned'] = binning(data['Horsepower'], countMatrix, lista_variaveis.index('Horsepower'), 5)
data['Weight_binned'] = binning(data['Weight'], countMatrix, lista_variaveis.index('Weight'), 40)


# Função para contar as ocorrências apenas para as variáveis 'binned'
def contar_ocorrencias_binned(dados, variaveis_binned):
    # Criar um dicionário vazio para armazenar as ocorrências
    ocorrencias = {}
    
    # Percorrer cada variável na lista de variáveis 'binned'
    for var in variaveis_binned:
        # Obter os valores únicos (alfabeto) da variável
        alfabeto_var = np.unique(dados[var])
        
        # Criar um dicionário para armazenar as ocorrências de cada símbolo da variável atual
        ocorrencias_var = {}
        
        # Contar as ocorrências de cada símbolo
        for simbolo in alfabeto_var:
            # Contar quantas vezes o símbolo aparece na variável e armazenar no dicionário
            contagem = (dados[var] == simbolo).sum()
            ocorrencias_var[simbolo] = contagem
        
        # Armazenar o dicionário de ocorrências da variável no dicionário principal
        ocorrencias[var] = ocorrencias_var
    
    # Retornar o dicionário com as ocorrências de cada variável 'binned'
    return ocorrencias

# Lista das variáveis 'binned'
variaveis_binned = ['Displacement_binned', 'Horsepower_binned', 'Weight_binned']

# Calcular ocorrências para as variáveis 'binned'
ocorrencias_binned = contar_ocorrencias_binned(data, variaveis_binned)

# Plotar os gráficos de ocorrências para as variáveis 'binned'
plot_ocorrencias(ocorrencias_binned)


print('')


# 7
# Função para calcular a entropia de uma variável (valor médio teórico de bits por símbolo)
def calcular_entropia(dados_var):
    _, contagens = np.unique(dados_var, return_counts=True)
    probabilidades = contagens / len(dados_var)
    return -np.sum(probabilidades * np.log2(probabilidades))

entropia_vars = {var: calcular_entropia(data[var]) for var in 
                 ['Acceleration', 'Cylinders', 'Displacement_binned', 'Horsepower_binned', 'ModelYear', 'Weight_binned', 'MPG']}
for var, entropia in entropia_vars.items():
    print(f'Entropia de {var}: {entropia:.9f} bits/símbolo')


# 8

import huffmancodec as huffc

def calcular_comprimento_medio_huffman(dados_var):
    codec = huffc.HuffmanCodec.from_data(dados_var)
    _, lengths = codec.get_code_len()
    freq = np.bincount(dados_var.astype(int))
    prob = freq[freq > 0] / np.sum(freq)
    return np.sum(prob * lengths)

def calcular_variancia_huffman(dados_var, comprimento_medio):
    codec = huffc.HuffmanCodec.from_data(dados_var)
    _, lengths = codec.get_code_len()
    freq = np.bincount(dados_var.astype(int))
    prob = freq[freq > 0] / np.sum(freq)
    return np.sum(prob * (lengths - comprimento_medio) ** 2)

comprimento_medio_vars = {var: calcular_comprimento_medio_huffman(data[var].astype(int)) for var in
                          ['Acceleration', 'Cylinders', 'Displacement_binned', 'Horsepower_binned', 'ModelYear', 'Weight_binned', 'MPG']}
variancia_vars = {var: calcular_variancia_huffman(data[var].astype(int), comprimento_medio_vars[var]) for var in comprimento_medio_vars}

# Exibir Comprimento Médio e Variância
print('\nComprimento médio e Variância de Huffman:')
for var in comprimento_medio_vars:
    print(f'{var}: = {comprimento_medio_vars[var]:.9f}, {variancia_vars[var]:.9f}')

print('')


# 9 
# Função para calcular os coeficientes de correlação de Pearson entre a variável alvo (target_var) e as demais variáveis
def calcular_correlacao_pearson(data, target_var, excluir_variaveis=[]):
    # Criar um dicionário vazio para armazenar as correlações
    correlacoes = {}
    
    # Listar variáveis que vamos calcular a correlação (excluindo as binned e a variável alvo)
    variaveis_a_calcular = []
    for var in data.columns:
        if var not in excluir_variaveis and var != target_var:
            variaveis_a_calcular.append(var)
    
    # Calcular a correlação de Pearson entre a variável alvo e cada variável selecionada
    for var in variaveis_a_calcular:
        matriz_correlacao = np.corrcoef(data[target_var], data[var])
        correlacao = matriz_correlacao[0, 1]
        correlacoes[var] = correlacao
    
    return correlacoes

# Lista das variáveis "binned" para excluir do cálculo da correlação
variaveis_binned = ['Displacement_binned', 'Horsepower_binned', 'Weight_binned']

# Aplicar a função para calcular as correlações entre MPG e as demais variáveis, excluindo as "binned"
correlacoes_mpg = calcular_correlacao_pearson(data, 'MPG', excluir_variaveis=variaveis_binned)

# Exibir os resultados
for var, correlacao in correlacoes_mpg.items():
    print(f'Coeficiente de correlação de {var}: {correlacao:.9f}')


# 10
# Função para calcular a informação mútua entre duas variáveis
def calcular_informacao_mutua(x, y):
    n = len(x)  # Número total de amostras
    
    # Encontrar os valores únicos e contagens para x e y
    valores_x, contagem_x = np.unique(x, return_counts=True)
    valores_y, contagem_y = np.unique(y, return_counts=True)
    
    # Calcular as probabilidades marginais de x e y
    p_x = contagem_x / n
    p_y = contagem_y / n
    
    # Inicializar a matriz conjunta p(x, y)
    p_xy = np.zeros((len(valores_x), len(valores_y)))
    
    # Calcular p(x, y): probabilidade conjunta de x e y
    for i, valor_x in enumerate(valores_x):
        for j, valor_y in enumerate(valores_y):
            p_xy[i, j] = np.sum((x == valor_x) & (y == valor_y)) / n

    # Calcular a informação mútua
    informacao_mutua = 0
    for i in range(len(valores_x)):
        for j in range(len(valores_y)):
            if p_xy[i, j] > 0:  # Ignorar valores onde p(x, y) é zero
                informacao_mutua += p_xy[i, j] * np.log2(p_xy[i, j] / (p_x[i] * p_y[j]))
    
    return informacao_mutua

# Calcular a MI entre MPG e as variáveis originais
mi_acceleration = calcular_informacao_mutua(data['MPG'], data['Acceleration'])
mi_cylinders = calcular_informacao_mutua(data['MPG'], data['Cylinders'])
mi_displacement = calcular_informacao_mutua(data['MPG'], data['Displacement_binned'])
mi_horsepower = calcular_informacao_mutua(data['MPG'], data['Horsepower_binned'])
mi_modelyear = calcular_informacao_mutua(data['MPG'], data['ModelYear'])
mi_weight = calcular_informacao_mutua(data['MPG'], data['Weight_binned'])

# Exibir os resultados da Informação Mútua
print('\nInformação Mútua: ')
print(f'MIAcc: {mi_acceleration:.9f}')
print(f'MICyl: {mi_cylinders:.9f}')
print(f'MIDis: {mi_displacement:.9f}')
print(f'MIHor: {mi_horsepower:.9f}')
print(f'MIMod: {mi_modelyear:.9f}')
print(f'MIWei: {mi_weight:.9f}\n')


# 11
# Função para estimar o MPG usando uma fórmula fixa
def estimar_mpg(data):
    return (-5.5241
            - 0.146 * data['Acceleration']
            - 0.4909 * data['Cylinders']
            + 0.0026 * data['Displacement_binned']
            - 0.0045 * data['Horsepower_binned']
            + 0.6725 * data['ModelYear']
            - 0.0059 * data['Weight_binned'])

# Função para calcular o RMSE entre valores reais e estimados de MPG
def calcular_rmse(mpg_real, mpg_estimado):
    return np.sqrt(np.mean((mpg_real - mpg_estimado) ** 2))

# Função para calcular o MAE entre valores reais e estimados de MPG
def calcular_mae(mpg_real, mpg_estimado):
    return np.mean(np.abs(mpg_real - mpg_estimado))

# Estimar o valor de MPG com base nos dados
mpg_estimado = estimar_mpg(data)

# Calcular RMSE e MAE entre o valor real e o estimado de MPG
rmse = calcular_rmse(data['MPG'], mpg_estimado)
mae = calcular_mae(data['MPG'], mpg_estimado)

# Substituir Acceleration e Weight_binned por suas médias e recalcular RMSE e MAE
data_substituida_acc = data.copy()
data_substituida_acc['Acceleration'] = data['Acceleration'].mean()
mpg_estimado_substituido_acc = estimar_mpg(data_substituida_acc)
rmse_menor_mi = calcular_rmse(data['MPG'], mpg_estimado_substituido_acc)
mae_menor_mi = calcular_mae(data['MPG'], mpg_estimado_substituido_acc)

data_substituida_weight = data.copy()
data_substituida_weight['Weight_binned'] = data['Weight_binned'].mean()
mpg_estimado_substituido_weight = estimar_mpg(data_substituida_weight)
rmse_maior_mi = calcular_rmse(data['MPG'], mpg_estimado_substituido_weight)
mae_maior_mi = calcular_mae(data['MPG'], mpg_estimado_substituido_weight)

# Exibir os resultados
print(f'MAE = {mae:.9f}')
print(f'RMSE = {rmse:.9f}\n')

print('Substituindo Acc pelo seu valor médio:')
print(f'MAE = {mae_menor_mi:.9f}')
print(f'RMSE = {rmse_menor_mi:.9f}\n')

print('Substituindo Weight pelo seu valor médio:')
print(f'MAE = {mae_maior_mi:.9f}')
print(f'RMSE = {rmse_maior_mi:.9f}')