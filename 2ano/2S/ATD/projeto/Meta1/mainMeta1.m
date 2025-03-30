%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% AUDIO_DIGIT_ANALYSIS.M
%
% Este script realiza as seguintes tarefas para identificação de dígitos a partir de sinais de áudio:
%  1) Cria uma tabela de metadados para arquivos de áudio e importa os sinais.
%  2) Pré-processa os sinais de áudio (remove silêncio inicial, normaliza amplitude).
%  3) Plota sinais de áudio brutos para os dígitos 0–9, repetição 5 (replica a Figura 2).
%  4) Extrai 5 características temporais de cada sinal pré-processado.
%  5) Plota sinais de áudio pré-processados para os dígitos 0–9, repetição 5.
%  6) Compara visualmente os gráficos das etapas 3 e 5 (descritos no texto).
%  7) Visualiza as características e identifica a melhor para discriminação de dígitos (replica a Figura 3).
%  8) Remove os sinais de áudio da tabela e salva em finalAudioData.mat.
%
% Autor: [Teodoro Marques, Bernardo Direito]
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear; close all; clc;

%% PARÂMETROS_INICIAIS
audioFolderPath      = 'samples';    % Caminho para a pasta contendo arquivos de áudio .wav
participantID        = 40;           % Identificador único para o participante
digitNumbers         = 0:9;          % Dígitos de 0 a 9
repetitionNumbers    = 0:49;         % 50 gravações por dígito
numberOfDigits       = length(digitNumbers);
numberOfRepetitions  = length(repetitionNumbers);

%% ETAPA_1_E_2: CRIAR_TABELA_DE_METADADOS_E_IMPORTAR_SINAIS_DE_ÁUDIO
% Cria uma tabela de metadados e importa os sinais de áudio
totalRecordings = numberOfDigits * numberOfRepetitions;
audioFilePath        = cell(totalRecordings, 1);
audioFileName        = cell(totalRecordings, 1);
participantIDVector  = zeros(totalRecordings, 1);
digitValue           = zeros(totalRecordings, 1);
repetitionNumber     = zeros(totalRecordings, 1);
rawAudioSignal       = cell(totalRecordings, 1);
samplingRate         = zeros(totalRecordings, 1);

recordingIndex = 1;
for currentDigit = digitNumbers
    for currentRepetition = repetitionNumbers
        % Cria uma string com o nome do arquivo de áudio no formato 'd_p_r.wav'
        fileNameStr = sprintf('%d_%d_%d.wav', currentDigit, participantID, currentRepetition);
        
        % Constrói o caminho completo do arquivo de áudio
        filePath = fullfile(audioFolderPath, fileNameStr);

        % Armazena valores em vetores
        audioFilePath{recordingIndex}    = filePath;
        audioFileName{recordingIndex}     = fileNameStr;
        participantIDVector(recordingIndex) = participantID;
        digitValue(recordingIndex)       = currentDigit;
        repetitionNumber(recordingIndex) = currentRepetition;

        try
            % Tenta ler o arquivo de áudio
            [signalData, sampleRate] = audioread(filePath);
        catch ME
            % Em caso de erro, exibe um aviso e define os dados de sinal e taxa de amostragem como vazios
            warning('Erro ao ler %s: %s', filePath, ME.message);
            signalData = []; sampleRate = NaN;
        end

        % Armazena os dados do sinal de áudio e taxa de amostragem em vetores
        rawAudioSignal{recordingIndex} = signalData;
        samplingRate(recordingIndex)   = sampleRate;

        % Incrementa o índice de gravação
        recordingIndex = recordingIndex + 1;
    end
end

metadataTable = table(audioFilePath, audioFileName, participantIDVector, digitValue, repetitionNumber, ...
                      rawAudioSignal, samplingRate, ...
    'VariableNames', {'AudioFilePath', 'AudioFileName', 'ParticipantID', 'DigitValue', ...
                      'RepetitionNumber', 'RawAudioSignal', 'SamplingRate'});

disp('--- Tabela de Metadados com Sinais de Áudio (primeiras 10 linhas) ---');
disp(metadataTable(1:min(10, height(metadataTable)), :));

%% ETAPA_3: PLOTAR_SINAIS_DE_ÁUDIO_BRUTOS (DÍGITOS 0–9, REPETIÇÃO 5)
figure('Name', 'OriginalAudioSignalPlots', 'NumberTitle', 'off', 'Position', [100 100 1200 800]);
for currentDigit = 0:9 
    subplot(5, 2, currentDigit + 1); % 5 por 2 !
    signalIndex = find(metadataTable.DigitValue == currentDigit & metadataTable.RepetitionNumber == 5, 1); % neste exemplo Ã© 5
    if ~isempty(signalIndex) && ~isempty(metadataTable.RawAudioSignal{signalIndex})
        signalData = metadataTable.RawAudioSignal{signalIndex};
        sampleRate = metadataTable.SamplingRate(signalIndex);
        timeAxis = (0:length(signalData) - 1) / sampleRate;
        plot(timeAxis, signalData, 'b', 'LineWidth', 2); 
        xlabel('Time (s)', 'FontSize', 12);
        ylabel('Amplitude', 'FontSize', 12);
        title(sprintf('Digit %d, Repetition 5', currentDigit), 'FontSize', 14);
        switch currentDigit
            case {0, 2, 8, 9}
                ylim([-0.02 0.02]);
            case {1, 3, 4, 5, 7}
                ylim([-0.03 0.03]);
            case 6
                ylim([-0.04 0.04]);
        end
        grid on;
        set(gca, 'FontSize', 10);
    else
        title(sprintf('Digit %d (not found)', currentDigit), 'FontSize', 14);
    end
end
sgtitle('Original Audio Signal Plots', 'FontSize', 16);

%% ETAPA_4 : PRÉ-PROCESSAMENTO DE SINAIS DE ÁUDIO
% 1) Remover silêncio inicial baseado no energy threshold
% 2) Normalização da amplitude de [-1, 1]
targetDurationSec = 0.6;  % duração fixa de 1 segundo
preprocessedAudioSignals = cell(totalRecordings, 1);

for i = 1:totalRecordings
    if ~isempty(metadataTable.RawAudioSignal{i})
        preprocessedSignal = removeInitialSilenceAndNormalize(metadataTable.RawAudioSignal{i}, metadataTable.SamplingRate(i), targetDurationSec);
    else
        preprocessedSignal = [];
    end
    preprocessedAudioSignals{i} = preprocessedSignal;
end

metadataTable.PreprocessedAudioSignal = preprocessedAudioSignals;

%% ETAPA_5: PLOTAR_SINAIS_DE_ÁUDIO_PRÉ-PROCESSADOS (DÍGITOS 0–9, REPETIÇÃO 5)

% Plota os sinais de áudio pré-processados para os dígitos 0–9, repetição 5
figure('Name', 'PreprocessedAudioSignalPlots', 'NumberTitle', 'off');

% Plota os sinais de áudio pré-processados para os dígitos 0–9, repetição 5
for currentDigit = 0:9  % Plota dígitos 0–9 em uma grade 5x2
    subplot(5, 2, currentDigit + 1);  % Cria um subplot para cada dígito
    signalIndex = find(metadataTable.DigitValue == currentDigit & metadataTable.RepetitionNumber == 5, 1);  % Encontra o índice do sinal correspondente

    % Verifica se o sinal de áudio pré-processado não está vazio
    if ~isempty(signalIndex) && ~isempty(metadataTable.PreprocessedAudioSignal{signalIndex})
        % Se não estiver vazio, plota o sinal de áudio pré-processado
        signalData = metadataTable.PreprocessedAudioSignal{signalIndex};  % Obtém os dados do sinal pré-processado
        sampleRate = metadataTable.SamplingRate(signalIndex);  % Obtém a taxa de amostragem
        timeAxis = (0:length(signalData) - 1) / sampleRate;  % Cria o eixo do tempo
        plot(timeAxis, signalData, 'b');  % Plota o sinal com linha azul
        xlabel('Tempo (s)');  % Define o rótulo do eixo x
        ylabel('Amplitude');  % Define o rótulo do eixo y
        title(sprintf('Dígito %d, Repetição 5', currentDigit));  % Define o título do subplot
        ylim([-1 1]);  % Define os limites do eixo y para amplitude normalizada
        grid on;  % Adiciona uma grade ao gráfico
    else
        % Exibe mensagem se o sinal não for encontrado
        title(sprintf('Dígito %d (não encontrado)', currentDigit));
    end
end

sgtitle('Gráficos de Sinais de Áudio Pré-processados');  % Define o título geral da figura

%% ETAPA_6: COMPARAÇÃO_VISUAL_DOS_GRÁFICOS

% Descrição fornecida no relatório

%% ETAPA_7: EXTRAIR_CARACTERÍSTICAS_TEMPORAIS

% Características extraídas: 1) Energia Total, 2) Desvio Padrão, 3) Fator de Crista,
%                            4) Taxa de Cruzamento por Zero, 5) Duração Original (segundos)

% Define o número de características a serem extraídas
numberOfFeatures = 5;

% Inicializa a matriz de características com zeros
featureMatrix = zeros(totalRecordings, numberOfFeatures);

% Loop para extrair características de cada sinal de áudio pré-processado
for i = 1:totalRecordings
    if ~isempty(metadataTable.PreprocessedAudioSignal{i})
        % Obtém o comprimento do sinal original
        originalSignalLength = length(metadataTable.RawAudioSignal{i});
        
        % Extrai as características temporais do sinal pré-processado, passando o comprimento original
        featureValues = extractTemporalFeatures(metadataTable.PreprocessedAudioSignal{i}, metadataTable.SamplingRate(i), originalSignalLength);
    else
        % Se o sinal estiver vazio, define as características como zeros
        featureValues = zeros(1, numberOfFeatures);
    end
    % Armazena as características extraídas na matriz de características
    featureMatrix(i, :) = featureValues;
end

% Adiciona as características extraídas à tabela de metadados
metadataTable.TotalEnergy      = featureMatrix(:, 1);  % Energia Total
metadataTable.StandardDeviation = featureMatrix(:, 2); % Desvio Padrão
metadataTable.CrestFactor = featureMatrix(:, 3);  % Fator de Crista (substituindo Assimetria)
metadataTable.ZeroCrossingRate = featureMatrix(:, 4);  % Taxa de Cruzamento por Zero
metadataTable.OriginalDuration = featureMatrix(:, 5);  % Duração original em segundos

%% ETAPA_8: VISUALIZAR_CARACTERÍSTICAS
% Parte A: Boxplot e Scatter 3D para replicar a Figura 3

% BOXPLOT DA ENERGIA TOTAL DUPLICADO REMOVIDO
% Parte A: Boxplot da Energia Total por Dígito
% figure('Name', 'Boxplot_TotalEnergy', 'NumberTitle', 'off', 'Position', [100, 100, 1200, 600]);
% boxchart(categorical(metadataTable.DigitValue), metadataTable.TotalEnergy, 'BoxFaceColor', 'b', 'MarkerColor', [0.7 0.7 1]);
% xlabel('Dígito');
% ylabel('Energia Total');
% title('Boxplot da Energia Total por Dígito');

% Parte B: Dispersão 3D das Características: Taxa de Cruzamento por Zero, Desvio Padrão e Duração Original
figure('Name', '3DScatter_Features', 'NumberTitle', 'off', 'Position', [100, 100, 1200, 600]);
hold on;
digitColors = [0.7 0.7 1; 1 0.7 0.7; 0 1 0; 1 0 0; 1 1 0; 0.5 0 0.5; 1 0.5 0; 0 1 1; 0.6 0.3 0; 0 0 0.5];
for currentDigit = 0:9
    digitIndices = metadataTable.DigitValue == currentDigit;
    scatter3(metadataTable.ZeroCrossingRate(digitIndices), metadataTable.StandardDeviation(digitIndices), ...
             metadataTable.OriginalDuration(digitIndices), 10, digitColors(currentDigit + 1, :), 'filled');
end
hold off;
xlabel('Taxa de Cruzamento por Zero');
ylabel('Desvio Padrão');
zlabel('Duração Original (s)');
title('Dispersão 3D da Taxa de Cruzamento por Zero, Desvio Padrão e Duração Original');
legend(cellstr(num2str((0:9)')), 'Location', 'eastoutside');

% Define viewing angle for better 3D visualization
view([-37.5, 30]); % Azimuth = -37.5, Elevation = 30
grid on;
rotate3d on; % Enable 3D rotation with mouse

% Definir os nomes das características extraídas
featureNames = {'Energia Total', 'Desvio Padrão', 'Fator de Crista', 'Taxa de Cruzamento por Zero', 'Duração Original (s)'};  % Nomes das características extraídas

% Loop para criar gráficos de dispersão para cada característica extraída
for featureIndex = 1:numberOfFeatures
    % Criar uma nova figura para cada par de características
    if mod(featureIndex, 2) == 1
        figure('Name', ['ScatterPlot_', featureNames{featureIndex}], 'NumberTitle', 'off', 'Position', [100, 100, 1200, 600]);
    end
    subplot(1, 2, mod(featureIndex - 1, 2) + 1);  % Criar subplots lado a lado
    hold on;
    % Loop para plotar os dados de cada dígito
    for currentDigit = digitNumbers
        digitIndices = (metadataTable.DigitValue == currentDigit);  % Encontrar índices dos sinais do dígito atual
        scatter(repmat(currentDigit, 1, sum(digitIndices)), featureMatrix(digitIndices, featureIndex), 'filled');  % Plotar os dados
    end
    hold off;
    xlabel('Dígito');  % Rótulo do eixo x
    ylabel(featureNames{featureIndex});  % Rótulo do eixo y
    xticks(digitNumbers);  % Definir os ticks do eixo x
    title(featureNames{featureIndex});  % Título do subplot
end

% Loop para criar boxplots para cada característica extraída
for featureIndex = 1:numberOfFeatures
    % Cria uma nova figura para cada par de características
    if mod(featureIndex, 2) == 1
        figure('Name', ['Boxplot_', featureNames{featureIndex}], 'NumberTitle', 'off', 'Position', [100, 100, 1200, 600]);
    end
    subplot(1, 2, mod(featureIndex - 1, 2) + 1);  % Cria subplots lado a lado
    % Cria um boxplot para a característica atual
    boxchart(categorical(metadataTable.DigitValue), featureMatrix(:, featureIndex));
    xlabel('Dígito');  % Define o rótulo do eixo x
    ylabel(featureNames{featureIndex});  % Define o rótulo do eixo y
    title(featureNames{featureIndex});  % Define o título do subplot
end

%% ETAPA_9: REMOVER_SINAIS_DE_ÁUDIO_E_SALVAR
% Remove os sinais de áudio da tabela e salva em finalAudioData.mat
metadataTable.RawAudioSignal = [];
save('finalAudioData.mat', 'metadataTable');

disp('--- Fim: Estrutura de dados de áudio salva em finalAudioData.mat ---');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% FUNÇÕES_AUXILIARES
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [preprocessedSignal] = removeInitialSilenceAndNormalize(signal, sampleRate, targetDurationSec)
    % Calcula o tamanho da janela de movsum como 0,1% do comprimento total do sinal
    % Usa-se max(1, round()) para garantir que o tamanho da janela seja pelo menos 1
    windowSize = max(1, round(0.001 * length(signal)));
    
    % Calcula a soma móvel dos valores absolutos do sinal para detectar o início do sinal
    % Isso ajuda a identificar onde o sinal de áudio significativo começa
    movingSumSignal = movsum(abs(signal), windowSize);
    
    % Calcula o limiar de energia como 20% do valor máximo de energia
    % Valor arbitrário escolhido para representar quando a energia do sinal é considerável
    % 0,2 significa que consideramos o sinal relevante quando atinge 20% da energia máxima
    limiar = 0.2 * max(movingSumSignal);
    
    % Encontra o primeiro índice onde o sinal móvel ultrapassa o limiar
    % Isso indica o início do sinal de áudio significativo
    startIndex = find(movingSumSignal > limiar, 1);
    
    % Se nenhum início for encontrado, usa o início do sinal
    if isempty(startIndex)
        startIndex = 1;
    end
    
    % Extrai o sinal a partir do ponto de início detectado
    preprocessedSignal = signal(startIndex:end);
    
    % Normalização de amplitude
    % Primeiro, normaliza para o intervalo [0, 1]
    % Subtrai o valor mínimo e divide pela variação total
    preprocessedSignal = (preprocessedSignal - min(preprocessedSignal)) / ...
                         (max(preprocessedSignal) - min(preprocessedSignal));
    
    % Em seguida, dimensiona para o intervalo [-1, 1] 
    % Permite uma representação dinâmica melhor do sinal
    preprocessedSignal = 2 * preprocessedSignal - 1;
    
    % Ajusta a duração do sinal para exatamente 0,6 segundos
    targetLength = round(targetDurationSec * sampleRate);
    currentLength = length(preprocessedSignal);
    
    % Verifica o comprimento do sinal e ajusta
    if currentLength < targetLength
        % Se o sinal for mais curto, adiciona zeros
        preprocessedSignal = [preprocessedSignal; zeros(targetLength - currentLength, 1)];
    elseif currentLength > targetLength
        % Se o sinal for mais longo, trunca
        preprocessedSignal = preprocessedSignal(1:targetLength);
    end
    
    % Normalização suave para prevenir cortes
    % Garante que nenhum valor esteja exatamente em -1 ou 1
    preprocessedSignal = preprocessedSignal * 0.99;
end

% function frameEnergy = calculateFrameEnergy(signal, frameSamples, numberOfFrames)
%    frameEnergy = zeros(numberOfFrames, 1);
%    for frameIndex = 1:numberOfFrames
%        frame = signal((frameIndex - 1) * frameSamples + 1 : frameIndex * frameSamples);
%        frameEnergy(frameIndex) = sum(frame .^ 2);
%    end
%end

% Função modificada para calcular o Fator de Crista (Ratio of peak amplitude to RMS - (Root Mean Square): Provides a measure of the magnitude of the signal - value) em vez da assimetria
% Fator de crista -> Razão entre o valor de pico e o RMS (que é o valor quadrático médio) 
function featureValues = extractTemporalFeatures(signal, sampleRate, originalSignalLength)
    featureValues = zeros(1, 5);
    featureValues(1) = sum(signal .^ 2);                        % Total Energy
    featureValues(2) = std(signal);                             % Standard Deviation
    
    % Fator de Crista (Crest Factor) - Razão entre valor de pico e RMS
    peakValue = max(abs(signal));
    rmsValue = sqrt(mean(signal.^2));
    if rmsValue > 0
        featureValues(3) = peakValue / rmsValue;                % Crest Factor
    else
        featureValues(3) = 0;
    end
    
    featureValues(4) = calculateZeroCrossingRate(signal);       % Zero Crossing Rate
    featureValues(5) = originalSignalLength / sampleRate;       % Duration of original signal in seconds
end

function zeroCrossingRate = calculateZeroCrossingRate(signal)
    signalSign = sign(signal);
    signDifference = diff(signalSign);
    zeroCrossingRate = sum(signDifference ~= 0) / (length(signal) - 1);
end