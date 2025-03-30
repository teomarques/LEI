%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% MAIN.M
%
% Este script realiza as seguintes tarefas:
%  1) Cria uma tabela de metadados para os áudios e importa os sinais.
%  2) Realiza pré-processamento dos sinais (remoção de silêncio inicial,
%     normalização, sem ajuste de duração para features).
%  3) Representa graficamente os sinais brutos para dígitos 0-9, repetição 5.
%  4) Extrai 5 características temporais de cada sinal antes de padding.
%  5) Representa graficamente os sinais pré-processados para dígitos 0-9, repetição 5.
%  6) Compara visualmente os gráficos de 3 e 5 (descrito no texto).
%  7) Visualiza as features e identifica as melhores para discriminação.
%  8) Remove os sinais de áudio da tabela e salva em finalData.mat.
%
% Autor: [Seu Nome]
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear; close all; clc;

%% PARÂMETROS INICIAIS
baseDir      = 'samples';    % Pasta onde estão os ficheiros .wav
participant  = 40;           % ID do participante
digitsRange  = 0:9;          % Dígitos de 0 a 9
repetitions  = 0:49;         % 50 gravações de cada dígito
nDigits      = length(digitsRange);
nReps        = length(repetitions);

%% PONTO 1 e 2: CRIAR ESTRUTURA (TABELA) E IMPORTAR SINAIS
nTotal = nDigits * nReps;
diretorio       = cell(nTotal,1);
nomeFicheiro    = cell(nTotal,1);
participanteVec = zeros(nTotal,1);
digito          = zeros(nTotal,1);
repeticao       = zeros(nTotal,1);
audioSignal     = cell(nTotal,1);
fsVal           = zeros(nTotal,1);

idx = 1;
for d = digitsRange
    for r = repetitions
        nomeArq = sprintf('%d_%d_%d.wav', d, participant, r);
        caminho = fullfile(baseDir, nomeArq);

        diretorio{idx}    = caminho;
        nomeFicheiro{idx} = nomeArq;
        participanteVec(idx) = participant;
        digito(idx)       = d;
        repeticao(idx)    = r;

        try
            [sig, fs] = audioread(caminho);
        catch ME
            warning('Erro ao ler %s: %s', caminho, ME.message);
            sig = []; fs = NaN;
        end

        audioSignal{idx} = sig;
        fsVal(idx)       = fs;

        idx = idx + 1;
    end
end

T = table(diretorio, nomeFicheiro, participanteVec, digito, repeticao, ...
          audioSignal, fsVal, ...
    'VariableNames', {'Diretorio','NomeFicheiro','Participante','Digito',...
                      'Repeticao','AudioSignal','Fs'});

disp('--- Tabela com Metadados e Sinais (primeiras 10 linhas) ---');
disp(T(1:min(10,height(T)), :));

%% PONTO 3: REPRESENTAR GRAFICAMENTE OS SINAIS BRUTOS (DIGITOS 0-9, REPETIÇÃO 5)
fig1 = figure('Name','Gráficos dos Áudios Originais','NumberTitle','off');
for d = 0:8  % Plot digits 0-8 em uma grid 3x3
    subplot(3,3,d+1);
    idx = find(T.Digito == d & T.Repeticao == 5, 1);
    if ~isempty(idx) && ~isempty(T.AudioSignal{idx})
        sig = T.AudioSignal{idx};
        fs = T.Fs(idx);
        t = (0:length(sig)-1)/fs;
        plot(t, sig, 'b');
        xlabel('Tempo (s)');
        ylabel('Amplitude');
        title(sprintf('Dígito %d, Repetição 5', d));
        
        % Ajusta o eixo Y de forma automática, permitindo ver todo o sinal
        ylim('auto');
        
        grid on;
    else
        title(sprintf('Dígito %d (não encontrado)', d));
    end
end
sgtitle('Gráficos dos Áudios Originais');
print(fig1, '-dpng', 'graficos_audios_originais.png');  % Salva como PNG


%% PONTO 4: PRÉ-PROCESSAMENTO DOS SINAIS
% Passos: 1) Remoção de silêncio inicial
%         2) Normalização para [-1, 1]
%         (Sem padding, pois não é necessário para features ou plots)
preprocSignals = cell(nTotal,1);

for i = 1:nTotal
    if ~isempty(T.AudioSignal{i})
        ppSig = preprocessSignal(T.AudioSignal{i}, T.Fs(i));
    else
        ppSig = [];
    end
    preprocSignals{i} = ppSig;
end

T.PreprocSignal = preprocSignals;

%% PONTO 5: REPRESENTAR GRAFICAMENTE OS SINAIS PRÉ-PROCESSADOS (DIGITOS 0-9, REPETIÇÃO 5)
fig2 = figure('Name','Gráficos dos Áudios Pré-Processados','NumberTitle','off');
for d = 0:8  % Plot digits 0-8 to match Figure 2 style
    subplot(3,3,d+1);
    idx = find(T.Digito == d & T.Repeticao == 5, 1);
    if ~isempty(idx) && ~isempty(T.PreprocSignal{idx})
        sig = T.PreprocSignal{idx};
        fs = T.Fs(idx);
        t = (0:length(sig)-1)/fs;
        plot(t, sig, 'b');
        xlabel('Tempo (s)');
        ylabel('Amplitude');
        title(sprintf('Dígito %d, Repetição 5', d));
        ylim([-1 1]);  % Normalized amplitude
        grid on;
    else
        title(sprintf('Dígito %d (não encontrado)', d));
    end
end
sgtitle('Gráficos dos Áudios Pré-Processados');
print(fig2, '-dpng', 'graficos_audios_preprocessados.png');  % Salva como PNG

%% PONTO 6: COMPARAÇÃO VISUAL DOS GRÁFICOS (DESCRIÇÃO NO TEXTO ABAIXO)

%% PONTO 7: CÁLCULO DAS FEATURES
% Features: 1) Energia total, 2) Desvio padrão, 3) Amplitude máxima,
%           4) Zero Crossing Rate, 5) Duração (s)
nFeatures = 5;
featuresMatrix = zeros(nTotal, nFeatures);

for i = 1:nTotal
    if ~isempty(T.PreprocSignal{i})
        feats = computeFeatures(T.PreprocSignal{i}, T.Fs(i));
    else
        feats = zeros(1, nFeatures);
    end
    featuresMatrix(i,:) = feats;
end

T.TotalEnergy = featuresMatrix(:,1);
T.StdDev      = featuresMatrix(:,2);
T.MaxAmp      = featuresMatrix(:,3);
T.ZCR         = featuresMatrix(:,4);
T.Duration    = featuresMatrix(:,5);

%% PONTO 8: VISUALIZAÇÃO DAS FEATURES
% A) Boxplot e 3D Scatter para replicar Figure 3
fig3 = figure('Name','Representação gráfica das características extraídas','NumberTitle','off');

% Boxplot de Total Energy
subplot(1,2,1);
boxchart(categorical(T.Digito), T.TotalEnergy, 'BoxFaceColor', 'b', 'MarkerColor', [0.7 0.7 1]);
xlabel('Dígito');
ylabel('Total Energy');
title('Boxplot de Total Energy por Dígito');

% 3D Scatter de ZCR, StdDev, Duration
subplot(1,2,2);
hold on;
colors = [0.7 0.7 1; 1 0.7 0.7; 0 1 0; 1 0 0; 1 1 0; 0.5 0 0.5; 1 0.5 0; 0 1 1; 0.6 0.3 0; 0 0 0.5];
for d = 0:9
    idx = T.Digito == d;
    scatter3(T.ZCR(idx), T.StdDev(idx), T.Duration(idx), 10, colors(d+1,:), 'filled');
end
hold off;
xlabel('ZCR');
ylabel('Std Dev');
zlabel('Duration (s)');
title('3D Scatter de ZCR, Std Dev e Duration');
legend(cellstr(num2str((0:9)')), 'Location', 'eastoutside');
print(fig3, '-dpng', 'representacao_grafica_features.png');  % Salva como PNG

% B) Scatter e Boxplots para todas as features (original)
fig4 = figure('Name','Scatter das 5 Features','NumberTitle','off');
featureNames = {'Total Energy','Std Dev','Max Amp','ZCR','Duration (s)'};
for f = 1:nFeatures
    subplot(1,nFeatures,f);
    hold on;
    for d = digitsRange
        idxD = (T.Digito == d);
        scatter(repmat(d,1,sum(idxD)), featuresMatrix(idxD,f), 'filled');
    end
    hold off;
    xlabel('Dígito');
    ylabel(featureNames{f});
    xticks(digitsRange);
    title(featureNames{f});
end
sgtitle('Scatter das Features extraídas');
print(fig4, '-dpng', 'scatter_5_features.png');  % Salva como PNG

fig5 = figure('Name','Boxplots das 5 Features','NumberTitle','off');
for f = 1:nFeatures
    subplot(1,nFeatures,f);
    boxchart(categorical(T.Digito), featuresMatrix(:,f));
    xlabel('Dígito');
    ylabel(featureNames{f});
    title(featureNames{f});
end
sgtitle('Boxplots das Features extraídas');
print(fig5, '-dpng', 'boxplots_5_features.png');  % Salva como PNG

%% PONTO 9: REMOÇÃO DOS SINAIS E SALVAMENTO
T.AudioSignal   = [];
T.PreprocSignal = [];
save('finalData.mat', 'T');

disp('--- Fim: Estrutura de dados salva em finalData.mat ---');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% FUNÇÕES AUXILIARES
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [ppSig] = preprocessSignal(sig, fs)
    frameSizeSec = 0.001;
    frameSamples = round(frameSizeSec * fs);
    numFrames    = floor(length(sig) / frameSamples);
    energy       = getFrameEnergy(sig, frameSamples, numFrames);

    energyThreshold = 0.01;
    startFrame = find(energy > energyThreshold, 1);
    if isempty(startFrame)
        startFrame = 1;
    end
    startSample = (startFrame - 1)*frameSamples + 1;

    ppSig = sig(startSample:end);

    minVal = min(ppSig);
    maxVal = max(ppSig);
    if (maxVal - minVal) < 1e-12
        ppSig = zeros(size(ppSig));
    else
        ppSig = (ppSig - minVal) / (maxVal - minVal);  % [0, 1]
        ppSig = 2*ppSig - 1;                           % [-1, 1]
    end
end

function energyVec = getFrameEnergy(y, frameSamples, numFrames)
    energyVec = zeros(numFrames, 1);
    for j = 1:numFrames
        frame = y((j-1)*frameSamples + 1 : j*frameSamples);
        energyVec(j) = sum(frame.^2);
    end
end

function feats = computeFeatures(sig, fs)
    feats = zeros(1,5);
    feats(1) = sum(sig.^2);            % Energia total
    feats(2) = std(sig);               % Desvio padrão
    feats(3) = max(abs(sig));          % Amplitude máxima
    feats(4) = zerocrossrate(sig);     % Zero Crossing Rate
    feats(5) = length(sig)/fs;         % Duração em segundos
end

function zcr = zerocrossrate(sig)
    s  = sign(sig);
    ds = diff(s);
    zcr = sum(ds ~= 0) / (length(sig)-1);
end
